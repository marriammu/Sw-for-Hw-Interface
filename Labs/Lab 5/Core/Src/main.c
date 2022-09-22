
#include "GPIO.h"

void delay30ms()
{
  unsigned int i;
  for (i = 0; i < 30000; i++){}
}

int main(void)
{
  unsigned char i;

  GPIO_EnableClock('A');
  GPIO_EnableClock('B');

  for (i = 0; i < 7; i++)
  {
    GPIO_Init('A', i, OUTPUT,PUSH_PULL);
  }
	KeyPad_Init();
 while (1)
 {
  	KeyPad_Manage();
}
  return 0;
}

void KeyPad_CallOut_ButtonPressed_Notification()
{
	 char number= KeyPad_Getkey();
	 for (int seg = 0; seg < 7; seg++)
	 GPIO_WritePin('A', seg, (number & (1 << seg)) >> seg);
}
