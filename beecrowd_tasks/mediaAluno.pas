program MediaAluno;

uses
  SysUtils;

var
  A, B, C, Media: Double;

begin
  ReadLn(A);
  ReadLn(B);
  ReadLn(C);

  Media := (A * 2 + B * 3 + C * 5) / 10;

  WriteLn('MEDIA = ', FormatFloat('0.0', Media));
end.
