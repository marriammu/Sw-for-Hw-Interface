#define Define_REG(Base_Address,Offset) ((unsigned int*)(Base_Address+Offset))
#define DMA_RCCENR  Define_REG(0x40023800,0x30)    // DMA RCC Clock
#define DMA2_LISR Define_REG(0x40026400,0x00)     //DMA low interrupt status register
#define DMA2_S0CR Define_REG(0x40026400,0x10)     //stream 0 configuration register
#define DMA2_S0NDTR Define_REG(0x40026400, 0x14)   //number of data register
#define DMA2_S0PAR Define_REG(0x40026400, 0x18 )   //peripheral address register
#define DMA2_S0M0AR Define_REG(0x40026400,0x1C)    //memory 0 address register
#define DMA2_S0M1AR Define_REG(0x40026400, 0x20)  //memory 1 address register
#define DMA2_S0FCR Define_REG(0x40026400, 0x24)   //FIFO control register
#define DMA2_LIFCR Define_REG(0x40026400, 0x08)   // low interrupt flag clear register
#define NVIC_ISER  Define_REG(0xE000E100,0x04)   // interrupt line

// Priority Levels
#define low 0x00
#define medium 0x01
#define high 0x02
#define very_high 0x03
// Data Size
#define Byte 0x00
#define Half_Word 0x01
#define Word 0x02
// Transfer mode
#define Peripheral_To_Memory 0x00
#define Memory_To_Peripheral 0x01
#define Memory_To_Memory 0x02
// Pointer mode
#define Fixed 0x00
#define Incrementing 0x01
// Transfer Type
#define single 0x00
#define INCR4 0x01  //incremental burst of 4 beats
#define INCR8 0x02 //incremental burst of 8 beats
#define INCR16 0x03 //incremental burst of 16 beats

void DMA_Enable_Clock ();
void NVIC_INPUT();
void DMA_Init(unsigned char ItemsNumber ,unsigned char Priority ,unsigned char ItemSize,unsigned int DataTransefer,unsigned char TransferMode,unsigned char Pointer,unsigned int *SourceArray,unsigned int *DestinationArray);
void DMA_FIFO ();
void Enable_DMA();
void DMA2_Stream0_IRQHandler();
char CheckTransfer();
void Clear_Flags();

