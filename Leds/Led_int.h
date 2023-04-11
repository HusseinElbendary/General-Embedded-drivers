/*
 * Led_int.h
 *
 *  Created on: 27 Aug 2019
 *      Author: coder
 */

#ifndef LED_INT_H_
#define LED_INT_H_

#define LED_u8ON DIO_u8HIGH
#define LED_u8OFF DIO_u8LOW

#define LED_u8ID_0 0
#define LED_u8ID_1 1
#define LED_u8ID_2 2
#define LED_u8ID_3 3
#define LED_u8ID_4 4
#define LED_u8ID_5 5
#define LED_u8ID_6 6
#define LED_u8ID_7 7


void Led_vidIint(u8 ID);
void Led_vidControl(u8 ID, u8 State);
void Led_vidClearAll(void);
void Led_vidSetAll(void);
#endif /* LED_INT_H_ */
