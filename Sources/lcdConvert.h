#ifndef _LCD_CONVERT_H_
#define _LCD_CONVERT_H_

typedef unsigned char uint8_t;


typedef struct LcdRows{
	uint8_t data0;
	uint8_t data1;
	uint8_t data2;
	uint8_t data3;
}LcdRow;

void printNumberLcd(void* ptr,int num);

void printTimeLcd(void* ptr,int num);



#endif
