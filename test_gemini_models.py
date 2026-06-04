import os
import sys
import time

try:
    from google import genai
    from google.genai import types
except ImportError:
    print("Erro: A biblioteca google-genai não está instalada.")
    sys.exit(1)

def discover_and_test_models():
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
        print("Erro: A variável de ambiente GEMINI_API_KEY não foi encontrada.")
        sys.exit(1)

    print("Iniciando descoberta de modelos do Gemini...")
    client = genai.Client(api_key=api_key)
    
    available_models = []
    
    try:
        # Busca todos os modelos disponíveis na API
        model_list = client.models.list()
        for model in model_list:
            name = model.name.lower()
            if "vision" not in name and "bison" not in name and "aqa" not in name and "embed" not in name and "voice" not in name:
                available_models.append(model.name)
    except Exception as e:
        print(f"Erro ao listar modelos: {e}")
        sys.exit(1)

    print(f"\nForam encontrados {len(available_models)} modelos candidatos para geração de texto.")
    print("Testando cada modelo com um prompt simples ('Olá!')...\n")

    working_models = []
    failed_models = []

    for model_name in available_models:
        print(f"Testando: {model_name}...", end=" ", flush=True)
        try:
            # Teste rápido
            response = client.models.generate_content(
                model=model_name,
                contents="Olá! Responda apenas com a palavra 'OK'."
            )
            if response.text:
                print("✅ FUNCIONOU")
                working_models.append(model_name)
            else:
                print("❌ SEM RESPOSTA")
                failed_models.append(f"{model_name} (Retorno vazio)")
        except Exception as e:
            err_msg = str(e).lower()
            if "429" in err_msg or "resource_exhausted" in err_msg:
                print("⚠️ COTA EXCEDIDA (Mas o modelo existe e é válido)")
                working_models.append(model_name) # Se bateu na cota, é porque o modelo aceita a requisição
            else:
                print(f"❌ FALHOU ({e})")
                failed_models.append(f"{model_name} ({e})")
        
        # Pausa para evitar rate limit massivo
        time.sleep(1)

    print("\n" + "="*50)
    print(" RESULTADO FINAL: MODELOS LLM DISPONÍVEIS E FUNCIONAIS ")
    print("="*50)
    for w_model in working_models:
        print(f" - {w_model}")
        
    if failed_models:
        print("\nModelos com falha ou incompatíveis:")
        for f_model in failed_models:
            print(f" - {f_model}")

if __name__ == "__main__":
    discover_and_test_models()