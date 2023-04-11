/*
 * Uart_prg.c
 *
 *  Created on: Sep 28, 2019
 *      Author: yomna
 */


#include "std_types.h"
#include "Bit_math.h"

#include "Uart_int.h"
#include "Uart_cfg.h"
#include "Uart_priv.h"

void (*UART_RX_COM_ISR)(void);
void (*UART_DATA_EMPTY_ISR)(void);
void (*UART_TX_COM_ISR)(void);

void Uart_vidInit(void)
{
	u8 Reg_Value = 0;


	SET_BIT(Reg_Value,7);

	SET_BIT(UCSRB,4);    // RX EN
	SET_BIT(UCSRB,3);    // TX EN



#if UART_u8OPERATION ==UART_u8OPERATION_ASYNCH
	CLEAR_BIT(Reg_Value,6);  // CLEAR FOR ASYNCHRONES
	CLEAR_BIT(UCSRB,0);
#elif UART_u8OPERATION ==UART_u8OPERATION_SYNCH
	SET_BIT(Reg_Value,6);  // CLEAR FOR ASYNCHRONES
#if UART_u8CLK==UART_u8CLK_TX_RISING
	SET_BIT(UCSRB,0);
#elif UART_u8CLK==UART_u8CLK_TX_FALLING
	CLEAR_BIT(UCSRB,0);
#endif

#endif

#if UART_u8UPM==UART_u8UPM_DISABLED
	CLEAR_BIT(Reg_Value,5);
	CLEAR_BIT(Reg_Value,4);
#elif UART_u8UPM==UART_u8UPM_EVEN
	SET_BIT(Reg_Value,5);
	CLEAR_BIT(Reg_Value,4);
#elif UART_u8UPM==UART_u8UPM_ODD
	SET_BIT(Reg_Value,5);
	SET_BIT(Reg_Value,4);
#endif


#if UART_u8STOPBIT==UART_u8STOPBIT_1_BIT
	CLEAR_BIT(Reg_Value,3);
#elif UART_u8STOPBIT==UART_u8STOPBIT_2_BIT
	SET_BIT(Reg_Value,3);
#endif


	/* Character size*/
#if UART_u8CHAR_SIZE==UART_u8CHAR_SIZE_5_bit
	CLEAR_BIT(UCSRB,2);  // IN 5 BIT DATA TRANSFER
	CLEAR_BIT(Reg_Value,2);
	CLEAR_BIT(Reg_Value,1);
#elif UART_u8CHAR_SIZE==UART_u8CHAR_SIZE_6_bit
	CLEAR_BIT(UCSRB,2);  // IN 6 BIT DATA TRANSFER
	CLEAR_BIT(Reg_Value,2);
	SET_BIT(Reg_Value,1);
#elif UART_u8CHAR_SIZE==UART_u8CHAR_SIZE_7_bit
	CLEAR_BIT(UCSRB,2);  // IN 7 BIT DATA TRANSFER
	SET_BIT(Reg_Value,2);
	CLEAR_BIT(Reg_Value,1);
#elif UART_u8CHAR_SIZE==UART_u8CHAR_SIZE_8_bit
	CLEAR_BIT(UCSRB,2);  // IN 8 BIT DATA TRANSFER
	SET_BIT(Reg_Value,2);
	SET_BIT(Reg_Value,1);
#elif UART_u8CHAR_SIZE==UART_u8CHAR_SIZE_9_bit
	SET_BIT(UCSRB,2);  // IN 9 BIT DATA TRANSFER
	SET_BIT(Reg_Value,2);
	SET_BIT(Reg_Value,1);
#endif


#if UART_u8BAURD_RATE==UART_u8BAURD_RATE_2400
	UBRRH = 0;
	UBRRL = 207;
#elif UART_u8BAURD_RATE==UART_u8BAURD_RATE_4800
	UBRRH = 0;
	UBRRL = 103;
#elif UART_u8BAURD_RATE==UART_u8BAURD_RATE_9600
	UBRRH = 0;
	UBRRL = 51;

#elif UART_u8BAURD_RATE==UART_u8BAURD_RATE_14400
	UBRRH = 0;
	UBRRL = 34;
#elif UART_u8BAURD_RATE==UART_u8BAURD_RATE_19200
	UBRRH = 0;
	UBRRL = 25;
#elif UART_u8BAURD_RATE==UART_u8BAURD_RATE_28800
	UBRRH = 0;
	UBRRL = 16;
#elif UART_u8BAURD_RATE==UART_u8BAURD_RATE_38400
	UBRRH = 0;
	UBRRL = 12;
#elif UART_u8BAURD_RATE==UART_u8BAURD_RATE_57600
	UBRRH = 0;
	UBRRL = 8;
#elif UART_u8BAURD_RATE==UART_u8BAURD_RATE_76800
	UBRRH = 0;
	UBRRL = 6;
#elif UART_u8BAURD_RATE==UART_u8BAURD_RATE_115200
	UBRRH = 0;
	UBRRL = 3;
#elif UART_u8BAURD_RATE==UART_u8BAURD_RATE_230400
	UBRRH = 0;
	UBRRL = 1;
#elif UART_u8BAURD_RATE==UART_u8BAURD_RATE_250000
	UBRRH = 0;
	UBRRL = 1;
#elif UART_u8BAURD_RATE==UART_u8BAURD_RATE_500000
	UBRRH = 0;
	UBRRL = 0;
#endif


	/*Assign in UCSRC Register*/
	UCSRC = Reg_Value;
}

void Uart_vidSendData(u16 Data)
{
	/* wait until the UDR register is Empty */
	while(GET_BIT(UCSRA,5) == 0);
#if UART_u8CHAR_SIZE==UART_u8CHAR_SIZE_9_bit
	UDR = (u8)Data;
	UCSRB |=  GET_BIT(UCSRA,8);
#else
	UDR = (u8)Data;
#endif
}

u16   Uart_u8ReceiveData(void)
{
	/* wait until Rx Complete Flag = 1 */
	while(GET_BIT(UCSRA,7) == 0);

#if UART_u8CHAR_SIZE==UART_u8CHAR_SIZE_9_bit
	return UDR|GET_BIT(UCSRA,8);
#else
	return (u16) UDR;
#endif

}

void Uart_vidSetInterrupt(u8 Interrupt_ID ,void(*pFun)(void))
{

	SET_BIT(SREG,7);
	if(Interrupt_ID==UART_u8Interrupt_RX_COM)
	{
		SET_BIT(UCSRB,7);// enable Rx interrupt
		UART_RX_COM_ISR=pFun;
	}
	else if(Interrupt_ID==UART_u8Interrupt_DATA_EMPTY)
	{
		SET_BIT(UCSRB,5);// enable data register empty interrupt
		UART_DATA_EMPTY_ISR=pFun;
	}
	else if(Interrupt_ID==UART_u8Interrupt_TX_COM)
	{
		SET_BIT(UCSRB,6);// enable Tx interrupt
		UART_TX_COM_ISR=pFun;
	}
}

void __vector_13 (void)//USART RX complete
{
	UART_RX_COM_ISR();
}
void __vector_14 (void)//USART DATA empty
{
	UART_DATA_EMPTY_ISR();
}
void __vector_15 (void)//USART TX complete
{
	UART_TX_COM_ISR();
}
