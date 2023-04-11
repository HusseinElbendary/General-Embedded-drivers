/*
 * Servo_prg.c
 *
 *  Created on: 17 Sep 2019
 *      Author: coder
 */

#include "Std_types.h"
#include "Bit_math.h"
#define F_CPU 8000000
#include <util/delay.h>
#include "Dio_int.h"
#include "Timer_int.h"
#include "Servo_cfg.h"
#include "Servo_int.h"


void Servo_vidInit(u8 ID)
{

	if(ID==SERVO_u8SERVO_1)
	{
		Timer_vidInit(TIMER_u8TIMER_1A);
		Timer_vidSetICR1(20000);
#if SERVO_u8SERVO_1_PIN == DIO_u8PIN_29
		Dio_vidSetPinDir(DIO_u8PIN_29,DIO_u8OUTPUT);
#elif SERVO_u8SERVO_1_PIN == DIO_u8PIN_28
		Dio_vidSetPinDir(DIO_u8PIN_28,DIO_u8OUTPUT);
#endif
	}
	else if(ID==SERVO_u8SERVO_2)
	{
		Timer_vidInit(TIMER_u8TIMER_1B);
		Timer_vidSetICR1(20000);
#if SERVO_u8SERVO_2_PIN == DIO_u8PIN_29
		Dio_vidSetPinDir(DIO_u8PIN_29,DIO_u8OUTPUT);
#elif SERVO_u8SERVO_2_PIN == DIO_u8PIN_28
		Dio_vidSetPinDir(DIO_u8PIN_28,DIO_u8OUTPUT);
#endif
	}
	Timer_vidSetCompareValue(TIMER_u8TIMER_1A,0);
	Timer_vidSetCompareValue(TIMER_u8TIMER_1B,0);
	Timer_vidStartTimer(TIMER_u8TIMER_1);
}

void Servo_vidWriteDeg(u8 Servo_ID,u16 Servo_Degree)
{
	u16 OCR_Val;
	OCR_Val=(Servo_Degree*((SERVO_u16MAX_Value-SERVO_u16MIN_Value)/180.0))+SERVO_u16MIN_Value;
	if(Servo_ID==SERVO_u8SERVO_1)
	{
		Timer_vidSetCompareValue(TIMER_u8TIMER_1A,OCR_Val);

	}
	if(Servo_ID==SERVO_u8SERVO_2)
	{
		Timer_vidSetCompareValue(TIMER_u8TIMER_1B,OCR_Val);
	}
}

