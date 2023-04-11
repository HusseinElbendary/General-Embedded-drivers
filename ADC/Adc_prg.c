/*
 * Adc_prg.c
 *
 *  Created on: 11 Sep 2019
 *      Author: coder
 */

#include "Std_types.h"
#include "Bit_math.h"

#include <avr/io.h>

#define F_CPU 8000000
#include <util/delay.h>

#include "Adc_cfg.h"
#include "Adc_int.h"

void Adc_vidInit(void)
{
#if ADC_u8VREF == ADC_u8AREF
	CLEAR_BIT(ADMUX,7);
	CLEAR_BIT(ADMUX,6);

#elif ADC_u8VREF == ADC_u8AVCC
	CLEAR_BIT(ADMUX,7);
	SET_BIT(ADMUX,6);

#elif ADC_u8VREF == ADC_u8AREF_256 // Vref=2.56volt
	SET_BIT(ADMUX,7);
	SET_BIT(ADMUX,6);

#endif

#if ADC_u8ADJUST==ADC_u8RIGHT_ADJUST
	CLEAR_BIT(ADMUX,5);
#elif ADC_u8ADJUST==ADC_u8LEFT_ADJUST
	SET_BIT(ADMUX,5);
#endif

	SET_BIT(ADCSRA,7); //enable ADC

#if ADC_u8AutoTrigger == ADC_u8AutoTrigger_Off
	CLEAR_BIT(ADCSRA,5);
#elif ADC_u8AutoTrigger == ADC_u8AutoTrigger_On

#if ADC_u8TriggerSource==ADC_u8TriggerSource_FREE_RUNNING
	CLEAR_BIT(SFIOR,7);
	CLEAR_BIT(SFIOR,6);
	CLEAR_BIT(SFIOR,5);
#elif ADC_u8TriggerSource==ADC_u8TriggerSource_ANALOG_COMPARATOR
	CLEAR_BIT(SFIOR,7);
	CLEAR_BIT(SFIOR,6);
	SET_BIT(SFIOR,5);
#elif ADC_u8TriggerSource==ADC_u8TriggerSource_EXTERNAL_INTERRUPT_0
	CLEAR_BIT(SFIOR,7);
	SET_BIT(SFIOR,6);
	CLEAR_BIT(SFIOR,5);
#elif ADC_u8TriggerSource==ADC_u8TriggerSource_TIMER0_COMPARE_MATCH
	CLEAR_BIT(SFIOR,7);
	SET_BIT(SFIOR,6);
	SET_BIT(SFIOR,5);
#elif ADC_u8TriggerSource==ADC_u8TriggerSource_TIMER0_OVERFLOW
	SET_BIT(SFIOR,7);
	CLEAR_BIT(SFIOR,6);
	CLEAR_BIT(SFIOR,5);
#elif ADC_u8TriggerSource==ADC_u8TriggerSource_TIMER1_COMPARE_MATCHB
	SET_BIT(SFIOR,7);
	CLEAR_BIT(SFIOR,6);
	SET_BIT(SFIOR,5);
#elif ADC_u8TriggerSource==ADC_u8TriggerSource_TIMER1_OVERFLOW
	SET_BIT(SFIOR,7);
	SET_BIT(SFIOR,6);
	CLEAR_BIT(SFIOR,5);
#elif ADC_u8TriggerSource==ADC_u8TriggerSource_TIMER1_CAPTURE_EVENT
	SET_BIT(SFIOR,7);
	SET_BIT(SFIOR,6);
	SET_BIT(SFIOR,5);
#endif

#endif

	CLEAR_BIT(ADCSRA,3);

#if ADC_u8PRESCALE == ADC_u8PRESCALE_x2
	CLEAR_BIT(ADCSRA,2);
	CLEAR_BIT(ADCSRA,1);
	CLEAR_BIT(ADCSRA,0);
#elif ADC_u8PRESCALE == ADC_u8PRESCALE_x4
	CLEAR_BIT(ADCSRA,2);
	SET_BIT(ADCSRA,1);
	CLEAR_BIT(ADCSRA,0);
#elif ADC_u8PRESCALE == ADC_u8PRESCALE_x8
	CLEAR_BIT(ADCSRA,2);
	SET_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,0);
#elif ADC_u8PRESCALE == ADC_u8PRESCALE_x16
	SET_BIT(ADCSRA,2);
	CLEAR_BIT(ADCSRA,1);
	CLEAR_BIT(ADCSRA,0);
#elif ADC_u8PRESCALE == ADC_u8PRESCALE_x32
	SET_BIT(ADCSRA,2);
	CLEAR_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,0);
#elif ADC_u8PRESCALE == ADC_u8PRESCALE_x64
	SET_BIT(ADCSRA,2);
	SET_BIT(ADCSRA,1);
	CLEAR_BIT(ADCSRA,0);
#elif ADC_u8PRESCALE == ADC_u8PRESCALE_x128
	SET_BIT(ADCSRA,2);
	SET_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,0);
#endif


}


u16 Adc_u16ConvertChannel(u8 Channel)
{
	u8 Reg_value;
	u16 Adc_result=0;
	Reg_value=(ADMUX&0xE0)|(Channel);
	ADMUX=Reg_value;

#if ADC_u8AutoTrigger == ADC_u8AutoTrigger_Off
	SET_BIT(ADCSRA,6);
#endif

	while(!GET_BIT(ADCSRA,4));
	SET_BIT(ADCSRA,4);

#if ADC_u8ADJUST==ADC_u8RIGHT_ADJUST
	Adc_result=ADCL;
	Adc_result|=(ADCH<<8);
#elif ADC_u8ADJUST==ADC_u8LEFT_ADJUST
	Adc_result=ADCH;
#endif

	return Adc_result;



}
