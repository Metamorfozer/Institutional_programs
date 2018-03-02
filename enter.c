#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
 FILE *f = NULL;
 char s[1000];
 system("clear");
 f = fopen("cpoem.txt", "wt"); //w - перезапись, r - открыть для чтения, rb - открыть существующий файл для чтения
 if (f==NULL)
 {
  printf("Ошибка при создании файла");
  return 1;
 }
 while (1)
 {
  printf("Введите строку: ");
  fgets(s, 999, stdin);
  if (!strcmp(s, "stop\n"))
  break;
  fprintf(f, "%s", s);
 }
 fclose(f);
 f = fopen("cpoem.txt", "rt");
 char *E = NULL;
 while (!feof(f))
 {
  E = fgets(s, 999, f);
  if (E!=NULL)
  printf("%s", s);;
 }
 fclose(f);
 return 0;
}
