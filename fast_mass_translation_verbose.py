import sys
import re
import os
import time
import json
import concurrent.futures
from threading import Lock

try:
    from google import genai
except ImportError:
    print("Erro: A biblioteca google-genai não está instalada.")
    sys.exit(1)

from gba_text_simulator import simulate_and_format_text

CACHE_FILE = "translation_cache.json"
FINISHED_FILES_FILE = "finished_files.json"
STATS_FILE = "translation_stats.json"

AI_MODELS = [
    'gemini-2.5-flash',
    'gemini-2.5-pro',
    'gemini-2.0-flash',
    'gemini-2.0-flash-001',
    'gemini-2.0-flash-lite',
    'gemini-2.0-flash-lite-001',
    'gemini-flash-latest',
    'gemini-flash-lite-latest',
    'gemini-pro-latest',
    'gemini-2.5-flash-lite',
    'gemini-3-flash-preview',
    'gemini-3.1-flash-lite-preview',
    'gemini-3.1-flash-lite',
    'gemini-3.5-flash',
    'gemma-4-26b-a4b-it',
    'gemma-4-31b-it'
]

# ─────────────────────────────────────────────
# CONTEXTO DO UNIVERSO POKÉMON PARA A IA
# ─────────────────────────────────────────────
POKEMON_UNIVERSE_CONTEXT = """
CONTEXTO DO UNIVERSO POKÉMON EMERALD:
- Ambientado na região de Hoenn, um arquipélago tropical com muita água e natureza exuberante
- As principais cidades incluem: Cidade de Pétala (Petalburg), Ruivópolis (Rustboro), Mauville, Lilycove, Cidade Vera (Verdanturf), Fortree, Sootopolis, etc.
- O Professor Birch é o professor Pokémon local
- Os principais vilões são o Team Aqua e o Team Magma
- Lendários: Rayquaza, Groudon, Kyogre
- O professor dá ao jogador o seu primeiro Pokémon: Treecko, Torchic ou Mudkip
- NPCs comuns: Treinadores, Médicos Pokémon, Vendedores, Pescadores, Experts, Pesquisadores, Vovôs sábios, crianças curiosas
- Itens importantes: Pokébolas, Poções, Insígnias dos Líderes de Ginásio, TMs (Máquinas Técnicas), Bagas
- Mecânicas de jogo: batalhas, capturas, ginásios, Concursos Pokémon, Liga Pokémon
- O tom geral é aventureiro, amigável, com senso de maravilha e descoberta
"""

TRANSLATION_STYLE_GUIDE = """
GUIA DE ESTILO PARA TRADUÇÃO PT-BR:
- Use linguagem acessível e calorosa, adequada para todas as idades
- NPCs têm PERSONALIDADES DISTINTAS — adapte o tom conforme o tipo de NPC:
    • Vovô/Vovó: sábio, nostálgico, usa expressões antigas como "No meu tempo..."
    • Criança: animada, usa palavras como "incrível!", "demais!", fala sobre Pokémon com euforia
    • Cientista/Pesquisador: formal, técnico, usa termos como "fascinante", "dados indicam que..."
    • Pescador: descontraído, usa gírias do mar, fala de Pokémon aquáticos
    • Treinador rival: confiante, levemente arrogante, sempre desafiador
    • Comerciante: amigável e prestativo, focado em serviços e itens
    • Médico Pokémon: gentil, atencioso, preocupado com saúde dos Pokémon
    • Guarda/Policial: sério, objetivo, focado em segurança
    • Morador comum: casual, fala sobre a vida na cidade/rota
- Preserve TODOS os nomes de Pokémon em inglês (Pikachu, Mudkip, etc.) — são nomes próprios
- Nomes de cidades e regiões: use versões em PT-BR quando existirem (ex: Hoenn, Mauville)
- Termos de jogo que NÃO devem ser traduzidos: HP, PP, TM, HM, EV, IV
- Expressões que PODEM ser traduzidas: "Gym Badge" → "Insígnia", "Trainer" → "Treinador"
"""

