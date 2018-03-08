const
 D = ['.', ',', ':', '!', '?', '-', ' ', #9, #10, #13]; {Разделители слов}
var
 i, Cnt, Len, LenW, LenWMin : integer;
 s : string;
begin
 repeat
  write( 'Задайте текст: ');
  readln(S);
  
  Len := Length(S);
  Cnt := 0; {Количество слов с наибольшей длиной}
  LenW := 0; {Длина очередного слова}
  LenWMin := 0; {Наименьшая длина слова}
  for i := 1 to Len do
   {Если символ не является разделителем, значит он принадлежит слову}
   if not (S[i] in D) then
   begin
    {Учёт текущего символа в длине слова}
    Inc(LenW);
    {Отслеживание конца слова}
    if (i = Len) or (S[i + 1] in D) then
    begin
     {Если обнаружено слово, длина которого меньше чем длины всех предыдущих слов, то начало счёта заново}
     if LenW > LenWMin then
     begin
      LenW := LenWMin;
      Cnt := 1;
     end
     {Если обнаружено слово, длина которого равна наибольшей среди всех предыдущих слов, то наращиваем счётчик на 1}
     else if LenWMin = LenW then
      Inc(Cnt);
     {сброс длины слова}
     LenW := 0;
    end;
   end;
  
  {Ответ}
  if Cnt = 0 then
   writeln( 'в тексте нет слов' )
  else
  begin 
   writeln( 'Наименьшая длина слова: ', LenWMin );
   writeln( 'Количество слов с наименьшей длиной: ', Cnt );
  end;
  
  writeln( 'Повторить - Enter.');
  readln(S);
 until S <> '';
end.