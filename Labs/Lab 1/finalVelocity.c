#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int u;
    int a;
    int t;
    printf(" please enter the initial velocity \n");
    scanf("%d",&u);
    printf(" please enter the acceleration  \n");
    scanf("%d",&a);
    printf(" please enter the time \n");
    scanf("%d",&t);
    int v = u + a*t;
    printf("\n The final Velocity is : %d",v);
    float s = u*t + 0.5*a*t*t;
    printf("\n The distance traversed is : %f \n",s);
}