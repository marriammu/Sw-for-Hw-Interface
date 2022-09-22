
#include "Peripherals.h"
#include<string.h>
// GPIO
unsigned int* look_up[2][5]={
		                     {GPIOA_MODER,GPIOA_OTYPER,GPIOA_PUPDR,GPIOA_IDR ,GPIOA_ODR},
		                     {GPIOB_MODER,GPIOB_OTYPER,GPIOB_PUPDR,GPIOB_IDR ,GPIOB_ODR}
                            };
void GPIO_EnableClock(char PortID) {
	if (PortID==0)
	{
//	*((unsigned int *) 0x40023830) |= (0x01 << 0);
	*( GPIO_RCCENR) |= (0x01 << 0);
	}
	if (PortID==1)
	{
//	*((unsigned int *)  0x40023830) |= (0x01 << 1);
	*( GPIO_RCCENR) |= (0x01 << 1);
	}
}
void GPIO_Init(unsigned char PortID, unsigned char PinNum, unsigned char PinMode,
              unsigned char DefaultState) {
	*(look_up[PortID][0]) &= ~(0x03 << 2 * PinNum);
	*(look_up[PortID][0]) |= PinMode << 2 * PinNum;
	*(look_up[PortID][1]) &= ~(1 << PinNum);
	*(look_up[PortID][1])|= ((DefaultState & _OUTTYPE_MASK) >> _OUTTYPE_SHIFT) << PinNum;
	*(look_up[PortID][2]) &= ~(0x03 << 2 * PinNum);
	*(look_up[PortID][2]) |= ((DefaultState & _PUPD_MASK) >> _PUPD_SHIFT) << (2 * PinNum);
}
void GPIO_Alternate(){
	*(GPIOA_Alternate) |=(0x07<< 2*4);
}
unsigned char GPIO_WritePin(unsigned char PortID, unsigned char PinNum,
                           unsigned char Data) {
 unsigned char result;

     if (((*(look_up[PortID][0]) & (0x03 << 2 * PinNum)) >> (2 * PinNum)) == 1) {
       if (Data) {
         *(look_up[PortID][4]) |= (1 << PinNum);
       }
       else {
          *(look_up[PortID][4]) &= ~(1 << PinNum);
       }
       result = OK;
     }
     else {
       result = NOK;
     }

  // end switch

 return result;
}
unsigned char GPIO_ReadPin(unsigned char PortID, unsigned char PinNum) {
 unsigned char data = 0;


     data = (*(look_up[PortID][3]) & (1 << PinNum)) >> PinNum;

 return data;
}
// UART
void UART_EnableClock(char PinNum){
	*(RCC_APB1ENR) |= (0x01 << PinNum);
}

void UART_Init(){
	*(USART_CR1)|=(0x01<<13);
	*(USART_CR1) |= (0x01<<3);
	*(USART_BRR)  = 0x683;
	*(USART_CR1) &= ~(0x01<<15);
	*(USART_CR1) &= ~(0x01<<12);
	*(USART_CR2) &= ~(0x01<<12);

	}
void UART_Transmit( char * str){

for (int i=0;i<strlen(str);i++)
{
	*(USART_DR) = str[i];
while (((*(USART_SR)>>6)&1)==0){}
}}

// Interrupt
void SYSCFG_clock(char PinNum) {

	*( RCC_APB2ENR) |= (0x01 << PinNum);
}
 void Enable_External_Interrupt(char PinNum){

	*(SYSCFG_EXTICR1) &= ~(0x0F<<(PinNum*4));
 }
 void Interrupt_Mask_REG(char PinNum){
	 *(EXTI_IMR) |=(0x01<<PinNum);
 }
 void Falling_Edge(char PinNum)
 {
	 *(EXTI_FTSR) |=(0x01<<PinNum);
 }
 void NVIC_INPUT()
 {
	 *(NVIC_ISER)|=(0x01<<0x06);

 }
 void Pending_REG(char PinNum)
 {
	 *(EXTI_PR)|=(0x01<<PinNum);
 }

