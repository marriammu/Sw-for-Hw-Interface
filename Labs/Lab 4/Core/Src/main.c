#include "GPIO.h"
#include "stm32f401xc.h"
#include "stm32f401cc_interface.h"

int main(void) {
	char sevenSegment[11][8] = {
	// 7 segment code table
	//  a  b  c  d  e  f  g  .
	  { 1, 1, 1, 1, 1, 1, 0},  // 0
	  { 0, 1, 1, 0, 0, 0, 0},  // 1
	  { 1, 1, 0, 1, 1, 0, 1},  // 2
	  { 1, 1, 1, 1, 0, 0, 1},  // 3
	  { 0, 1, 1, 0, 0, 1, 1},  // 4
	  { 1, 0, 1, 1, 0, 1, 1},  // 5
	  { 1, 0, 1, 1, 1, 1, 1},  // 6
	  { 1, 1, 1, 0, 0, 0, 0},  // 7
	  { 1, 1, 1, 1, 1, 1, 1},  // 8
	  { 1, 1, 1, 1, 0, 1, 1}   // 9
	};

	for (int i=0;i<=7;i++){
		GPIO_Init('A', i, OUTPUT, PUSH_PULL);
	}
  while (1) {
	  int i;
	  int j;
	  //led on
	  for (i =0;i<10;i++)
	  {
		  for (j =0 ;j<8;j++){
			  GPIO_WritePin('A', j, sevenSegment [i][j]);
		  }
		  for (int i = 0; i < 1000000; i++)
			  {
			  }
	  }
  }
  return 0;
}
