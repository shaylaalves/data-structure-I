program SistemaDeAtendimento;

type
    Cliente = record
        nome: string[50];
        codigo: integer;
    end;

    Fila = record
        clientes: array[1..100] of Cliente;
        inicio, fim: integer;
    end;

var
    filaAtendimento: Fila;

procedure InicializaFila(var f: Fila);
begin
    f.inicio := 1;
    f.fim := 0;
end;

function FilaVazia(f: Fila): boolean;
begin
    FilaVazia := f.fim < f.inicio;
end;

procedure Enfileira(var f: Fila; c: Cliente);
begin
    if f.fim < 100 then
    begin
        f.fim := f.fim + 1;
        f.clientes[f.fim] := c;
    end
    else
        writeln('Fila cheia!');
end;

function Desenfileira(var f: Fila): Cliente;
begin
    if not FilaVazia(f) then
    begin
        Desenfileira := f.clientes[f.inicio];
        f.inicio := f.inicio + 1;
    end
    else
    begin
        writeln('Fila vazia!');
        Desenfileira.nome := '';
        Desenfileira.codigo := -1;
    end;
end;

procedure AtenderClientes(var f: Fila);
var
    cliente: Cliente;
begin
    while not FilaVazia(f) do
    begin
        cliente := Desenfileira(f);
        writeln('Atendendo cliente: ', cliente.nome, ' (Codigo: ', cliente.codigo, ')');
    end;
end;

var
    cliente: Cliente;
    opcao: integer;

begin
    InicializaFila(filaAtendimento);

    repeat
        writeln('1. Adicionar cliente à fila');
        writeln('2. Atender clientes');
        writeln('3. Sair');
        writeln('Escolha uma opcao: ');
        readln(opcao);

        case opcao of
            1: begin
                    writeln('Digite o nome do cliente: ');
                    readln(cliente.nome);
                    writeln('Digite o codigo do cliente: ');
                    readln(cliente.codigo);
                    Enfileira(filaAtendimento, cliente);
               end;
            2: AtenderClientes(filaAtendimento);
        end;
    until opcao = 3;
end.
