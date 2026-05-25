#!/bin/bash
# Um script para ajudar a converter PNGs pra o formato de paleta GBA
echo "Convertendo PNG para formato indexado (se necessário)..."
for file in "$@"; do
    if [ -f "$file" ]; then
        magick "$file" -colors 16 -type Palette "$file.tmp.png"
        mv "$file.tmp.png" "$file"
        echo "Processado $file"
    fi
done
