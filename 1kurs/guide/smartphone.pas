uses crt;
const lim = 10;


type smart = record
    cmp,modl: string[30];
    dig: single;
    bat: integer;
    end;


var cat: array[1..lim] of smart;
    i,n: integer;

Procedure add;
begin
     clrscr;
     if n=lim then
       writeln('База переполнена.')
       else
       begin
         n:=n+1;
       write('Введите производителя: ');
       readln(cat[n].cmp);
       write('Введите модель: ');
       readln(cat[n].modl);
       write('Введите диагональ: ');
       readln(cat[n].dig);
       write('Введите ёмкость батареи: ');
       readln(cat[n].bat);
       end;
end;


Procedure odin (a:integer);
begin
     writeln('Производитель: ',cat[a].cmp);
     writeln('Модель: ',cat[a].modl);
     writeln('Диагональ: ',cat[a].dig:0:2);
     writeln('Ёмкость: ',cat[a].bat);
     writeln;
end;

Procedure allin;
begin
     clrscr;
     If n=0 then
       writeln('пусто')
     else
          for i:=1 to n do
            odin(i);
end;


Procedure find;
var b: string;
    c: boolean;
begin
     clrscr;
     writeln('Поиск производителя:');
     c:=false;
     readln(b);
     for i:=1 to n do
     if b=cat[i].cmp then
     begin
          c:=true;
          odin(i);
     end;
     if c = false then
       writeln('Такой производитель не найден.');
end;

    
function menu: integer;
var
   d:integer;
begin
     clrscr;
     writeln('Приветствуем Вас в нашем магазине смартфнов!');
     writeln(' 1- добавить смартфон в каталог');
     writeln(' 2- показать весь каталог');
     writeln(' 3 - поиск по производителю');
     writeln(' 4 - выход');
     writeln('Выберете действие');
     readln(d);
     menu:=d;
end;

begin
     n:=0;
     while true do 
     begin
          case menu of
            1:add;
            2:begin allin;
          writeln('Нажмите клавишу');
          readkey;
          end;
          3:begin
          find;
          writeln('нажмите клавишу');
          readkey;
          end;
          4:break;
          end;
    end;
end.
          