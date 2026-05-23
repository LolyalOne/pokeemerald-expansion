import os
import re
import random

def main():
    maps_dir = 'data/maps'
    if not os.path.exists(maps_dir):
        print(f"Directory {maps_dir} not found!")
        return

    variations = [
        "Feliz aniversario, Lucas! Voce e um amigo incrivel.\\p",
        "Parabens, Lucas! Que sua jornada seja epica.\\p",
        "Hoje e o seu dia, Lucas! Aproveite a aventura.\\p"
    ]

    blacklist = [
        "sign", "desc", "item", "coin", "mart", "shop", "nurse", "heal",
        "battle", "defeat", "intro", "outro", "win", "lose", "won", "lost",
        "statue", "pc", "machine", "console", "system", "name", "player",
        "wait", "switch", "explain", "choose", "movement", "event"
    ]

    modified_files = 0
    total_injections = 0

    for root, dirs, files in os.walk(maps_dir):
        for file in files:
            if file == 'scripts.inc':
                filepath = os.path.join(root, file)
                
                with open(filepath, 'r', encoding='utf-8') as f:
                    lines = f.readlines()
                
                new_lines = []
                file_modified = False
                current_label = ""
                in_string_block = False

                for line in lines:
                    # Match a label definition e.g. SomeLabel_Text::
                    label_match = re.match(r'^([a-zA-Z0-9_]+):+:?$', line.strip())
                    if label_match:
                        current_label = label_match.group(1).lower()
                        in_string_block = False
                        new_lines.append(line)
                        continue
                    
                    # Match the start of a .string block
                    string_match = re.match(r'^(\s*\.string\s+")(.*)$', line)
                    if string_match:
                        if not in_string_block:
                            in_string_block = True
                            
                            # Check if we should inject based on label
                            is_valid = current_label and not any(b in current_label for b in blacklist)
                            
                            if is_valid:
                                prefix = string_match.group(1)
                                rest = string_match.group(2)
                                birthday_msg = random.choice(variations)
                                new_line = prefix + birthday_msg + rest + "\n"
                                new_lines.append(new_line)
                                file_modified = True
                                total_injections += 1
                                continue
                        
                    else:
                        if line.strip() != "":
                            in_string_block = False

                    new_lines.append(line)

                if file_modified:
                    with open(filepath, 'w', encoding='utf-8') as f:
                        f.writelines(new_lines)
                    modified_files += 1

    print(f"Modificacao concluida! Arquivos modificados: {modified_files}")
    print(f"Total de injecoes feitas: {total_injections}")

if __name__ == '__main__':
    main()