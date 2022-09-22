#include <stdio.h>
#include <stdlib.h>

int main()
{
   
    unsigned char number, theRotatedNumber;
    int rotateCycles;
    char direction;
    printf("Enter the 8bit number:\n");
    scanf("%d", &number);
    printf("Enter the number of rotate cycles:\n");
    scanf("%d", &rotateCycles);
    printf("Enter the rotate direction l or r:\n");
    scanf(" %c", &direction);
    switch (direction)
    {
    case 'l':
        theRotatedNumber = (number << rotateCycles) | (number >> 8 - rotateCycles);
        break;
    case 'r':
        theRotatedNumber = (number >> rotateCycles) | (number << 8 - rotateCycles);
        break;
    }
    printf("%d\n", theRotatedNumber);

}
