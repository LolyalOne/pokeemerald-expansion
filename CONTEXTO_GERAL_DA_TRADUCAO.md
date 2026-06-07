# Contexto Geral da Tradução do Projeto Pokémon Emerald Expansion

## Visão Geral
Este documento serve como um guia abrangente sobre como o sistema de tradução massiva automática está estruturado neste projeto. O objetivo principal do sistema é traduzir todo o texto dos NPCs de Pokémon Emerald do inglês para o Português do Brasil (PT-BR), inserindo de forma orgânica um cumprimento de feliz aniversário para o protagonista "Lucas".

## Arquitetura do Sistema
O processo de tradução é automatizado via scripts Python que leem os arquivos de dados do jogo (`.inc` e `.s`), interagem com a API da Google (Gemini) e reescrevem o código-fonte modificado para ser compilado no jogo de GBA.

### 1. Script Principal: `fast_mass_translation_verbose.py`
Este é o motor primário (e em tempo real) responsável por orquestrar toda a tradução.
*   **Paralelismo Seguro:** O script lê o arquivo `todos_os_mapas.txt` (que contém a lista de diretórios) e utiliza até 5 *workers* (`ThreadPoolExecutor`) simultaneamente para processar até 5 mapas ao mesmo tempo. Ele usa _locks_ (`threading.Lock`) para garantir que os caches em disco nunca sejam corrompidos.
*   **Gestão da API e Limites (Rate Limit):** A API gratuita do Gemini tem limite de requisições. O script testa dinamicamente um *pool* de mais de 10 modelos do Google (`gemini-2.5-flash`, `gemini-2.0-pro`, etc.). Quando um esgota a cota, ele salta para o próximo. Se todos esgotarem, o script "dorme" (`time.sleep(60)`) rigorosamente por 60 segundos antes de recomeçar as chamadas, evitando travamentos irreversíveis e mantendo a constância das requisições.
*   **Fallback Automático:** Caso algum modelo retorne erro '404 Not Found' repetidas vezes, o script o adiciona a uma `invalid_models` "lista negra", evitando desperdício de requisições em futuras iterações.

### 2. A Inteligência Artificial (Gemini)
A interação com a API ocorre de forma altamente contextualizada. Para cada fala encontrada nos scripts, o Python gera um *prompt* robusto contendo as seguintes diretrizes:
*   **Universo Pokémon:** Regras estritas dizendo que itens (TM, HM) não devem ser traduzidos e que o tom do universo deve ser amigável.
*   **Personalidade do NPC:** O script tenta adivinhar o tipo do NPC a partir do nome da *label* (ex: `LASS` = Criança Animada; `SCIENTIST` = Formal e Técnico).
*   **Sistema de Aniversário:** O LLM é instruído a celebrar o aniversário do Lucas com no máximo 1 ou 2 frases, e o script providencia um histórico circular em tempo real para a IA (o `used_birthday_phrases`), dizendo a ela quais foram as últimas 8 frases usadas para *impedir que ela se repita*.

### 3. Integração e Tratamento do Texto: `gba_text_simulator.py`
*   Após o LLM retornar a string PT-BR sem marcações, ela precisa ser recodificada para a sintaxe legível do Game Boy Advance.
*   A string bruta é repassada para o módulo simulador. Ele insere marcadores de quebra de linha `\n` e passagens de painel `\p` garantindo que os limites da *Text Box* do jogo (aproximadamente 34/35 caracteres por linha x 2 linhas) sejam respeitados perfeitamente.

## Segurança e Controle de Acesso (`.env`)
No passado, a chave da API (`GEMINI_API_KEY`) estava exposta no código-fonte, o que impedia *pushes* pro GitHub por questões de segurança (Push Protection).
*   **Solução Implementada:** O sistema foi alterado para carregar a chave de API de maneira segura através das variáveis de ambiente usando `os.environ.get("GEMINI_API_KEY")` ou lendo manualmente um arquivo local `.env` (que está contido no `.gitignore` e não sobe para a nuvem). 
*   Isso significa que, localmente, a tradução continua rodando sem interrupções e, online, o código pode ser armazenado abertamente no GitHub com segurança.

## Caches e Salvamento (`.json`)
Para não torrar cota da API à toa recriando traduções toda vez que o script é reiniciado, três arquivos json locais armazenam todo o progresso:
*   `translation_cache.json`: Dicionário completo. Se o inglês original for a chave `X`, a tradução retornada pela IA é gravada e recuperada da próxima vez sem tocar na rede.
*   `finished_files.json`: Lista de diretórios/mapas que já tiveram todos os seus diálogos lidos, processados e salvos. Se o arquivo estiver lá, a thread o pula imediatamente.
*   `translation_stats.json`: Conta quais modelos estão "trabalhando" mais, contabilizando `Success` e `Fails`, o que ajuda o desenvolvedor a diagnosticar qual LLM atende melhor.

### Como Continuar?
Para enviar as mudanças pro Git, você pode fazer isso normalmente. E para continuar a tradução, basta rodar o comando:
`cd pokeemerald-expansion && python3 ./fast_mass_translation_verbose.py`
E monitorar a saída em tempo real no arquivo:
`logs_traducao_tempo_real.txt`