#include <stdio.h>
#include <stdlib.h>
#include <math.h>
const long double eps = 1E-6L;
int main()
{
        long double a = 1.0L, sum = a,x;
        int n = 0;
        system("clear");
        scanf("%Lf", &x);
        while(fabsl(a)>eps && n<100)
        {
                n++;
                a*=x/n;
                sum+=a;
        }
        printf("exp=%.20Lf\nsum=%.20Lf\n", expl(x), sum);
        return 0;
}
