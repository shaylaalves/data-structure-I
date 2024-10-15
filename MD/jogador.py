# Programa para verificar se um jogador de futebol está entre os top cinco da atualidade.

top_cinco_jogadores = {"Lionel Messi", "Cristiano Ronaldo", "Robert Lewandowski", "Kylian Mbappe", "Neymar"}

jogador = input("Digite o nome do jogador: ")

if jogador in top_cinco_jogadores:
    print(f"{jogador} está entre os top cinco jogadores de futebol da atualidade.")
else:
    print(f"{jogador} não está entre os top cinco jogadores de futebol da atualidade.")
