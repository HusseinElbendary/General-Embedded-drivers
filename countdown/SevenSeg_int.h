/*
 * SevenSeg_int.h
 *
 *  Created on: 27 Aug 2019
 *      Author: coder
 */

#ifndef SEVENSEG_INT_H_
#define SEVENSEG_INT_H_

#define SEVENSEG_u8RIGHT_ID 0
#define SEVENSEG_u8LEFT_ID  1

#define SEVENSEG_u8NO_NUM 0x00
#define SEVENSEG_u8NUM_0 0x3F
#define SEVENSEG_u8NUM_1 0x06
#define SEVENSEG_u8NUM_2 0x5B
#define SEVENSEG_u8NUM_3 0x4F
#define SEVENSEG_u8NUM_4 0x66
#define SEVENSEG_u8NUM_5 0x6D
#define SEVENSEG_u8NUM_6 0x7D
#define SEVENSEG_u8NUM_7 0x07
#define SEVENSEG_u8NUM_8 0x7F
#define SEVENSEG_u8NUM_9 0x67

void SevenSeg_vidInit(u8 ID);
void SevenSeg_vidDisplay(u8 ID,u8 DisplayNum);

#endif /* SEVENSEG_INT_H_ */
