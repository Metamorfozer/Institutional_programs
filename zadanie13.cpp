#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
using namespace std;

int i,n = 0;
char namefile[15];
const int lim = 10;

struct people
{
 char store[15];
 char goods[15];
 float price;
};

people power[lim];
void save()
{
 system("clear");
 FILE *f;
 int i;
 cout << "Введите название файла: ";
 cin  >> namefile;
 f = fopen(namefile, "r");
 if (!(f==NULL))
 {
  fclose(f);
  cout << "Файл уже существует, перезаписать?\n";
  cout << "Напишите 1, если хотите перезаписать,\nдругая клавиша просто сохранит содержимое массива в конец файла\n";
  char p;
  cin >> p;
  if (p==1)
  {
   f = fopen(namefile, "wb");
   for (i=0;i<n;i++)
   {
    fwrite(&power[i], sizeof(people), 1, f);
   }
   fclose(f);
  }
  else
  {
   f = fopen(namefile, "r+b");
   fseek(f, 0, SEEK_END);
   for (i=0;i<n;i++)
   {
    fwrite(&power[i], sizeof(people), 1, f);
   }
   fclose(f);
  }
 }
 else
 {
  f = fopen(namefile, "wb");
  for (i=0;i<n;i++)
  {
   fwrite(&power[i], sizeof(people), 1, f);
  }
  fclose(f);
 }
}

void odin(int a)
{
 cout << "Магазин,  номер "    << a               << endl
      << "Название магазина: " << power[a].store  << endl
      << "Название товара: "   << power[a].goods  << endl
      << "Стоимость: "         << power[a].price  << " руб." << endl;
}

void find()
{
 system("clear");
 char namestore[15];
 cout << "Введите название магазина: ";
 cin  >> namestore;
 for (i = 0; i<n; i++)
 {
  if (strcmp(namestore, power[i].store)==0)
  {
   for (i=0;i<n;i++)
   odin(i);
  }
  else
  {
   printf("Магазин не найден");
  }
 }
 system("pause");
}

void add()
{
 system("clear");
 if (n==(lim-1))
 printf("Заполнено!\n");
 else
 {
  cout << "Магазин,  номер " << n << endl
       << "Введите название магазина: ";
  cin  >> power[n].store;
  cout << "Введите название товара: ";
  cin  >> power[n].goods;
  cout << "Введите цену: ";
  cin  >> power[n].price;
  n++;
 }
}

void all()
{
 system("clear");
 if (n==0)
 cout << "Не найдено ни одного магазина!\n";
 else
 for (i=0;i<n;i++)
 odin(i);
}

void loading()
{
 FILE *f = NULL;
 system("clear");
 cout << "Введите название файла: ";
 cin  >> namefile;
 f = fopen(namefile, "rb");
 fseek(f, 0, SEEK_END);
 int z = ftell(f);
 cout << "Размер: " << z << endl;
 fseek(f, 0, SEEK_SET);
 cout << z/sizeof(people);
 for (i=0;i<z/sizeof(people);i++)
 {
  fread(&power[i], sizeof(people), 1, f);
  cout << "Магазин, номер "     << i              << endl
       << "Название магазина: " << power[i].store << endl
       << "Название товара: "   << power[i].goods << endl
       << "Цена: "              << power[i].price << endl;
 }
 fclose(f);
 system("pause");
}

void sort()
{
 people h;
 int k = 1, c = 3;
 while(k==1)
 {
  k = 0;
  for (int i = 0; i<c-1; i++)
  {
   if (strcmp(power[i].store, power[i+1].store)>0)
   {
    h = power[i];
    power[i] = power[i+1];
    power[i+1] = h;
    k = 1;
   }
  }
 }
}


int menu()
{
 int d;
 system("clear");
 printf("1 - сохранить в файл\n");
 printf("2 - загрузить из файла\n");
 printf("3 - поиск по названию магазина\n");
 printf("4 - добавить магазин\n");
 printf("5 - показать все магазины\n");
 printf("6 - сортировка магазинов\n");
 printf("7 - выход\n");
 printf("Введите цифру: ");
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
          save();
          break;
   case 2:
          loading();
          system("pause");
          break;
   case 3:
          find();
          break;
   case 4:
          add();
          break;
   case 5:
          all();
          system("pause");
          break;
   case 6:
          sort();
          break;
   case 7:
          return 0;
  }
 }
 return 0;
}
