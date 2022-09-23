

#include "GPIO.h"
#include "RCC.h"
#include "NVIC.h"
#include "EXTI.h"
#include "SYSCFG.h"

void Seg_Incremet();

int counter=0;
unsigned char sevenSegHex[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66,
                                 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
extern unsigned int* look_up[2][5];
void delay30ms()
{
  unsigned int i;
  for (i = 0; i < 30000; i++){}
}


int main(void)
{


  GPIO_EnableClock(0);
  GPIO_EnableClock(1);

  GPIO_Init(1,0, INPUT,PULL_UP);
  GPIO_Init(1,1, INPUT,PULL_UP);

  for(int i=0;i<7;i++)
  {
  GPIO_Init(0,i, OUTPUT,PUSH_PULL);
  }
  for (int i = 0; i < 7; i++)
    GPIO_WritePin(0, i, (sevenSegHex[0] & (1 << i)) >> i);
	 SYSCFG_clock(14);
	 Enable_External_Interrupt(0);
	 Enable_External_Interrupt(1);
	 Falling_Edge(0);
	 Falling_Edge(1);
	  NVIC_INPUT();

int localCounter;
 while (1)
 {
	 Interrupt_Mask_Enable(0);
	 Interrupt_Mask_Enable(1);
	 localCounter=counter;
	 Interrupt_Mask_Disable(0);
	 Interrupt_Mask_Disable(1);
	 for (int i = 0; i < 7; i++) {
	      GPIO_WritePin(0, i, (sevenSegHex[localCounter] & (1 << i)) >> i);

	      Pending_REG(0);
	 }
}
  return 0;
}

void Seg_Increment()
{
	Interrupt_Mask_Disable(1);

    if (counter==9)
    	counter =9;
    else
    counter++;
	Interrupt_Mask_Enable(1);
}
void Seg_Decrement()
{
Interrupt_Mask_Disable(0);
	
	  if (counter==0)
	     	counter =0;
	     else
	    counter--;
Interrupt_Mask_Enable(0);
}

