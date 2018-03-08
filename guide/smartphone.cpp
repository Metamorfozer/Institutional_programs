#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const int lim = 10;
struct smart
{
 char modl[30], cmp[30];
 float dig;
 int dat;
};
smart cat[lim];
int i,n = 0;

void add()
{
 system("clear");
 if (n==(lim-1))
 printf("Каталог заполнен\n");
 else
 {
  n++;
  printf("Введите производителя: ");
  scanf("%s", cat[n].cmp);
  printf("\nВведите модель: ");
  scanf("%s", cat[n].modl);
  printf("\nВведите диагональ: ");
  scanf("%f", &cat[n].dig);
 }
}

void odin(int a)
{
 printf("Производитель: %s\n", cat[n].cmp);
 printf("Модель: %s\n", cat[n].modl);
 printf("Диагональ: %f\n", cat[n].dig);
}
void allin()
{
 system("clear");
 if (n==0)
 printf("Пусто");
 else
 for (i=0;i<n;i++)
 odin(i);
}
void find()
{
 char b[30];
 int c;
 system("clear");
 printf("Введите модель телефона: ");
 c = 0;
 scanf("%s", b);
 for(i=0;i<n;i++)
 {
  if (!strcmp(b, cat[i].cmp))
  {
   c=1;
   odin(i);
  }
  if (c==0)
  printf("Не найдено");
 }
}

int menu()
{
 int d;
 system("clear");
 printf("1 - добавить\n");
 printf("2- показать всё\n");
 printf("3 - показать по производителю\n");
 printf("4 - выход\n");
 scanf("%d", &d);
 return d;
}

int main()
{
 n = 0;
 while (1)
 {
  switch(menu())
  {
   case 1:
          add();
          break;
   case 2:
          allin();
          printf("Нажмите Ctrl+C...\n");
          system("pause");
          break;
   case 3:
          find();
          printf("Нажмите Ctrl+C...\n");
          system("pause");
          break;
   case 4:
          return 0;
  }
 }
 return 0;
}