BIRTHDAY_CREATIVE_GUIDE = """
GUIA CRIATIVO PARA O ANIVERSÁRIO DO LUCAS:
- O protagonista se chama LUCAS e hoje é seu ANIVERSÁRIO
- Cada NPC deve parabenizar de um jeito ÚNICO, baseado em sua personalidade e função
- A parabenização deve ser INTEGRADA NATURALMENTE ao texto original — não apenas colada no final
- Exemplos de integração criativa por tipo de NPC:
    • Médico: "Seus Pokémon estão com saúde ótima... igualzinho você no seu aniversário, Lucas!"
    • Pescador: "Hoje o mar está calmo — sinal de boa sorte pro aniversariante!"
    • Cientista: "Fascinante! Coincidentemente, hoje marca mais um ano de vida para você, Lucas!"
    • Criança: "LUCAS! Hoje é seu aniversário?! QUE MASSA!"
    • Vovô: "Ah, jovem Lucas... Parabéns pelo aniversário. Em cada ano que passa, você fica mais sábio."
    • Comerciante: "Aniversário merece um desconto especial, Lucas — mas aqui só temos preços fixos, haha!"
- NUNCA repita a mesma frase de parabenização que já foi usada antes
- Varie os gatilhos: pode ser o NPC que sabe, um Pokémon que avisa, o clima do dia, etc.
- O cumprimento deve ter no máximo 1-2 frases extras — não sobrecarregue o texto
"""

# CONTEXTO DE INTERAÇÃO DO CÓDIGO (Gerado para a IA ter consciência de seu papel)
CODE_INTERACTION_CONTEXT = """
CONTEXTO DO SEU AMBIENTE DE EXECUÇÃO:
- Você é um modelo de linguagem atuando como motor de tradução assíncrono.
- Um script Python em múltiplas threads (até 5 simultâneas) envia arquivos de mapa do Pokémon Emerald em blocos isolados.
- Se o limite de cota da API (Rate Limit / 429) for atingido, a execução aguardará 60 segundos antes de reenviar o prompt.
- Para evitar gargalos, se você falhar repetidamente ou não for encontrado (404), será isolado da fila (invalid_models).
- O script usa um arquivo JSON local ("translation_cache.json") como cache; seu resultado aqui substituirá permanentemente a string original no arquivo fonte `.inc`.
- A formatação correta de texto (quebras de linha, tags Hex e limite de 280 caracteres) é posteriormente processada pelo script usando o módulo `gba_text_simulator.py`. Portanto, entregue APENAS o texto puro sem formatações adicionais.
"""


# ─────────────────────────────────────────────
# VARIÁVEIS GLOBAIS THREAD-SAFE
# ─────────────────────────────────────────────
invalid_models = set()
model_lock = Lock()
cache_lock = Lock()
file_lock = Lock()
stats_lock = Lock()

# Histórico de parabenizações usadas (para evitar repetição)
used_birthday_phrases = []
birthday_phrases_lock = Lock()


def load_json(filepath):
    if os.path.exists(filepath):
        try:
            with open(filepath, 'r', encoding='utf-8') as f:
                return json.load(f)
        except Exception:
            return {} if "cache" in filepath or "stats" in filepath else []
    return {} if "cache" in filepath or "stats" in filepath else []


def save_json(filepath, data):
    with open(filepath, 'w', encoding='utf-8') as f:
        json.dump(data, f, ensure_ascii=False, indent=2)


def update_stats(model_name, success=True, cached=False):
    """Atualiza estatísticas de uso dos modelos."""
    with stats_lock:
        stats = load_json(STATS_FILE)
        if model_name not in stats:
            stats[model_name] = {"success": 0, "fail": 0, "cached": 0}
        if cached:
            stats[model_name]["cached"] += 1
        elif success:
            stats[model_name]["success"] += 1
        else:
            stats[model_name]["fail"] += 1
        save_json(STATS_FILE, stats)


# Carregamento inicial
cache = load_json(CACHE_FILE)
finished_files = load_json(FINISHED_FILES_FILE)

api_key = os.environ.get("GEMINI_API_KEY")
if not api_key:
    try:
        with open('.env') as f:
            for line in f:
                if line.startswith('GEMINI_API_KEY='):
                    api_key = line.split('=', 1)[1].strip().strip('"\'')
    except Exception:
        pass
