#include <math.h>
#include <stdio.h>

void main()
{
        int i;
        float n, a, S;
        printf("\nВведите n: ");
        scanf("%f",&n);
        printf("\nВведите a: ");
        scanf("%f",&a);
        {
                S=1/a;
                for (i=2; i<=n; i++)
                        S+=1/a*a;
        }
        printf("S = %f\n", S);
}
