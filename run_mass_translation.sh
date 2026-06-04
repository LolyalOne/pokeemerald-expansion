#!/bin/bash

# Define a chave da API
export GEMINI_API_KEY="$(grep GEMINI_API_KEY .env | cut -d '=' -f2)"

# Encontra todos os scripts de mapa e os salva numa lista
find data/maps -name "scripts.inc" > todos_os_mapas.txt

total=$(wc -l < todos_os_mapas.txt)
atual=1

echo "=========================================================="
echo " INICIANDO TRADUÇÃO MASSIVA (LORE DO ANIVERSÁRIO DO LUCAS)"
echo " TOTAL DE MAPAS A PROCESSAR: $total"
echo "=========================================================="

# Lê linha por linha
while IFS= read -r arquivo; do
    echo "[$atual/$total] Traduzindo: $arquivo" | tee -a traducoes_log.txt
    
    # Roda o script de IA (que já tem um sleep embutido pra evitar rate limit)
    python3 ai_birthday_translator.py "$arquivo" >> traducoes_log.txt 2>&1
    
    # Pega o exit code pra ver se travou
    if [ $? -ne 0 ]; then
        echo "Erro fatal ou interrupção. Parando o processo em $arquivo." | tee -a traducoes_log.txt
        exit 1
    fi
    
    # Pausa mais um pouquinho pra não sobrecarregar o Gemini (Erro 503)
    sleep 3
    
    ((atual++))
done < todos_os_mapas.txt

echo "TRADUÇÃO COMPLETA!"
