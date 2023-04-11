/*
 * main.c
 *
 *  Created on: Sep 13, 2019
 *      Author: Na
 */

#include "Std_types.h"
#include "Bit_math.h"

#define F_CPU 8000000
#include <util/delay.h>

#include "Dio_int.h"
#include "Lcd_int.h"
#include "SevenSeg_int.h"
#include "Keypad_int.h"

int main(void)
{
	u8 count=0,temp=KEYPAD_u8NO_KEY,i=0;
	u8* number[2];
	Lcd_vidInit();
	Keypad_vidInit();
	SevenSeg_vidInit(SEVENSEG_u8LEFT_ID);
	SevenSeg_vidInit(SEVENSEG_u8RIGHT_ID);

	while(1)
	{
		Lcd_vidWriteString("Enter Number: ");
		while(count>0)
		{
			temp=Keypad_u8GetKey();
			if(CheckNumber(temp))
			{
				number[i++]=temp;
			}
			if(i==2)
			{
				i=0;
				Lcd_vidWriteString("Counting Down: ");
				count=StringToNum(number);
				while(count>0)
				{
					SevenSeg_vidDisplay(SEVENSEG_u8LEFT_ID,count%10);
					SevenSeg_vidDisplay(SEVENSEG_u8RIGHT_ID,count/10);
					_delay_ms(1000);
					count--;
				}
				while(1)
				{
					SevenSeg_vidDisplay(SEVENSEG_u8LEFT_ID,0);
					SevenSeg_vidDisplay(SEVENSEG_u8RIGHT_ID,0);
					Dio_vidTglPin(DIO_u8PIN_31);
					_delay_ms(500);
					SevenSeg_vidDisplay(SEVENSEG_u8LEFT_ID,SEVENSEG_u8NO_NUM);
					SevenSeg_vidDisplay(SEVENSEG_u8RIGHT_ID,SEVENSEG_u8NO_NUM);
					Dio_vidTglPin(DIO_u8PIN_31);
					_delay_ms(500);
				}
			}
		}

	}
	return 0;
}
u8 CheckNumber(u8 num)
{
	switch (num)
	{
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
	case 0:
		return 1;
	default:
		return 0;
	}
}

u8 StringToNum(u8* number)
{
	return (number[0]-'0')*10+(number[1]);
}
