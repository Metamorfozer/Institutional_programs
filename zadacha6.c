#include <stdio.h>

int i,j,n;
int a[50][50];
int main()
{
        printf("Введите n: ");
        scanf("%d", &n);
        for (i=0; i<n; i++)
        {
                for (j=0; j<n; j++)
                {
                        if (i==j)
                                a[i][j]=1;
                        else
                        if (i>j)
                        {
                                a[i+1][j]=a[i][j]+1;
                                a[i][j]=a[i][j]+1;
                                a[i][j]=a[i][j]+1;
                        }
                        else
                        if (i<j)
                        {
                                a[i][j+1]=a[i][j]+1;
                                a[i][j]=a[i][j]+1;
                                a[i][j]=a[i][j]+1;
                        }
                        printf(" %d ", a[i][j]);
                }
                printf("\n\n");
        }
        return 0;
}
