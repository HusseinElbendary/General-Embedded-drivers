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
#if LCD_u8DATATRANSFARE==LCD_u8_8BIT
	Dio_vidSetPinDir(LCD_u8D0,DIO_u8OUTPUT);
	Dio_vidSetPinDir(LCD_u8D1,DIO_u8OUTPUT);
	Dio_vidSetPinDir(LCD_u8D2,DIO_u8OUTPUT);
	Dio_vidSetPinDir(LCD_u8D3,DIO_u8OUTPUT);
#endif
	Dio_vidSetPinDir(LCD_u8D4,DIO_u8OUTPUT);
	Dio_vidSetPinDir(LCD_u8D5,DIO_u8OUTPUT);
	Dio_vidSetPinDir(LCD_u8D6,DIO_u8OUTPUT);
	Dio_vidSetPinDir(LCD_u8D7,DIO_u8OUTPUT);

	Dio_vidSetPinDir(LCD_u8RS,DIO_u8OUTPUT);
	Dio_vidSetPinDir(LCD_u8RW,DIO_u8OUTPUT);
	Dio_vidSetPinDir(LCD_u8EN,DIO_u8OUTPUT);


#if LCD_u8DATATRANSFARE==LCD_u8_8BIT

#if LCD_u8LINES==LCD_u8_2LINE
	Lcd_vidSendCommand(0x38); /* 8-bit , 2 lines , 5*7 pixels*/
#elif LCD_u8LINES==LCD_u8_1LINE
	Lcd_vidSendCommand(0x30);/* 8-bit , 1 line , 5*7 pixels*/
#endif


#elif LCD_u8DATATRANSFARE==LCD_u8_4BIT

#if LCD_u8LINES==LCD_u8_2LINE
	Lcd_vidSendCommand(0x28); /* 4-bit , 2 lines , 5*7 pixels*/
#elif LCD_u8LINES==LCD_u8_1LINE
	Lcd_vidSendCommand(0x20);/* 4-bit , 1 line , 5*7 pixels*/
#endif

#endif
	_delay_ms(2);
#if LCD_u8DISPLAY==LCD_u8DISPLAYON

#if LCD_u8CURSOR==LCD_u8CURSOROFF
	Lcd_vidSendCommand(LCD_u8DISPLAYONCURSOROFF);
#elif LCD_u8CURSOR==LCD_u8CURSORON
	Lcd_vidSendCommand(LCD_u8DISPLAYONCURSORON);
#elif LCD_u8CURSOR==LCD_u8CURSORBLINKING
	Lcd_vidSendCommand(LCD_u8DISPLAYONBLINKON);
#endif
#endif

#if LCD_u8DISPLAY==LCD_u8DISPLAYOFF

#if LCD_u8CURSOR==LCD_u8CURSOROFF
	Lcd_vidSendCommand(LCD_u8DISPLAYONCURSOROFF);
#elif LCD_u8CURSOR==LCD_u8CURSORON
	Lcd_vidSendCommand(LCD_u8DISPLAYONCURSORON);
#elif LCD_u8CURSOR==LCD_u8CURSORBLINKING
	Lcd_vidSendCommand(LCD_u8DISPLAYONBLINKON);
#endif

#endif
	_delay_ms(2);


	Lcd_vidSendCommand(LCD_u8SCREENCLEAR); /* clear screen*/
	_delay_ms(2);



}

