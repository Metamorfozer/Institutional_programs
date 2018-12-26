#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
        float x,y;
        printf("\nВведите х:");
        scanf("%f", &x);
        printf("\nВведите у:");
        scanf("%f", &y);
        float z1 = cos(x)*cos(x)*cos(x)*cos(x) + sin(y)*sin(y) + 1.0/4.0*sin(2*x)*sin(2*x)-1;
        float z2 = sin(y+x)*cos(y-x);
        printf("\nz1 = %f\nz2 = %f\n", z1, z2);
        return 0;
}

