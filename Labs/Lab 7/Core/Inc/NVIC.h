#ifndef NVIC_H
#define NVIC_H

#include "main.h"

#define DEFINE_REG(PORT_ID,REG_ID) ((unsigned int*)(PORT_ID+REG_ID))

#define NVIC_ISER  (DEFINE_REG(0xE000E100,0x00))

void NVIC_INPUT();


#endif