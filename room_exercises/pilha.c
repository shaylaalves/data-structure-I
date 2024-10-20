#include <stdio.h>

#define TAMANHO 10

typedef struct
{
  int topo;
  int elementos[TAMANHO];
} Pilha;

void inicializarPilha(Pilha *p)
{
  p->topo = -1;
}

void empilhar(Pilha *p, int valor)
{
  if (p->topo == TAMANHO - 1)
  {
    printf("A pilha está cheia!\n");
  }
  else
  {
    p->topo++;
    p->elementos[p->topo] = valor;
    printf("%d foi empilhado.\n", valor);
  }
}

int desempilhar(Pilha *p)
{
  if (p->topo == -1)
  {
    printf("A pilha está vazia!\n");
    return -1;
  }
  else
  {
    int valor = p->elementos[p->topo];
    p->topo--;
    printf("%d foi desempilhado.\n", valor);
    return valor;
  }
}

int espiar(Pilha *p)
{
  if (p->topo == -1)
  {
    printf("A pilha está vazia!\n");
    return -1;
  }
  else
  {
    printf("Topo da pilha: %d\n", p->elementos[p->topo]);
    return p->elementos[p->topo];
  }
}

int main()
{
  Pilha minhaPilha;
  inicializarPilha(&minhaPilha);

  empilhar(&minhaPilha, 5);
  empilhar(&minhaPilha, 10);
  empilhar(&minhaPilha, 15);

  espiar(&minhaPilha);

  desempilhar(&minhaPilha);
  espiar(&minhaPilha);

  desempilhar(&minhaPilha);
  desempilhar(&minhaPilha);
  desempilhar(&minhaPilha);

  return 0;
}
