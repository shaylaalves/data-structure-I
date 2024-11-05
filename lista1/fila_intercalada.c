#include <stdio.h>
#include <stdlib.h>

#define MAX 10
#define MAX_INTERCALADA 20

typedef struct
{
  int V[MAX];
  int frente;
  int traseira;
} Fila;

typedef struct
{
  int V[MAX_INTERCALADA];
  int frente;
  int traseira;
} FilaIntercalada;

// Função para criar a fila
Fila *criarFila()
{
  Fila *fila = (Fila *)malloc(sizeof(Fila));
  fila->frente = -1;
  fila->traseira = -1;
  return fila;
}

// Função para criar a fila intercalada
FilaIntercalada *criarFilaIntercalada()
{
  FilaIntercalada *filaIntercalada = (FilaIntercalada *)malloc(sizeof(FilaIntercalada));
  filaIntercalada->frente = -1;
  filaIntercalada->traseira = -1;
  return filaIntercalada;
}

// Verifica se a fila está cheia
int filaCheia(Fila *fila)
{
  return (fila->traseira == MAX - 1);
}

// Verifica se a fila está vazia
int filaVazia(Fila *fila)
{
  return (fila->frente == -1 || fila->frente > fila->traseira);
}

// Função para enfileirar (inserir um elemento no final da fila)
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

// Função para desenfileirar (remover um elemento do início da fila)
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
    // Se todos os elementos foram removidos, reseta a fila
    fila->frente = fila->traseira = -1;
  }

  printf("Desenfileirado: %d\n", valor);
  return valor;
}

// Função para exibir o primeiro elemento da fila sem removê-lo
void VerFrente(Fila *fila)
{
  if (filaVazia(fila))
  {
    printf("Fila vazia!\n");
    return;
  }

  printf("Primeiro elemento da fila: %d\n", fila->V[fila->frente]);
}

// Função para imprimir os elementos da fila
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

// Função para intercalar duas filas
void intercalarFilas(Fila *fila1, Fila *fila2, FilaIntercalada *filaIntercalada)
{
  while (!filaVazia(fila1) && !filaVazia(fila2))
  {
    enfileirar(filaIntercalada, desenfileirar(fila1));
    enfileirar(filaIntercalada, desenfileirar(fila2));
  }
}

int main()
{
  Fila *fila1 = criarFila();
  Fila *fila2 = criarFila();
  FilaIntercalada *filaIntercalada = criarFilaIntercalada();

  // Enfileirando 10 elementos em cada fila
  for (int i = 1; i <= 10; i++)
  {
    enfileirar(fila1, i);
    enfileirar(fila2, i + 10);
  }

  printf("Fila 1 antes da intercalação:\n");
  mostrarFila(fila1);

  printf("Fila 2 antes da intercalação:\n");
  mostrarFila(fila2);

  intercalarFilas(fila1, fila2, filaIntercalada);

  printf("Fila intercalada:\n");
  mostrarFila(filaIntercalada);

  free(fila1);
  free(fila2);
  free(filaIntercalada);

  return 0;
}
