#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

typedef struct
{
  char elementos[MAX];
  int frente;
  int traseira;
} Fila;

typedef struct
{
  char elementos[MAX];
  int topo;
} Pilha;

Fila *criarFila()
{
  Fila *fila = (Fila *)malloc(sizeof(Fila));
  fila->frente = -1;
  fila->traseira = -1;
  return fila;
}

int filaVazia(Fila *fila)
{
  return fila->frente == -1;
}

void enfileirar(Fila *fila, char c)
{
  if (fila->traseira == MAX - 1)
  {
    printf("Fila cheia!\n");
    return;
  }
  if (fila->frente == -1)
  {
    fila->frente = 0;
  }
  fila->traseira++;
  fila->elementos[fila->traseira] = c;
}

char desenfileirar(Fila *fila)
{
  if (filaVazia(fila))
  {
    printf("Fila vazia!\n");
    return '\0';
  }
  char c = fila->elementos[fila->frente];
  fila->frente++;
  if (fila->frente > fila->traseira)
  {
    fila->frente = fila->traseira = -1;
  }
  return c;
}

Pilha *criarPilha()
{
  Pilha *pilha = (Pilha *)malloc(sizeof(Pilha));
  pilha->topo = -1;
  return pilha;
}

int pilhaVazia(Pilha *pilha)
{
  return pilha->topo == -1;
}

void empilhar(Pilha *pilha, char c)
{
  if (pilha->topo == MAX - 1)
  {
    printf("Pilha cheia!\n");
    return;
  }
  pilha->topo++;
  pilha->elementos[pilha->topo] = c;
}

char desempilhar(Pilha *pilha)
{
  if (pilhaVazia(pilha))
  {
    printf("Pilha vazia!\n");
    return '\0';
  }
  return pilha->elementos[pilha->topo--];
}

int main()
{
  char str[MAX];
  Fila *fila = criarFila();
  Pilha *pilha = criarPilha();

  printf("Digite uma palavra ou frase: ");
  fgets(str, sizeof(str), stdin);

  // Remover caracteres não alfabéticos e transformar em minúsculas
  int len = strlen(str);
  for (int i = 0; i < len; i++)
  {
    if (isalpha(str[i]))
    {
      char c = tolower(str[i]);
      enfileirar(fila, c);
      empilhar(pilha, c);
    }
  }

  int ehPalindromo = 1;
  while (!filaVazia(fila) && !pilhaVazia(pilha))
  {
    char f = desenfileirar(fila);
    char p = desempilhar(pilha);
    if (f != p)
    {
      ehPalindromo = 0;
      break;
    }
  }

  if (ehPalindromo)
  {
    printf("A string é um palíndromo.\n");
  }
  else
  {
    printf("A string não é um palíndromo.\n");
  }

  free(fila);
  free(pilha);

  return 0;
}