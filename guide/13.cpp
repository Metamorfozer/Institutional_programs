#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

struct pupil
{
 char surname[30];
 int growth;
 float weight;
};

int main()
{
 FILE *f = NULL;
 pupil a;
 int i,n=0;
 system("clear");
 f = fopen("c_class.dat", "wb");
 for (i=0;i<3;i++)
 {
  n++;
  cout << "Ученик, номер " << n << "\n";
  cout << "Введите фамилию: ";
  cin >> a.surname;
  cout << "Введите вес: ";
  cin >> a.weight;
  cout << "Введите рост: ";
  cin >> a.growth;
  fwrite(&a, sizeof(pupil), 1, f);
 }
 fclose(f);
 f = fopen("c_class.dat", "rb");
 fseek(f, 0, SEEK_END);
 int z = ftell(f);
 cout << "Размер: " << z << endl;
 fseek(f, 0, SEEK_SET);
 n = 0;
 for (i=0;i<z/sizeof(pupil);i++)
 {
  n++;
  fread(&a, sizeof(pupil), 1, f);
  cout << "Ученик, номер " << n    << endl
       << "Фамилия: " << a.surname << endl
       << "Вес: "     << a.weight  << endl
       << "Рост: "    << a.growth  << endl;
 }
 fclose(f);
 return 0;
}
