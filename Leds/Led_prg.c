/*
 * Led_prg.c
 *
 *  Created on: 27 Aug 2019
 *      Author: coder
 */

#include "Std_types.h"
#include "Bit_math.h"

#include "Dio_int.h"
#include "Led_cfg.h"
#include "Led_int.h"

void Led_vidIint(u8 ID)
{
	switch(ID)
	{
	case 0:
	{
		Dio_vidSetPinDir(LED_u8ID0 ,DIO_u8OUTPUT);
		break;
	}
	case 1:
	{
		Dio_vidSetPinDir(LED_u8ID1 ,DIO_u8OUTPUT);
		break;
	}

	case 2:
	{
		Dio_vidSetPinDir(LED_u8ID2 ,DIO_u8OUTPUT);
		break;
	}

	case 3:
	{
		Dio_vidSetPinDir(LED_u8ID3 ,DIO_u8OUTPUT);
		break;
	}

	case 4:
	{
		Dio_vidSetPinDir(LED_u8ID4 ,DIO_u8OUTPUT);
		break;
	}

	case 5:
	{
		Dio_vidSetPinDir(LED_u8ID5 ,DIO_u8OUTPUT);
		break;
	}

	case 6:
	{
		Dio_vidSetPinDir(LED_u8ID6 ,DIO_u8OUTPUT);
		break;
	}
	case 7:
	{
		Dio_vidSetPinDir(LED_u8ID7 ,DIO_u8OUTPUT);
		break;
	}

	}

}

void Led_vidControl(u8 ID, u8 State)
{

	switch(ID)
		{
		case 0:
		{
			Dio_vidSetPinVal(LED_u8ID0 ,State);
			break;
		}
		case 1:
		{
			Dio_vidSetPinVal(LED_u8ID1 ,State);
			break;
		}

		case 2:
		{
			Dio_vidSetPinVal(LED_u8ID2 ,State);
			break;
		}

		case 3:
		{
			Dio_vidSetPinVal(LED_u8ID3 ,State);
			break;
		}

		case 4:
		{
			Dio_vidSetPinVal(LED_u8ID4 ,State);
			break;
		}

		case 5:
		{
			Dio_vidSetPinVal(LED_u8ID5 ,State);
			break;
		}

		case 6:
		{
			Dio_vidSetPinVal(LED_u8ID6 ,State);
			break;
		}
		case 7:
		{
			Dio_vidSetPinVal(LED_u8ID7 ,State);
			break;
		}

		}
}

void Led_vidSetAll(void)
{
	Dio_vidSetPinVal(LED_u8ID0 ,LED_u8ON);
	Dio_vidSetPinVal(LED_u8ID1 ,LED_u8ON);
	Dio_vidSetPinVal(LED_u8ID2 ,LED_u8ON);
	Dio_vidSetPinVal(LED_u8ID3 ,LED_u8ON);
	Dio_vidSetPinVal(LED_u8ID4 ,LED_u8ON);
	Dio_vidSetPinVal(LED_u8ID5 ,LED_u8ON);
	Dio_vidSetPinVal(LED_u8ID6 ,LED_u8ON);
	Dio_vidSetPinVal(LED_u8ID7 ,LED_u8ON);
}

void Led_vidClearAll(void)
{
	Dio_vidSetPinVal(LED_u8ID0 ,LED_u8OFF);
	Dio_vidSetPinVal(LED_u8ID1 ,LED_u8OFF);
	Dio_vidSetPinVal(LED_u8ID2 ,LED_u8OFF);
	Dio_vidSetPinVal(LED_u8ID3 ,LED_u8OFF);
	Dio_vidSetPinVal(LED_u8ID4 ,LED_u8OFF);
	Dio_vidSetPinVal(LED_u8ID5 ,LED_u8OFF);
	Dio_vidSetPinVal(LED_u8ID6 ,LED_u8OFF);
	Dio_vidSetPinVal(LED_u8ID7 ,LED_u8OFF);
}
