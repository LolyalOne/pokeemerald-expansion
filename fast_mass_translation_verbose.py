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
CONTEXTO DO UNIVERSO POKÉMON EMERALD (HOENN):

[REGIÃO E GEOGRAFIA]
- Hoenn é um arquipélago tropical com praias, florestas densas, vulcões, cavernas submarinas e montanhas nevadas
- O clima é quente e úmido — ideal para Pokémon de água, fogo e plantas
- Cidades principais e seus temas:
    • Cidade de Pétala (Petalburg City) — cidade calma à beira de um lago, lar do Ginásio de Normal
    • Ruivópolis (Rustboro City) — centro industrial e científico, Ginásio de Pedra da Roxanne
    • Dewford Town — ilha de surf e cavernas, Ginásio de Luta do Brawly
    • Slateport City — porto movimentado, mercado, Museu Marítimo
    • Mauville City — centro de Hoenn, cheio de energia, Ginásio Elétrico do Wattson
    • Verdanturf Town (Cidade Vera) — vilarejo pacífico perto do Túnel Rusturf, famoso pelo ar puro
    • Fallarbor Town — cidade na base de um vulcão, especialistas em Concursos
    • Lavaridge Town — resort termal com fontes de água quente, Ginásio de Fogo da Flannery
    • Fortree City — cidade nas copas das árvores, Ginásio de Voador da Winona
    • Lilycove City — cidade cosmopolita, museu de arte, QG do Team Aqua
    • Mossdeep City — ilha remota, base espacial, Ginásio Psíquico dos gêmeos Tate & Liza
    • Sootopolis City — cidade dentro de uma cratera vulcânica inundada, Ginásio de Água da Wallace
    • Ever Grande City — sede da Liga Pokémon de Hoenn
    • Pacifidlog Town — vilarejo flutuante sobre troncos de Corsola
- Rotas notáveis: Rota 110 (ciclovia elevada), Rota 119 (selva com chuva constante), Mt. Chimney (vulcão ativo)

[PERSONAGENS E ORGANIZAÇÕES]
- Professor Birch: professor Pokémon de Hoenn, estuda Pokémon em ambientes selvagens, é descontraído e aventureiro
- May/Brendan: rival do protagonista, filho(a) do Prof. Birch — amigável e empolgado(a)
- Steven Stone: Campeão de Hoenn, colecionador de pedras raras, muito elegante e misterioso
- Wallace: Líder de Ginásio de Água e ex-Campeão, artístico e refinado
- Team Magma (Maxie): quer expandir as terras secas, desperta Groudon
- Team Aqua (Archie): quer expandir os oceanos, desperta Kyogre
- Elite 4: Sidney (Sombrio), Phoebe (Fantasma), Glacia (Gelo), Drake (Dragão)

[POKÉMON NOTÁVEIS DA REGIÃO]
- Iniciais: Treecko (Planta), Torchic (Fogo), Mudkip (Água)
- Lendários centrais: Groudon (Terra), Kyogre (Água), Rayquaza (Dragão/Voador — mora na Sky Pillar)
- Pokémon típicos de Hoenn: Zigzagoon, Wurmple, Ralts, Aron, Feebas, Absol, Bagon, Beldum
- Pokémon aquáticos abundantes: Tentacool, Wingull, Wailmer, Sharpedo, Relicanth
- Pokémon únicos: Kecleon (invisível nas rotas), Lileep e Anorith (fósseis), Jirachi (lendário evento)

[ITENS E MECÂNICAS]
- Itens que NÃO devem ser traduzidos: TM, HM, EV, IV, HP, PP, EXP
- Itens que PODEM ser traduzidos: Potion → Poção, Pokéball → Pokébola, Rare Candy → Bala Rara
- HMs importantes: HM01 Corte, HM03 Surf, HM04 Força, HM05 Lampejo, HM06 Mergulho
- Insígnias de Ginásio: Stone Badge, Knuckle Badge, Dynamo Badge, Heat Badge, Balance Badge, Feather Badge, Mind Badge, Rain Badge
- Concursos Pokémon: competições de beleza, dureza, simpatia, inteligência e tenacidade — muito populares em Hoenn
- Bagas (Berries): plantas coletáveis que servem para curar, criar comidas, modificar Pokémon

