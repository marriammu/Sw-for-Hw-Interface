#ifndef EXTI_H
#define EXTI_H

#define DEFINE_REG(PORT_ID,REG_ID) ((unsigned int*)(PORT_ID+REG_ID))

#define EXTI_IMR     (DEFINE_REG(0x40013C00,0x00))
#define EXTI_FTSR     (DEFINE_REG(0x40013C00,0x0c))
#define EXTI_PR     (DEFINE_REG(0x40013C00,0x14))

void Interrupt_Mask_Enable(char PinNum);
void Interrupt_Mask_Disable(char PinNum);
void Falling_Edge(char PinNum);

void Pending_REG(char PinNum);

#endif