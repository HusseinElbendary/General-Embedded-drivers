/*
 * Time_cfg.h
 *
 *  Created on: Sep 14, 2019
 *      Author: Na
 */

#ifndef TIME_CFG_H_
#define TIME_CFG_H_

/*******************************************************/

#define TIMER_u8T0_NORMAL_MOOD 		0/*timer 0 normal mood*/
#define TIMER_u8T0_PWM_PHASE_MOOD 	1/*timer 0 PWM and phase correct mood*/
#define TIMER_u8T0_CTC_MOOD 		2/*timer 0 CTC with OCR as top mood*/
#define TIMER_u8T0_FPWM_MOOD		3/*timer 0 Fast PWM mood*/

#define TIMER_u8T0_PRESCALE_X1 			0 /*timer 1 prescale*/
#define TIMER_u8T0_PRESCALE_X8 			1
#define TIMER_u8T0_PRESCALE_X64 		2
#define TIMER_u8T0_PRESCALE_X256 		3
#define TIMER_u8T0_PRESCALE_X1024 		4
#define TIMER_u8T0_PRESCALE_EXT_FALLING 5 /*external clock source on falling edge on T1 pin*/
#define TIMER_u8T0_PRESCALE_EXT_RISING  6 /*external clock source on rising edge on T1 pin*/

/*timer 0 normal mood moods*/
#define TIMER_u8T0_NML_NML 	0/* normal port operation, OC0 DC*/
#define TIMER_u8T0_NML_TGLCMP	1/* toggle OC0 on compare match*/
#define TIMER_u8T0_NML_CLRCMP  2/* Clear OC0 on compare match */
#define TIMER_u8T0_NML_STCMP 	3/* Set OC0 on compare match */

/*timer 0 fast pwm moods */
#define TIMER_u8T0_FPWM_NML 		0 /* normal fast pwm*/
#define TIMER_u8T0_FPWM_CLRCMP_STTP 1 /* clear on compare, set on top*/
#define TIMER_u8T0_FPWM_STCMP_CLRTP 2 /* set on compare,clear on top*/

/*timer 0 phase correct PWM moods */
#define TIMER_u8T0_Phase_NML 		 0 /* normal fast pwm*/
#define TIMER_u8T0_PHASE_CLRUP_STDWN 1 /* phase correction, clear on compare counting up and set on compare counting down*/
#define TIMER_u8T0_PHASE_STUP_CLRDWN 2 /*phase correction,Set on compare counting up and Clear on compare counting down*/


#define TIMER_u8T1_NORMAL_MOOD	 	0 /*timer 1 normal mood*/
#define TIMER_u8T1_PHASE_8BIT	 	1 /*timer 1 phase correction 8 bit mood*/
#define TIMER_u8T1_PHASE_9BIT		2 /*timer 1 phase correction 9 bit mood*/
#define TIMER_u8T1_PHASE_10BIT	 	3 /*timer 1 phase correction 10 bit mood*/
#define TIMER_u8T1_CTC_OCR		 	4 /*timer 1 compare mood on OCR1A as TOP*/
#define TIMER_u8T1_FPWM_8BIT 	 	5 /*timer 1 Fast PWM 8 BIT mood*/
#define TIMER_u8T1_FPWM_9BIT 	 	6 /*timer 1 Fast PWM 9 BIT mood*/
#define TIMER_u8T1_FPWM_10BIT	 	7 /*timer 1 Fast PWM 10 BIT mood*/
#define TIMER_u8T1_PHASE_FREQ_ICR 	8 /*timer 1 phase and frequency correction using ICR1A as top*/
#define TIMER_u8T1_PHASE_FREQ_OCR	9 /*timer 1 phase and frequency correction using OCR1A as top*/
#define TIMER_u8T1_PHASE_ICR 		10 /*timer 1 phase correction using ICR1A as top*/
#define TIMER_u8T1_PHASE_OCR 		11 /*timer 1 phase correction using OCR1A as top*/
#define TIMER_u8T1_CTC_ICR 			12 /*timer 1 Compare mood using ICR1A as top*/
#define TIMER_u8T1_FPWM_ICR 		13 /*timer 1 Fast pwm using ICR1A as top*/
#define TIMER_u8T1_FPWM_OCR 		14 /*timer 1 Fast pwm using OCR1A as top*/


#define TIMER_u8T1_PRESCALE_X1 			0 /*timer 1 prescale*/
#define TIMER_u8T1_PRESCALE_X8 			1
#define TIMER_u8T1_PRESCALE_X64 		2
#define TIMER_u8T1_PRESCALE_X256 		3
#define TIMER_u8T1_PRESCALE_X1024 		4
#define TIMER_u8T1_PRESCALE_EXT_FALLING 5 /*external clock source on falling edge on T1 pin*/
#define TIMER_u8T1_PRESCALE_EXT_RISING  6 /*external clock source on rising edge on T1 pin*/

/*timer 1 normal mood*/
#define TIMER_u8T1_NML_NML 	0/* normal port operation, OC1A/B DC*/
#define TIMER_u8T1_NML_TGLCMP	1/* toggle OC1A/B on compare match*/
#define TIMER_u8T1_NML_CLRCMP  2/* Clear OC1A/B on compare match */
#define TIMER_u8T1_NML_STCMP 	3/* Set OC1A/B on compare match */


