#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Paciente
{
  char nome[50];
  struct Paciente *proximo;
} Paciente;

typedef struct
{
  Paciente *inicio;
} Lista;

typedef struct
{
  Paciente *inicio;
  Paciente *fim;
} Fila;

typedef struct
{
  Paciente *topo;
} Pilha;

void inicializarLista(Lista *lista)
{
  lista->inicio = NULL;
}

void adicionarPaciente(Lista *lista, char *nome)
{
  Paciente *novo = (Paciente *)malloc(sizeof(Paciente));
  strcpy(novo->nome, nome);
  novo->proximo = lista->inicio;
  lista->inicio = novo;
  printf("Paciente %s adicionado à lista de triagem.\n", nome);
}

Paciente *removerPacienteLista(Lista *lista)
{
  if (lista->inicio == NULL)
    return NULL;
  Paciente *removido = lista->inicio;
  lista->inicio = lista->inicio->proximo;
  removido->proximo = NULL;
  return removido;
}

void inicializarFila(Fila *fila)
{
  fila->inicio = NULL;
  fila->fim = NULL;
}

void enfileirar(Fila *fila, Paciente *paciente)
{
  paciente->proximo = NULL;
  if (fila->fim == NULL)
  {
    fila->inicio = paciente;
    fila->fim = paciente;
  }
  else
  {
    fila->fim->proximo = paciente;
    fila->fim = paciente;
  }
  printf("Paciente %s movido para a fila de consulta.\n", paciente->nome);
}

Paciente *desenfileirar(Fila *fila)
{
  if (fila->inicio == NULL)
    return NULL;
  Paciente *removido = fila->inicio;
  fila->inicio = fila->inicio->proximo;
  if (fila->inicio == NULL)
    fila->fim = NULL;
  removido->proximo = NULL;
  return removido;
}

void inicializarPilha(Pilha *pilha)
{
  pilha->topo = NULL;
}

void empilhar(Pilha *pilha, Paciente *paciente)
{
  paciente->proximo = pilha->topo;
  pilha->topo = paciente;
  printf("Paciente %s movido para o histórico de atendimentos.\n", paciente->nome);
}

void exibirPacientes(Paciente *paciente, char *titulo)
{
  printf("\n%s:\n", titulo);
  if (paciente == NULL)
  {
    printf("Nenhum paciente.\n");
    return;
  }
  while (paciente != NULL)
  {
    printf("- %s\n", paciente->nome);
    paciente = paciente->proximo;
  }
  printf("\n");
}

void menu()
{
  Lista lista;
  Fila fila;
  Pilha pilha;

  inicializarLista(&lista);
  inicializarFila(&fila);
  inicializarPilha(&pilha);

  int opcao;
  char nome[50];
  Paciente *paciente;

  do
  {
    printf("\n--- Sistema de Clínica Médica ---\n");
    printf("1. Adicionar paciente à triagem\n");
    printf("2. Mover paciente para fila de consulta\n");
    printf("3. Registrar atendimento\n");
    printf("4. Exibir estado atual\n");
    printf("0. Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);
    getchar();

    switch (opcao)
    {
    case 1:
      printf("Digite o nome do paciente: ");
      fgets(nome, sizeof(nome), stdin);
      nome[strcspn(nome, "\n")] = '\0';
      adicionarPaciente(&lista, nome);
      break;
    case 2:
      paciente = removerPacienteLista(&lista);
      if (paciente == NULL)
      {
        printf("Nenhum paciente aguardando triagem.\n");
      }
      else
      {
        enfileirar(&fila, paciente);
      }
      break;
    case 3:
      paciente = desenfileirar(&fila);
      if (paciente == NULL)
      {
        printf("Nenhum paciente aguardando consulta.\n");
      }
      else
      {
        empilhar(&pilha, paciente);
      }
      break;
    case 4:
      exibirPacientes(lista.inicio, "Pacientes aguardando triagem");
      exibirPacientes(fila.inicio, "Pacientes aguardando consulta");
      exibirPacientes(pilha.topo, "Histórico de atendimentos");
      break;
    case 0:
      printf("Encerrando o sistema...\n");
      break;
    default:
      printf("Opção inválida. Tente novamente.\n");
    }
  } while (opcao != 0);
}

int main()
{
  menu();
  return 0;
}
