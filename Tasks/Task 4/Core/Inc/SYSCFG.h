
#ifndef SYSCFG_H
#define SYSCFG_H

#define DEFINE_REG(PORT_ID,REG_ID) ((unsigned int*)(PORT_ID+REG_ID))
#define SYSCFG_EXTICR1 (DEFINE_REG(0x40013800,0x08))

void Enable_External_Interrupt(char PinNum);

#endif