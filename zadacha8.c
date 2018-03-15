#include <stdio.h>
#include <string.h>

int main()
{
        char s[50];
        int i;
        printf("\nСтрока: ");
        scanf("%s", s);
        for (i=0; i<=strlen(s); i++)
        {
                if (s[i] == '(')
                {
                        //for (i=i+1;i<=strlen(s);i++)
                        printf("\nВывод: ");
                        i=i+1;
                        while (s[i] != ')')
                        {
                                printf("%c", s[i]);
                                i=i+1;
                        }
                }
        }
        printf("\n");
        return 0;
}