client = genai.Client(api_key=api_key)


def detect_npc_type(label_name: str, original_text: str) -> str:
    """
    Tenta inferir o tipo de NPC a partir do nome do label e do texto original.
    Retorna uma dica de contexto para a IA.
    """
    label_lower = label_name.lower()
    text_lower = original_text.lower()

    npc_hints = {
        "doctor|nurse|heal|joy|nurse_joy|pokemon_center": "Médico(a) ou Atendente do Centro Pokémon",
        "fisher|fish|rod|angler": "Pescador(a) — fala de pesca e Pokémon aquáticos",
        "scientist|researcher|prof|professor|birch|lab": "Cientista ou Professor — linguagem técnica e formal",
        "child|kid|boy|girl|youngster|lass": "Criança — animada, fala empolgada sobre Pokémon",
        "old|elder|granny|grandpa|grandma|senior": "Idoso(a) — sábio, nostálgico, usa expressões antigas",
        "rival|aqua|magma|grunt|admin|boss|leader": "Membro de time vilão ou rival — confiante, levemente ameaçador",
        "gym|leader|badge|arena": "Líder de Ginásio — desafiador, especialista em um tipo",
        "shop|mart|merchant|store|sell|buy": "Comerciante — amigável, focado em produtos",
        "guide|tourist|traveler|hiker": "Viajante ou Guia — aventureiro, fala de locais e rotas",
        "guard|police|officer|ranger": "Guarda ou Policial — sério e direto",
        "trainer|battler|fight": "Treinador Pokémon — competitivo, entusiasmado com batalhas",
    }

    for keywords, description in npc_hints.items():
        if any(k in label_lower or k in text_lower for k in keywords.split("|")):
            return description

    return "Morador(a) comum da cidade ou rota — tom casual e amigável"


def get_recent_birthday_phrases_context() -> str:
    """Retorna as últimas parabenizações usadas para evitar repetição."""
    with birthday_phrases_lock:
        if not used_birthday_phrases:
            return "Nenhuma parabenização foi usada ainda — seja criativo!"
        recent = used_birthday_phrases[-8:]  # Mostra os últimos 8 exemplos
        formatted = "\n".join(f"  - \"{p}\"" for p in recent)
        return f"Parabenizações JÁ USADAS (NÃO repita estas nem frases parecidas):\n{formatted}"


def register_birthday_phrase(phrase: str):
    """Registra uma parabenização usada."""
    with birthday_phrases_lock:
        # Extrai apenas a parte do aniversário (heurística simples)
        for keyword in ["parabéns", "aniversário", "anos", "feliz", "lucas"]:
            idx = phrase.lower().find(keyword)
            if idx != -1:
                start = max(0, idx - 20)
                snippet = phrase[start:idx + 60].strip()
                used_birthday_phrases.append(snippet)
                break


def build_translation_prompt(original_text: str, label_name: str) -> str:
    """
    Constrói um prompt rico e detalhado para a tradução, com todo o contexto necessário.
    """
    npc_type = detect_npc_type(label_name, original_text)
    birthday_context = get_recent_birthday_phrases_context()

    prompt = f"""Você é um escritor e localizador experiente do jogo Pokémon Emerald para PT-BR.

════════════════════════════════════════
CONTEXTO DO UNIVERSO
════════════════════════════════════════
{POKEMON_UNIVERSE_CONTEXT}

════════════════════════════════════════
GUIA DE ESTILO
════════════════════════════════════════
{TRANSLATION_STYLE_GUIDE}

════════════════════════════════════════
GUIA DO ANIVERSÁRIO
════════════════════════════════════════
{BIRTHDAY_CREATIVE_GUIDE}

════════════════════════════════════════
CONTEXTO DO SCRIPT PYTHON
════════════════════════════════════════
{CODE_INTERACTION_CONTEXT}

════════════════════════════════════════
CONTEXTO ESPECÍFICO DESTA FALA
════════════════════════════════════════
- Nome do label/NPC: {label_name}
- Tipo provável de NPC: {npc_type}
- {birthday_context}

════════════════════════════════════════
TEXTO ORIGINAL (em inglês)
════════════════════════════════════════
"{original_text}"

════════════════════════════════════════
REGRAS ABSOLUTAS DE SAÍDA
════════════════════════════════════════
1. Mantenha 100% do CONTEÚDO e FUNÇÃO original (dicas, itens, direções, mecânicas de jogo).
2. Adapte o TOM ao tipo de NPC identificado acima.
3. Integre a parabenização do aniversário do LUCAS de forma NATURAL e CRIATIVA.
4. A parabenização deve ser ÚNICA — não repita frases já listadas acima.
5. Retorne APENAS o texto traduzido em uma única linha, sem aspas, sem explicações.
6. Máximo de ~280 caracteres no total (limite da caixa de texto do GBA).
7. Não use markdown, emojis, ou formatação especial.
8. Nomes de Pokémon permanecem em inglês.

Texto traduzido:"""

    return prompt


