#include "EXTI.h"


 void Interrupt_Mask_Enable(char PinNum){
	 *(EXTI_IMR) |=(0x01<<PinNum);
 }
 void Interrupt_Mask_Disable(char PinNum){
	 *(EXTI_IMR) |= (0x00<<PinNum);
 }
void Falling_Edge(char PinNum)
{
	*(EXTI_FTSR) |=(0x01<<PinNum);
}
void Pending_REG(char PinNum)
{
	*(EXTI_PR)|=(0x01<<PinNum);
}