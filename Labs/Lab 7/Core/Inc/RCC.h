
#ifndef RCC_H
#define RCC_H

#include "main.h"

#define DEFINE_REG(PORT_ID,REG_ID) ((unsigned int*)(PORT_ID+REG_ID))

#define RCC_AHB1ENR (DEFINE_REG(0x40023800,0x30))
#define RCC_APB2ENR (DEFINE_REG(0x40023800,0x44))

void SYSCFG_clock(char PinNum);


#endif