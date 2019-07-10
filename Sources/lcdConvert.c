/*
 * lcdConvert.c
 *
 *  Created on: Jul 1, 2019
 *      Author: hp
 */
#include "lcdConvert.h"
#include "myLCD.h"

#define RIGHT_DIR

#ifdef RIGHT_DIR
	LcdRow none = {0x00,0x00,0x00,0x00};
	LcdRow zero = {0x40,0xC0,0x80,0xC0};
	LcdRow one = {0x00,0x80,0x80,0x00};
	LcdRow two = {0x40,0x40,0xC0,0x80};
	LcdRow three = {0x40,0x80,0xC0,0x80};
	LcdRow four = {0x00,0x80,0xC0,0x40};
	LcdRow five = {0x40,0x80,0x40,0xC0};
	LcdRow six = {0x40,0xC0,0x40,0xC0};
	LcdRow seven = {0x00,0x80,0x80,0x80};
	LcdRow eight = {0x40,0xC0,0xC0,0xC0};
	LcdRow nine = {0x40,0x80,0xC0,0xC0};

#else
	LcdRow none = {0x00,0x00,0x00,0x00};
	LcdRow zero = {0x01,0x03,0x02,0x03};
	LcdRow one = {0x00,0x01,0x00,0x01};
	LcdRow two = {0x01,0x01,0x03,0x02};
	LcdRow three = {0x01,0x01,0x01,0x03};
	LcdRow four = {0x00,0x03,0x01,0x01};
	LcdRow five = {0x01,0x02,0x01,0x03};
	LcdRow six = {0x01,0x02,0x03,0x03};
	LcdRow seven = {0x01,0x01,0x00,0x01};
	LcdRow eight = {0x01,0x03,0x03,0x03};
	LcdRow nine = {0x01,0x03,0x01,0x03};
#endif

LcdRow shiffLcdRow(LcdRow rowSourse,int shiff){
	LcdRow newLcdRow;
	newLcdRow.data0 = rowSourse.data0 >> shiff;
	newLcdRow.data1 = rowSourse.data1 >> shiff;
	newLcdRow.data2 = rowSourse.data2 >> shiff;
	newLcdRow.data3 = rowSourse.data3 >> shiff;
	return newLcdRow;
}

LcdRow convert(int num,int shiff){
	
	switch (num)
		{
		case 0:
			return shiffLcdRow(zero,shiff);
			break;
		case 1:
				return shiffLcdRow(one,shiff);
				break;
		case 2:
				return shiffLcdRow(two,shiff);
				break;
		case 3:
				return shiffLcdRow(three,shiff);
				break;
		case 4:
				return shiffLcdRow(four,shiff);
				break;
		case 5:
				return shiffLcdRow(five,shiff);
				break;				

		case 6:
				return shiffLcdRow(six,shiff);
				break;
		case 7:
				return shiffLcdRow(seven,shiff);
				break;
		case 8:
				return shiffLcdRow(eight,shiff);
				break;
		case 9:
				return shiffLcdRow(nine,shiff);
				break;
		default:
			break;
		}

}

void printNumberLcd(void* ptr,int num){
	if(num>9999){
		num = num%9999;
	}
	// number 0 --> 9999
	int s0,s1,s2,s3;
	LcdRow row0,row1,row2,row3;
	
	if(num<10){
		s0 = num;
		row0 = convert(s0,0);
		row1 = none;
		row2 = none;
		row3 = none;
	}
	else if (num>=10&&num<100){
		s0 = num%10;
		num = num/10;
		s1 = num;
		row0 = convert(s0,0);
		row1 = convert(s1,2);
		row2 = none;
		row3 = none;
	}
	else if(num>=100&&num<1000){
		s0 = num%10;
		num = num/10;
		s1 = num%10;
		num = num/10;
		s2 = num;
		row0 = convert(s0,0);
		row1 = convert(s1,2);
		row2 = convert(s2,4);
		row3 = none;
	}
	else {
		s0 = num%10;
		num = num/10;
		s1 = num%10;
		num = num/10;
		s2 = num%10;
		num = num/10;
		s3 = num;
		//
		row0 = convert(s0,0);
		row1 = convert(s1,2);
		row2 = convert(s2,4);
		row3 = convert(s3,6);
	}
	
	//
	
  myLCD_SetFrontplaneData(ptr,0,row0.data0|row1.data0|row2.data0|row3.data0);
  myLCD_SetFrontplaneData(ptr,1,row0.data1|row1.data1|row2.data1|row3.data1);
  myLCD_SetFrontplaneData(ptr,2,row0.data2|row1.data2|row2.data2|row3.data2);
  myLCD_SetFrontplaneData(ptr,3,row0.data3|row1.data3|row2.data3|row3.data3);
	
}

void printTimeLcd(void* ptr,int num){
	int second,minute;
	unsigned char s0,s1;
	unsigned char m0,m1;
	LcdRow row0,row1,row2,row3;
	second = num%60;
	num=num/60;
	if(num>99){
		num = num%99;
	}
	minute = num;
	
	//
	s0 = second%10;
	s1 = (second/10)%10;
	m0 = minute%10;
	m1 = (minute/10)%10;
	//
	row0 = convert(s0,0);
	row1 = convert(s1,2);
	row2 = convert(m0,4);
	row3 = convert(m1,6);
	
	myLCD_SetFrontplaneData(ptr,0,row0.data0|row1.data0|row2.data0|row3.data0|0x80);
	myLCD_SetFrontplaneData(ptr,1,row0.data1|row1.data1|row2.data1|row3.data1);
	myLCD_SetFrontplaneData(ptr,2,row0.data2|row1.data2|row2.data2|row3.data2);
	myLCD_SetFrontplaneData(ptr,3,row0.data3|row1.data3|row2.data3|row3.data3);
}
