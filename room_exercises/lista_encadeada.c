#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int info;
  struct Node *proximo;
} Node;

Node *criaNo(int valor)
{
  Node *novo_no = (Node *)malloc(sizeof(Node));
  if (novo_no == NULL)
  {
    printf("Erro ao alocar memória\n");
    exit(1);
  }
  novo_no->info = valor;
  novo_no->proximo = NULL;
  return novo_no;
}

void insereInicio(Node **cabeca, int valor)
{
  Node *novo_no = criaNo(valor);
  novo_no->proximo = *cabeca;
  *cabeca = novo_no;
}

void insereFinal(Node **cabeca, int valor)
{
  Node *novo_no = criaNo(valor);
  if (*cabeca == NULL)
  {
    *cabeca = novo_no;
    return;
  }
  Node *temp = *cabeca;
  while (temp->proximo != NULL)
  {
    temp = temp->proximo;
  }
  temp->proximo = novo_no;
}

void insereMeio(Node *anterior, int valor)
{
  if (anterior == NULL)
  {
    printf("O nó anterior não pode ser NULL\n");
    return;
  }
  Node *novo_no = criaNo(valor);
  novo_no->proximo = anterior->proximo;
  anterior->proximo = novo_no;
}

void imprimeLista(Node *no)
{
  while (no != NULL)
  {
    printf("%d -> ", no->info);
    no = no->proximo;
  }
  printf("NULL\n");
}

int main()
{
  Node *cabeca = NULL;

  insereInicio(&cabeca, 10);
  insereInicio(&cabeca, 20);
  insereInicio(&cabeca, 30);

  insereFinal(&cabeca, 40);
  insereFinal(&cabeca, 50);

  insereMeio(cabeca, 25);

  printf("Lista encadeada: ");
  imprimeLista(cabeca);

  return 0;
}
