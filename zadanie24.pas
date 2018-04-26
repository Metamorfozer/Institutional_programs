uses Crt;
var s,s1,smin : string;
    k : integer;
    f : text;
begin
   ClrScr;
   Assign(f, '1.txt');
   {$I-}
   Reset(f);
   {$I+}
   if (IOResult <> 0) then
   Begin
    writeln('Error');
    exit;
   end;
   smin:='';
   While not Eof(f) do begin
     Readln(f, s);
     While Pos('  ',s)>0 do Delete(s,Pos('  ',s),1);
	 While Pos('.',s)>0 do Delete(s,Pos('.',s),1);
	 While Pos(',',s)>0 do Delete(s,Pos(',',s),1);
     if s[1]=' ' then Delete(s,1,1);
	 if s[1]='.' then Delete(s,1,1);
	 if s[1]=',' then Delete(s,1,1);
     if s[Length(s)]=' ' then Delete(s,Length(s),1);
	 if s[Length(s)]='.' then Delete(s,Length(s),1);
     While s<>'' do begin
     if Pos(' ',s)>0 then begin
         s1:=Copy(s,1,Pos(' ',s)-1);
         Delete(s,1,Pos(' ',s));
       end else begin
         s1:=s;  s:='';
       end;
       if (smin='') or (Length(s1)<Length(smin)) then smin:=s1;
     end;
   end;
   Close(f);

   Reset(f);
   k:=0;
   While not Eof(f) do begin
     Readln(f, s);
     {Udalyaem lishnie probeli}
     While Pos('  ',s)>0 do Delete(s,Pos('  ',s),1);
     if s[1]=' ' then Delete(s,1,1);
     if s[Length(s)]=' ' then Delete(s,Length(s),1);

     While s<>'' do begin
       if Pos(' ',s)>0 then begin
         s1:=Copy(s,1,Pos(' ',s)-1);
         Delete(s,1,Pos(' ',s));
       end else begin
         s1:=s;  s:='';
       end;
       if s1=smin then Inc(k);
     end;
   end;
   Close(f);

   if smin<>''
     then Writeln('Slovo "',smin,'" vstrechaetsya ',k,' raz')
     else Writeln('File ne soderjit slov');
   Readln;
end.
