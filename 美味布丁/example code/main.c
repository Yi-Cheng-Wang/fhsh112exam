#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a1,b1,c1,d1,e1,a2,b2,c2,d2,e2,a3,b3,c3,d3,e3,min;
    scanf("%d %d %d %d %d %d %d %d %d %d",&a1,&b1,&c1,&d1,&e1,&a2,&b2,&c2,&d2,&e2);
    a3=a2/a1;
    b3=b2/b1;
    c3=c2/c1;
    d3=d2/d1;
    e3=e2/e1;
    min=a3;
    if (min > b3) min=b3;
    if (min > c3) min=c3;
    if (min > d3) min=d3;
    if (min > e3) min=e3;
    printf("%d",min*(a1+b1+c1+d1+e1));
    return 0;
}
