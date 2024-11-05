#include <stdio.h>

#define MAX 50

typedef struct
{
  double num[MAX];
  int elementos;
} Pilha;

void push(Pilha *pilha, double num)
{
  if (pilha->elementos < MAX - 1)
  {
    pilha->num[++(pilha->elementos)] = num;
  }
}

double pop(Pilha *pilha)
{
  if (pilha->elementos >= 0)
  {
    return pilha->num[(pilha->elementos)--];
  }
  return 0.0;
}

int main()
{
  double str[MAX];
  Pilha pilha;
  pilha.elementos = -1;

  printf("Digite a quantidade de numeros: ");
  int n;
  scanf("%d", &n);

  printf("Digite os numeros: \n");
  for (int i = 0; i < n; i++)
  {
    scanf("%lf", &str[i]);
    push(&pilha, str[i]);
  }

  double anterior = pop(&pilha);
  int crescente = 1;

  printf("Desempilhando numeros: ");
  printf("%.1lf ", anterior);

  while (pilha.elementos >= 0)
  {
    double atual = pop(&pilha);
    printf("%.1lf ", atual);

    if (atual >= anterior)
    {
      crescente = 0;
    }
    anterior = atual;
  }
  printf("\n");

  if (crescente)
  {
    printf("A sequencia eh estritamente crescente.\n");
  }
  else
  {
    printf("A sequência não é estritamente crescente.\n");
  }

  return 0;
}