program SalarioFuncionario;

var
  numeroFuncionario: Integer;
  horasTrabalhadas: Integer;
  valorPorHora: Real;
  salario: Real;

begin
  ReadLn(numeroFuncionario);
  ReadLn(horasTrabalhadas);
  ReadLn(valorPorHora);

  salario := horasTrabalhadas * valorPorHora;

  WriteLn('NUMBER = ', numeroFuncionario);
  WriteLn('SALARY = U$ ', salario:0:2);
end.
