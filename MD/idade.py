# Programa para verificar se um número é uma idade válida para um ser humano típico

# Conjunto de todas as idades possíveis para um ser humano (de 0 a 122 anos, idade da pessoa mais velha já registrada)
idades_possiveis = list(range(123))

# Função para verificar se um número é uma idade válida
def eh_idade_valida(idade):
    if idade in idades_possiveis:
        return True
    else:
        return False

# Solicitar uma idade ao usuário
idade_usuario = int(input("Digite uma idade: "))

# Verificar se a idade é válida e exibir o resultado
if eh_idade_valida(idade_usuario):
    print(f"{idade_usuario} é uma idade válida para um ser humano típico.")
else:
    print(f"{idade_usuario} não é uma idade válida para um ser humano típico.")
