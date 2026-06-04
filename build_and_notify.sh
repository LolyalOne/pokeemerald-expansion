#!/bin/bash
# Pokeemerald Build & Notify Script

echo "Iniciando compilação..." > build_status.log
make -j4 > build_output.log 2>&1
EXIT_CODE=$?

if [ $EXIT_CODE -eq 0 ]; then
    echo "Compilação concluída com sucesso!" >> build_status.log
    /mnt/c/WINDOWS/System32/WindowsPowerShell/v1.0/powershell.exe -WindowStyle Hidden -Command "(New-Object -ComObject WScript.Shell).Popup('A ROM do Pokeemerald foi gerada com sucesso!', 0, 'Build Concluída', 64)"
else
    echo "Erro na compilação. Código: $EXIT_CODE" >> build_status.log
    /mnt/c/WINDOWS/System32/WindowsPowerShell/v1.0/powershell.exe -WindowStyle Hidden -Command "(New-Object -ComObject WScript.Shell).Popup('Ocorreu um erro na compilação do Pokeemerald.', 0, 'Erro na Build', 16)"
fi
