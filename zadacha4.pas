uses Crt;
const
 eps = 1E-10;
var 
 a,sum,x:extended;
 n:integer;
begin
 ClrScr;
 readln(x);
 a:=1.0; 
 sum:=a; 
 n:=0;
 while (abs(a)>eps)AND(n<100)do
  begin
  n:=n+1;
  a:=a*x/n;
  sum:=sum+a;
  end;
 writeln('exp=', exp(x):0:20);
 writeln('sum=', sum:0:20);
end.