
#include "GPIO.h"
//#include "stm32f401cc_interface.h"
#define GPIO_REG(PORT_ID,REG_ID) ((unsigned int*)(PORT_ID+REG_ID))
#define GPIO_ENR      ((unsigned int)0x40023800+0x30)
#define GPIOA_MODER   (GPIO_REG(0x40020000,0x00))
#define GPIOA_OTYPER  (GPIO_REG(0x40020000,0x04))
#define GPIOA_PUPDR   (GPIO_REG(0x40020000,0x0c))
#define GPIOA_IDR      (GPIO_REG(0x40020000,0x10))
#define GPIOA_ODR      (GPIO_REG(0x40020000,0x14))
#define GPIOB_MODER  (GPIO_REG(0x40020400,0x00))
#define GPIOB_OTYPER  (GPIO_REG(0x40020400,0x04))
#define GPIOB_PUPDR   (GPIO_REG(0x40020400,0x0c))
#define GPIOB_IDR      (GPIO_REG(0x40020400,0x10))
#define GPIOB_ODR      (GPIO_REG(0x40020400,0x14))
#define _OUTTYPE_MASK ((unsigned char)0x01)
#define _OUTTYPE_SHIFT 0
#define _PUPD_MASK ((unsigned char)0x06)
#define _PUPD_SHIFT 1
unsigned int* look_up[2][5]={
		                     {GPIOA_MODER,GPIOA_OTYPER,GPIOA_PUPDR,GPIOA_IDR ,GPIOA_ODR},
		                     {GPIOB_MODER,GPIOB_OTYPER,GPIOB_PUPDR,GPIOB_IDR ,GPIOB_ODR}
                            };

void GPIO_EnableClock(char PortID) {
	if (PortID==0)
	{
//	*((unsigned int *) 0x40023830) |= (0x01 << 0);
	*((unsigned int *)  GPIO_ENR) |= (0x01 << 0);
	}
	if (PortID==1)
	{
//	*((unsigned int *)  0x40023830) |= (0x01 << 1);
	*((unsigned int *)  GPIO_ENR) |= (0x01 << 1);
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