void Lcd_vidWriteChar(u8 Character)
{
#if LCD_u8DATATRANSFARE==LCD_u8_8BIT
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

#elif LCD_u8DATATRANSFARE==LCD_u8_4BIT
	Dio_vidSetPinVal(LCD_u8RS,DIO_u8HIGH);// Send HIGH pulse on RS pin for selecting data register
	Dio_vidSetPinVal(LCD_u8RW,DIO_u8LOW);// Send LOW pulse on RW pin for Write operation
	Dio_vidSetPinVal(LCD_u8EN,DIO_u8HIGH);// Generate a High-to-low pulse on EN pin

	Dio_vidSetPinVal(LCD_u8D4,GET_BIT(Character,4));
	Dio_vidSetPinVal(LCD_u8D5,GET_BIT(Character,5));
	Dio_vidSetPinVal(LCD_u8D6,GET_BIT(Character,6));
	Dio_vidSetPinVal(LCD_u8D7,GET_BIT(Character,7));//Send Higher nibble

	_delay_ms(2);
	Dio_vidSetPinVal(LCD_u8EN,DIO_u8LOW);

	Dio_vidSetPinVal(LCD_u8RS,DIO_u8HIGH);// Send HIGH pulse on RS pin for selecting data register
	Dio_vidSetPinVal(LCD_u8RW,DIO_u8LOW);// Send LOW pulse on RW pin for Write operation
	Dio_vidSetPinVal(LCD_u8EN,DIO_u8HIGH);// Generate a High-to-low pulse on EN pin

	Dio_vidSetPinVal(LCD_u8D4,GET_BIT(Character,0));
	Dio_vidSetPinVal(LCD_u8D5,GET_BIT(Character,1));
	Dio_vidSetPinVal(LCD_u8D6,GET_BIT(Character,2));
	Dio_vidSetPinVal(LCD_u8D7,GET_BIT(Character,3));//Send Lower nibble

	_delay_ms(2);
	Dio_vidSetPinVal(LCD_u8EN,DIO_u8LOW);


#endif

}
void Lcd_vidSendCommand(u8 Cmd)
{
#if LCD_u8DATATRANSFARE==LCD_u8_8BIT
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

#elif LCD_u8DATATRANSFARE==LCD_u8_4BIT
	Dio_vidSetPinVal(LCD_u8RS,DIO_u8LOW);// Send HIGH pulse on RS pin for selecting data register
	Dio_vidSetPinVal(LCD_u8RW,DIO_u8LOW);// Send LOW pulse on RW pin for Write operation
	Dio_vidSetPinVal(LCD_u8EN,DIO_u8HIGH);// Generate a High-to-low pulse on EN pin

	Dio_vidSetPinVal(LCD_u8D4,GET_BIT(Cmd,4));
	Dio_vidSetPinVal(LCD_u8D5,GET_BIT(Cmd,5));
	Dio_vidSetPinVal(LCD_u8D6,GET_BIT(Cmd,6));
	Dio_vidSetPinVal(LCD_u8D7,GET_BIT(Cmd,7));//Send Higher nibble

	_delay_ms(2);
	Dio_vidSetPinVal(LCD_u8EN,DIO_u8LOW);

	Dio_vidSetPinVal(LCD_u8RS,DIO_u8LOW);// Send HIGH pulse on RS pin for selecting data register
	Dio_vidSetPinVal(LCD_u8RW,DIO_u8LOW);// Send LOW pulse on RW pin for Write operation
	Dio_vidSetPinVal(LCD_u8EN,DIO_u8HIGH);// Generate a High-to-low pulse on EN pin

	Dio_vidSetPinVal(LCD_u8D4,GET_BIT(Cmd,0));
	Dio_vidSetPinVal(LCD_u8D5,GET_BIT(Cmd,1));
	Dio_vidSetPinVal(LCD_u8D6,GET_BIT(Cmd,2));
	Dio_vidSetPinVal(LCD_u8D7,GET_BIT(Cmd,3));//Send Lower nibble

	_delay_ms(2);
	Dio_vidSetPinVal(LCD_u8EN,DIO_u8LOW);

#endif
}
void Lcd_vidWriteCustomChar(u8* Pattern)
{
    unsigned char i;
    Lcd_vidSendCommand(0x40);  /* Command 0x40 and onwards forces
                                       the device to point CGRAM address */
    for(i=0;i<8;i++) /* Write Pattern for generation of 1 character */
    {
    	Lcd_vidWriteChar(Pattern[i]);
    }

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


