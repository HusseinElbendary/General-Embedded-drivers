/*
 * Uart_int.h
 *
 *  Created on: Sep 28, 2019
 *      Author: yomna
 */

#ifndef UART_INT_H_
#define UART_INT_H_

#define UART_u8Interrupt_RX_COM 	0
#define UART_u8Interrupt_DATA_EMPTY 1
#define UART_u8Interrupt_TX_COM 	2


void Uart_vidInit(void);

void Uart_vidSendData(u16 Data);

u16   Uart_u8ReceiveData(void);

void Uart_vidSetInterrupt(u8 Interrupt_ID ,void(*pFun)(void));

#endif /* UART_INT_H_ */