/*timer 1 fast pwm moods */
#define TIMER_u8T1_FPWM_NML 0 /* normal fast pwm OC1A/B are dc*/
#define TIMER_u8T1_FPWM_TGLCMP_A 1 /*toggle OC1A on compare ,OC1B is dc( if WGM = 15)*/
#define TIMER_u8T1_FPWM_CLRCMP_STBTM 2 /* clear OC1A/OC1B on compare, set on bottom*/
#define TIMER_u8T1_FPWM_STCMP_CLRBTM 3/* set OC1A/OC1B on compare,clear on bottom*/

/*timer 1 phase correct moods */
#define TIMER_u8T1_PHASE_NML 0 /* normal phase correction mood*/
#define TIMER_u8T1_PHASE_TGLCMP 1 /*  phase correction,toggle OC1A on compare ( if WGM = 9 or 4), OC1B is DC*/
#define TIMER_u8T1_PHASE_CLRUP_STDWN 2 /* phase correction, clear on compare counting up and set on compare counting down*/
#define TIMER_u8T1_PHASE_STUP_CLRDWN 3/*phase correction,Set on compare counting up and Clear on compare counting down*/






#define TIMER_u8T2_NORMAL_MOOD 		0/*timer 2 normal mood*/
#define TIMER_u8T2_PWM_PHASE_MOOD 	1/*timer 2 PWM and phase correct mood*/
#define TIMER_u8T2_CTC_MOOD 		2/*timer 2 CTC with OCR as top mood*/
#define TIMER_u8T2_FPWM_MOOD		3/*timer 2 Fast PWM mood*/

#define TIMER_u8T2_PRESCALE_X1 			0 /*timer 2 prescale*/
#define TIMER_u8T2_PRESCALE_X8 			1
#define TIMER_u8T2_PRESCALE_X32 		2
#define TIMER_u8T2_PRESCALE_X64 		3
#define TIMER_u8T2_PRESCALE_X128		4
#define TIMER_u8T2_PRESCALE_X256 		5
#define TIMER_u8T2_PRESCALE_X1024 		6

/*timer 0 normal mood moods*/
#define TIMER_u8T2_NML_NML 	0/* normal port operation, OC0 DC*/
#define TIMER_u8T2_NML_TGLCMP	1/* toggle OC2 on compare match*/
#define TIMER_u8T2_NML_CLRCMP  2/* Clear OC2 on compare match */
#define TIMER_u8T2_NML_STCMP 	3/* Set OC2 on compare match */

/*timer 0 fast pwm moods */
#define TIMER_u8T2_FPWM_NML 		0 /* normal fast pwm*/
#define TIMER_u8T2_FPWM_CLRCMP_STTP 1 /* clear on compare, set on top*/
#define TIMER_u8T2_FPWM_STCMP_CLRTP 2 /* set on compare,clear on top*/

/*timer 0 phase correct PWM moods */
#define TIMER_u8T2_Phase_NML 		 0 /* normal fast pwm*/
#define TIMER_u8T2_PHASE_CLRUP_STDWN 1 /* phase correction, clear on compare counting up and set on compare counting down*/
#define TIMER_u8T2_PHASE_STUP_CLRDWN 2 /*phase correction,Set on compare counting up and Clear on compare counting down*/


/*************************config options**************************/

#define TIMER_u8T0_MOOD TIMER_u8T0_NORMAL_MOOD
#define TIMER_u8T0_PRESCALE TIMER_u8T0_PRESCALE_X1
#define TIMER_u8T0_NML_MOOD_TYPE TIMER_u8T0_NML_NML/** only for TIMER_u8T0_MOOD =TIMER_u8T0_NML_MOOD**/
#define TIMER_u8T0_FPWM_MOOD_TYPE TIMER_u8T0_FPWM_CLRCMP_STTP/** only for TIMER_u8T0_MOOD =TIMER_u8T0_FPWM_MOOD**/
#define TIMER_u8T0_PHASE_MOOD_TYPE TIMER_u8T0_Phase_NML/** only for TIMER_u8T0_MOOD =TIMER_u8T0_FPWM_MOOD**/

#define TIMER_u8T1_MOOD TIMER_u8T1_FPWM_ICR
#define TIMER_u8T1_PRESCALE TIMER_u8T1_PRESCALE_X8
#define TIMER_u8T1_NML_MOOD_TYPE_A TIMER_u8T1_NML_NML
#define TIMER_u8T1_NML_MOOD_TYPE_B TIMER_u8T1_NML_NML
#define TIMER_u8T1_PHASE_MOOD_TYPE_A TIMER_u8T1_PHASE_NML
#define TIMER_u8T1_PHASE_MOOD_TYPE_B TIMER_u8T1_PHASE_NML
#define TIMER_u8T1_FPWM_MOOD_TYPE_A TIMER_u8T1_FPWM_CLRCMP_STBTM
#define TIMER_u8T1_FPWM_MOOD_TYPE_B TIMER_u8T1_FPWM_CLRCMP_STBTM

#define TIMER_u8T2_MOOD TIMER_u8T2_NORMAL_MOOD
#define TIMER_u8T2_PRESCALE TIMER_u8T2_PRESCALE_X1024
#define TIMER_u8T2_NML_MOOD_TYPE TIMER_u8T2_NML_NML /** only for TIMER_u8T2_MOOD =TIMER_u8T2_NML_MOOD**/
#define TIMER_u8T2_FPWM_MOOD_TYPE TIMER_u8T2_FPWM_CLRCMP_STTP/** only for TIMER_u8T2_MOOD =TIMER_u8T2_FPWM_MOOD**/
#define TIMER_u8T2_PHASE_MOOD_TYPE TIMER_u8T2_Phase_NML/** only for TIMER_u8T2_MOOD =TIMER_u8T2_FPWM_MOOD**/

#endif /* TIME_CFG_H_ */
