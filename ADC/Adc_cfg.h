/*
 * Adc_cfg.h
 *
 *  Created on: 11 Sep 2019
 *      Author: coder
 */

#ifndef ADC_CFG_H_
#define ADC_CFG_H_

#define ADC_u8AREF 0
#define ADC_u8AVCC 1
#define ADC_u8AREF_256 2

#define ADC_u8RIGHT_ADJUST 0
#define ADC_u8LEFT_ADJUST  1

#define ADC_u8AutoTrigger_Off 0
#define ADC_u8AutoTrigger_On 1

#define ADC_u8TriggerSource_FREE_RUNNING 0
#define ADC_u8TriggerSource_ANALOG_COMPARATOR 1
#define ADC_u8TriggerSource_EXTERNAL_INTERRUPT_0 2
#define ADC_u8TriggerSource_TIMER0_COMPARE_MATCH 3
#define ADC_u8TriggerSource_TIMER0_OVERFLOW 4
#define ADC_u8TriggerSource_TIMER1_COMPARE_MATCHB 5
#define ADC_u8TriggerSource_TIMER1_OVERFLOW 6
#define ADC_u8TriggerSource_TIMER1_CAPTURE_EVENT 7


#define ADC_u8PRESCALE_x2	0
#define ADC_u8PRESCALE_x4	1
#define ADC_u8PRESCALE_x8	2
#define ADC_u8PRESCALE_x16	3
#define ADC_u8PRESCALE_x32	4
#define ADC_u8PRESCALE_x64	5
#define ADC_u8PRESCALE_x128	6
/*------------Mode Configurations------------*/

#define ADC_u8VREF ADC_u8AVCC

#define ADC_u8ADJUST  ADC_u8RIGHT_ADJUST

#define ADC_u8AutoTrigger ADC_u8AutoTrigger_On

#define ADC_u8TriggerSource ADC_u8TriggerSource_EXTERNAL_INTERRUPT_0

#define ADC_u8PRESCALE ADC_u8PRESCALE_x8

#endif /* ADC_CFG_H_ */
