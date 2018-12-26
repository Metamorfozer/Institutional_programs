uses Crt;
var
 x,y,z1,z2:extended;
Begin
    write('Введите х:');
    read(x);
    write('Введите у:');
    read(y);
    z1:= cos(x)*cos(x)*cos(x)*cos(x) + sin(y)*sin(y) + 1/4*sin(2*x)*sin(2*x)-1;
    z2:= sin(y+x)*cos(y-x);
    writeln('х = ', z1:0:6);
    writeln('y = ', z2:0:6);
end.