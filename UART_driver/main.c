/*
 * main.c
 *
 *  Created on: Sep 28, 2019
 *      Author: yomna
 */


/*********************Transmitter Code*****************************/

#include "std_types.h"
#include "Bit_math.h"

#include "Uart_int.h"

#define F_CPU 8000000
#include <util/delay.h>

int main (void)
{

	Uart_vidInit();

	while(1)
	{
		Uart_vidSendData('a');
		_delay_ms(1000);

		Uart_vidSendData('b');
		_delay_ms(1000);

	}

	return 0;
}

/*********************Receiver Code*****************************/
/*
#include "std_types.h"
#include "Bit_math.h"

#include "Uart_int.h"
#include "Dio_int.h"

int main(void)
{
	u8 Data;
	Uart_vidInit();

	while(1)
	{
		Data = Uart_u8ReceiveData();
		if(Data == 'a')
		{
			Dio_vidSetPinValue(DIO_u8PIN_31,DIO_u8HIGH);
		}
		else
		{
			Dio_vidSetPinValue(DIO_u8PIN_31,DIO_u8LOW);
		}
		Uart_vidSendData('a');
		_delay_ms(1000);
		Uart_vidSendData('b');
		_delay_ms(1000);
	}
	return 0;
}

*/
