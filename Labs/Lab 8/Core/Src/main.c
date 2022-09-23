#include "GPIO.h"
#include "UART.h"
#include "RCC.h"


int main(void){
	 GPIO_EnableClock(0);
	  GPIO_Init(0,2, ALTERNATE_FUN ,PUSH_PULL);
	  GPIO_Alternate();
	  UART_EnableClock(17);
	  UART_Init();
	  UART_Transmit("Hello World!");
	while(1){}
return 0;
}