[TOM GERAL]
- Aventureiro, caloroso, com senso de maravilha e descoberta
- O mundo é seguro mas cheio de segredos — grutas escondidas, ilhas misteriosas, Pokémon raros
- A amizade entre humanos e Pokémon é o tema central
- Humor leve é bem-vindo, mas nunca sarcástico ou pesado demais
"""

TRANSLATION_STYLE_GUIDE = """
GUIA DE ESTILO PARA LOCALIZAÇÃO PT-BR (Pokémon Emerald):

[PRINCÍPIOS GERAIS]
- Use linguagem acessível, calorosa e adequada para todas as idades (7–35 anos)
- O PT-BR brasileiro é o alvo — use "você", não "tu"; "legal" não "fixe"; "ônibus" não "autocarro"
- Prefira frases curtas e diretas — a caixa de texto do GBA é pequena
- Mantenha o espírito de aventura e descoberta que caracteriza a franquia

[PERSONALIDADES POR TIPO DE NPC]
Cada NPC tem voz própria. Adapte ATIVAMENTE o vocabulário, ritmo e expressões:

• CRIANÇA (Youngster, Lass, Bug Catcher):
  - Tom: super animada, fala rápida, usa gírias de criança
  - Expressões: "Que demais!", "Não acredito!", "Meu Pokémon é o mais forte!"
  - Evite palavras difíceis; frases curtas e exclamativas

• IDOSO/SÁBIO (Elder, Gentleman, Aroma Lady):
  - Tom: calmo, reflexivo, usa provérbios e memórias do passado
  - Expressões: "No meu tempo...", "A experiência ensina que...", "Aprendi com os anos..."
  - Ritmo mais lento, frases mais elaboradas

• CIENTISTA/PESQUISADOR (Scientist, Researcher, Professor):
  - Tom: formal, entusiasmado com dados e descobertas
  - Expressões: "Fascinante!", "Meus estudos revelam que...", "Segundo minhas pesquisas..."
  - Pode usar termos técnicos moderados (type, habitat, evolução)

• PESCADOR (Fisher, Angler, Sailor):
  - Tom: descontraído, prático, tem orgulho da vida no mar
  - Expressões: "Meu velho!", "Vai pescar?", "Água boa hoje pra Pokémon aquáticos!"
  - Gírias náuticas leves, fala de pesca, rios, praias

• TREINADOR POKÉMON GENÉRICO (Trainer, Camper, Picnicker):
  - Tom: competitivo mas amigável, sempre pronto pra batalha
  - Expressões: "Bora batalhar!", "Meu time tá afiado!", "Não vou perder!"
  - Foca em batalhas, estratégias e vitórias

• RIVAL / VILÃO (Team Magma/Aqua Grunt, Admin, Boss):
  - Tom: confiante, ameaçador mas sem ser excessivamente agressivo
  - Grunts: obedientes, fanáticos pela causa
  - Admins: intimidadores, inteligentes
  - Bosses (Maxie/Archie): grandiosos, convictos de sua ideologia

• LÍDER DE GINÁSIO (Gym Leader):
  - Tom: desafiador, especialista em seu tipo, orgulhoso mas justo
  - Cada líder tem personalidade própria — respeite a original

• MÉDICO / ATENDENTE DE CENTRO POKÉMON (Nurse Joy):
  - Tom: gentil, sereno, muito preocupado com o bem-estar dos Pokémon
  - Expressões: "Seus Pokémon estão ótimos!", "Cuide bem deles!", "Descanse bastante!"

• COMERCIANTE / VENDEDOR (Mart Clerk, Shop Owner):
  - Tom: amigável, prestativo, levemente formal
  - Sempre focado em ajudar o cliente, menciona produtos e preços quando relevante

• GUARDA / POLICIAL (Guard, Officer Jenny):
  - Tom: sério, direto, focado em segurança e regras
  - Frases curtas e objetivas; não perde tempo com formalidades desnecessárias

