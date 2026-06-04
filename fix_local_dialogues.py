import sys
import re
from gba_text_simulator import simulate_and_format_text

def clean_local_string(s):
    """Remove a formatação antiga para recalcular."""
    s = s.replace('$', '')
    s = s.replace('\\n', ' ')
    s = s.replace('\\l', ' ')
    s = s.replace('\\p', ' \\p ')
    return re.sub(' +', ' ', s).strip()

def fix_local_file(filepath):
    print(f"[*] Arrumando formatação de {filepath}...")
    
    with open(filepath, 'r', encoding='utf-8') as f:
        lines = f.readlines()
        
    new_lines = []
    i = 0
    fixed_count = 0
    
    while i < len(lines):
        line = lines[i]
        label_match = re.match(r'^([A-Za-z0-9_]+)::', line) or re.match(r'^([A-Za-z0-9_]+):$', line.strip())
        
        new_lines.append(line)
        i += 1
        
        if label_match:
            # Verifica as próximas linhas pra ver se tem .string
            raw_text_parts = []
            j = i
            
            while j < len(lines):
                # Se for apenas linha em branco, pula
                if not lines[j].strip():
                    j += 1
                    continue
                    
                string_match = re.search(r'^\s*\.string\s+"(.*)"', lines[j])
                if string_match:
                    raw_text_parts.append(string_match.group(1))
                    j += 1
                else:
                    break # Não é mais .string, quebra
            
            if raw_text_parts:
                # Significa que encontrou texto para arrumar!
                raw_combined = "".join(raw_text_parts)
                raw_clean = clean_local_string(raw_combined)
                
                caixas = raw_clean.split('\\p')
                formatted_ptbr = ""
                
                for idx, caixa in enumerate(caixas):
                    caixa = caixa.strip()
                    if not caixa:
                        continue
                        
                    simulated = simulate_and_format_text(caixa)
                    formatted_ptbr += simulated
                    
                    if idx < len(caixas) - 1:
                        formatted_ptbr += "\\p"
                
                if not formatted_ptbr.endswith('$'):
                    formatted_ptbr += '$'
                
                new_lines.append(f'    .string "{formatted_ptbr}"\n')
                fixed_count += 1
                
                # Avança o index principal i até onde processamos
                i = j
                
    with open(filepath, 'w', encoding='utf-8') as f:
        f.writelines(new_lines)
        
    print(f"[+] Sucesso! {fixed_count} falas foram recalculadas e formatadas perfeitamente para a tela do GBA.")

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Uso: python3 fix_local_dialogues.py <caminho_do_arquivo>")
    else:
        filepath = sys.argv[1].replace('\\', '/')
        fix_local_file(filepath)
