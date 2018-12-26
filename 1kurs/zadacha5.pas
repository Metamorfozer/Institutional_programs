var a, S:real;
 i, n:integer;
Begin
write('Введите n: ');
readln(n);
write('Введите a: ');
readln(a); 
Begin  
 S:=1/a;
 for i:=2 to n do
 S:=S+(1/a*a);
end;
 writeln('S = ', S:0:6);
end.