def get_ai_translation(original_text: str, filepath: str, label_name: str) -> str:
    """
    Busca a tradução no cache ou solicita à IA com prompt enriquecido.
    """
    with cache_lock:
        if original_text in cache:
            update_stats("cache", cached=True)
            return cache[original_text]

    prompt = build_translation_prompt(original_text, label_name)

    while True:
        quota_hit = 0
        for model_name in AI_MODELS:
            with model_lock:
                if model_name in invalid_models:
                    continue

            try:
                print(f"    [AI] {model_name} → {label_name}...", flush=True)
                response = client.models.generate_content(model=model_name, contents=prompt)
                translated = response.text.strip().replace('"', '').replace('\n', ' ')

                # Valida que a tradução não está vazia ou muito curta
                if len(translated) < 5:
                    raise ValueError("Resposta da IA muito curta ou inválida.")

                # Registra a parte do aniversário para evitar repetições
                register_birthday_phrase(translated)

                with cache_lock:
                    cache[original_text] = translated

                update_stats(model_name, success=True)
                return translated

            except Exception as e:
                err = str(e).lower()
                if "429" in err or "resource_exhausted" in err:
                    quota_hit += 1
                    update_stats(model_name, success=False)
                    continue
                elif "404" in err or "not found" in err or "not supported" in err:
                    with model_lock:
                        invalid_models.add(model_name)
                    update_stats(model_name, success=False)
                    continue
                else:
                    print(f"    [WARN] Erro inesperado em {model_name}: {e}", flush=True)
                    update_stats(model_name, success=False)
                    time.sleep(2)

        print("    [!!!] Todos os modelos esgotaram a cota. Aguardando 60s antes de tentar novamente...", flush=True)
        time.sleep(60)


def should_skip_translation(raw_combined: str) -> bool:
    """
    Verifica se o texto já está traduzido e possui a parabenização do aniversário.
    Evita reprocessar textos que já estão corretos.
    """
    has_lucas = "Lucas" in raw_combined
    has_birthday = any(kw in raw_combined.lower() for kw in ["aniversário", "parabéns", "feliz aniversário"])
    is_already_portuguese = any(kw in raw_combined.lower() for kw in [
        " de ", " do ", " da ", " que ", " em ", " para ", " com ", " não ", " sim ", " você "
    ])
    return has_lucas and has_birthday and is_already_portuguese


