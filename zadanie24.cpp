#include "string.h"
#include "iostream"
#include "conio.h"
using namespace std;
const int n = 100;
int main()
{
        int count = 0, min = 1000;
        char res[n],  s[n], temp[n];
        cout << "Enter string: ";
        gets(s);
        strcpy(temp, s);
        for(char *p = strtok(s, " ,."); p; p = strtok(NULL, " ,."))
        {
                if(strlen(p) < min)
                {
                        min = strlen(p);
                        strcpy(res,p);

                }
        }
        min = 1000;
        for(char *p = strtok(temp, " ,."); p; p = strtok(NULL, " ,."))
        {
                if(strlen(p) == strlen(res))
                {
                        count++;
                }
        }
        cout << "\nSamoe korotkoe slovo: " << res << ", vstrechaetsya " << count << " raz";
        return 0;
}
