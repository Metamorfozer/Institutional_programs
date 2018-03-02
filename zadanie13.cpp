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
 FILE *f = NULL;
 int i;
 cout << "Введите название файла: ";
 cin  >> namefile;
 f = fopen(namefile, "wb");
 for (i=0;i<n;i++)
 {
  fwrite(&power[n], sizeof(people), 1, f);
 }
 fclose(f);
}

void odin(int n)
{
 n++;
 cout << "Магазин,  номер "    << n               << endl
      << "Название магазина: " << power[n].store << endl
      << "Название товара: "   << power[n].goods    << endl
      << "Стоимость: "         << power[n].price << " руб." << endl;
}

void find()
{
 system("clear");
 char namestore[15];
 cout << "Введите название магазина: ";
 cin  >> namestore;
 n = 1;
 for (i = 0; i<lim; i++)
 {
  n++;
  if (strcmp(namestore, power[n].store)==0)
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
  n++;
  cout << "Магазин,  номер "     << n          << endl
       << "Введите название магазина: ";
  cin  >> power[n].store;
  cout << "Введите название товара: ";
  cin  >> power[n].goods;
  cout << "Введите цену: ";
  cin  >> power[n].price;
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
 int g = 1;
 n = n - 1;
 for (i=0;i<z/sizeof(people);i++)
 {
  fread(&power[i], sizeof(people), 1, f);
  cout << "Магазин, номер"      << g               << endl
       << "Название магазина: " << power[n].store << endl
       << "Название товара: "   << power[n].goods    << endl
       << "Цена: "              << power[n].price     << endl;
  n++;
  g++;
 }
 fclose(f);
 system("pause");
}
/*
void sort()
{
 int counter = 0;
 n = 0;
 int j = 1;
 for (int i = 1; i < n; i++)
 {
  for ( j = i; j > 0 && power[n-1].store > power[n].store ;j++ )
  {
   n++;
   counter++;
   char tmp[15] = power[n-1].store;
   power[n-1].store = power[n].store;
   power[n].store = tmp;
  }
 }
 cout << counter << endl;
}
*/

int menu()
{
 int d;
 system("clear");
 printf("1 - сохранить в файл\n");
 printf("2 - загрузить из файла\n");
 printf("3 - поиск по названию магазина\n");
 printf("4 - добавить магазин\n");
 printf("5 - показать все магазины\n");
 //printf("6 - сортировка магазинов");
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
          //system("pause");
          break;
   case 4:
          add();
          break;
   case 5:
          all();
          system("pause");
          break;
   /*case 6:
          sort();
          system("pause");
          break;*/
   case 7:
          return 0;
  }
 }
 return 0;
}
