#include <stdio.h>

int main()
{
 const int m=5, n=5;
 int a[m][n];
 int i, j, jmin, imax, jmax;
 
 srand(time(NULL));
 
 for (i=0;i<n; i++)
 {
  for (j=0; j<m; j++)
  {
    a[i][j]=rand() % 30;
    printf("%4d ", a[i][j]);
  }
 printf("\n");
 }
 
 imax = 1;
 jmax = 1;
 
 for (j=0;j<n; j++)
   if (a[1][jmax] > a[1][j])
   {
     jmax = j;
   }
   for (i=0;i<n; i++)
   {
     jmin = 1;
     for (j=0;j<n; j++)
       if (a[i][jmin] > a[i][jmin])
       {
	 imax = i;
	 jmax = jmin;
       }
   }
     
 /*for (i=0;i<m; i++)
 {
  for (j=0; j<n; j++)
  {
   a[i][j]=rand() % 30;
   printf("%4d ", a[i][j]);
  }
  printf("\n");
 }
 printf("\n");
 
   imax = 1;
   jmax = 1;
   
   for (j=0;j<n;j++)
    if (a[imax][jmax]>a[i][j])
     jmax=j;
     for (i=0;j<m;i++)
     {
      jmin=1;
      for (j=0;j<n;j++)
      if (a[i][jmin]>a[i][j])
      jmin=j;
      if (a[imax][jmax]<a[i][jmin])
      {
       imax=i;
       jmax=jmin;
      }
     }*/
     printf("Максимальный среди минимальных в позиции: %d,%d\n", imax, jmax);
     return 0;
}