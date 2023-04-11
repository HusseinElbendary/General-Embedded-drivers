/*
 * Lcd_int.h
 *
 *  Created on: Aug 22, 2019
 *      Author: Na
 */

#ifndef LCD_INT_H_
#define LCD_INT_H_

#define LCD_u8SCREENCLEAR 0x01
#define LCD_u8CURSORRETURN 0x02

#define LCD_u8DECCURSOR 0x10
#define LCD_u8INCCURSOR 0x14

#define LCD_u8SHIFTRIGHT 0x18
#define LCD_u8SHIFTLEFT  0x1C


#define LCD_u8DISPLAYOFFCURSOROFF 0x08
#define LCD_u8DISPLAYOFFCURSORON  0x0A
#define LCD_u8DISPLAYONCURSOROFF  0x0C
#define LCD_u8DISPLAYONCURSORON   0x0E
#define LCD_u8DISPLAYONBLINKON    0x0F



#define LCD_u8ROW1 0x80
#define LCD_u8ROW2 0xC0

void Lcd_vidInit(void);
void Lcd_vidWriteChar(u8 Character);
void Lcd_vidSendCommand(u8 Cmd);
void Lcd_vidWriteString(u8 string[33]);
void Lcd_vidGoTo(u8 Loc_u8Row,u8 Loc_u8Col);


#endif /* LCD_INT_H_ */
