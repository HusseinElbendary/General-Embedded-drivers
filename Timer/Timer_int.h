/*
 * Timer_int.h
 *
 *  Created on: Sep 14, 2019
 *      Author: Na
 */

#ifndef TIMER_INT_H_
#define TIMER_INT_H_


#define TIMER_u8TIMER_0  0
#define TIMER_u8TIMER_1A 1
#define TIMER_u8TIMER_1B 2
#define TIMER_u8TIMER_1  3
#define TIMER_u8TIMER_2  4

#define TIMER_u8T0_CMP_INTERRUPT	0
#define TIMER_u8T0_OV_INTERRUPT 	1
#define TIMER_u8T1A_CMP_INTERRUPT 	2
#define TIMER_u8T1B_CMP_INTERRUPT 	3
#define TIMER_u8T1_OV_INTERRUPT 	4
#define TIMER_u8T1_IN_CAP_INTERRUPT 5
#define TIMER_u8T2_CMP_INTERRUPT 	6
#define TIMER_u8T2_OV_INTERRUPT 	7

#define TIMER_u8T0_OV_FLAG 		0
#define TIMER_u8T0_CMP_FLAG 	1
#define TIMER_u8T1_OV_FLAG 		2
#define TIMER_u8T1A_CMP_FLAG 	3
#define TIMER_u8T1B_CMP_FLAG 	4
#define TIMER_u8T1_IN_CAP_FLAG  5
#define TIMER_u8T2_OV_FLAG 		6
#define TIMER_u8T2_CMP_FLAG 	7



void Timer_vidInit(u8 Timer_ID);
void Timer_vidStartTimer(u8 Timer_ID);
void Timer_vidStopTimer(u8 Timer_ID);
void Timer_vidSetICR1(u16 val);
void Timer_vidSetCompareValue(u8 Timer_ID,u16 val);
void Timer_vidSetTimerValue(u8 Timer_ID,u16 val);
void Timer_vidSetInterrupt(u8 Interrupt_ID);
void Timer_vidClearInterrupt(u8 Interrupt_ID);
u8 Timer_u8CheckOVFlag(u8 Timer_ID);
u8 Timer_u8CheckCompareFlag(u8 Timer_ID);
u16  Timer_u16GetTimerValue(u8 Timer_ID);

#endif /* TIMER_INT_H_ */
