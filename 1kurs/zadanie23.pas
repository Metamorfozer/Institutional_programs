uses Crt;

type number = record
     numer:integer;
      temp:integer;
end;

var  files:array[1..10] of number;
m, i, n, s:integer;
         f:file of number;
Begin
 n:=3;
 s:=0;
 clrscr;
 assign(f, 'A.txt');
 for i:=1 to n do
 Begin
  write('Enter natural number: ');
  read(files[i].numer);
 end;
 rewrite(f);
 for i:=1 to n do
  write(f, files[i]);
 close(f);
 clrscr;
 write('Enter number m: ');
 read(m);
 assign(f, 'A.txt');
 {$I-}
 Reset(f);
 {$I+}
 if (IOResult <> 0) then
 Begin
  writeln('Error');
  exit;
 end;
 for i:=1 to filesize(f) do
 Begin
  read(f, files[i]);
  if ((files[i].numer mod m)=0) then
  Begin
   files[s+1].temp := files[i].numer;
               s := s+1;
  end;
 end;
 close(f);
 assign(f, 'B.txt');
 rewrite(f);
 for i:=1 to s do
  write(f, files[i]);
 close(f);
 assign(f, 'B.txt');
 Reset(f);
 for i:=1 to filesize(f) do
 Begin
  read(f, files[i]);
  writeln(files[i].temp);
 end;
 close(f);
end.
