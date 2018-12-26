#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;

int i, m, n=3;

struct number
{
        int numer;
        float temp;
};

number files[10];
int main()
{
        system("clear");
        FILE *f;
        f = fopen("A.txt", "wb");
        for (i = 0; i<n; i++)
        {
                cout << "Enter natural number: ";
                cin  >> files[i].numer;
        }
        for (i=0; i<n; i++)
                fwrite(&files[i], sizeof(number), 1, f);
        fclose(f);
        system("clear");
        cout << "Enter number m: ";
        cin  >> m;
        f = fopen("A.txt", "r");
        fseek(f, 0, SEEK_END);
        int z = ftell(f);
        int s = 0;
        fseek(f, 0, SEEK_SET);
        for (i=0; i<z/sizeof(number); i++)
        {
                fread(&files[i], sizeof(number), 1, f);
                if ((files[i].numer % m)==0)
                {
                        files[s].temp = files[i].numer;
                        s++;
                }
        }
        fclose(f);
        f = fopen("B.txt", "wb");
        for (i=0; i<s; i++)
                fwrite(&files[i], sizeof(number), 1, f);
        fclose(f);
        f = fopen("B.txt", "r");
        fseek(f, 0, SEEK_END);
        int b = ftell(f);
        fseek(f, 0, SEEK_SET);
        for (i=0; i<s; i++)
        {
                fread(&files[i], sizeof(number), 1, f);
                cout << files[i].temp << endl;
        }
        fclose(f);
}
