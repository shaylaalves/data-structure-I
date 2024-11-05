#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct
{
  char itens[MAX];
  int topo;
} Pilha;

Pilha *criarPilha()
{
  Pilha *pilha = (Pilha *)malloc(sizeof(Pilha));
  pilha->topo = -1;
  return pilha;
}

int pilhaCheia(Pilha *pilha)
{
  return (pilha->topo == MAX - 1);
}

int pilhaVazia(Pilha *pilha)
{
  return (pilha->topo == -1);
}

void empilhar(Pilha *pilha, char caractere)
{
  if (pilhaCheia(pilha))
  {
    printf("Pilha cheia!\n");
    return;
  }

  pilha->itens[++(pilha->topo)] = caractere;
}

char desempilhar(Pilha *pilha)
{
  if (pilhaVazia(pilha))
  {
    printf("Pilha vazia!\n");
    return '\0';
  }

  return pilha->itens[(pilha->topo)--];
}

void inverterString(char *str)
{
  int tamanho = strlen(str);
  Pilha *pilha = criarPilha();

  for (int i = 0; i < tamanho; i++)
  {
    empilhar(pilha, str[i]);
  }

  printf("String invertida: ");
  while (!pilhaVazia(pilha))
  {
    printf("%c", desempilhar(pilha));
  }
  printf("\n");

  free(pilha);
}

int main()
{
  char str[MAX];

  printf("Digite uma string: ");
  fgets(str, MAX, stdin);

  str[strcspn(str, "\n")] = '\0';

  inverterString(str);

  return 0;
}
