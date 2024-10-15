function IsEmpty(var P:Pilha): boolean; begin

if P.topo=0 then IsEmpty: true IsEmpty := false; else

end;

function IsFull (var P:Pilha): boolean; begin if P.topo-MAX then IsFull: true else IsFull: false;

end;

procedure Push(var P:Pilha; x: Elem);

begin

if not IsFull (P) then begin P.topo: P.topo +1; end else end; P.memo [P.topo] := x; writeln('Stack Overflow!');

function Pop (var P: Pilha): Elem; begin if not IsEmpty(P) then begin end else Pop: P.memo [P.topo]; P.topo: P.topo-1; writeln('Stack Underflow');

end;

function Top (var P:Pilha): Elem; begin

end;

end.

if not IsEmpty(P) then Top: P.memo [P.topo] else writeln ('Stack Underflow');