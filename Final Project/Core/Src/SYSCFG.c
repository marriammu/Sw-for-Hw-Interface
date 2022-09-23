#include "SYSCFG.h"

void Enable_External_Interrupt(char PinNum){

*(SYSCFG_EXTICR1) &= ~(0x0F<<(PinNum*4));
}