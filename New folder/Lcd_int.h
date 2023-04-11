/*
 * Lcd_int.h
 *
 *  Created on: Aug 22, 2019
 *      Author: Na
 */

#ifndef LCD_INT_H_
#define LCD_INT_H_

#define LCD_u8CLEAR 0x01
#define LCD_u8ROW1 0x80
#define LCD_u8ROW2 0x40

void Lcd_vidInit(void);
void Lcd_vidWriteChar(u8 Character);
void Lcd_vidSendCommand(u8 Cmd);
void Lcd_vidWriteString(u8 string[33]);
void Lcd_vidGoTo(u8 Loc_u8Row,u8 Loc_u8Col);


#endif /* LCD_INT_H_ */
