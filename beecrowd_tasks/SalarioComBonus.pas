program SalarioComBonus;

var
  NomeVendedor: String;
  SalarioFixo: Real;
  TotalVendasPorMes: Real;
  TotalReceber: Real;

begin
  ReadLn(NomeVendedor);
  ReadLn(SalarioFixo);
  ReadLn(TotalVendasPorMes);
  
  TotalReceber := SalarioFixo + (TotalVendasPorMes * 0.15);
  
  WriteLn('TOTAL = R$ ', TotalReceber:0:2);
end.
