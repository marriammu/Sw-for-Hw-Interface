#include "RCC.h"

void SYSCFG_clock(char PinNum) {

*( RCC_APB2ENR) |= (0x01 << PinNum);
}