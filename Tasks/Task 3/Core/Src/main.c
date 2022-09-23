#include "GPIO.h"
#include "stm32f401xc.h"
#include "stm32f401cc_interface.h"

int main(void) {

		GPIO_Init('B', 5, OUTPUT, PUSH_PULL);
		GPIO_Init('B', 6, OUTPUT, PUSH_PULL);
		GPIO_Init('B', 7, OUTPUT, PUSH_PULL);
		GPIO_Init('B', 3, INPUT, PULL_UP);
		GPIO_WritePin('B', 5,1);
		GPIO_WritePin('B', 6,1);
		GPIO_WritePin('B', 7,1);

		 char i = 0;
		 char ButtonSatus1;
		 char ButtonSatus2;
  while (1) {
      ButtonSatus1=GPIO_ReadPin('B',3);
      if (  ButtonSatus1==1 ){
    	    for (int n=0;n<2000;n++)
    	    {}

    	    ButtonSatus2=GPIO_ReadPin('B',3);
    	      if ( ButtonSatus2==0){
    	    	  GPIO_WritePin('B', 5,i&0x01);
    	    	  GPIO_WritePin('B', 6,i&0x02);
    	    	  GPIO_WritePin('B', 7,i&0x04);

                      i++;
    	      }
      }

  }
  return 0;
}
