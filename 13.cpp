#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct pupil
{
 char surname[30];
 int grade;
 float weight;
};

int main()
{
 FILE *f=NULL;
 pupil a;
 int i;
 system("clear");
 f=fopen("c_class.dat","wb");
 for(i=0;i<3;i++)
 {
   cout<<"Введите фамилию: ";
   cin>>a.surname;
   cout<<"Введите класс: ";
   cin>>a.grade;
   cout<<"Введите вес:";
   cin>>a.weight;
   fwrite(&a,sizeof(pupil),1,f);
 }
 fclose(f);
 f=fopen("c_class.dat","rb");
 fseek(f,0,SEEK_END);//SEEK_SET относительно начала  SEEK_CUR текущей позиции  SEEK_END относительно конца,
 int z=ftell(f);
 cout<<"размер: "<<z<<endl;
 fseek(f,0,SEEK_SET);
 for(i=0;i<(z/sizeof(pupil));i++)
 {
   fread(&a,sizeof(pupil),1,f);
   cout<<a.surname<<endl<<a.grade<<endl<<a.weight<<endl<<endl;
 }
 fclose(f);
 return 0;
}
