#include <string.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

const int n = 100;
int main()
{
        system("clear");
        int count = 0, min = 1000; //count - счётчик слов, min - минимальная длина слова
        char res[n],  s[n];
        FILE *f;
        char *estr;
        f = fopen("1.txt", "r");
        while (!(feof(f)))
        {
                estr = fgets(s, sizeof(s), f);
                if (estr == NULL)
                        if (feof(f)!=0)
                        {
                                break;
                        }
                        else
                        {
                                cout << "\nОшибка чтения из файла\n";
                        }
                for (char *p = strtok(s, " ,."); p; p = strtok(NULL, " ,."))//strtok разбиение строки на части, в первом аргументе указатель на разбиваемую строку в качестве второго аргумента принимает массив символов для разделителей
                {
                        if(strlen(p) < min)//Если длина слова p меньше минимальной длины, то
                        {
                                min = strlen(p);//Присвоить к переменной min длинну слова p
                                strcpy(res,p);//Скопировать слово p в (самое короткое слово) res
                        }
                }
        }
        fclose(f);
        f = fopen("1.txt", "r");
        min = 1000;//Заново присваиваем к переменной min 1000, как в начале
        while (!(feof(f)))
        {
                estr = fgets(s, sizeof(s), f);
                if (estr == NULL)
                        if (feof(f)!=0)
                        {
                                break;
                        }
                        else
                        {
                                cout << "\nОшибка чтения из файла\n";
                        }
                for (char *p = strtok(s, " ,."); p; p = strtok(NULL, " ,."))//проходимся по строке второй раз, узнать сколько рах встречается самое короткое слово
                { if(strlen(p) == strlen(res))
                  { count++;//Счётчик слова
                  }  }
        }
        fclose(f);
        count = count - 1;
        cout << "Самое короткое слово " << res << ", встречается " << count << " раз\n";
        return 0;
}
