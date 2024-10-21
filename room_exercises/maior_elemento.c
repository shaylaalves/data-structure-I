#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Elemento
{
  int valor;
  struct Elemento *proximo;
} Elemento;

typedef struct Pilha
{
  Elemento *topo;
} Pilha;

Pilha *criar_pilha()
{
  Pilha *pilha = (Pilha *)malloc(sizeof(Pilha));
  pilha->topo = NULL;
  return pilha;
}

void empilhar(Pilha *pilha, int valor)
{
  Elemento *novo_elem = (Elemento *)malloc(sizeof(Elemento));
  novo_elem->valor = valor;
  novo_elem->proximo = pilha->topo;
  pilha->topo = novo_elem;
}

int desempilhar(Pilha *pilha)
{
  if (pilha->topo == NULL)
  {
    fprintf(stderr, "Pilha vazia\n");
    exit(EXIT_FAILURE);
  }
  Elemento *temp = pilha->topo;
  int valor = temp->valor;
  pilha->topo = pilha->topo->proximo;
  free(temp);
  return valor;
}

int esta_vazia(Pilha *pilha)
{
  return pilha->topo == NULL;
}

int encontrar_maior(Pilha *pilha)
{
  if (esta_vazia(pilha))
  {
    fprintf(stderr, "Pilha vazia\n");
    exit(EXIT_FAILURE);
  }

  int maior = INT_MIN;
  Elemento *atual = pilha->topo;

  while (atual != NULL)
  {
    if (atual->valor > maior)
    {
      maior = atual->valor;
    }
    atual = atual->proximo;
  }

  return maior;
}

int main()
{
  Pilha *pilha = criar_pilha();

  empilhar(pilha, 10);
  empilhar(pilha, 20);
  empilhar(pilha, 5);
  empilhar(pilha, 15);

  int maior_elemento = encontrar_maior(pilha);
  printf("O maior elemento na pilha é: %d\n", maior_elemento);

  while (!esta_vazia(pilha))
  {
    desempilhar(pilha);
  }

  free(pilha);
  return 0;
}
