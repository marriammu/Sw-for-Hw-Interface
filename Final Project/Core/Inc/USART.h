#ifndef USART_H
#define USART_H


#define DEFINE_REG(PORT_ID,REG_ID) ((unsigned int*)(PORT_ID+REG_ID))


#define USART_SR (DEFINE_REG(0x040004400,0x00)) // Status Register
#define USART_DR (DEFINE_REG(0x040004400,0x04)) // Data Register
#define USART_CR1 (DEFINE_REG(0x40004400,0x0C)) // Control Register 1
#define USART_CR2 (DEFINE_REG(0x40004400,0x10))  // Control Register 1
#define USART_BRR (DEFINE_REG(0x40004400,0x08))  // Baud Rate Register


void UART_Init();
void UART_Transmit(char * str);
void UART_EnableClock(char PinNum);

#endif