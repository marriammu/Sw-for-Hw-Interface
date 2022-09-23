#include <stdio.h>
#include <stdlib.h>

int main()
{ double result = 1.0;
int Exponent;
int IterationNumber;
int PoweredExponent = 1;
double factorial=1.0;
printf("\n Please enter the exponent : \n");
scanf("%d",&Exponent);
printf("\n Please enter the number of iterations : \n");
scanf("%d",&IterationNumber);
printf(" Tailor Expansion : \n");
for (int i =0 ; i<=IterationNumber ; i ++){
    factorial = (1+i)*factorial;
    printf(" (%d",Exponent);
    printf("^");
    printf("%d",i);
    printf(")/");
    printf("%d",i);
    printf("! +");
    PoweredExponent= Exponent*PoweredExponent;
    float AddedTerm = PoweredExponent/factorial;
    result= result+ AddedTerm;

  }
  printf(" ..............\n \n");
  printf(" The Result: \n");
  printf("%f \n",result);
}
