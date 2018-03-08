uses crt;
var i,j,n:integer;
    a: array [0..50,0..50] of Integer;

begin
 write('Введите n: ');
 read(n);
 n:=n-1;
 for i:=0 to n do
  begin
  for j:=0 to n do
   begin
   if i=j then
   begin
    a[i][j]:=1;
   end
    else
   if i>j then
    begin
    a[i+1][j]:=a[i][j]+1;
    a[i][j]:=a[i][j]+1;
    a[i][j]:=a[i][j]+1;
    end;
   if i<j then
    begin
    a[i][j+1]:=a[i][j]+1;
    a[i][j]:=a[i][j]+1;
    a[i][j]:=a[i][j]+1;
    end;
    write(' ');
    write(a[i][j]);
    write(' ');
   end;
   writeln();
   writeln();
  end;
end.