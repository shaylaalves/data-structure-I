#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct
{
  int numeros[MAX];
  int topo;
} Pilha;

Pilha *criarPilha()
{
  Pilha *pilha = (Pilha *)malloc(sizeof(Pilha));
  pilha->topo = -1;
  return pilha;
}

void empilha(Pilha *pilha, int elemento)
{
  if (pilha->topo < MAX - 1)
  {
    pilha->numeros[++(pilha->topo)] = elemento;
  }
  else
  {
    printf("Pilha cheia!\n");
  }
}

void convertdecimalbinario(Pilha *pilha, int numero)
{
  if (numero == 0)
  {
    empilha(pilha, 0);
    return;
  }

  while (numero > 0)
  {
    empilha(pilha, numero % 2);
    numero = numero / 2;
  }
}

void imprimirBinario(Pilha *pilha)
{
  printf("Número em binário: ");
  while (pilha->topo != -1)
  {
    printf("%d", pilha->numeros[pilha->topo--]);
  }
  printf("\n");
}

int main()
{
  Pilha *pilha = criarPilha();

  int numero;
  printf("Digite um número decimal: ");
  scanf("%d", &numero);

  convertdecimalbinario(pilha, numero);
  imprimirBinario(pilha);

  free(pilha);
  return 0;
}
