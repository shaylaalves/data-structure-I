#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct
{
  int inverter[MAX];
  int frente;
  int traseira;
} Fila;

typedef struct
{
  int dados[MAX];
  int topo;
} Pilha;

Fila *criarFila()
{
  Fila *fila = (Fila *)malloc(sizeof(Fila));
  fila->frente = -1;
  fila->traseira = -1;
  return fila;
}

int filaCheia(Fila *fila)
{
  return fila->traseira == MAX - 1;
}

int filaVazia(Fila *fila)
{
  return fila->frente == -1 || fila->frente > fila->traseira;
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
  fila->inverter[fila->traseira] = valor;
}

int desenfileirar(Fila *fila)
{
  if (filaVazia(fila))
  {
    printf("Fila vazia!\n");
    return -1;
  }
  int valor = fila->inverter[fila->frente];
  fila->frente++;
  if (fila->frente > fila->traseira)
  {
    fila->frente = fila->traseira = -1;
  }
  return valor;
}

Pilha *criarPilha()
{
  Pilha *pilha = (Pilha *)malloc(sizeof(Pilha));
  pilha->topo = -1;
  return pilha;
}

int pilhaCheia(Pilha *pilha)
{
  return pilha->topo == MAX - 1;
}

int pilhaVazia(Pilha *pilha)
{
  return pilha->topo == -1;
}

void empilhar(Pilha *pilha, int valor)
{
  if (pilhaCheia(pilha))
  {
    printf("Pilha cheia!\n");
    return;
  }
  pilha->topo++;
  pilha->dados[pilha->topo] = valor;
}

int desempilhar(Pilha *pilha)
{
  if (pilhaVazia(pilha))
  {
    printf("Pilha vazia!\n");
    return -1;
  }
  return pilha->dados[pilha->topo--];
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
    printf("%d ", fila->inverter[i]); // Usando 'inverter'
  }
  printf("\n");
}

int main()
{
  Fila *fila = criarFila();
  Pilha *pilha = criarPilha();

  printf("Insira 10 números:\n");
  for (int i = 0; i < MAX; i++)
  {
    int numero;
    scanf("%d", &numero);
    enfileirar(fila, numero);
  }

  printf("Fila original:\n");
  mostrarFila(fila);

  while (!filaVazia(fila))
  {
    int valor = desenfileirar(fila);
    empilhar(pilha, valor);
  }

  while (!pilhaVazia(pilha))
  {
    int valor = desempilhar(pilha);
    enfileirar(fila, valor);
  }

  printf("Fila invertida:\n");
  mostrarFila(fila);

  free(fila);
  free(pilha);

  return 0;
}