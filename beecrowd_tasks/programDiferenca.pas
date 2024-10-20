program Diferenca;

var
  A, B, C, D: Integer;
  ResultadoDiferenca: Integer;

begin
  ReadLn(A);
  ReadLn(B);
  ReadLn(C);
  ReadLn(D);

  ResultadoDiferenca := (A * B) - (C * D);

  WriteLn('DIFERENCA = ', ResultadoDiferenca);
end.