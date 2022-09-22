#include <stdio.h>
#include <stdlib.h>

int main()
{
int x = 0;
int y = 0;
int z=0;
int size;
printf("Please Enter the number of the series terms :\n ");
scanf("%d",&size);
 for(int num=0; num<=size;num++)
 {

    if (num==0){
        x=num;
        printf("%d",num);
       printf(",");
        }
     else if (num==1) {
            y=num;
         printf("%d",y);
         printf(",");
}
else {
        z=x+y;
        x=y;
        y=z;

 printf("%d",z);
         printf(",");
}
}
printf("......... \n");
}
