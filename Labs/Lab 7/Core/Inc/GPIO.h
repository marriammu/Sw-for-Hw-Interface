#ifndef GPIO_H
#define GPIO_H

#define OK ((unsigned char)0)
#define NOK ((unsigned char)1)

// Mode Types
#define INPUT ((unsigned char)0x00)
#define OUTPUT ((unsigned char)0x01)
#define ALTERNATE_FUN ((unsigned char)0x02)
#define ANALOG ((unsigned char)0x03)

// Output modes
#define PUSH_PULL ((unsigned char)0x00)
#define OPEN_DRAIN ((unsigned char)0x01)

// Resistor modes
#define NO_PULL_UP_DOWN ((unsigned char)0x00)
#define PULL_UP ((unsigned char)0x02)
#define PULL_DOWN ((unsigned char)0x04)

#define _OUTTYPE_MASK ((unsigned char)0x01)
#define _OUTTYPE_SHIFT 0
#define _PUPD_MASK ((unsigned char)0x06)
#define _PUPD_SHIFT 1

#define DEFINE_REG(PORT_ID,REG_ID) ((unsigned int*)(PORT_ID+REG_ID))
#define GPIOA_MODER  (DEFINE_REG(0x40020000,0x00))
#define GPIOA_OTYPER  (DEFINE_REG(0x40020000,0x04))
#define GPIOA_PUPDR   (DEFINE_REG(0x40020000,0x0c))
#define GPIOA_IDR      (DEFINE_REG(0x40020000,0x10))
#define GPIOA_ODR      (DEFINE_REG(0x40020000,0x14))
#define GPIOB_MODER  (DEFINE_REG(0x40020400,0x00))
#define GPIOB_OTYPER  (DEFINE_REG(0x40020400,0x04))
#define GPIOB_PUPDR   (DEFINE_REG(0x40020400,0x0c))
#define GPIOB_IDR      (DEFINE_REG(0x40020400,0x10))
#define GPIOB_ODR      (DEFINE_REG(0x40020400,0x14))

void GPIO_EnableClock(char PortID);

void GPIO_Init(unsigned char PortID, unsigned char PinNum, unsigned char PinDir,
               unsigned char DefaultState);
unsigned char GPIO_WritePin(unsigned char PortID, unsigned char PinNum,
                            unsigned char Data);

unsigned char GPIO_ReadPin(unsigned char PortID, unsigned char PinNum);




#endif