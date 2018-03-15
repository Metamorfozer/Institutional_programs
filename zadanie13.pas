uses Crt;

type people = record
     store, goods:string[15];
     price:integer;
end;

const lim = 10;

var power:array[1..lim] of people;
    i, n:integer;
function menu():integer;
var d:integer;
Begin
 clrscr;
 writeln('1 - сохранить в файл');
 writeln('2 - загрузить из файла');
 writeln('3 - поиск по названию магазина');
 writeln('4 - добавить магазин');
 writeln('5 - показать все магазины');
 writeln('6 - сортировка магазинов');
 writeln('7 - выход');
 write('Введите цифру: ');
 readln(d);
 menu:=d;
end;

procedure save();
var i:integer;
    fb:file of people;
    namefile:string;
Begin
 clrscr;
 write('Введите название файла: ');
 readln(namefile);
 assign(fb, namefile);
 {$I-}
 Reset(fb);
 {$I+}
 if (IOResult=0) then
 Begin
  close(fb);
  writeln('Файл уже существует, перезаписать?');
  writeln('Напишите 1, если хотите перезаписать, ');
  writeln(' при нажатии другой клавиши просто сохранит содержимое массива в конец файла');
  readln(i);
 end;

 if (i=1) then
 Begin
   rewrite(fb);
   for i:=1 to n do
   write(fb, power[i]);
 end
 else
 Begin
  reset(fb);
  seek(fb, filesize(fb));
  for i:=1 to n do
   write(fb, power[i]);
 end;
 close(fb);
end;

procedure odin(a:integer);
Begin
 writeln('Магазин, номер ', a);
 writeln('Название магазина: ', power[a].store);
 writeln('Название товара: ', power[a].goods);
 writeln('Стоимость: ', power[a].price, ' руб.');
end;

procedure find();
var     c:integer; 
namestore:string;
Begin
 clrscr;
 write('Введите название магазина: ');
 c:=0;
 readln(namestore);
 for i:=1 to n do
 Begin
  if (namestore = power[i].store) then
  Begin
   c:=1;
   odin(i);
  end;
  if (c=0) then
  writeln('Магазин не найден');
 end;
end;

procedure add();
Begin
 clrscr;
 if (n = (lim-1)) then
  writeln('Заполнено!')
 else
 Begin
  inc(n);
  writeln('Магазин,  номер ', n);
  write('Введите название магазина: ');
  readln(power[n].store);
  write('Введите название товара: ');
  readln(power[n].goods);
  write('Введите цену: ');
  readln(power[n].price);
 end;
end;

procedure all();
Begin
 clrscr;
 if (not(n = 0)) then
 Begin
  for i:=1 to n do
   odin(i);
 end
 else
 writeln('Не найдено ни одного магазина!');
end;

procedure sort();
var j:integer; 
    h:people;
Begin
 for j:=1 to n-1 do 
 for i:=1 to n-1 do
 Begin
  if (power[i].store > power[i+1].store) then
  Begin
   h:=power[i];
   power[i]:=power[i+1];
   power[i+1]:=h;
  end;
 end;
end;

procedure loading();
var i:integer;
    fb:file of people;
    namefile:string;
Begin
 clrscr;
 write('Введите название файла: ');
 readln(namefile);
 assign(fb, namefile);
 {$I-}
 Reset(fb);
 {$I+}
 if (IOResult <> 0) then
 Begin
  writeln('Ошибка при открытии файла');
  exit;
 end;
 for i:=1 to filesize(fb) do
 if (i<lim) then
  Begin
   read(fb, power[i]);
   writeln('Магазин, номер ', i);
   writeln('Название магазина: ', power[i].store);
   writeln('Название товара: ', power[i].goods);
   writeln('Стоимость: ', power[i].price, ' руб.');
  end;
 close(fb);
end;

Begin
 n:=0;
 while (true) do
 Begin
  case menu of
  1:
  Begin
   save();
   writeln('Введите любую клавишу для продолжения');
   readkey;
  end;
  2:
  Begin
   loading();
   writeln('Введите любую клавишу для продолжения');
   readkey;
  end;
  3:
  Begin
   find();
   writeln('Введите любую клавишу для продолжения');
   readkey;
  end;
  4:
  Begin
   add();
   writeln('Введите любую клавишу для продолжения');
   readkey;
  end;
  5:
  Begin
   all();
   writeln('Введите любую клавишу для продолжения');
   readkey;
  end;
  6:
  Begin
   sort();
   writeln('Введите любую клавишу для продолжения');
   readkey;
  end;
  7:
  exit;
  end;
 end;
end.
