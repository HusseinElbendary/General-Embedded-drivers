/*
 * Keypad_int.h
 *
 *  Created on: Aug 23, 2019
 *      Author: Na
 */

#ifndef KEYPAD_INT_H_
#define KEYPAD_INT_H_

#define KEYPAD_u8NO_KEY  0xff

void Keypad_vidInit(void);
u8 Keypad_u8GetKey(void);

#endif /* KEYPAD_INT_H_ */
