var x,y:real;
    oa,ob,p,k,lt,pt,v:boolean;
begin
 write('Введите координату х: ');
 readln(x);
 write('Введите координату у: ');
 readln(y);
 oa:=(((x*x+y*y)<1)and(y>0));
 ob:=(((x*x+y*y)<=1)and(y<=0));
 p:=((x>-1)and(x<1)and(y>-4)and(y<0));
 k:=((x>=-1)and(x<=1)and(y>=0)and(y<=2));
 lt:=((x>=-3)and(x<=-1)and(y>=0)and(y<=2)and(((x/-3)+(y/2))<=1));
 pt:=((x>=1)and(x<=3)and(y>=0)and(y<=2)and(((x/3)+(y/2))<=1));
 v:=((x>=-3)and(x<=3)and(y>=-9)and(y<=0)and(((x*x)-y-9)<=0));
 if(lt or pt or (k and not oa) or (v and not p) or ob ) then
   writeln('Да')
  else
   writeln('Нет');
end.