#include <stdio.h>
#include <stdlib.h>

int main()
{
 float x,y;
 int oa,ob,p,k,lt,pt,v;
 printf("\nVvedite koordinatu x: ");
 scanf("%f",&x);
 printf("\nVvedite koordinatu y: ");
 scanf("%f",&y);
 oa=(((x*x+y*y)<1)&&(y>0));
 ob=(((x*x+y*y)<=1)&&(y<=0));
 p=((x>=-1)&&(x<1)&&(y>-4)&&(y<0));
 k=((x>=-1)&&(x<=1)&&(y>=0)&&(y<=2));
 lt=((x>=-3)&&(x<=-1)&&(y>=0)&&(y<=2)&&(((x/-3)+(y/2))<=1));
 pt=((x>=1)&&(x<=3)&&(y>=0)&&(y<=2)&&(((x/3)+(y/2))<=1));
 v=((x>=-3)&&(x<=3)&&(y>=-9)&&(y<=0)&&(((x*x)-y-9)<=0));
 if (lt || pt || (k&&!oa) || (v&&!p) || ob)
   printf("Da\n");
 else
   printf("Net\n");
 return 0;
}