/*
 * main.c
 *
 *  Created on: Sep 14, 2019
 *      Author: Na
 */


/* TCCR0 6=1, 3=1 5=1 4=0 2=0 1=0 0=1*/


#include "Std_types.h"
#include "Bit_math.h"
#include <avr/io.h>
#define F_CPU 8000000
#include <util/delay.h>
#include "Dio_int.h"

int main(void)
{/*
	SET_BIT(TCCR0,6);
	SET_BIT(TCCR0,3);// fast pwm

	SET_BIT(TCCR0,5);
	CLEAR_BIT(TCCR0,4);//clear compare set top
	Dio_vidSetPinDir(DIO_u8PIN_11,DIO_u8OUTPUT);
	CLEAR_BIT(TCCR0,2);
	CLEAR_BIT(TCCR0,1);
	SET_BIT(TCCR0,0); // no prescale
	OCR0=0;
	u8 flag=0;
	while(1)
	{
		if(!flag)
		{
		OCR0++;
		}
		else{
			OCR0--;
		}
		_delay_ms(5);
		if(OCR0==255)
		{
		flag=1;
		}
		else if(OCR0==0)
		{
			flag=0;
		}
	}
*/


	SET_BIT(TCCR1A,7);
	CLEAR_BIT(TCCR1A,6);
	SET_BIT(TCCR1A,1);
	CLEAR_BIT(TCCR1A,0);
	SET_BIT(TCCR1B,4);
	SET_BIT(TCCR1B,3);
	Dio_vidSetPinDir(DIO_u8PIN_29,DIO_u8OUTPUT);

	CLEAR_BIT(TCCR1B,2);
	SET_BIT(TCCR1B,1);
	CLEAR_BIT(TCCR1B,0);
	ICR1=20000;
	//OCR1A=300;
	//OCR1A=2700;

}
