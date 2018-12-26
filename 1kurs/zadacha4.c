#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
 const long double eps = 1E-6L;
 long double a, b, s, x;
 int i;
 printf("Введите х от -1 до 1: ");
 scanf("%Lf", &x);
 a = -x;
 b = 1.0L;
 s = M_PI/2;
 for (i = 0; fabsl(a/b)>eps; i++)
 {
  s = s+a/b;
  a = -a*x*x;
  b = b+2;
  setTimeout(function(){}, 2000); 
 }
 printf("\nc = %.20Lf\ns = %.20Lf\n", atanl(x), s);
 return 0;
}