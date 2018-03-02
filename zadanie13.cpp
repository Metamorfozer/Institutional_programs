#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<windows.h>
using namespace std;

int i,n = 0;
char namefile[15];
const int lim = 10;
struct pupil
{
 char magazine[30];
 char tovar[30];
 float cena;
};

pupil cat[lim];
void save()
{
 system("cls");
 FILE *f = NULL;
 int i;
 cout << "Введите название файла: ";
 cin  >> namefile;
 f = fopen(namefile, "wb");
 for (i=0;i<n;i++)
 {
  fwrite(&cat[n], sizeof(pupil), 1, f);
 }
 fclose(f);
}

void find()
{
 FILE *f = NULL;
 system("cls");
 cout << "Введите название файла: ";
 cin >> namefile;
 f = fopen(namefile, "rb");
 if (f!=NULL)
 {
 fseek(f, 0, SEEK_SET);
 int z=ftell(f);
 char namemagazine[15];
 system("cls");
 cout << "Введите название магазина: ";
 cin  >> namemagazine;
 for(i=0;i<(z/sizeof(pupil));i++)
 {
  cout << "Дошло.";
  if (strcmp(namemagazine, cat[n].magazine)==0)
  {
   fread(&cat[i], sizeof(pupil), 1, f);
   cout << "Магазин, номер "     << n               << endl
        << "Название магазина: " << cat[n].magazine << endl
        << "Название товара: "   << cat[n].tovar    << endl
        << "Стоимость: "         << cat[n].cena     << endl;
  }
  else
  {
  printf("Магазин не найден");
  fclose(f);
  }
  fclose(f);
 }
 }
 else
 {
  cout << "Такой файл не существует!\n";
 }
}

void add()
{
 system("cls");
 if (n==(lim-1))
 printf("Каталог заполнен\n");
 else
 {
  n++;
  cout << "Магазин, номер "     << n          << endl
       << "Введите название магазина: ";
  cin  >> cat[n].magazine;
  cout << "Введите название товара: ";
  cin  >> cat[n].tovar;
  cout << "Введите стоимость: ";
  cin  >> cat[n].cena;
 }
}

void odin(int n)
{
 n++;
 cout << "Магазин, номер "     << n               << endl
      << "Название магазина: " << cat[n].magazine << endl
      << "Название товара: "   << cat[n].tovar    << endl
      << "Стоимость: "         << cat[n].cena << " руб." << endl;
}

void all()
{
 system("cls");
 if (n==0)
 cout << "Не добавлен ни один магазин!\n";
 else
 for (i=0;i<n;i++)
 odin(i);
}

void loading()
{
 FILE *f = NULL;
 cout << "Введите название файла: ";
 cin  >> namefile;
 f = fopen(namefile, "rb");
 fseek(f, 0, SEEK_END);
 int z = ftell(f);
 cout << "Размер: " << z << endl;
 fseek(f, 0, SEEK_SET);
 int g = 1;
 n = n - 1;
 for (i=0;i<z/sizeof(pupil);i++)
 {
  fread(&cat[i], sizeof(pupil), 1, f);
  cout << "Магазин, номер "     << g              << endl
       << "Название магазина: " << cat[n].magazine << endl
       << "Название товара: "   << cat[n].tovar    << endl
       << "Стоимость: "         << cat[n].cena     << endl;
  n++;
  g++;
 }
 fclose(f);
 system("pause");
}

int menu()
{
 int d;
 system("cls");
 printf("1 - сохранить в файл\n");
 printf("2 - загрузить из файла\n");
 printf("3 - поиск товара по названию магазина\n");
 printf("4 - добавить магазин\n");
 printf("5 - показать все магазины\n");
 printf("6 - выход\n");
 scanf("%d", &d);
 return d;
}

int main()
{
 setlocale(LC_ALL, "rus");
 setlocale(LC_ALL,"Russian");
 SetConsoleCP(1251);
 SetConsoleOutputCP(1251);
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
         system("pause");
         break;
  case 4:
         add();
         break;
  case 5:
         all();
         system("pause");
         break;
  case 6:
         return 0;
 }
 }
 return 0;
}