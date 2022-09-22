#include <stdio.h>
#include <stdlib.h>

int main()
{
 for (int j =0; j <9;j++)
 {
     printf("           ");
     for (int i=0;i<9;i++)
     {
        if (i==-j+4||i==j+4 ||i==j-4 ||i==-j+12)
         {

             printf("*");

         }
        else if (i>=-j+4 && i<=j+4&&i>=j-4 &&i<=-j+12){
                printf("*");
             }
        else printf(" ");
     }
     printf("\n");
 }
}