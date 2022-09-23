#include "stm32f401cc_interface.h"

int main(void) {
	RCC_AHB1ENR |=(1<<1);
	GPIOB_MODER &= ~((0x03)<<(2*3));
	GPIOB_MODER |= ((0x15)<<(2*5));
	GPIOB_OTYPER &= ~(7<<5);
	GPIOB_ODR  |=(7<<5);
	GPIOB_PUPDR |= ((0x01)<<(2*3));
	 char i = 0;
	 char ButtonSatus1;
	 char ButtonSatus2;
  while (1) {
      ButtonSatus1 = GPIOB_IDR>>3 & 1 ;
      if (  ButtonSatus1==1 ){
    	    for (int n=0;n<2000;n++)
    	    {}
    	    ButtonSatus2=GPIOB_IDR>>3 & 1;
    	      if ( ButtonSatus2==0){
    	    	  GPIOB_ODR  &=~(7<<5);
    	    		GPIOB_ODR  |=(i%8<<5);
                      i++;
    	      }
      }

  }
  return 0;
}