def process_file_with_ai(filepath: str):
    """
    Processa um arquivo de mapa, traduzindo todas as falas de NPCs encontradas.
    """
    filepath = filepath.strip()
    if not filepath:
        return

    with file_lock:
        if filepath in finished_files:
            return

    map_name = os.path.basename(os.path.dirname(filepath))
    print(f"\n[MAPA] Processando: {map_name} ({filepath})", flush=True)

    try:
        with open(filepath, 'r', encoding='utf-8') as f:
            lines = f.readlines()
    except Exception as e:
        print(f"[ERRO] Falha ao ler {filepath}: {e}")
        return

    new_lines = []
    i = 0
    alteracoes = 0
    ignorados = 0

    while i < len(lines):
        line = lines[i]
        label_match = (
            re.match(r'^([A-Za-z0-9_]+)::', line) or
            re.match(r'^([A-Za-z0-9_]+):$', line.strip())
        )
        new_lines.append(line)
        i += 1

        if label_match:
            label_name = label_match.group(1)
            raw_text_parts = []
            j = i

            # Coleta todas as linhas .string do bloco
            while j < len(lines):
                if not lines[j].strip():
                    j += 1
                    continue
                string_match = re.search(r'^\s*\.string\s+"(.*)"', lines[j])
                if string_match:
                    raw_text_parts.append(string_match.group(1))
                    j += 1
                else:
                    break

            if raw_text_parts:
                raw_combined = (
                    "".join(raw_text_parts)
                    .replace('$', '')
                    .replace('\\n', ' ')
                    .replace('\\l', ' ')
                    .replace('\\p', ' ')
                    .strip()
                )

                # Verifica se já foi traduzido corretamente
                if should_skip_translation(raw_combined):
                    print(f"  [SKIP] {label_name} já traduzido e com aniversário.", flush=True)
                    for p in raw_text_parts:
                        new_lines.append(f'    .string "{p}"\n')
                    ignorados += 1
                else:
                    print(f"  [TRAD] {label_name} em {map_name}", flush=True)
                    ai_text = get_ai_translation(raw_combined, filepath, label_name)

                    if ai_text:
                        simulated_text = simulate_and_format_text(ai_text)
                        if not simulated_text.endswith('$'):
                            simulated_text += '$'
                        new_lines.append(f'    .string "{simulated_text}"\n')
                        alteracoes += 1
                    else:
                        # Fallback: mantém o texto original. Note que não adicionamos a original antes no new_lines,
                        # então o append aqui é seguro e não causa duplicação.
                        for p in raw_text_parts:
                            new_lines.append(f'    .string "{p}"\n')

                i = j

    # Salva o arquivo modificado
    with open(filepath, 'w', encoding='utf-8') as f:
        f.writelines(new_lines)

    # Atualiza arquivos de controle
    with file_lock:
        finished_files.append(filepath)
        save_json(FINISHED_FILES_FILE, finished_files)
        save_json(CACHE_FILE, cache)

    print(
        f"[OK] {map_name} concluído — "
        f"{alteracoes} traduzidos, {ignorados} ignorados.",
        flush=True
    )


def print_summary():
    """Exibe um resumo das estatísticas de tradução ao final."""
    stats = load_json(STATS_FILE)
    if not stats:
        return

    print("\n════════════════════════════════════════")
    print("RESUMO DE USO DOS MODELOS")
    print("════════════════════════════════════════")
    for model, data in sorted(stats.items(), key=lambda x: -x[1].get("success", 0)):
        total = data.get("success", 0) + data.get("fail", 0)
        cached = data.get("cached", 0)
        if total > 0 or cached > 0:
            print(f"  {model:<35} ✓ {data.get('success',0):>4}  ✗ {data.get('fail',0):>4}  cache: {cached:>4}")
    print("════════════════════════════════════════\n")


def main():
    map_list = "todos_os_mapas.txt"
    if not os.path.exists(map_list):
        print("[ERRO] Arquivo todos_os_mapas.txt não encontrado.")
        return

    with open(map_list, 'r', encoding='utf-8') as f:
        files_to_process = [l.strip() for l in f.readlines() if l.strip()]

    pending = [f for f in files_to_process if f not in finished_files]

    print("════════════════════════════════════════")
    print("  TRADUÇÃO POKÉMON EMERALD — PT-BR")
    print("════════════════════════════════════════")
    print(f"  Total de mapas:    {len(files_to_process)}")
    print(f"  Já concluídos:     {len(finished_files)}")
    print(f"  A processar:       {len(pending)}")
    print(f"  Cache atual:       {len(cache)} entradas")
    print("════════════════════════════════════════\n")

    if not pending:
        print("Todos os mapas já foram traduzidos!")
        print_summary()
        return

    # Mantendo 5 workers como solicitado, mas a lógica de retry agora espera 60s
    with concurrent.futures.ThreadPoolExecutor(max_workers=5) as executor:
        executor.map(process_file_with_ai, pending)

    print("\n════════════════════════════════════════")
    print("  TRADUÇÃO FINALIZADA COM SUCESSO!")
    print("════════════════════════════════════════")
    print_summary()


if __name__ == "__main__":
    main()