• SURFISTA / ENTUSIASTA DE ÁGUA (Swimmer, Surfer):
  - Tom: descontraído, californiano, adora a natureza aquática
  - Expressões: "Cara, o mar tá perfeito!", "Adoro surfar com meu Pokémon!"

• MORADOR COMUM (Pokémon Fan, Hiker, Beauty):
  - Tom: casual, amigável, fala sobre o cotidiano e observações sobre Hoenn

[REGRAS DE LOCALIZAÇÃO]
NUNCA traduza:
  - Nomes de Pokémon: Pikachu, Mudkip, Rayquaza, Tentacool, etc.
  - Siglas técnicas: TM, HM, HP, PP, EV, IV, EXP
  - Nomes de personagens: Steven, Wallace, May, Birch, Archie, Maxie
  - Nomes de lugares que o jogo mantém em inglês: Mauville, Lilycove, Dewford

PODE e DEVE traduzir:
  - Nomes de cidades com tradução canônica PT-BR: Rustboro → Ruivópolis, Petalburg → Cidade de Pétala
  - Itens genéricos: Potion → Poção, Pokéball → Pokébola, Berry → Baga, Rare Candy → Bala Rara
  - Termos de jogo: Gym Badge → Insígnia, Gym Leader → Líder de Ginásio, Trainer → Treinador
  - Títulos e profissões: Professor → Professor, Nurse → Enfermeira/Médica

[PADRÕES PROIBIDOS]
- NÃO use linguagem formal demais (parece robótica)
- NÃO use gírias muito datadas ou regionais demais
- NÃO tradução literal palavra por palavra — adapte o SENTIDO
- NÃO use emojis, asteriscos, markdown ou qualquer formatação especial
- NÃO inicie o texto com "Olá," ou "Ei," de forma repetitiva — varie os inícios
"""

BIRTHDAY_CREATIVE_GUIDE = """
GUIA CRIATIVO — ANIVERSÁRIO DO LUCAS:

[CONTEXTO]
- O protagonista se chama LUCAS e hoje é seu ANIVERSÁRIO
- O NPC sabe disso de alguma forma — seja por rumor, por um Pokémon, pelo clima, por intuição, etc.
- A celebração deve parecer ESPONTÂNEA e AUTÊNTICA, não forçada

[REGRA PRINCIPAL]
A parabenização deve ser integrada DENTRO da fala, não simplesmente colada no início ou final.
O conteúdo FUNCIONAL original (dicas, direções, informações de jogo) deve estar presente E COMPLETO.
A menção ao aniversário é a cereja do bolo — enriquece, não substitui.

[TÉCNICAS DE INTEGRAÇÃO CRIATIVA]
Use uma destas abordagens para variar:

1. GANCHO EMOCIONAL — o NPC conecta o aniversário ao tema da sua fala:
   Ex (Pescador): "Hoje a maré tá a seu favor, Lucas — afinal, aniversariante merece sorte boa!"
   Ex (Médico): "Deixa eu verificar... tudo certo! Pokémon saudáveis, igual ao aniversariante deles!"

2. TERCEIROS INFORMAM — outro personagem ou Pokémon "avisou" sobre o aniversário:
   Ex: "Meu Zigzagoon ficou agitado hoje — acho que farejou que tem aniversariante na área!"
   Ex: "A Nurse Joy daqui me contou que você tá fazendo aniversário hoje!"

3. SINAL DO AMBIENTE — algo no mundo de Hoenn "celebra" junto:
   Ex: "Veja que dia lindo em Hoenn! Parece que até a natureza tá comemorando seu aniversário, Lucas!"
   Ex: "O Mt. Chimney soltou um clarão hoje — deve ser pra iluminar o caminho do aniversariante!"

4. MEMÓRIA OU TRADIÇÃO — o NPC conecta ao passado ou a um costume local:
   Ex: "Cá entre nós, antigamente em Hoenn se dava uma Baga pro aniversariante como boa sorte..."
   Ex: "Você me lembra de quando eu tinha sua idade e fazia aniversário por estas rotas..."

