/*
 * Lcd_cfg.h
 *
 *  Created on: Aug 23, 2019
 *      Author: Na
 */

#ifndef LCD_CFG_H_
#define LCD_CFG_H_

#define LCD_u8_4BIT   0
#define LCD_u8_8BIT   1
#define LCD_u8_1LINE  0
#define LCD_u8_2LINE  1
#define LCD_u8DISPLAYON  0
#define LCD_u8DISPLAYOFF 1
#define LCD_u8CURSORON  	  0
#define LCD_u8CURSORBLINKING  1
#define LCD_u8CURSOROFF 	  2

/*--------------PINS CONFIGURATION--------------*/
#define LCD_u8D0 DIO_u8PIN_0
#define LCD_u8D1 DIO_u8PIN_1
#define LCD_u8D2 DIO_u8PIN_2
#define LCD_u8D3 DIO_u8PIN_3
#define LCD_u8D4 DIO_u8PIN_4
#define LCD_u8D5 DIO_u8PIN_5
#define LCD_u8D6 DIO_u8PIN_6
#define LCD_u8D7 DIO_u8PIN_7

#define LCD_u8RS DIO_u8PIN_10
#define LCD_u8RW DIO_u8PIN_9
#define LCD_u8EN DIO_u8PIN_8

/*--------------MODE CONFIGURATION--------------*/
#define LCD_u8DATATRANSFARE  LCD_u8_4BIT

#define LCD_u8LINES			 LCD_u8_2LINE

#define LCD_u8DISPLAY		 LCD_u8DISPLAYON
#define LCD_u8CURSOR		 LCD_u8CURSOROFF

#endif /* LCD_CFG_H_ */
