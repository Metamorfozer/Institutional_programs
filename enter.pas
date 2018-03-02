uses Crt;
var
   f:text; //text - файловая переменная
   s:string;
Begin
 clrscr;
 assign(f,'poem.txt'); //Связывает файловую переменную
 rewrite(f);
 while true do
 Begin
  write('Введите строку: ');
  readln(s);
  if s='stop' then
  break;
  writeln(f, s);
 end;
 close(f);
 assign(f, 'poem.txt');
 writeln('Файл poem.txt имеет следующее содержание:');
 {$I-}
 reset(f);
 {$I+}
 if IOResult <> 0 then
 Begin
  writeln('Ошибка при открытии файла!');
  exit;
 end;
 while not eof(f) do
 Begin
  readln(f, s);
  writeln(s);
 end;
 close(f);
end.