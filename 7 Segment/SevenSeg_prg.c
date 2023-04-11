/*
 * SevenSeg_prg.c
 *
 *  Created on: 27 Aug 2019
 *      Author: coder
 */

#include "Std_types.h"
#include "Bit_math.h"

#define F_CPU 8000000
#include "util/delay.h"

#include "Dio_int.h"
#include "SevenSeg_cfg.h"
#include "SevenSeg_int.h"

void SevenSeg_vidInit(u8 ID)
{
	if(ID==SEVENSEG_u8RIGHT_ID)
	{
		Dio_vidSetPinDir(SEVENSEG_u8RIGHTPIN_A ,DIO_u8OUTPUT);
		Dio_vidSetPinDir(SEVENSEG_u8RIGHTPIN_B ,DIO_u8OUTPUT);
		Dio_vidSetPinDir(SEVENSEG_u8RIGHTPIN_C ,DIO_u8OUTPUT);
		Dio_vidSetPinDir(SEVENSEG_u8RIGHTPIN_D ,DIO_u8OUTPUT);
		Dio_vidSetPinDir(SEVENSEG_u8RIGHTPIN_E ,DIO_u8OUTPUT);
		Dio_vidSetPinDir(SEVENSEG_u8RIGHTPIN_F ,DIO_u8OUTPUT);
		Dio_vidSetPinDir(SEVENSEG_u8RIGHTPIN_G ,DIO_u8OUTPUT);
		Dio_vidSetPinDir(SEVENSEG_u8RIGHTPIN_DP,DIO_u8OUTPUT);
	}
	else
	{
		Dio_vidSetPinDir(SEVENSEG_u8LEFTPIN_A ,DIO_u8OUTPUT);
		Dio_vidSetPinDir(SEVENSEG_u8LEFTPIN_B ,DIO_u8OUTPUT);
		Dio_vidSetPinDir(SEVENSEG_u8LEFTPIN_C ,DIO_u8OUTPUT);
		Dio_vidSetPinDir(SEVENSEG_u8LEFTPIN_D ,DIO_u8OUTPUT);
		Dio_vidSetPinDir(SEVENSEG_u8LEFTPIN_E ,DIO_u8OUTPUT);
		Dio_vidSetPinDir(SEVENSEG_u8LEFTPIN_F ,DIO_u8OUTPUT);
		Dio_vidSetPinDir(SEVENSEG_u8LEFTPIN_G ,DIO_u8OUTPUT);
		Dio_vidSetPinDir(SEVENSEG_u8LEFTPIN_DP,DIO_u8OUTPUT);
	}

}


void SevenSeg_vidDisplay(u8 ID,u8 DisplayNum)
{
	if(ID==SEVENSEG_u8RIGHT_ID)
	{
		Dio_vidSetPinVal(SEVENSEG_u8RIGHTPIN_A ,GET_BIT(DisplayNum,0));
		Dio_vidSetPinVal(SEVENSEG_u8RIGHTPIN_B ,GET_BIT(DisplayNum,1));
		Dio_vidSetPinVal(SEVENSEG_u8RIGHTPIN_C ,GET_BIT(DisplayNum,2));
		Dio_vidSetPinVal(SEVENSEG_u8RIGHTPIN_D ,GET_BIT(DisplayNum,3));
		Dio_vidSetPinVal(SEVENSEG_u8RIGHTPIN_E ,GET_BIT(DisplayNum,4));
		Dio_vidSetPinVal(SEVENSEG_u8RIGHTPIN_F ,GET_BIT(DisplayNum,5));
		Dio_vidSetPinVal(SEVENSEG_u8RIGHTPIN_G ,GET_BIT(DisplayNum,6));
		Dio_vidSetPinVal(SEVENSEG_u8RIGHTPIN_DP,GET_BIT(DisplayNum,7));
	}
	else
	{
		Dio_vidSetPinVal(SEVENSEG_u8LEFTPIN_A ,GET_BIT(DisplayNum,0));
		Dio_vidSetPinVal(SEVENSEG_u8LEFTPIN_B ,GET_BIT(DisplayNum,1));
		Dio_vidSetPinVal(SEVENSEG_u8LEFTPIN_C ,GET_BIT(DisplayNum,2));
		Dio_vidSetPinVal(SEVENSEG_u8LEFTPIN_D ,GET_BIT(DisplayNum,3));
		Dio_vidSetPinVal(SEVENSEG_u8LEFTPIN_E ,GET_BIT(DisplayNum,4));
		Dio_vidSetPinVal(SEVENSEG_u8LEFTPIN_F ,GET_BIT(DisplayNum,5));
		Dio_vidSetPinVal(SEVENSEG_u8LEFTPIN_G ,GET_BIT(DisplayNum,6));
		Dio_vidSetPinVal(SEVENSEG_u8LEFTPIN_DP,GET_BIT(DisplayNum,7));
	}

}
