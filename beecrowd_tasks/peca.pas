program peca;

var
    codigo1, numeroPeca1, codigo2, numeroPeca2: integer;
    valorUnitario1, valorUnitario2, valorPago: Real;
begin 
    ReadLn(codigo1, numeroPeca1, valorUnitario1);
    ReadLn(codigo2, numeroPeca2, valorUnitario2);
    
    valorPago := (numeroPeca1 * valorUnitario1) + (numeroPeca2 * valorUnitario2);
    
    WriteLn('VALOR A PAGAR: R$ ', valorPago:0:2);
end.




