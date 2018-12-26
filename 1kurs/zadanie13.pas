uses Crt;

type MARSH = record
     start, endl:string[40];
     nomer:integer;
end;

const lim = 10;

var bd:array[1..lim] of MARSH;
    i, size:integer;

function menu():integer;
var k:integer;
Begin
 clrscr;
 writeln('1 - добавить маршрут');
 writeln('2 - печатать базу');
 writeln('3 - считать с файла');
 writeln('4 - сохранить в файл');
 writeln('5 - выход');
 write('Напишите цифру для действия: ');
 readln(k);
 menu:=k;
end;

procedure add();
Begin
 clrscr;
 if (size = lim) then
  writeln('Места нет')
 else
 Begin
  inc(size);
  writeln('Введите название начального пункт: ');
  readln(bd[size].start);
  writeln('Введите название конечного пункта: ');
  readln(bd[size].endl);
  writeln('Введите номер маршрута: ');
  readln(bd[size].nomer);
 end;
end;

procedure show();
Begin
 clrscr;
 if (not(size = 0)) then
 Begin
  for i:=1 to size do
  Begin
   writeln('Начальный маршрут: ', bd[i].start);
   writeln('Конечный маршрут: ', bd[i].endl);
   writeln('Номер маршрута: ', bd[i].nomer);
  end;
 end
 else
 writeln('Данный нет');
end;

procedure sort();
var i, j, a:integer;
    b:MARSH;
Begin
 for i:=1 to size - 1 do
 Begin
  if (not(bd[i].nomer = bd[i+1].nomer)) then
  Begin
   b:=bd[i];
   bd[i]:=bd[i+1];
   bd[i+1]:=b;
  end;
 end;
end;

procedure fileIn();
var i:integer;
    fileIn:file of MARSH;
    filePath:string;
Begin
 clrscr;
 write('Введите название файла: ');
 readln(filePath);
 assign(fileIn, filePath);
 {$I-}
 Reset(fileIn);
 {$I+}
 if (IOResult <> 0) then
 Begin
  writeln('Ошибка при открытии файла');
  exit;
 end;
 if (size=0) then
  inc(size);
 for i:=size to filesize(fileIn) do
  if (i<lim) then
  Begin
   read(fileIn, bd[i]);
   inc(size);
  end;
 sort();
 close(fileIn);
end;

procedure save();
var i:integer;
    fileOut:file of MARSH;
    filePath:string;
Begin
 clrscr;
 write('Введите название файла: ');
 readln(filePath);
 assign(fileOut, filePath);
 {$I-}
 Reset(fileOut);
 {$I+}
 if (IOResult=0) then
 Begin
  close(fileOut);
  writeln('Файл с таким названием уже существует');
  writeln('1 - перезаписать');
  readln(i);
 end;

 if (i=2) then
 Begin
  reset(fileOut);
  seek(fileOut, filesize(fileOut));
  for i:=1 to size do
   write(fileOut, bd[i]);
 end
 else
 Begin
  rewrite(fileOut);
  for i:=1 to size do
   write(fileOut, bd[i]);
 end;
 close(fileOut);
end;

Begin
 while (true) do
 Begin
  case menu of
  1:
  Begin
   add();
   sort();
   writeln('Введите любую клавишу для продолжения');
   readkey;
  end;
  2:
  Begin
   show();
   writeln('Введите любую клавишу для продолжения');
   readkey;
  end;
  3:
  Begin
   fileIn();
   writeln('Введите любую клавишу для продолжения');
   readkey;
  end;
  4:
  Begin
   save();
   writeln('Введите любую клавишу для продолжения');
   readkey;
  end;
  5: exit;
  end;
 end;
end.
