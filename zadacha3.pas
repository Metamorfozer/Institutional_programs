var F,x,dx,xin,xout,a,b,c:real;
   m,r,t, q, p,g:integer;
Begin
 write('Введите х-начальное: ');
 readln(xin);
 write('Введите х-конечное: ');
 readln(xout);
 write('Введите dx: ');
 readln(dx);
 write('Введите а: ');
 readln(a);
 write('Введите b: ');
 readln(b);
 write('Введите c: ');
 readln(c);

 x:=xin;

  while (x<=xout) do
  begin
  if ((a<0)AND NOT(x=0)) then 
   begin
    F:=a*x*x+b*b*x;
   end
  else
    if ((a>0)AND(x=0)AND NOT(x-c=0)) then 
     begin
     F:=x-(a/(x-c));
     end
    else
     begin
     write('x=',x:0:5);
     writeln(' F=Решение невозможно');
     end;
       m:=trunc(a);
       r:=trunc(b);
       t:=trunc(c);
       q:=not (m or r);
       p:= r or t;
       m:= q and p;
       if m <> 0 then
       begin
       if not(c=0) then
         begin
         F:=1+x/c;
         write('x=',x:0:5);
         writeln(' F =',F:0:5);
         end
        else
         writeln('Решение невозможно');
       end
      else
       begin
       g:=trunc(F);
       write('x=', x:0:5);
       writeln(' F=', g);
       end;       
  x:=x+dx;
  end
end.