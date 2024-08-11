program Volumesfera;

const
    pi = 3.14159;

var
    raio: Real;
    volume: Real;

begin
    ReadLn(raio);
    
    volume := (4.0 / 3.0) * pi * raio * raio * raio;
    
    WriteLn('VOLUME = ', volume:0:3);
end.
