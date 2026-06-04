import re

# Tabela aproximada de largura da fonte normal do Pokémon Emerald (em pixels)
# Inclui os acentos do esmeralda-ptbr
CHAR_WIDTHS = {
    'A': 6, 'B': 6, 'C': 6, 'D': 6, 'E': 5, 'F': 5, 'G': 6, 'H': 6, 'I': 3, 'J': 5, 'K': 6, 'L': 5, 'M': 7, 'N': 6, 'O': 6, 'P': 6, 'Q': 6, 'R': 6, 'S': 6, 'T': 5, 'U': 6, 'V': 6, 'W': 7, 'X': 6, 'Y': 6, 'Z': 6,
    'a': 5, 'b': 5, 'c': 5, 'd': 5, 'e': 5, 'f': 4, 'g': 5, 'h': 5, 'i': 3, 'j': 3, 'k': 5, 'l': 3, 'm': 7, 'n': 5, 'o': 5, 'p': 5, 'q': 5, 'r': 4, 's': 5, 't': 4, 'u': 5, 'v': 5, 'w': 7, 'x': 5, 'y': 5, 'z': 5,
    '0': 6, '1': 4, '2': 6, '3': 6, '4': 6, '5': 6, '6': 6, '7': 6, '8': 6, '9': 6,
    ' ': 4, '.': 3, ',': 3, '!': 3, '?': 6, "'": 3, '"': 5, '-': 4, '/': 5, ':': 3, ';': 3, '(': 4, ')': 4,
    'Á': 6, 'É': 5, 'Í': 3, 'Ó': 6, 'Ú': 6, 'Ç': 6, 'Ã': 6, 'Õ': 6, 'Ä': 6, 'Ö': 6,
    'á': 5, 'é': 5, 'í': 3, 'ó': 5, 'ú': 5, 'ç': 5, 'ã': 5, 'õ': 5, 'ä': 5, 'ö': 5,
}

MAX_LINE_WIDTH = 202 # Pixels (aproximado da caixa de texto do GBA)
MAX_LINES = 2 # Máximo de linhas visíveis por vez na caixa padrão

def get_char_width(char):
    # Se o caractere não estiver na tabela, assume uma média de 5 pixels + 1 de espaçamento
    return CHAR_WIDTHS.get(char, 5) + 1 

def get_string_width(text):
    return sum(get_char_width(c) for c in text)

def simulate_and_format_text(raw_text):
    """
    Simula o texto sendo digitado na caixa do GBA.
    Quebra o texto em \\n, \\l e \\p conforme a necessidade.
    """
    words = raw_text.split(' ')
    formatted_text = ""
    
    current_line_width = 0
    current_lines = 1
    
    for i, word in enumerate(words):
        word_width = get_string_width(word)
        space_width = get_char_width(' ')
        
        # Se for a primeira palavra da linha
        if current_line_width == 0:
            formatted_text += word
            current_line_width += word_width
        # Se a palavra cabe na linha atual
        elif current_line_width + space_width + word_width <= MAX_LINE_WIDTH:
            formatted_text += " " + word
            current_line_width += space_width + word_width
        # Se a palavra NÃO cabe, precisamos quebrar a linha
        else:
            if current_lines == 1:
                formatted_text += "\\n" + word
                current_lines = 2
            else:
                # Já estamos na linha 2. A próxima linha requer scroll (\l)
                formatted_text += "\\l" + word
                
            current_line_width = word_width
            
    return formatted_text

def print_gba_mockup(formatted_string):
    """
    Imprime um "MOCKUP" visual no terminal simulando a tela do GBA.
    """
    # Regex para separar o texto pelos comandos \p, \n, \l
    # Primeiro dividimos por \p para pegar as caixas independentes
    boxes = formatted_string.split('\\p')
    
    print("\n" + "="*40)
    print(" 🎮 SIMULADOR DE CAIXA DE TEXTO GBA")
    print("="*40)
    
    for box_idx, box in enumerate(boxes):
        print(f"--- Tela {box_idx + 1} ---")
        
        # Lida com o scroll dentro da mesma caixa de diálogo
        # Transformamos \l em uma nova linha "virtual" simulando o scroll
        box = box.replace('\\l', '\n[SCROLL]-> ')
        box = box.replace('\\n', '\n')
        
        lines = box.split('\n')
        
        # Desenha a moldura da caixa
        print("+" + "-"*36 + "+")
        for line in lines:
            # Apenas visual para o terminal, trunca em 34 chars físicos
            visual_line = line.strip()
            print(f"| {visual_line:<34} |")
        print("+" + "-"*36 + "+")
        
        if box_idx < len(boxes) - 1:
            print("         (Pressione A para continuar)")
            print("")
    print("="*40 + "\n")

if __name__ == "__main__":
    import sys
    
    if len(sys.argv) > 1:
        test_string = sys.argv[1]
    else:
        test_string = "Olá! Eu sou o Professor Birch! Bem-vindo ao mundo fascinante de POKéMON! Esta é uma demonstração de como o sistema de simulação de caixa de texto garante que nenhuma palavra fique cortada na tela pequena do Game Boy Advance. Muito legal, não é mesmo?"
    
    # 1. Simula e formata (insere \n e \l onde precisa)
    formatted = simulate_and_format_text(test_string)
    
    # 2. Mostra o resultado final que vai pro arquivo
    print("Texto formatado para injeção (.inc):")
    print(f'"{formatted}\\p"')
    
    # 3. Imprime o Mockup visual
    print_gba_mockup(formatted)