5. HUMOR LEVE — brincadeira gentil relacionada ao aniversário:
   Ex: "Aniversário em Hoenn é coisa séria, hein! Até os Wingull parecem mais animados hoje!"
   Ex: "Um conselho de presente: nunca lute contra Pokémon mais forte sem Poções... especialmente hoje!"

6. SURPRESA / DESCOBERTA — o NPC reage como se tivesse acabado de descobrir:
   Ex: "Espera — hoje é seu aniversário?! Por que não me avisou antes, Lucas?! Parabéns!"
   Ex: "Meu Pokémon farejou algo especial em você... Aniversário, né? Parabéns, treinador!"

[EXEMPLOS POR TIPO DE NPC]
• Médico/Enfermeira: "Seus Pokémon estão com saúde perfeita — igual a você no seu aniversário, Lucas!"
• Pescador: "Hoje o peixe tá mordendo demais... sorte de aniversariante deve estar sobrando em Hoenn!"
• Cientista: "Fascinante! Segundo meus dados, hoje é o aniversário de Lucas. Parabéns, jovem pesquisador!"
• Criança: "LUCAS! Hoje é seu aniversário?! DEMAIS!! Você é o melhor treinador aniversariante de Hoenn!"
• Vovô: "Jovem Lucas... parabéns pelos anos vividos. Que cada batalha te ensine mais um pouco."
• Comerciante: "Hoje devia ter um desconto especial pra aniversariante... mas temos preço fixo, haha! Parabéns!"
• Guarda: "Documento, por favor... brincadeira. Ouvi que é seu aniversário. Parabéns, siga em frente!"
• Treinador: "Hoje você batalha com sorte dobrada — ouvi que é seu aniversário! Vai ser uma luta e tanto!"
• Surfista: "Cara, o mar tá perfeito hoje — sinal de boa energia pra um aniversariante como você!"
• Membro Team Aqua/Magma: "Normalmente não parabenizaria um inimigo... mas parabéns, Lucas. Aproveite enquanto pode!"

[REGRAS DE VARIAÇÃO ANTI-REPETIÇÃO]
- As últimas frases de aniversário usadas serão fornecidas abaixo — NÃO use fórmulas parecidas
- Observe o PADRÃO das frases anteriores e escolha uma TÉCNICA DIFERENTE (veja as 6 técnicas acima)
- Se as últimas foram com "gancho emocional", use "terceiros informam" ou "sinal do ambiente"
- Varie também a POSIÇÃO na frase: às vezes no início, às vezes no meio, às vezes no final
- Varie o GRAU DE SURPRESA: às vezes o NPC já sabia, às vezes acabou de descobrir

[LIMITES]
- Máximo de 1-2 frases extras para o aniversário — não sobrecarregue o diálogo
- Mantenha sempre o conteúdo funcional original íntegro e completo
- Nunca use "Feliz Aniversário, Lucas!" sozinho — é preguiçoso e genérico
"""

# CONTEXTO DE INTERAÇÃO DO CÓDIGO (Gerado para a IA ter consciência de seu papel)
CODE_INTERACTION_CONTEXT = """
CONTEXTO DO SEU AMBIENTE DE EXECUÇÃO:

[PAPEL DESTA CHAMADA]
- Você é um motor de localização assíncrono integrado a um pipeline de tradução de ROM hack de GBA
- Este prompt foi gerado por um script Python que processa arquivos .inc e .s do pokeemerald-expansion
- Sua resposta será gravada permanentemente em "translation_cache.json" e substituirá o texto original no código-fonte

[PIPELINE COMPLETO]
1. Script Python lê "todos_os_mapas.txt" e distribui arquivos entre até 5 threads paralelas
2. Cada thread encontra blocos `.string "..."` nos arquivos de mapa assembly
3. Para cada bloco, este prompt é gerado e enviado à API Gemini
4. Sua resposta (texto puro) é passada para o módulo `gba_text_simulator.py`
5. O simulador insere marcadores de quebra \\n, passagem de painel \\p e respeita o limite de 34 chars/linha
6. O resultado final substitui o bloco `.string` original no arquivo fonte

