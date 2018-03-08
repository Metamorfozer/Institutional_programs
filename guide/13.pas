uses crt;
const lim = 10;
type
    smart = record
    cmp, model:string[30];
    dig:single;
    bat:integer;
end;
var
   cat:array[1..lim] of smart;
   i,n:integer;
procedure add;
Begin
clrscr;
if n=lim then
 writeln('Каталог заполнен.')
else
 Begin
  n:=n+1;
  write('Введите производителя: ');
  readln(cat[n].cmp);
  write('Введите модель: ');
  readln(cat[n].model);
  write('Введите диагональ: ');
  readln(cat[n].dig);
  write('Введите ёмкость батареи: ');
  readln(cat[n].bat);
  end;
end;
procedure odin(a:integer);
Begin
 writeln('Производитель: ', cat[a].cmp);
 writeln('Модель: ', cat[a].model);
 writeln('Диагональ: ', cat[a].dig);
 writeln('Ёмкость батареи: ', cat[a].bat);
end;
procedure allin;
Begin
 clrscr;
 if n = 0 then
  writeln('Пусто.')
 else
  for i := 1 to n do
  odin[i];
end;
procedure find;
var
   b:string;
   c:boolean;
Begin
 clrscr;
 writeln('Введите марку производителя: ');
 readln(b);
 for i := 1 to n do
  if b = cat[i].cmp then
  Begin
   c:=true;
   odin(i);
  end;
  if c=false then
   writeln('Не найдено!');
end;
function menu:integer;
var d:integer;
Begin
 clrscr;
 writeln('Приветствую!');
 writeln('Выберите действие:');
 writeln('1 - добавить');
 writeln('2 - показать всё');
 writeln('3 - искать по производителю');
 writeln('4 - выход');
 readln(d);
 menu:=d;
end;
Begin
 n:=0;
 while true do
 Begin
  case menu of
  1:add;
  2:allin;
  writeln('Нажмите клавишу...');
  keypress;
  3:find
  writeln('Нажмите клавишу...');
  4:break;
 end;
end.
end.