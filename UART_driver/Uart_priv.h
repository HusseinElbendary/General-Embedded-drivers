/*
 * Uart_priv.h
 *
 *  Created on: Sep 28, 2019
 *      Author: yomna
 */

#ifndef UART_PRIV_H_
#define UART_PRIV_H_


#define UDR     *((volatile u8*)  0x2C  )
#define UCSRA   *((volatile u8*)  0x2B  )
#define UCSRB   *((volatile u8*)  0x2A  )
#define UCSRC   *((volatile u8*)  0x40  )
#define UBRRL   *((volatile u8*)  0x29  )
#define UBRRH   *((volatile u8*)  0x40  )

#define SREG    *((volatile u8*)  0x5F  )


void __vector_13 (void) __attribute__ ((single,__INTR_ATTRS ));
void __vector_14 (void) __attribute__ ((single,__INTR_ATTRS ));
void __vector_15 (void) __attribute__ ((single,__INTR_ATTRS ));

#endif /* UART_PRIV_H_ */
