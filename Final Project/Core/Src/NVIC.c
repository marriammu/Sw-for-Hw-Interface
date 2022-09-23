#include "NVIC.h"
void NVIC_INPUT()
{
    *(NVIC_ISER)|=(0x01<<0x06);

}