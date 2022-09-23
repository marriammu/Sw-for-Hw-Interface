#include "GPIO.h"
#include "RCC.h"
#include "NVIC.h"
#include "DMA.h"
#include <stdio.h>
void CompareArrays();
void CreateArrays();
#define NumberOfArrayItems 100
int flag =1;
unsigned int SourceArray[NumberOfArrayItems]={};
unsigned int DestinationArray[NumberOfArrayItems]={};

void CreateArray()
{
    for(int i =1;i<=100;i++)
    {
        SourceArray[i-1]=i*100;
    }
}

void CompareArrays()
{
	char TrasferCompeleteWithoutError =  CheckTransfer();

	if (TrasferCompeleteWithoutError){
    for(int i =1;i<=100;i++)
    {
        if (SourceArray[i-1]!= DestinationArray[i-1])
        {
        	flag=0;
        }
    }
    if (flag==1)
    	GPIO_WritePin(0,1,1);
 }
}
void CallOut()
{
	CompareArrays();

}
int main (){
	GPIO_EnableClock(0);
	NVIC_INPUT();
	DMA_Enable_Clock();
	GPIO_Init(0,1,OUTPUT,PUSH_PULL);
	CreateArray();
	DMA_Init(NumberOfArrayItems,very_high,Word,Memory_To_Memory,single,Incrementing,SourceArray,DestinationArray);
	DMA_FIFO ();
//    Enable_DMA();
	while(1){}
	return 0;
}
