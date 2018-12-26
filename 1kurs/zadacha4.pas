var a, b, s, x, e:real;
begin
 write('Введите x: ');
 readln(x);
 write('e = ');
 readln(e);
 a:= -x;
 b:= 1;
 s:= 3.14/2;
 while (abs(a/b)>e) do
 begin
  s:= s+a/b;
  a:= -a*x*x;
  b:= b+2;
 end;
 writeln('s =', s:0:6);
end.