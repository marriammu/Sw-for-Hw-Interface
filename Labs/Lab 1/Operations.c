#include <stdio.h>
#include <stdlib.h>

int main ()
{
    
    int num1, num2, num3;

    printf("please enter the first number: \n");
    scanf("%d",&num1);
    printf("please enter the second number: \n");
    scanf("%d",&num2);
    printf("please enter the third number: \n");
    scanf("%d",&num3);
    printf("Sum is: %d\n", num1 + num2 + num3);
    printf("Average is: %lf\n", (num1 + num2 + num3) / 3.0);
    printf("Product is: %d\n", num1 * num2 * num3);
    printf("Largest is: %d\n", num1 > num2 ? (num1 > num3 ? num1 : num3) : (num2 > num3 ? num2 : num3));
    printf("Smallest is: %d\n", num1 < num2 ? (num1 < num3 ? num1 : num3) : (num2 < num3 ? num2 : num3));
    return 0;

}