/*
 * Lcd_prg.c
 *
 *  Created on: Aug 22, 2019
 *      Author: Na
 */

#include "Std_types.h"
#include "Bit_math.h"

#include "Dio_int.h"

#define F_CPU 8000000
#include <util/delay.h>

#include "Lcd_cfg.h"
#include "Lcd_int.h"


void Lcd_vidInit(void)
{
	Dio_vidSetPinDir(LCD_u8D0,DIO_u8OUTPUT);
	Dio_vidSetPinDir(LCD_u8D1,DIO_u8OUTPUT);
	Dio_vidSetPinDir(LCD_u8D2,DIO_u8OUTPUT);
	Dio_vidSetPinDir(LCD_u8D3,DIO_u8OUTPUT);
	Dio_vidSetPinDir(LCD_u8D4,DIO_u8OUTPUT);
	Dio_vidSetPinDir(LCD_u8D5,DIO_u8OUTPUT);
	Dio_vidSetPinDir(LCD_u8D6,DIO_u8OUTPUT);
	Dio_vidSetPinDir(LCD_u8D7,DIO_u8OUTPUT);
	Dio_vidSetPinDir(LCD_u8RS,DIO_u8OUTPUT);
	Dio_vidSetPinDir(LCD_u8RW,DIO_u8OUTPUT);
	Dio_vidSetPinDir(LCD_u8EN,DIO_u8OUTPUT);



	Lcd_vidSendCommand(0x38); /* 8-bit , 2 lines , 5*7 pixels*/
	_delay_ms(2);
	Lcd_vidSendCommand(0x0C); /* make cursor invisible*/
	_delay_ms(2);
	Lcd_vidSendCommand(0x01); /* clear screen*/
	_delay_ms(2);



}



void Lcd_vidWriteChar(u8 Character)
{
	Dio_vidSetPinVal(LCD_u8RS,DIO_u8HIGH);
	Dio_vidSetPinVal(LCD_u8RW,DIO_u8LOW);
	Dio_vidSetPinVal(LCD_u8EN,DIO_u8HIGH);

	Dio_vidSetPinVal(LCD_u8D0,GET_BIT(Character,0));
	Dio_vidSetPinVal(LCD_u8D1,GET_BIT(Character,1));
	Dio_vidSetPinVal(LCD_u8D2,GET_BIT(Character,2));
	Dio_vidSetPinVal(LCD_u8D3,GET_BIT(Character,3));
	Dio_vidSetPinVal(LCD_u8D4,GET_BIT(Character,4));
	Dio_vidSetPinVal(LCD_u8D5,GET_BIT(Character,5));
	Dio_vidSetPinVal(LCD_u8D6,GET_BIT(Character,6));
	Dio_vidSetPinVal(LCD_u8D7,GET_BIT(Character,7));

	_delay_ms(2);
	Dio_vidSetPinVal(LCD_u8EN,DIO_u8LOW);

}
void Lcd_vidSendCommand(u8 Cmd)
{
	Dio_vidSetPinVal(LCD_u8RS,DIO_u8LOW);
	Dio_vidSetPinVal(LCD_u8RW,DIO_u8LOW);
	Dio_vidSetPinVal(LCD_u8EN,DIO_u8HIGH);

	Dio_vidSetPinVal(LCD_u8D0,GET_BIT(Cmd,0));
	Dio_vidSetPinVal(LCD_u8D1,GET_BIT(Cmd,1));
	Dio_vidSetPinVal(LCD_u8D2,GET_BIT(Cmd,2));
	Dio_vidSetPinVal(LCD_u8D3,GET_BIT(Cmd,3));
	Dio_vidSetPinVal(LCD_u8D4,GET_BIT(Cmd,4));
	Dio_vidSetPinVal(LCD_u8D5,GET_BIT(Cmd,5));
	Dio_vidSetPinVal(LCD_u8D6,GET_BIT(Cmd,6));
	Dio_vidSetPinVal(LCD_u8D7,GET_BIT(Cmd,7));

	_delay_ms(2);
	Dio_vidSetPinVal(LCD_u8EN,DIO_u8LOW);

}
void Lcd_vidWriteString(u8 string[33])
{
	u8 i;
	for(i=0;string[i]!='\0';i++)
	{
		Lcd_vidWriteChar(string[i]);
	}
}

void Lcd_vidGoTo(u8 Loc_u8Row,u8 Loc_u8Col)
{
	if(Loc_u8Row)
	{
		Lcd_vidSendCommand(LCD_u8ROW2+Loc_u8Col);
	}
	else
	{
		Lcd_vidSendCommand(LCD_u8ROW1+Loc_u8Col);
	}
}


