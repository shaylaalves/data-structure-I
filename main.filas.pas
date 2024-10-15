unit Filas;

interface
  const MAX = 200;
  type Elem = Integer;
       Fila = record
     total : integer;
     comeco: integer;
     final: integer;
     memo : array[1..MAX] of Elem;
       end;

  procedure Qinit(var F: Fila);
  function QisEmpty(var F: Fila):  boolean;
  function QisFull(var F: Fila):  boolean;
  procedure Enqueue(var F: Fila; x:Elem);
  function Dequeue(var F: Fila) : Elem;

implementation
 procedure Qinit(var F: Fila);
 begin
  F.total := 0;
  F.comeco:= 1;
  F.final:=1;
 end;

  function QisEmpty(var F: Fila):  boolean;
  begin
 QisEmpty := (F.total = 0);
  end;

  function QisFull(var F: Fila):  boolean;
  begin
 QisFull := (F.total = MAX);
  end;

  procedure adc(var i:integer);
  begin
 i := +1;
 if i>MAX then i := 1;
  end;

  procedure Enqueue(var F: Fila; x:Elem);
  begin
 if not QisFull(F) then
 begin
  F.memo[F.final]:=X;
  adc(F.final);
  inc(F.Total);
 end
 else
  writeln('Fila lotada.');
  end;

  function Dequeue(var F: Fila) : Elem;
  begin
 if not QisEmpty(F) then
  begin
   Dequeue := F.memo[F.comeco];
   adc(F.comeco);
   dec(F.total);
  end
 else
  writeln('Fila Vazia: impossível remover');
end;

end.