[LIMITES TÉCNICOS CRÍTICOS]
- Limite ABSOLUTO: ~280 caracteres (o `gba_text_simulator.py` cortará qualquer excesso)
- Quebras de linha e formatação GBA são inseridas DEPOIS pelo simulador — entregue APENAS texto puro
- Uma única linha de resposta — sem \\n, \\p, $, \\l no seu output
- Sem aspas ao redor do texto na resposta

[GESTÃO DE COTA E RETRY]
- Se a API retornar erro 429 (rate limit), o script aguarda 60 segundos e retenta com outro modelo
- Se retornar 404, o modelo é adicionado a uma lista negra e nunca mais chamado nesta execução
- Existe um pool de 16+ modelos Gemini sendo testados em sequência — sua resposta define qual modelo "vence" esta tarefa
- Respostas válidas são cacheadas; respostas inválidas (<5 chars) geram nova tentativa

[CACHE E IDEMPOTÊNCIA]
- Se o texto original em inglês já existir no cache, sua resposta atual NÃO será usada — retorna do JSON
- Cada resposta sua é, portanto, permanente para aquele texto original específico
- Isso significa: acerte na primeira vez, pois não há segunda chance para o mesmo texto
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
    Retorna uma dica de contexto rica para a IA usar na tradução.
    """
    label_lower = label_name.lower()
    text_lower = original_text.lower()

    # Ordem importa: mais específico primeiro
    npc_rules = [
        # Vilões e organizações
        (["aqua_grunt", "magma_grunt", "grunt"],
         "Membro de base do Team Aqua ou Magma — fanático, obediente, tom ameaçador mas genérico"),
        (["aqua_admin", "magma_admin", "admin"],
         "Administrador do Team Aqua ou Magma — intimidador, inteligente, estratégico"),
        (["archie", "maxie"],
         "Líder do Team Aqua/Magma — grandioso, apaixonado pela causa, fala em ideais maiores"),
        # Líderes de Ginásio e Elite
        (["gym_leader", "leader", "gymleader"],
         "Líder de Ginásio — desafiador, especialista, orgulhoso mas respeitoso"),
        (["elite", "champion", "steven", "wallace"],
         "Membro da Elite 4 ou Campeão — poderoso, elegante, fala com peso e autoridade"),
        # Profissionais de Pokémon
        (["nurse", "joy", "pokemon_center", "pokecenter", "heal"],
         "Enfermeira Joy do Centro Pokémon — serena, gentil, cuidadosa com saúde dos Pokémon"),
        (["doctor", "medic"],
         "Médico(a) — atencioso, usa terminologia de saúde adaptada ao mundo Pokémon"),
        (["scientist", "researcher", "lab", "professor", "prof", "birch"],
         "Cientista ou Professor — formal, técnico, entusiasmado com descobertas"),
        # Treinadores específicos
        (["fisher", "fish", "angler", "rod"],
         "Pescador(a) — descontraído, orgulhoso da vida no mar, fala de Pokémon aquáticos"),
        (["swimmer", "surfer", "diver"],
         "Surfista ou Mergulhador — descontraído, adora a água, gírias de praia"),
        (["hiker", "mountaineer", "climber"],
         "Alpinista — resistente, ama desafios físicos, fala de montanhas e cavernas"),
        (["youngster", "child", "kid", "bug_catcher", "lass", "camper"],
         "Criança ou Jovem Treinador — super animada, usa gírias de criança, fala em Pokémon com euforia"),
        (["old_man", "elder", "gentleman", "granny", "grandpa", "grandma", "senior", "old_lady"],
         "Idoso(a) Sábio(a) — reflexivo, nostálgico, usa provérbios e memórias do passado"),
        (["rival", "opponent"],
         "Rival — confiante, levemente arrogante, sempre desafiador mas com respeito"),
        (["shop", "mart", "store", "merchant", "clerk", "vendor"],
         "Comerciante ou Vendedor(a) — amigável, prestativo, focado em produtos e serviços"),
        (["guard", "police", "officer", "jenny", "ranger"],
         "Guarda ou Policial — sério, objetivo, frases curtas e diretas"),
        (["trainer", "battler", "beauty", "picnicker", "ruin_maniac", "expert"],
         "Treinador(a) Pokémon — competitivo, entusiasmado com batalhas e estratégias"),
        (["sailor", "captain", "pirate"],
         "Marinheiro ou Capitão — rude mas bem-humorado, fala do mar e viagens"),
        (["fan", "enthusiast", "collector"],
         "Fã ou Colecionador de Pokémon — apaixonado, fala de Pokémon favoritos e raridades"),
        (["tour", "guide", "traveler", "tourist"],
         "Guia ou Turista — aventureiro, conhece histórias e segredos de Hoenn"),
    ]

    for keywords, description in npc_rules:
        if any(k in label_lower or k in text_lower for k in keywords):
            return description

    # Detecção por conteúdo do texto quando label não ajuda
    text_clues = {
        ("surf", "swim", "dive", "ocean", "sea", "water"): "Personagem aquático — fala de água, praias e Pokémon aquáticos",
        ("fire", "lava", "volcano", "chimney"): "Personagem de fogo ou áreas vulcânicas — entusiasmado com calor e força",
        ("cave", "mine", "underground", "fossil"): "Explorador de cavernas ou minerador — fala de mistérios subterrâneos",
        ("contest", "beauty", "ribbon", "performance"): "Entusiasta de Concursos Pokémon — focado em elegância e performances",
        ("berry", "grow", "plant", "farm"): "Agricultor ou Especialista em Bagas — calmo, fala de natureza e cultivo",
        ("legend", "ancient", "ruin", "history"): "Estudioso de história ou ruínas — fascinado pelo passado de Hoenn",
    }

    for keywords, description in text_clues.items():
        if any(k in text_lower for k in keywords):
            return description

    return "Morador(a) comum de Hoenn — tom casual e amigável, fala sobre o cotidiano da região"


def get_recent_birthday_phrases_context() -> str:
    """
    Retorna as últimas parabenizações usadas para evitar repetição,
    e sugere ativamente uma técnica diferente das recentes.
    """
    TECHNIQUES = [
        "GANCHO EMOCIONAL — conecte o aniversário ao tema da fala do NPC",
        "TERCEIROS INFORMAM — um Pokémon ou outro NPC 'avisou' sobre o aniversário",
        "SINAL DO AMBIENTE — algo em Hoenn (clima, natureza, animais) celebra junto",
        "MEMÓRIA OU TRADIÇÃO — o NPC conecta a uma lembrança ou costume de Hoenn",
        "HUMOR LEVE — brincadeira gentil relacionada ao aniversário",
        "SURPRESA / DESCOBERTA — o NPC reage como se tivesse acabado de descobrir",
    ]

    with birthday_phrases_lock:
        if not used_birthday_phrases:
            return (
                "Nenhuma parabenização foi usada ainda — seja criativo!\n"
                f"Sugestão de técnica: {TECHNIQUES[0]}"
            )

        recent = used_birthday_phrases[-8:]
        formatted = "\n".join(f"  - \"{p}\"" for p in recent)

        # Sugere uma técnica baseada em rotação pelo número de frases usadas
        suggested_technique = TECHNIQUES[len(used_birthday_phrases) % len(TECHNIQUES)]

        return (
            f"Parabenizações JÁ USADAS (NÃO repita estas nem frases parecidas):\n{formatted}\n\n"
            f"⟶ Técnica sugerida para ESTA fala: {suggested_technique}"
        )


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


def build_translation_prompt(original_text: str, label_name: str, map_name: str = "") -> str:
    """
    Constrói um prompt rico e detalhado para a tradução, com todo o contexto necessário.
    """
    npc_type = detect_npc_type(label_name, original_text)
    birthday_context = get_recent_birthday_phrases_context()

    # Tenta extrair cidade/área do nome do mapa para dar mais contexto geográfico
    map_context = ""
    if map_name:
        map_lower = map_name.lower()
        location_hints = {
            "rustboro": "Ruivópolis — cidade industrial e científica",
            "petalburg": "Cidade de Pétala — cidade calma à beira de lago",
            "slateport": "Slateport City — porto movimentado",
            "mauville": "Mauville City — centro de Hoenn, cheio de energia",
            "verdanturf": "Cidade Vera — vilarejo pacífico com ar puro",
            "fallarbor": "Fallarbor Town — cidade perto de vulcão",
            "lavaridge": "Lavaridge Town — resort de fontes termais",
            "fortree": "Fortree City — cidade nas copas das árvores",
            "lilycove": "Lilycove City — cidade cosmopolita com museu de arte",
            "mossdeep": "Mossdeep City — ilha remota com base espacial",
            "sootopolis": "Sootopolis City — cidade dentro de cratera vulcânica",
            "dewford": "Dewford Town — ilha de surf e cavernas",
            "pacifidlog": "Pacifidlog Town — vilarejo flutuante sobre Corsola",
            "route": "Uma rota de Hoenn — natureza aberta, treinadores ao longo do caminho",
            "cave": "Interior de uma caverna de Hoenn",
            "sea": "No mar de Hoenn — ambiente aquático",
            "gym": "Ginásio Pokémon — arena de batalha",
            "pokemon_center": "Centro Pokémon — local de cura e descanso",
            "mart": "Poké Mart — loja de itens",
        }
        for key, desc in location_hints.items():
            if key in map_lower:
                map_context = f"- Localização do mapa: {desc}"
                break
        if not map_context and map_name:
            map_context = f"- Arquivo de mapa: {map_name}"

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
CONTEXTO DO PIPELINE TÉCNICO
════════════════════════════════════════
{CODE_INTERACTION_CONTEXT}

════════════════════════════════════════
CONTEXTO ESPECÍFICO DESTA FALA
════════════════════════════════════════
- Nome do label/NPC: {label_name}
- Tipo provável de NPC: {npc_type}
{map_context}
- {birthday_context}

════════════════════════════════════════
EXEMPLO DE ENTRADA E SAÍDA ESPERADA
════════════════════════════════════════
Entrada:  "The POKéMON in the grass here are weak. They're easy to catch."
Saída:    Ah, os Pokémon na grama aqui são fraquinhos, fáceis de capturar! Hoje é seu aniversário, Lucas? Que sorte a sua — dia de festa e de captura fácil!

Entrada:  "I heard TEAM MAGMA is causing trouble at the museum."
Saída:    Ouvi dizer que o Team Magma tá aprontando no museu... Cuidado por lá, Lucas. Ah, e parabéns pelo aniversário — que tal resolver isso como um presente pra Hoenn?

════════════════════════════════════════
TEXTO ORIGINAL (em inglês)
════════════════════════════════════════
"{original_text}"

════════════════════════════════════════
REGRAS ABSOLUTAS DE SAÍDA
════════════════════════════════════════
1. Mantenha 100% do CONTEÚDO e FUNÇÃO original (dicas, itens, direções, mecânicas de jogo).
2. Adapte o TOM ao tipo de NPC identificado acima — use vocabulário e ritmo condizentes.
3. Integre a parabenização do aniversário do LUCAS usando a técnica sugerida acima.
4. A parabenização deve ser ÚNICA — diferente de todas as listadas na seção de histórico.
5. Retorne APENAS o texto traduzido em uma única linha, sem aspas, sem explicações adicionais.
6. Máximo de ~280 caracteres no total (o simulador GBA cortará qualquer excesso).
7. Não use \\n, \\p, $, \\l, markdown, emojis ou qualquer formatação especial.
8. Nomes de Pokémon permanecem em inglês. Itens técnicos (TM, HM, HP) não são traduzidos.
9. Comece diretamente com o texto — sem "Texto traduzido:", sem prefixo algum.

"""

    return prompt


def get_ai_translation(original_text: str, filepath: str, label_name: str) -> str:
    """
    Busca a tradução no cache ou solicita à IA com prompt enriquecido.
    """
    with cache_lock:
        if original_text in cache:
            update_stats("cache", cached=True)
            return cache[original_text]

    map_name = os.path.basename(os.path.dirname(filepath))
    prompt = build_translation_prompt(original_text, label_name, map_name)

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