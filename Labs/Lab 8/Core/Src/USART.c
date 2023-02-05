#include "USART.h"
#include "RCC.h"
void UART_EnableClock(char PinNum){
	*(RCC_APB1ENR) |= (0x01 << PinNum);
}

void UART_Init(){
	*(USART_CR1)|=(0x01<<13); // UART Enabeled Check
	*(USART_CR1) |= (0x01<<3); // Transmitter Enabeled Check
	*(USART_BRR)  = 0x683; // BuadRate
	*(USART_CR1) &= ~(0x01<<15); //Oversampling Mode
	*(USART_CR1) &= ~(0x01<<12); // WordLength
	*(USART_CR2) &= ~(0x01<<12); // Stop bits

	}
void UART_Transmit( char * str){

for (int i=0;i<strlen(str);i++)
{
	*(USART_DR) = str[i];
while (((*(USART_SR)>>6)&1)==0){}
}}
