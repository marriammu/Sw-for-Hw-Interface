#include "EXTI.h"

void Interrupt_Mask_REG(char PinNum){
	*(EXTI_IMR) |=(0x01<<PinNum);
}
void Falling_Edge(char PinNum)
{
	*(EXTI_FTSR) |=(0x01<<PinNum);
}
void Pending_REG(char PinNum)
{
	*(EXTI_PR)|=(0x01<<PinNum);
}