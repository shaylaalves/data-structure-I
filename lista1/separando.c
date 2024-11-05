#include <stdio.h>
#include <stdlib.h>

#define MAX 20

typedef struct
{
  int par[MAX];
  int frente;
  int traseira;
} Fila;

typedef struct
{
  int impar[MAX];
  int frente;
  int traseira;
} FilaImpar;

Fila *criarFila()
{
  Fila *fila = (Fila *)malloc(sizeof(Fila));
  fila->frente = -1;
  fila->traseira = -1;
  return fila;
}

FilaImpar *criarFilaImpar()
{
  FilaImpar *filaImpar = (FilaImpar *)malloc(sizeof(FilaImpar));
  filaImpar->frente = -1;
  filaImpar->traseira = -1;
  return filaImpar;
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
  fila->traseira++;
  fila->par[fila->traseira] = valor;
}

void mostrarFila(Fila *fila)
{
  if (filaVazia(fila))
  {
    printf("Fila Vazia!\n");
    return;
  }
  printf("Fila: ");
  for (int i = fila->frente; i <= fila->traseira; i++)
  {
    printf("%d ", fila->par[i]);
  }
  printf("\n");
}

int main()
{
  Fila *filaPar = criarFila();
  FilaImpar *filaImpar = criarFilaImpar();

  for (int i = 1; i <= 20; i++)
  {
    if (i % 2 == 0)
    {
      enfileirar(filaPar, i);
    }
    else
    {
      enfileirar((Fila *)filaImpar, i);
    }
  }

  printf("Fila Par:\n");
  mostrarFila(filaPar);

  printf("Fila Impar:\n");
  mostrarFila((Fila *)filaImpar);

  free(filaPar);
  free(filaImpar);

  return 0;
}