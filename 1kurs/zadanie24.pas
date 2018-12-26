var s, smin, sl:string;
    i, dmin, count:integer;
Begin
 write('Введите текст: ');
 read(s);
 s:=s+' ';
 sl:='';
 count:=0;
 dmin:=length(s);
 for i:=1 to length(s) do
  if s[i] <> ' ' then
   sl:=sl + s[i]
  else
  Begin
   if (length(sl)<dmin)and(length(sl)<>0) then
   Begin
    dmin:=length(sl);
    smin:=sl;
   end;
   sl:='';
   end;
   for i:=1 to length(s) do
   Begin
    if s[i] <> ' ' then
     sl:=sl + s[i]
    else
    Begin
     if ((length(sl)<>0)) then
     Begin
      if (length(sl)=length(smin)) then
      count:=count + 1;
     end;
    end;
   end;
   writeln('Самое короткое слово "', smin, '" длинной в ', dmin, ' символов, встречается в тексте ', count, ' раз');
end.
