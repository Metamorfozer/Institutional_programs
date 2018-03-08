const
  m=5; n=5; LIM=30; W=4;
var
  a: array [1..m,1..n] of Real;
  i, j, jmin, imax, jmax: Integer;
begin
  Randomize;
  for i:=1 to m do 
   for j:=1 to n do 
   a[i,j]:=Random(LIM);
    for i:=1 to m do 
    begin 
     for j:=1 to n do 
      Write(a[i,j]:W:0); 
      Writeln; 
    end;
  imax:=1; 
  jmax:=1; 
  for j:=2 to n do 
   if a[1,jmax]>a[1,j] then 
   jmax:=j;
   for i:=2 to m do 
   begin
    jmin:=1; 
    for j:=2 to n do 
     if a[i,jmin]>a[i,j] then 
     jmin:=j;
      if a[imax,jmax]<a[i,jmin] then 
      begin
       imax:=i; 
       jmax:=jmin;
      end;
   end;
  WriteLn('Максимальный среди минимальных в позиции: ',imax,',',jmax);
end.