import sys
import re
import os
import time
import json

try:
    from google import genai
except ImportError:
    print("Erro: A biblioteca google-genai não está instalada.")
    print("Execute: pip install google-genai")
    sys.exit(1)

from gba_text_simulator import simulate_and_format_text

# Cache de Strings (poupando tokens)
CACHE_FILE = "translation_cache.json"
# Cache de Arquivos (poupando tempo de execução)
FINISHED_FILES_FILE = "finished_files.json"

# Lista exaustiva de modelos para o contexto de 2026
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

INVALID_MODELS = set()

def load_json(filepath):
    if os.path.exists(filepath):
        try:
            with open(filepath, 'r', encoding='utf-8') as f:
                return json.load(f)
        except:
            return {} if "cache" in filepath else []
    return {} if "cache" in filepath else []

def save_json(filepath, data):
    with open(filepath, 'w', encoding='utf-8') as f:
        json.dump(data, f, ensure_ascii=False, indent=2)

def get_ai_translation(original_text, file_context="NPC Genérico", cache=None):
    if cache and original_text in cache:
        return cache[original_text]

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
    
    prompt = f"""
Você é um escritor e tradutor do jogo Pokémon Emerald.
Sua missão é reescrever a seguinte fala de um NPC, traduzindo para o Português (PT-BR).

Regras Absolutas:
1. O protagonista do jogo se chama "Lucas". Hoje é o ANIVERSÁRIO dele!
2. Você deve adaptar a fala para parabenizá-lo ou mencionar o dia especial, MAS o NPC deve manter sua função.
3. Retorne apenas o texto cru em uma única linha.

Texto Original:
"{original_text}"
"""

    while True:
        quota_hit_any = False
        for model_name in AI_MODELS:
            if model_name in INVALID_MODELS:
                continue
            try:
                print(f"    [AI] Tentando: {model_name}...")
                response = client.models.generate_content(model=model_name, contents=prompt)
                time.sleep(4.5) 
                translated = response.text.strip().replace('"', '').replace('\n', ' ')
                if cache is not None:
                    cache[original_text] = translated
                    save_json(CACHE_FILE, cache)
                return translated
            except Exception as e:
                err = str(e).lower()
                if "429" in err or "resource_exhausted" in err:
                    print(f"    [!] Cota cheia para {model_name}.")
                    quota_hit_any = True
                    continue
                elif "404" in err or "not found" in err or "not supported" in err:
                    print(f"    [!] Modelo {model_name} inválido. Removendo.")
                    INVALID_MODELS.add(model_name)
                    continue
                else:
                    print(f"    [!] Erro ({model_name}): {e}")
                    time.sleep(5)
        if quota_hit_any:
            print("    [!!!] Todos os modelos em cota. Dormindo 60s...")
            time.sleep(60)
        else:
            return None

def process_file_with_ai(filepath):
    api_key = os.environ.get("GEMINI_API_KEY")
    if not api_key:
        try:
            with open('.env') as f:
                for line in f:
                    if line.startswith('GEMINI_API_KEY='):
                        api_key = line.split('=', 1)[1].strip().strip('"\'')
        except Exception:
            pass
    if not api_key:
        print("Erro: GEMINI_API_KEY não definida.")
        sys.exit(1)
    
    finished_files = load_json(FINISHED_FILES_FILE)
    if filepath in finished_files:
        print(f"[*] Ignorando: {filepath} (Já processado anteriormente)")
        return

    cache = load_json(CACHE_FILE)
    print(f"[*] Processando: {filepath}...")
    
    with open(filepath, 'r', encoding='utf-8') as f:
        lines = f.readlines()
        
    new_lines = []
    i = 0
    alteracoes = 0
    
    while i < len(lines):
        line = lines[i]
        label_match = re.match(r'^([A-Za-z0-9_]+)::', line) or re.match(r'^([A-Za-z0-9_]+):$', line.strip())
        new_lines.append(line)
        i += 1
        if label_match:
            label_name = label_match.group(1)
            raw_text_parts = []
            j = i
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
                raw_combined = "".join(raw_text_parts).replace('$', '').replace('\\n', ' ').replace('\\l', ' ').replace('\\p', ' ')
                if "Lucas" in raw_combined and ("aniversário" in raw_combined.lower() or "parabéns" in raw_combined.lower()):
                    for p in raw_text_parts: new_lines.append(f'    .string "{p}"\n')
                else:
                    print(f"  -> Traduzindo [{label_name}]...")
                    ai_text = get_ai_translation(raw_combined, cache=cache)
                    if ai_text:
                        simulated_text = simulate_and_format_text(ai_text)
                        if not simulated_text.endswith('$'): simulated_text += '$'
                        new_lines.append(f'    .string "{simulated_text}"\n')
                        alteracoes += 1
                    else:
                        for p in raw_text_parts: new_lines.append(f'    .string "{p}"\n')
                i = j
                
    with open(filepath, 'w', encoding='utf-8') as f:
        f.writelines(new_lines)
    
    # Marca como finalizado para nunca mais abrir este arquivo
    finished_files.append(filepath)
    save_json(FINISHED_FILES_FILE, finished_files)
    print(f"[+] Concluído! {alteracoes} diálogos injetados.")

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Uso: python3 ai_birthday_translator.py <arquivo.inc>")
    else:
        process_file_with_ai(sys.argv[1].replace('\\', '/'))
