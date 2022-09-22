
#include "GPIO.h"
#include "RCC.h"
#include "EXTI.h"
#include "NVIC.h"
#include "SYSCFG.h"
void Toggle_LED();
extern unsigned int* look_up[2][5];
void delay30ms()
{
  unsigned int i;
  for (i = 0; i < 30000; i++){}
}


int main(void)
{


  GPIO_EnableClock(0);

  GPIO_Init(0,0, INPUT,PULL_UP);
  GPIO_Init(0,1, OUTPUT,PUSH_PULL);
	SYSCFG_clock(14);
	Enable_External_Interrupt(0);
	Interrupt_Mask_REG(0);
	Falling_Edge(0);
	NVIC_INPUT();


 while (1)
 {



}
  return 0;
}

void Toggle_LED()
{

*(look_up[0][4])^= 0x01<<1;
Pending_REG(0);
}
