#include "DMA.h"
void DMA_Enable_Clock ()
{
  * (DMA_RCCENR) |=	(0x01<< 22);
}
void DMA_Init(unsigned char ItemsNumber ,unsigned char Priority ,unsigned char ItemSize,unsigned int DataTransefer,unsigned char TransferMode,unsigned char Pointer,unsigned int *SourceArray,unsigned int *DestinationArray)
{
	*(DMA2_S0CR) &= ~(0x11);  // disable DMA 2 stream 0
	*(DMA2_S0CR) |= (0x01<<4);  // Transfer Complete Interrupt Enable
	*(DMA2_S0CR) &= ~(0x11<<5); // DMA Flow Controller
	*(DMA2_S0CR) |= (DataTransefer<<6);  // Data transfer
	*(DMA2_S0CR) |= (Pointer<<9);  // Peripheral mode
	*(DMA2_S0CR) |= (Pointer<<10); // Memory mode
	*(DMA2_S0CR) |= (ItemSize<<11); // Peripheral Data size
	*(DMA2_S0CR) |= (ItemSize<<13); // Memory Data size
	*(DMA2_S0CR) |= (Priority<<16); //  priority level
	*(DMA2_S0CR) |= (TransferMode<<21); //Peripheral transfer mode
	*(DMA2_S0CR) |= (TransferMode<<23); //Memory transfer mode
	*(DMA2_S0CR) &= ~(0x11<<25);// channel 0 parameter
	*(DMA2_S0PAR)= (unsigned int)SourceArray; //Source address to Peripheral port
	*(DMA2_S0M0AR)= (unsigned int)DestinationArray;//Destination address to Memory port
	*(DMA2_S0NDTR)= ItemsNumber; // set number of data items
}
void NVIC_INPUT()
{
	 *(NVIC_ISER)|=(0x01<<24);
}

void DMA_FIFO ()
{
	*(DMA2_S0FCR)|= (0x01<<2);   // Direct Mode Disable
	*(DMA2_S0FCR)|= (0x01<<0);   // half fifo threshold
}
void Clear_Flags()
{
	*(DMA2_LIFCR) = ((0x01 << (0)) | (0x01 << (2))| (0x01 << (3)) | (0x01 << (4))| (0x01 << (5)));
}
void Enable_DMA()
{
	*(DMA2_S0CR) |= (0x01<<0);
}
char CheckTransfer(){
	char TransferComplete=((*(DMA2_LISR)>>5)&1);
	char TransferError=((*(DMA2_LISR)>>3)&1);
	if (TransferComplete&&(!TransferError))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void DMA2_Stream0_IRQHandler()
{
	CallOut();
	Clear_Flags();

}

