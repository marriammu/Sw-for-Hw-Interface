
#include "GPIO.h"
#include "Keypad.h"

int keymap[4][3] = {
		{0x06, 0x5B,0x4F},
		{0x66,0x6D,0x7D},
		{0x07, 0x7F ,0x6F},
		{0x3F,0x3F,0x3F}
};
char state=0;
char key;



extern void KeyPad_Init()
{
	  for(int Col=0;Col<3;Col++)
	  	{
	  	  GPIO_Init('B', Col, OUTPUT, PUSH_PULL);
	  	}
	  	for (int Row = 0; Row < 4; Row++)
	  	{
	  	    GPIO_Init('B', Row+3, INPUT,PUll_UP);
	  	}

}
extern void KeyPad_Manage()
{

	if(state==0)
	{
		for(int i=0;i<3;i++)
		{
			GPIO_WritePin('B',i,0);

			for(int j=0;j<4;j++)
			{
				if(!GPIO_ReadPin('B',j+3))
					{
					state=1;
					key=keymap[j][i];
					KeyPad_CallOut_ButtonPressed_Notification();
					}
			}
			GPIO_WritePin('B',i,1);
	     }

	}
}
extern char KeyPad_Getkey()
{
	if(state==1)
	{
	state=0;
	return key;
	}
	else
		return -1;
}




