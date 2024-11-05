#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct
{
  int V[MAX];
  int frente;
  int traseira;
} Fila;

Fila *criarFila()
{
  Fila *fila = (Fila *)malloc(sizeof(Fila));
  fila->frente = -1;
  fila->traseira = -1;
  return fila;
}

int filaCheia(Fila *fila)
{
  return (fila->traseira == MAX - 1);
}

int filaVazia(Fila *fila)
{
  return (fila->frente == -1 || fila->frente > fila->traseira);
}

void enfileirar(Fila *fila, int valor)
{
  if (filaCheia(fila))
  {
    printf("Fila cheia!\n");
    return;
  }

  if (fila->frente == -1)
  {
    fila->frente = 0;
  }

  fila->V[++(fila->traseira)] = valor;
  printf("Enfileirado: %d\n", valor);
}

int desenfileirar(Fila *fila)
{
  if (filaVazia(fila))
  {
    printf("Fila vazia!\n");
    return -1;
  }

  int valor = fila->V[fila->frente++];
  if (fila->frente > fila->traseira)
  {
    fila->frente = fila->traseira = -1;
  }

  printf("Desenfileirado: %d\n", valor);
  return valor;
}

void VerFrente(Fila *fila)
{
  if (filaVazia(fila))
  {
    printf("Fila vazia!\n");
    return;
  }

  printf("Primeiro elemento da fila: %d\n", fila->V[fila->frente]);
}

void mostrarFila(Fila *fila)
{
  if (filaVazia(fila))
  {
    printf("Fila vazia!\n");
    return;
  }

  printf("Fila: ");
  for (int i = fila->frente; i <= fila->traseira; i++)
  {
    printf("%d ", fila->V[i]);
  }
  printf("\n");
}

int main()
{
  Fila *fila = criarFila();

  enfileirar(fila, 10);
  enfileirar(fila, 20);
  enfileirar(fila, 30);

  VerFrente(fila);

  desenfileirar(fila);
  mostrarFila(fila);

  desenfileirar(fila);
  mostrarFila(fila);

  desenfileirar(fila);
  mostrarFila(fila);

  VerFrente(fila);

  free(fila);

  return 0;
}
