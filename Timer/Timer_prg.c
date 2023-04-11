/*
 * Timer_prg.c
 *
 *  Created on: Sep 14, 2019
 *      Author: Na
 */

#include "Std_types.h"
#include "Bit_math.h"

#include <avr/io.h>

#include "Time_cfg.h"
#include "Timer_int.h"


void Timer_vidInit(u8 ID)
{
	if(ID ==TIMER_u8TIMER_0)
	{
#if TIMER_u8T0_MOOD==TIMER_u8T0_NORMAL_MOOD
		CLEAR_BIT(TCCR0,6);
		CLEAR_BIT(TCCR0,3);

#if TIMER_u8T0_NML_MOOD_TYPE==TIMER_u8T0_NML_NML
		CLEAR_BIT(TCCR0,5);
		CLEAR_BIT(TCCR0,4);
#elif TIMER_u8T0_NML_MOOD_TYPE==TIMER_u8T0_NML_TGLCMP
		CLEAR_BIT(TCCR0,5);
		SET_BIT(TCCR0,4);
#elif TIMER_u8T0_NML_MOOD_TYPE==TIMER_u8T0_NML_CLRCMP
		SET_BIT(TCCR0,5);
		CLEAR_BIT(TCCR0,4);
#elif TIMER_u8T0_NML_MOOD_TYPE==TIMER_u8T0_NML_STCMP
		SET_BIT(TCCR0,5);
		SET_BIT(TCCR0,4);
#endif

#elif TIMER_u8T0_MOOD==TIMER_u8T0_PWM_PHASE_MOOD
		CLEAR_BIT(TCCR0,6);
		SET_BIT(TCCR0,3);

#if TIMER_u8T0_PHASE_MOOD_TYPE==TIMER_u8T0_Phase_NML
		CLEAR_BIT(TCCR0,5);
		CLEAR_BIT(TCCR0,4);
#elif TIMER_u8T0_PHASE_MOOD_TYPE==TIMER_u8T0_PHASE_CLRUP_STDWN
		SET_BIT(TCCR0,5);
		CLEAR_BIT(TCCR0,4);
#elif TIMER_u8T0_PHASE_MOOD_TYPE==TIMER_u8T0_PHASE_STUP_CLRDWN
		SET_BIT(TCCR0,5);
		SET_BIT(TCCR0,4);
#endif


#elif TIMER_u8T0_MOOD==TIMER_u8T0_CTC_MOOD
		SET_BIT(TCCR0,6);
		CLEAR_BIT(TCCR0,3);

#if TIMER_u8T0_NML_MOOD_TYPE==TIMER_u8T0_NML_NML
		CLEAR_BIT(TCCR0,5);
		CLEAR_BIT(TCCR0,4);
#elif TIMER_u8T0_NML_MOOD_TYPE==TIMER_u8T0_NML_TGLCMP
		CLEAR_BIT(TCCR0,5);
		SET_BIT(TCCR0,4);
#elif TIMER_u8T0_NML_MOOD_TYPE==TIMER_u8T0_NML_CLRCMP
		SET_BIT(TCCR0,5);
		CLEAR_BIT(TCCR0,4);
#elif TIMER_u8T0_NML_MOOD_TYPE==TIMER_u8T0_NML_STCMP
		SET_BIT(TCCR0,5);
		SET_BIT(TCCR0,4);
#endif


#elif TIMER_u8T0_MOOD==TIMER_u8T0_FPWM_MOOD
		SET_BIT(TCCR0,6);
		SET_BIT(TCCR0,3);

#if TIMER_u8T0_FPWM_MOOD_TYPE==TIMER_u8T0_FPWM_NML
		CLEAR_BIT(TCCR0,5);
		CLEAR_BIT(TCCR0,4);
#elif TIMER_u8T0_FPWM_MOOD_TYPE==TIMER_u8T0_FPWM_CLRCMP_STTP
		SET_BIT(TCCR0,5);
		CLEAR_BIT(TCCR0,4);
#elif TIMER_u8T0_FPWM_MOOD_TYPE==TIMER_u8T0_FPWM_STCMP_CLRTP
		SET_BIT(TCCR0,5);
		SET_BIT(TCCR0,4);
#endif

#endif

	}/* end of timer 0*/

	else if(ID ==TIMER_u8TIMER_1A)
	{
#if   TIMER_u8T1_MOOD==TIMER_u8T1_NORMAL_MOOD
		/*setting WGM bits*/
		CLEAR_BIT(TCCR1B,4);
		CLEAR_BIT(TCCR1B,3);
		CLEAR_BIT(TCCR1A,1);
		CLEAR_BIT(TCCR1A,0);

		/* setting COM1A bits*/
#if TIMER_u8T1_NML_MOOD_TYPE_A==TIMER_u8T1_NML_NML
		CLEAR_BIT(TCCR1A,7);
		CLEAR_BIT(TCCR1A,6);
#elif TIMER_u8T1_NML_MOOD_TYPE_A==TIMER_u8T1_NML_TGLCMP
		CLEAR_BIT(TCCR1A,7);
		SET_BIT(TCCR1A,6);
#elif TIMER_u8T1_NML_MOOD_TYPE_A==TIMER_u8T1_NML_CLRCMP
		SET_BIT(TCCR1A,7);
		CLEAR_BIT(TCCR1A,6);
#elif TIMER_u8T1_NML_MOOD_TYPE_A==TIMER_u8T1_NML_STCMP
		SET_BIT(TCCR1A,7);
		SET_BIT(TCCR1A,6);
#endif
/*********end of normal mood #if**********/


#elif TIMER_u8T1_MOOD==TIMER_u8T1_PHASE_8BIT
		CLEAR_BIT(TCCR1B,4);
		CLEAR_BIT(TCCR1B,3);
		CLEAR_BIT(TCCR1A,1);
		SET_BIT(TCCR1A,0);

		/* setting COM1A bits*/
#if TIMER_u8T1_PHASE_MOOD_TYPE_A==TIMER_u8T1_PHASE_NML
		CLEAR_BIT(TCCR1A,7);
		CLEAR_BIT(TCCR1A,6);
#elif TIMER_u8T1_PHASE_MOOD_TYPE_A==TIMER_u8T1_PHASE_TGLCMP
		CLEAR_BIT(TCCR1A,7);
		SET_BIT(TCCR1A,6);
#elif TIMER_u8T1_PHASE_MOOD_TYPE_A==TIMER_u8T1_PHASE_CLRUP_STDWN
		SET_BIT(TCCR1A,7);
		CLEAR_BIT(TCCR1A,6);
#elif TIMER_u8T1_PHASE_MOOD_TYPE_A==TIMER_u8T1_NML_STCMP
		SET_BIT(TCCR1A,7);
		SET_BIT(TCCR1A,6);
#endif
	/******** end of phase correction  8 bit mood #if********/

#elif TIMER_u8T1_MOOD==TIMER_u8T1_PHASE_9BIT
		CLEAR_BIT(TCCR1B,4);
		CLEAR_BIT(TCCR1B,3);
		SET_BIT(TCCR1A,1);
		CLEAR_BIT(TCCR1A,0);

		/* setting COM1A bits*/
#if TIMER_u8T1_PHASE_MOOD_TYPE_A==TIMER_u8T1_PHASE_NML
		CLEAR_BIT(TCCR1A,7);
		CLEAR_BIT(TCCR1A,6);
#elif TIMER_u8T1_PHASE_MOOD_TYPE_A==TIMER_u8T1_PHASE_TGLCMP
		CLEAR_BIT(TCCR1A,7);
		SET_BIT(TCCR1A,6);
#elif TIMER_u8T1_PHASE_MOOD_TYPE_A==TIMER_u8T1_PHASE_CLRUP_STDWN
		SET_BIT(TCCR1A,7);
		CLEAR_BIT(TCCR1A,6);
#elif TIMER_u8T1_PHASE_MOOD_TYPE_A==TIMER_u8T1_NML_STCMP
		SET_BIT(TCCR1A,7);
		SET_BIT(TCCR1A,6);
#endif

	/******** end of phase correction  9 bit mood #if********/

#elif TIMER_u8T1_MOOD==TIMER_u8T1_PHASE_10BIT
		CLEAR_BIT(TCCR1B,4);
		CLEAR_BIT(TCCR1B,3);
		SET_BIT(TCCR1A,1);
		SET_BIT(TCCR1A,0);

		/* setting COM1A bits*/
#if TIMER_u8T1_PHASE_MOOD_TYPE_A==TIMER_u8T1_PHASE_NML
		CLEAR_BIT(TCCR1A,7);
		CLEAR_BIT(TCCR1A,6);
#elif TIMER_u8T1_PHASE_MOOD_TYPE_A==TIMER_u8T1_PHASE_TGLCMP
		CLEAR_BIT(TCCR1A,7);
		SET_BIT(TCCR1A,6);
#elif TIMER_u8T1_PHASE_MOOD_TYPE_A==TIMER_u8T1_PHASE_CLRUP_STDWN
		SET_BIT(TCCR1A,7);
		CLEAR_BIT(TCCR1A,6);
#elif TIMER_u8T1_PHASE_MOOD_TYPE_A==TIMER_u8T1_NML_STCMP
		SET_BIT(TCCR1A,7);
		SET_BIT(TCCR1A,6);
#endif

	/******** end of phase correction  10 bit mood #if********/

#elif TIMER_u8T1_MOOD==TIMER_u8T1_CTC_OCR
		CLEAR_BIT(TCCR1B,4);
		SET_BIT(TCCR1B,3);
		CLEAR_BIT(TCCR1A,1);
		CLEAR_BIT(TCCR1A,0);

		/* setting COM1A bits*/
#if TIMER_u8T1_NML_MOOD_TYPE_A==TIMER_u8T1_NML_NML
		CLEAR_BIT(TCCR1A,7);
		CLEAR_BIT(TCCR1A,6);
#elif TIMER_u8T1_NML_MOOD_TYPE_A==TIMER_u8T1_NML_TGLCMP
		CLEAR_BIT(TCCR1A,7);
		SET_BIT(TCCR1A,6);
#elif TIMER_u8T1_NML_MOOD_TYPE_A==TIMER_u8T1_NML_CLRCMP
		SET_BIT(TCCR1A,7);
		CLEAR_BIT(TCCR1A,6);
#elif TIMER_u8T1_NML_MOOD_TYPE_A==TIMER_u8T1_NML_STCMP
		SET_BIT(TCCR1A,7);
		SET_BIT(TCCR1A,6);
#endif

/*******end of CTC mood #if*******/


#elif TIMER_u8T1_MOOD==TIMER_u8T1_FPWM_8BIT
		CLEAR_BIT(TCCR1B,4);
		SET_BIT(TCCR1B,3);
		CLEAR_BIT(TCCR1A,1);
		SET_BIT(TCCR1A,0);
		/* setting COM1A bits*/
#if TIMER_u8T1_FPWM_MOOD_TYPE_A==TIMER_u8T1_FPWM_NML
		CLEAR_BIT(TCCR1A,7);
		CLEAR_BIT(TCCR1A,6);
#elif TIMER_u8T1_FPWM_MOOD_TYPE_A==TIMER_u8T1_FPWM_TGLCMP_A
		CLEAR_BIT(TCCR1A,7);
		SET_BIT(TCCR1A,6);
#elif TIMER_u8T1_FPWM_MOOD_TYPE_A==TIMER_u8T1_FPWM_CLRCMP_STBTM
		SET_BIT(TCCR1A,7);
		CLEAR_BIT(TCCR1A,6);
#elif TIMER_u8T1_FPWM_MOOD_TYPE_A==TIMER_u8T1_FPWM_STCMP_CLRBTM
		SET_BIT(TCCR1A,7);
		SET_BIT(TCCR1A,6);
#endif

/*******end of Timer 1 Fast PWM 8-BIT mood #if*******/

#elif TIMER_u8T1_MOOD==TIMER_u8T1_FPWM_9BIT
		CLEAR_BIT(TCCR1B,4);
		SET_BIT(TCCR1B,3);
		SET_BIT(TCCR1A,1);
		CLEAR_BIT(TCCR1A,0);
		/* setting COM1A bits*/
#if TIMER_u8T1_FPWM_MOOD_TYPE_A==TIMER_u8T1_FPWM_NML
		CLEAR_BIT(TCCR1A,7);
		CLEAR_BIT(TCCR1A,6);
#elif TIMER_u8T1_FPWM_MOOD_TYPE_A==TIMER_u8T1_FPWM_TGLCMP_A
		CLEAR_BIT(TCCR1A,7);
		SET_BIT(TCCR1A,6);
#elif TIMER_u8T1_FPWM_MOOD_TYPE_A==TIMER_u8T1_FPWM_CLRCMP_STBTM
		SET_BIT(TCCR1A,7);
		SET_BIT(TCCR1A,6);
#elif TIMER_u8T1_FPWM_MOOD_TYPE_A==TIMER_u8T1_FPWM_STCMP_CLRBTM
		SET_BIT(TCCR1A,7);
		SET_BIT(TCCR1A,6);
#endif
/*******end of Timer 1 Fast PWM 9-BIT mood #if*******/

#elif TIMER_u8T1_MOOD==TIMER_u8T1_FPWM_10BIT
		CLEAR_BIT(TCCR1B,4);
		SET_BIT(TCCR1B,3);
		SET_BIT(TCCR1A,1);
		SET_BIT(TCCR1A,0);
		/* setting COM1A bits*/
#if TIMER_u8T1_FPWM_MOOD_TYPE_A==TIMER_u8T1_FPWM_NML
		CLEAR_BIT(TCCR1A,7);
		CLEAR_BIT(TCCR1A,6);
#elif TIMER_u8T1_FPWM_MOOD_TYPE_A==TIMER_u8T1_FPWM_TGLCMP_A
		CLEAR_BIT(TCCR1A,7);
		SET_BIT(TCCR1A,6);
#elif TIMER_u8T1_FPWM_MOOD_TYPE_A==TIMER_u8T1_FPWM_CLRCMP_STBTM
		SET_BIT(TCCR1A,7);
		SET_BIT(TCCR1A,6);
#elif TIMER_u8T1_FPWM_MOOD_TYPE_A==TIMER_u8T1_FPWM_STCMP_CLRBTM
		SET_BIT(TCCR1A,7);
		SET_BIT(TCCR1A,6);
#endif

/*******end of Timer 1 Fast PWM 10-BIT mood #if*******/

#elif TIMER_u8T1_MOOD==TIMER_u8T1_PHASE_FREQ_ICR
		SET_BIT(TCCR1B,4);
		CLEAR_BIT(TCCR1B,3);
		CLEAR_BIT(TCCR1A,1);
		CLEAR_BIT(TCCR1A,0);
		/* setting COM1A bits*/
#if TIMER_u8T1_PHASE_MOOD_TYPE_A==TIMER_u8T1_PHASE_NML
		CLEAR_BIT(TCCR1A,7);
		CLEAR_BIT(TCCR1A,6);
#elif TIMER_u8T1_PHASE_MOOD_TYPE_A==TIMER_u8T1_PHASE_TGLCMP
		CLEAR_BIT(TCCR1A,7);
		SET_BIT(TCCR1A,6);
#elif TIMER_u8T1_PHASE_MOOD_TYPE_A==TIMER_u8T1_PHASE_CLRUP_STDWN
		SET_BIT(TCCR1A,7);
		CLEAR_BIT(TCCR1A,6);
#elif TIMER_u8T1_PHASE_MOOD_TYPE_A==TIMER_u8T1_NML_STCMP
		SET_BIT(TCCR1A,7);
		SET_BIT(TCCR1A,6);
#endif

/*******end of Timer 1 phase and frequency correction on ICR as top  #if*******/

#elif TIMER_u8T1_MOOD==TIMER_u8T1_PHASE_FREQ_OCR
		SET_BIT(TCCR1B,4);
		CLEAR_BIT(TCCR1B,3);
		CLEAR_BIT(TCCR1A,1);
		SET_BIT(TCCR1A,0);

		/* setting COM1A bits*/
#if TIMER_u8T1_PHASE_MOOD_TYPE_A==TIMER_u8T1_PHASE_NML
		CLEAR_BIT(TCCR1A,7);
		CLEAR_BIT(TCCR1A,6);
#elif TIMER_u8T1_PHASE_MOOD_TYPE_A==TIMER_u8T1_PHASE_TGLCMP
		CLEAR_BIT(TCCR1A,7);
		SET_BIT(TCCR1A,6);
#elif TIMER_u8T1_PHASE_MOOD_TYPE_A==TIMER_u8T1_PHASE_CLRUP_STDWN
		SET_BIT(TCCR1A,7);
		CLEAR_BIT(TCCR1A,6);
#elif TIMER_u8T1_PHASE_MOOD_TYPE_A==TIMER_u8T1_NML_STCMP
		SET_BIT(TCCR1A,7);
		SET_BIT(TCCR1A,6);
#endif

/*******end of Timer 1 phase and frequency correction on OCR as top  #if*******/


#elif TIMER_u8T1_MOOD==TIMER_u8T1_PHASE_ICR
		SET_BIT(TCCR1B,4);
		CLEAR_BIT(TCCR1B,3);
		SET_BIT(TCCR1A,1);
		CLEAR_BIT(TCCR1A,0);

		/* setting COM1A bits*/
#if TIMER_u8T1_PHASE_MOOD_TYPE_A==TIMER_u8T1_PHASE_NML
		CLEAR_BIT(TCCR1A,7);
		CLEAR_BIT(TCCR1A,6);
#elif TIMER_u8T1_PHASE_MOOD_TYPE_A==TIMER_u8T1_PHASE_TGLCMP
		CLEAR_BIT(TCCR1A,7);
		SET_BIT(TCCR1A,6);
#elif TIMER_u8T1_PHASE_MOOD_TYPE_A==TIMER_u8T1_PHASE_CLRUP_STDWN
		SET_BIT(TCCR1A,7);
		CLEAR_BIT(TCCR1A,6);
#elif TIMER_u8T1_PHASE_MOOD_TYPE_A==TIMER_u8T1_NML_STCMP
		SET_BIT(TCCR1A,7);
		SET_BIT(TCCR1A,6);
#endif

/*******end of Timer 1 phase correction on ICR as top  #if*******/


#elif TIMER_u8T1_MOOD==TIMER_u8T1_PHASE_OCR
		SET_BIT(TCCR1B,4);
		CLEAR_BIT(TCCR1B,3);
		SET_BIT(TCCR1A,1);
		SET_BIT(TCCR1A,0);

		/* setting COM1A bits*/
#if TIMER_u8T1_PHASE_MOOD_TYPE_A==TIMER_u8T1_PHASE_NML
		CLEAR_BIT(TCCR1A,7);
		CLEAR_BIT(TCCR1A,6);
#elif TIMER_u8T1_PHASE_MOOD_TYPE_A==TIMER_u8T1_PHASE_TGLCMP
		CLEAR_BIT(TCCR1A,7);
		SET_BIT(TCCR1A,6);
#elif TIMER_u8T1_PHASE_MOOD_TYPE_A==TIMER_u8T1_PHASE_CLRUP_STDWN
		SET_BIT(TCCR1A,7);
		CLEAR_BIT(TCCR1A,6);
#elif TIMER_u8T1_PHASE_MOOD_TYPE_A==TIMER_u8T1_NML_STCMP
		SET_BIT(TCCR1A,7);
		SET_BIT(TCCR1A,6);
#endif

/*******end of Timer 1 phase and correction on OCR as top  #if*******/


#elif TIMER_u8T1_MOOD==TIMER_u8T1_CTC_ICR
		SET_BIT(TCCR1B,4);
		SET_BIT(TCCR1B,3);
		CLEAR_BIT(TCCR1A,1);
		CLEAR_BIT(TCCR1A,0);

		/* setting COM1A bits*/
#if TIMER_u8T1_NML_MOOD_TYPE_A==TIMER_u8T1_NML_NML
		CLEAR_BIT(TCCR1A,7);
		CLEAR_BIT(TCCR1A,6);
#elif TIMER_u8T1_NML_MOOD_TYPE_A==TIMER_u8T1_NML_TGLCMP
		CLEAR_BIT(TCCR1A,7);
		SET_BIT(TCCR1A,6);
#elif TIMER_u8T1_NML_MOOD_TYPE_A==TIMER_u8T1_NML_CLRCMP
		SET_BIT(TCCR1A,7);
		CLEAR_BIT(TCCR1A,6);
#elif TIMER_u8T1_NML_MOOD_TYPE_A==TIMER_u8T1_NML_STCMP
		SET_BIT(TCCR1A,7);
		SET_BIT(TCCR1A,6);
#endif

/*******end of CTC on ICR #if*******/
#elif TIMER_u8T1_MOOD==TIMER_u8T1_FPWM_ICR
		SET_BIT(TCCR1B,4);
		SET_BIT(TCCR1B,3);
		SET_BIT(TCCR1A,1);
		CLEAR_BIT(TCCR1A,0);

		/* setting COM1A bits*/
#if TIMER_u8T1_FPWM_MOOD_TYPE_A==TIMER_u8T1_FPWM_NML
		CLEAR_BIT(TCCR1A,7);
		CLEAR_BIT(TCCR1A,6);
#elif TIMER_u8T1_FPWM_MOOD_TYPE_A==TIMER_u8T1_FPWM_TGLCMP_A
		CLEAR_BIT(TCCR1A,7);
		SET_BIT(TCCR1A,6);
#elif TIMER_u8T1_FPWM_MOOD_TYPE_A==TIMER_u8T1_FPWM_CLRCMP_STBTM
		SET_BIT(TCCR1A,7);
		CLEAR_BIT(TCCR1A,6);
#elif TIMER_u8T1_FPWM_MOOD_TYPE_A==TIMER_u8T1_FPWM_STCMP_CLRBTM
		SET_BIT(TCCR1A,7);
		SET_BIT(TCCR1A,6);
#endif

/*******end of Timer 1 Fast PWM on ICR as top mood #if*******/



#elif TIMER_u8T1_MOOD==TIMER_u8T1_FPWM_OCR
		SET_BIT(TCCR1B,4);
		SET_BIT(TCCR1B,3);
		SET_BIT(TCCR1A,1);
		SET_BIT(TCCR1A,0);

		/* setting COM1A bits*/
#if TIMER_u8T1_FPWM_MOOD_TYPE_A==TIMER_u8T1_FPWM_NML
		CLEAR_BIT(TCCR1A,7);
		CLEAR_BIT(TCCR1A,6);
#elif TIMER_u8T1_FPWM_MOOD_TYPE_A==TIMER_u8T1_FPWM_TGLCMP_A
		CLEAR_BIT(TCCR1A,7);
		SET_BIT(TCCR1A,6);
#elif TIMER_u8T1_FPWM_MOOD_TYPE_A==TIMER_u8T1_FPWM_CLRCMP_STBTM
		SET_BIT(TCCR1A,7);
		CLEAR_BIT(TCCR1A,6);
#elif TIMER_u8T1_FPWM_MOOD_TYPE_A==TIMER_u8T1_FPWM_STCMP_CLRBTM
		SET_BIT(TCCR1A,7);
		SET_BIT(TCCR1A,6);
#endif
/*******end of Timer 1 Fast PWM on OCR as top mood #if*******/
#endif


	}

	else if(ID ==TIMER_u8TIMER_1B)
	{
#if   TIMER_u8T1_MOOD==TIMER_u8T1_NORMAL_MOOD
		/*setting WGM bits*/
		CLEAR_BIT(TCCR1B,4);
		CLEAR_BIT(TCCR1B,3);
		CLEAR_BIT(TCCR1A,1);
		CLEAR_BIT(TCCR1A,0);

		/* setting COM1B bits*/
#if TIMER_u8T1_NML_MOOD_TYPE_B==TIMER_u8T1_NML_NML
		CLEAR_BIT(TCCR1A,5);
		CLEAR_BIT(TCCR1A,4);
#elif TIMER_u8T1_NML_MOOD_TYPE_B==TIMER_u8T1_NML_TGLCMP
		CLEAR_BIT(TCCR1A,5);
		SET_BIT(TCCR1A,4);
#elif TIMER_u8T1_NML_MOOD_TYPE_B==TIMER_u8T1_NML_CLRCMP
		SET_BIT(TCCR1A,5);
		CLEAR_BIT(TCCR1A,4);
#elif TIMER_u8T1_NML_MOOD_TYPE_B==TIMER_u8T1_NML_STCMP
		SET_BIT(TCCR1A,5);
		SET_BIT(TCCR1A,4);
#endif
/*********end of normal mood #if**********/


#elif TIMER_u8T1_MOOD==TIMER_u8T1_PHASE_8BIT
		CLEAR_BIT(TCCR1B,4);
		CLEAR_BIT(TCCR1B,3);
		CLEAR_BIT(TCCR1A,1);
		SET_BIT(TCCR1A,0);


		/* setting COM1B bits*/
#if TIMER_u8T1_PHASE_MOOD_TYPE_B==TIMER_u8T1_PHASE_NML
		CLEAR_BIT(TCCR1A,5);
		CLEAR_BIT(TCCR1A,4);
#elif TIMER_u8T1_PHASE_MOOD_TYPE_B==TIMER_u8T1_PHASE_TGLCMP
		CLEAR_BIT(TCCR1A,5);
		SET_BIT(TCCR1A,4);
#elif TIMER_u8T1_PHASE_MOOD_TYPE_B==TIMER_u8T1_PHASE_CLRUP_STDWN
		SET_BIT(TCCR1A,5);
		CLEAR_BIT(TCCR1A,4);
#elif TIMER_u8T1_PHASE_MOOD_TYPE_B==TIMER_u8T1_PHASE_STUP_CLRDWN
		SET_BIT(TCCR1A,5);
		SET_BIT(TCCR1A,4);
#endif
	/******** end of phase correction  8 bit mood #if********/

#elif TIMER_u8T1_MOOD==TIMER_u8T1_PHASE_9BIT
		CLEAR_BIT(TCCR1B,4);
		CLEAR_BIT(TCCR1B,3);
		SET_BIT(TCCR1A,1);
		CLEAR_BIT(TCCR1A,0);


		/* setting COM1B bits*/
#if TIMER_u8T1_PHASE_MOOD_TYPE_B==TIMER_u8T1_PHASE_NML
		CLEAR_BIT(TCCR1A,5);
		CLEAR_BIT(TCCR1A,4);
#elif TIMER_u8T1_PHASE_MOOD_TYPE_B==TIMER_u8T1_PHASE_TGLCMP
		CLEAR_BIT(TCCR1A,5);
		SET_BIT(TCCR1A,4);
#elif TIMER_u8T1_PHASE_MOOD_TYPE_B==TIMER_u8T1_PHASE_CLRUP_STDWN
		SET_BIT(TCCR1A,5);
		CLEAR_BIT(TCCR1A,4);
#elif TIMER_u8T1_PHASE_MOOD_TYPE_B==TIMER_u8T1_PHASE_STUP_CLRDWN
		SET_BIT(TCCR1A,5);
		SET_BIT(TCCR1A,4);
#endif
	/******** end of phase correction  9 bit mood #if********/

#elif TIMER_u8T1_MOOD==TIMER_u8T1_PHASE_10BIT
		CLEAR_BIT(TCCR1B,4);
		CLEAR_BIT(TCCR1B,3);
		SET_BIT(TCCR1A,1);
		SET_BIT(TCCR1A,0);


		/* setting COM1B bits*/
#if TIMER_u8T1_PHASE_MOOD_TYPE_B==TIMER_u8T1_PHASE_NML
		CLEAR_BIT(TCCR1A,5);
		CLEAR_BIT(TCCR1A,4);
#elif TIMER_u8T1_PHASE_MOOD_TYPE_B==TIMER_u8T1_PHASE_TGLCMP
		CLEAR_BIT(TCCR1A,5);
		SET_BIT(TCCR1A,4);
#elif TIMER_u8T1_PHASE_MOOD_TYPE_B==TIMER_u8T1_PHASE_CLRUP_STDWN
		SET_BIT(TCCR1A,5);
		CLEAR_BIT(TCCR1A,4);
#elif TIMER_u8T1_PHASE_MOOD_TYPE_B==TIMER_u8T1_PHASE_STUP_CLRDWN
		SET_BIT(TCCR1A,5);
		SET_BIT(TCCR1A,4);
#endif
	/******** end of phase correction  10 bit mood #if********/

#elif TIMER_u8T1_MOOD==TIMER_u8T1_CTC_OCR
		CLEAR_BIT(TCCR1B,4);
		SET_BIT(TCCR1B,3);
		CLEAR_BIT(TCCR1A,1);
		CLEAR_BIT(TCCR1A,0);

		/* setting COM1B bits*/
#if TIMER_u8T1_NML_MOOD_TYPE_B==TIMER_u8T1_NML_NML
		CLEAR_BIT(TCCR1A,5);
		CLEAR_BIT(TCCR1A,4);
#elif TIMER_u8T1_NML_MOOD_TYPE_B==TIMER_u8T1_NML_TGLCMP
		CLEAR_BIT(TCCR1A,5);
		SET_BIT(TCCR1A,4);
#elif TIMER_u8T1_NML_MOOD_TYPE_B==TIMER_u8T1_NML_CLRCMP
		SET_BIT(TCCR1A,5);
		CLEAR_BIT(TCCR1A,4);
#elif TIMER_u8T1_NML_MOOD_TYPE_B==TIMER_u8T1_NML_STCMP
		SET_BIT(TCCR1A,5);
		SET_BIT(TCCR1A,4);
#endif
/*******end of CTC mood #if*******/


#elif TIMER_u8T1_MOOD==TIMER_u8T1_FPWM_8BIT
		CLEAR_BIT(TCCR1B,4);
		SET_BIT(TCCR1B,3);
		CLEAR_BIT(TCCR1A,1);
		SET_BIT(TCCR1A,0);

		/* setting COM1B bits*/
#if TIMER_u8T1_FPWM_MOOD_TYPE_B==TIMER_u8T1_FPWM_NML
		CLEAR_BIT(TCCR1A,5);
		CLEAR_BIT(TCCR1A,4);
#elif TIMER_u8T1_FPWM_MOOD_TYPE_B==TIMER_u8T1_FPWM_TGLCMP_A
		CLEAR_BIT(TCCR1A,5);
		SET_BIT(TCCR1A,4);
#elif TIMER_u8T1_FPWM_MOOD_TYPE_B==TIMER_u8T1_FPWM_CLRCMP_STBTM
		SET_BIT(TCCR1A,5);
		CLEAR_BIT(TCCR1A,4);
#elif TIMER_u8T1_FPWM_MOOD_TYPE_B==TIMER_u8T1_FPWM_STCMP_CLRBTM
		SET_BIT(TCCR1A,5);
		SET_BIT(TCCR1A,4);
#endif
/*******end of Timer 1 Fast PWM 8-BIT mood #if*******/

#elif TIMER_u8T1_MOOD==TIMER_u8T1_FPWM_9BIT
		CLEAR_BIT(TCCR1B,4);
		SET_BIT(TCCR1B,3);
		SET_BIT(TCCR1A,1);
		CLEAR_BIT(TCCR1A,0);

		/* setting COM1B bits*/
#if TIMER_u8T1_FPWM_MOOD_TYPE_B==TIMER_u8T1_FPWM_NML
		CLEAR_BIT(TCCR1A,5);
		CLEAR_BIT(TCCR1A,4);
#elif TIMER_u8T1_FPWM_MOOD_TYPE_B==TIMER_u8T1_FPWM_TGLCMP_A
		CLEAR_BIT(TCCR1A,5);
		SET_BIT(TCCR1A,4);
#elif TIMER_u8T1_FPWM_MOOD_TYPE_B==TIMER_u8T1_FPWM_CLRCMP_STBTM
		SET_BIT(TCCR1A,5);
		SET_BIT(TCCR1A,4);
#elif TIMER_u8T1_FPWM_MOOD_TYPE_B==TIMER_u8T1_FPWM_STCMP_CLRBTM
		SET_BIT(TCCR1A,5);
		SET_BIT(TCCR1A,4);
#endif
/*******end of Timer 1 Fast PWM 9-BIT mood #if*******/

#elif TIMER_u8T1_MOOD==TIMER_u8T1_FPWM_10BIT
		CLEAR_BIT(TCCR1B,4);
		SET_BIT(TCCR1B,3);
		SET_BIT(TCCR1A,1);
		SET_BIT(TCCR1A,0);

		/* setting COM1B bits*/
#if TIMER_u8T1_FPWM_MOOD_TYPE_B==TIMER_u8T1_FPWM_NML
		CLEAR_BIT(TCCR1A,5);
		CLEAR_BIT(TCCR1A,4);
#elif TIMER_u8T1_FPWM_MOOD_TYPE_B==TIMER_u8T1_FPWM_TGLCMP_A
		CLEAR_BIT(TCCR1A,5);
		SET_BIT(TCCR1A,4);
#elif TIMER_u8T1_FPWM_MOOD_TYPE_B==TIMER_u8T1_FPWM_CLRCMP_STBTM
		SET_BIT(TCCR1A,5);
		SET_BIT(TCCR1A,4);
#elif TIMER_u8T1_FPWM_MOOD_TYPE_B==TIMER_u8T1_FPWM_STCMP_CLRBTM
		SET_BIT(TCCR1A,5);
		SET_BIT(TCCR1A,4);
#endif
/*******end of Timer 1 Fast PWM 10-BIT mood #if*******/

#elif TIMER_u8T1_MOOD==TIMER_u8T1_PHASE_FREQ_ICR
		SET_BIT(TCCR1B,4);
		CLEAR_BIT(TCCR1B,3);
		CLEAR_BIT(TCCR1A,1);
		CLEAR_BIT(TCCR1A,0);

		/* setting COM1B bits*/
#if TIMER_u8T1_PHASE_MOOD_TYPE_B==TIMER_u8T1_PHASE_NML
		CLEAR_BIT(TCCR1A,5);
		CLEAR_BIT(TCCR1A,4);
#elif TIMER_u8T1_PHASE_MOOD_TYPE_B==TIMER_u8T1_PHASE_TGLCMP
		CLEAR_BIT(TCCR1A,5);
		SET_BIT(TCCR1A,4);
#elif TIMER_u8T1_PHASE_MOOD_TYPE_B==TIMER_u8T1_PHASE_CLRUP_STDWN
		SET_BIT(TCCR1A,5);
		CLEAR_BIT(TCCR1A,4);
#elif TIMER_u8T1_PHASE_MOOD_TYPE_B==TIMER_u8T1_PHASE_STUP_CLRDWN
		SET_BIT(TCCR1A,5);
		SET_BIT(TCCR1A,4);
#endif
/*******end of Timer 1 phase and frequency correction on ICR as top  #if*******/

#elif TIMER_u8T1_MOOD==TIMER_u8T1_PHASE_FREQ_OCR
		SET_BIT(TCCR1B,4);
		CLEAR_BIT(TCCR1B,3);
		CLEAR_BIT(TCCR1A,1);
		SET_BIT(TCCR1A,0);

		/* setting COM1B bits*/
#if TIMER_u8T1_PHASE_MOOD_TYPE_B==TIMER_u8T1_PHASE_NML
		CLEAR_BIT(TCCR1A,5);
		CLEAR_BIT(TCCR1A,4);
#elif TIMER_u8T1_PHASE_MOOD_TYPE_B==TIMER_u8T1_PHASE_TGLCMP
		CLEAR_BIT(TCCR1A,5);
		SET_BIT(TCCR1A,4);
#elif TIMER_u8T1_PHASE_MOOD_TYPE_B==TIMER_u8T1_PHASE_CLRUP_STDWN
		SET_BIT(TCCR1A,5);
		CLEAR_BIT(TCCR1A,4);
#elif TIMER_u8T1_PHASE_MOOD_TYPE_B==TIMER_u8T1_PHASE_STUP_CLRDWN
		SET_BIT(TCCR1A,5);
		SET_BIT(TCCR1A,4);
#endif
/*******end of Timer 1 phase and frequency correction on OCR as top  #if*******/


#elif TIMER_u8T1_MOOD==TIMER_u8T1_PHASE_ICR
		SET_BIT(TCCR1B,4);
		CLEAR_BIT(TCCR1B,3);
		SET_BIT(TCCR1A,1);
		CLEAR_BIT(TCCR1A,0);

		/* setting COM1B bits*/
#if TIMER_u8T1_PHASE_MOOD_TYPE_B==TIMER_u8T1_PHASE_NML
		CLEAR_BIT(TCCR1A,5);
		CLEAR_BIT(TCCR1A,4);
#elif TIMER_u8T1_PHASE_MOOD_TYPE_B==TIMER_u8T1_PHASE_TGLCMP
		CLEAR_BIT(TCCR1A,5);
		SET_BIT(TCCR1A,4);
#elif TIMER_u8T1_PHASE_MOOD_TYPE_B==TIMER_u8T1_PHASE_CLRUP_STDWN
		SET_BIT(TCCR1A,5);
		CLEAR_BIT(TCCR1A,4);
#elif TIMER_u8T1_PHASE_MOOD_TYPE_B==TIMER_u8T1_PHASE_STUP_CLRDWN
		SET_BIT(TCCR1A,5);
		SET_BIT(TCCR1A,4);
#endif
/*******end of Timer 1 phase correction on ICR as top  #if*******/


#elif TIMER_u8T1_MOOD==TIMER_u8T1_PHASE_OCR
		SET_BIT(TCCR1B,4);
		CLEAR_BIT(TCCR1B,3);
		SET_BIT(TCCR1A,1);
		SET_BIT(TCCR1A,0);

		/* setting COM1B bits*/
#if TIMER_u8T1_PHASE_MOOD_TYPE_B==TIMER_u8T1_PHASE_NML
		CLEAR_BIT(TCCR1A,5);
		CLEAR_BIT(TCCR1A,4);
#elif TIMER_u8T1_PHASE_MOOD_TYPE_B==TIMER_u8T1_PHASE_TGLCMP
		CLEAR_BIT(TCCR1A,5);
		SET_BIT(TCCR1A,4);
#elif TIMER_u8T1_PHASE_MOOD_TYPE_B==TIMER_u8T1_PHASE_CLRUP_STDWN
		SET_BIT(TCCR1A,5);
		CLEAR_BIT(TCCR1A,4);
#elif TIMER_u8T1_PHASE_MOOD_TYPE_B==TIMER_u8T1_PHASE_STUP_CLRDWN
		SET_BIT(TCCR1A,5);
		SET_BIT(TCCR1A,4);
#endif
/*******end of Timer 1 phase and correction on OCR as top  #if*******/


#elif TIMER_u8T1_MOOD==TIMER_u8T1_CTC_ICR
		SET_BIT(TCCR1B,4);
		SET_BIT(TCCR1B,3);
		CLEAR_BIT(TCCR1A,1);
		CLEAR_BIT(TCCR1A,0);


		/* setting COM1B bits*/
#if TIMER_u8T1_NML_MOOD_TYPE_B==TIMER_u8T1_NML_NML
		CLEAR_BIT(TCCR1A,5);
		CLEAR_BIT(TCCR1A,4);
#elif TIMER_u8T1_NML_MOOD_TYPE_B==TIMER_u8T1_NML_TGLCMP
		CLEAR_BIT(TCCR1A,5);
		SET_BIT(TCCR1A,4);
#elif TIMER_u8T1_NML_MOOD_TYPE_B==TIMER_u8T1_NML_CLRCMP
		SET_BIT(TCCR1A,5);
		CLEAR_BIT(TCCR1A,4);
#elif TIMER_u8T1_NML_MOOD_TYPE_B==TIMER_u8T1_NML_STCMP
		SET_BIT(TCCR1A,5);
		SET_BIT(TCCR1A,4);
#endif
/*******end of CTC on ICR #if*******/
#elif TIMER_u8T1_MOOD==TIMER_u8T1_FPWM_ICR
		SET_BIT(TCCR1B,4);
		SET_BIT(TCCR1B,3);
		SET_BIT(TCCR1A,1);
		CLEAR_BIT(TCCR1A,0);


		/* setting COM1B bits*/
#if TIMER_u8T1_FPWM_MOOD_TYPE_B==TIMER_u8T1_FPWM_NML
		CLEAR_BIT(TCCR1A,5);
		CLEAR_BIT(TCCR1A,4);
#elif TIMER_u8T1_FPWM_MOOD_TYPE_B==TIMER_u8T1_FPWM_TGLCMP_A
		CLEAR_BIT(TCCR1A,5);
		SET_BIT(TCCR1A,4);
#elif TIMER_u8T1_FPWM_MOOD_TYPE_B==TIMER_u8T1_FPWM_CLRCMP_STBTM
		SET_BIT(TCCR1A,5);
		CLEAR_BIT(TCCR1A,4);
#elif TIMER_u8T1_FPWM_MOOD_TYPE_B==TIMER_u8T1_FPWM_STCMP_CLRBTM
		SET_BIT(TCCR1A,5);
		SET_BIT(TCCR1A,4);
#endif
/*******end of Timer 1 Fast PWM on ICR as top mood #if*******/



#elif TIMER_u8T1_MOOD==TIMER_u8T1_FPWM_OCR
		SET_BIT(TCCR1B,4);
		SET_BIT(TCCR1B,3);
		SET_BIT(TCCR1A,1);
		SET_BIT(TCCR1A,0);

		/* setting COM1B bits*/
#if TIMER_u8T1_FPWM_MOOD_TYPE_B==TIMER_u8T1_FPWM_NML
		CLEAR_BIT(TCCR1A,5);
		CLEAR_BIT(TCCR1A,4);
#elif TIMER_u8T1_FPWM_MOOD_TYPE_B==TIMER_u8T1_FPWM_TGLCMP_A
		CLEAR_BIT(TCCR1A,5);
		SET_BIT(TCCR1A,4);
#elif TIMER_u8T1_FPWM_MOOD_TYPE_B==TIMER_u8T1_FPWM_CLRCMP_STBTM
		SET_BIT(TCCR1A,5);
		CLEAR_BIT(TCCR1A,4);
#elif TIMER_u8T1_FPWM_MOOD_TYPE_B==TIMER_u8T1_FPWM_STCMP_CLRBTM
		SET_BIT(TCCR1A,5);
		SET_BIT(TCCR1A,4);
#endif
/*******end of Timer 1 Fast PWM on OCR as top mood #if*******/
#endif


	}

	else if (ID ==TIMER_u8TIMER_2)
	{

#if TIMER_u8T2_MOOD==TIMER_u8T2_NORMAL_MOOD
		CLEAR_BIT(TCCR2,6);
		CLEAR_BIT(TCCR2,3);

#if TIMER_u8T2_NML_MOOD_TYPE==TIMER_u8T2_NML_NML
		CLEAR_BIT(TCCR2,5);
		CLEAR_BIT(TCCR2,4);
#elif TIMER_u8T2_NML_MOOD_TYPE==TIMER_u8T2_NML_TGLCMP
		CLEAR_BIT(TCCR2,5);
		SET_BIT(TCCR2,4);
#elif TIMER_u8T2_NML_MOOD_TYPE==TIMER_u8T2_NML_CLRCMP
		SET_BIT(TCCR2,5);
		CLEAR_BIT(TCCR2,4);
#elif TIMER_u8T2_NML_MOOD_TYPE==TIMER_u8T2_NML_STCMP
		SET_BIT(TCCR2,5);
		SET_BIT(TCCR2,4);
#endif

#elif TIMER_u8T2_MOOD==TIMER_u8T2_PWM_PHASE_MOOD
		CLEAR_BIT(TCCR2,6);
		SET_BIT(TCCR2,3);

#if TIMER_u8T2_PHASE_MOOD_TYPE==TIMER_u8T2_Phase_NML
		CLEAR_BIT(TCCR2,5);
		CLEAR_BIT(TCCR2,4);
#elif TIMER_u8T2_PHASE_MOOD_TYPE==TIMER_u8T2_PHASE_CLRUP_STDWN
		SET_BIT(TCCR2,5);
		CLEAR_BIT(TCCR2,4);
#elif TIMER_u8T2_PHASE_MOOD_TYPE==TIMER_u8T2_PHASE_STUP_CLRDWN
		SET_BIT(TCCR2,5);
		SET_BIT(TCCR2,4);
#endif


#elif TIMER_u8T2_MOOD==TIMER_u8T2_CTC_MOOD
		SET_BIT(TCCR2,6);
		CLEAR_BIT(TCCR2,3);

#if TIMER_u8T2_NML_MOOD_TYPE==TIMER_u8T2_NML_NML
		CLEAR_BIT(TCCR2,5);
		CLEAR_BIT(TCCR2,4);
#elif TIMER_u8T2_NML_MOOD_TYPE==TIMER_u8T2_NML_TGLCMP
		CLEAR_BIT(TCCR2,5);
		SET_BIT(TCCR2,4);
#elif TIMER_u8T2_NML_MOOD_TYPE==TIMER_u8T2_NML_CLRCMP
		SET_BIT(TCCR2,5);
		CLEAR_BIT(TCCR2,4);
#elif TIMER_u8T2_NML_MOOD_TYPE==TIMER_u8T2_NML_STCMP
		SET_BIT(TCCR2,5);
		SET_BIT(TCCR2,4);
#endif


#elif TIMER_u8T2_MOOD==TIMER_u8T2_FPWM_MOOD
		SET_BIT(TCCR2,6);
		SET_BIT(TCCR2,3);

#if TIMER_u8T2_FPWM_MOOD_TYPE==TIMER_u8T2_FPWM_NML
		CLEAR_BIT(TCCR2,5);
		CLEAR_BIT(TCCR2,4);
#elif TIMER_u8T2_FPWM_MOOD_TYPE==TIMER_u8T2_FPWM_CLRCMP_STTP
		SET_BIT(TCCR2,5);
		CLEAR_BIT(TCCR2,4);
#elif TIMER_u8T2_FPWM_MOOD_TYPE==TIMER_u8T2_FPWM_STCMP_CLRTP
		SET_BIT(TCCR2,5);
		SET_BIT(TCCR2,4);
#endif

#endif

	/* end of timer 2*/

	}

}
void Timer_vidStartTimer(u8 ID)
{
	if(ID ==TIMER_u8TIMER_0)
	{
		/****timer 0 prescale options****/
		#if TIMER_u8T0_PRESCALE==TIMER_u8T0_PRESCALE_X1
				SET_BIT(TCCR0,0);
				CLEAR_BIT(TCCR0,1);
				CLEAR_BIT(TCCR0,2);
		#elif TIMER_u8T0_PRESCALE==TIMER_u8T0_PRESCALE_X8
				CLEAR_BIT(TCCR0,0);
				SET_BIT(TCCR0,1);
				CLEAR_BIT(TCCR0,2);
		#elif TIMER_u8T0_PRESCALE==TIMER_u8T0_PRESCALE_X64
				SET_BIT(TCCR0,0);
				SET_BIT(TCCR0,1);
				CLEAR_BIT(TCCR0,2);
		#elif TIMER_u8T0_PRESCALE==TIMER_u8T0_PRESCALE_X256
				CLEAR_BIT(TCCR0,0);
				CLEAR_BIT(TCCR0,1);
				SET_BIT(TCCR0,2);
		#elif TIMER_u8T0_PRESCALE==TIMER_u8T0_PRESCALE_X1024
				SET_BIT(TCCR0,0);
				CLEAR_BIT(TCCR0,1);
				SET_BIT(TCCR0,2);
		#elif TIMER_u8T0_PRESCALE==TIMER_u8T0_PRESCALE_EXT_FALLING
				CLEAR_BIT(TCCR0,0);
				SET_BIT(TCCR0,1);
				SET_BIT(TCCR0,2);
		#elif TIMER_u8T0_PRESCALE==TIMER_u8T0_PRESCALE_EXT_RISING
				SET_BIT(TCCR0,0);
				SET_BIT(TCCR0,1);
				SET_BIT(TCCR0,2);
		#endif

	}

	else if (ID ==TIMER_u8TIMER_1)
	{
		/****timer 1 prescale options****/
		#if TIMER_u8T1_PRESCALE==TIMER_u8T1_PRESCALE_X1
				SET_BIT(TCCR1B,0);
				CLEAR_BIT(TCCR1B,1);
				CLEAR_BIT(TCCR1B,2);
		#elif TIMER_u8T1_PRESCALE==TIMER_u8T1_PRESCALE_X8
				CLEAR_BIT(TCCR1B,0);
				SET_BIT(TCCR1B,1);
				CLEAR_BIT(TCCR1B,2);
		#elif TIMER_u8T1_PRESCALE==TIMER_u8T1_PRESCALE_X64
				SET_BIT(TCCR1B,0);
				SET_BIT(TCCR1B,1);
				CLEAR_BIT(TCCR1B,2);
		#elif TIMER_u8T1_PRESCALE==TIMER_u8T1_PRESCALE_X256
				CLEAR_BIT(TCCR1B,0);
				CLEAR_BIT(TCCR1B,1);
				SET_BIT(TCCR1B,2);
		#elif TIMER_u8T1_PRESCALE==TIMER_u8T1_PRESCALE_X1024
				SET_BIT(TCCR1B,0);
				CLEAR_BIT(TCCR1B,1);
				SET_BIT(TCCR1B,2);
		#elif TIMER_u8T1_PRESCALE==TIMER_u8T1_PRESCALE_EXT_FALLING
				CLEAR_BIT(TCCR1B,0);
				SET_BIT(TCCR1B,1);
				SET_BIT(TCCR1B,2);
		#elif TIMER_u8T1_PRESCALE==TIMER_u8T1_PRESCALE_EXT_RISING
				SET_BIT(TCCR1B,0);
				SET_BIT(TCCR1B,1);
				SET_BIT(TCCR1B,2);
		#endif
	}


	else if (ID ==TIMER_u8TIMER_2)
	{
		/****timer 2 prescale options****/
		#if TIMER_u8T2_PRESCALE==TIMER_u8T2_PRESCALE_X1
				SET_BIT(TCCR2,0);
				CLEAR_BIT(TCCR2,1);
				CLEAR_BIT(TCCR2,2);
		#elif TIMER_u8T2_PRESCALE==TIMER_u8T2_PRESCALE_X8
				CLEAR_BIT(TCCR2,0);
				SET_BIT(TCCR2,1);
				CLEAR_BIT(TCCR2,2);
		#elif TIMER_u8T2_PRESCALE==TIMER_u8T2_PRESCALE_X32
				SET_BIT(TCCR2,0);
				SET_BIT(TCCR2,1);
				CLEAR_BIT(TCCR2,2);
		#elif TIMER_u8T2_PRESCALE==TIMER_u8T2_PRESCALE_X64
				CLEAR_BIT(TCCR2,0);
				CLEAR_BIT(TCCR2,1);
				SET_BIT(TCCR2,2);
		#elif TIMER_u8T2_PRESCALE==TIMER_u8T2_PRESCALE_X128
				SET_BIT(TCCR2,0);
				CLEAR_BIT(TCCR2,1);
				SET_BIT(TCCR2,2);
		#elif TIMER_u8T2_PRESCALE==TIMER_u8T2_PRESCALE_X256
				CLEAR_BIT(TCCR2,0);
				SET_BIT(TCCR2,1);
				SET_BIT(TCCR2,2);
		#elif TIMER_u8T2_PRESCALE==TIMER_u8T2_PRESCALE_X1024
				SET_BIT(TCCR2,0);
				SET_BIT(TCCR2,1);
				SET_BIT(TCCR2,2);
		#endif
	}

}
void Timer_vidStopTimer(u8 ID)
{
	if(ID ==TIMER_u8TIMER_0)
	{
		CLEAR_BIT(TCCR0,0);
		CLEAR_BIT(TCCR0,1);
		CLEAR_BIT(TCCR0,2);


	}

	else if (ID ==TIMER_u8TIMER_1)
	{
		CLEAR_BIT(TCCR1B,0);
		CLEAR_BIT(TCCR1B,1);
		CLEAR_BIT(TCCR1B,2);

	}


	else if (ID ==TIMER_u8TIMER_2)
	{
		CLEAR_BIT(TCCR2,0);
		CLEAR_BIT(TCCR2,1);
		CLEAR_BIT(TCCR2,2);

}
}
void Timer_vidSetCompareValue(u8 Timer_ID,u16 val)
{
	switch(Timer_ID)
	{
	case TIMER_u8TIMER_0:
	{
		OCR0=(u8)val;
		break;
	}
	case TIMER_u8TIMER_1A:
	{
		OCR1A=val;
		break;
	}
	case TIMER_u8TIMER_1B:
	{
		OCR1B=val;
		break;
	}
	case TIMER_u8TIMER_2:
	{
		OCR2=(u8)val;
		break;
	}
	}


}
void Timer_vidSetTimerValue(u8 Timer_ID,u16 val)
{
	switch(Timer_ID)
	{
	case TIMER_u8TIMER_0:
	{
		TCNT0=(u8)val;
		break;
	}
	case TIMER_u8TIMER_1A:
	case TIMER_u8TIMER_1B:
	case TIMER_u8TIMER_1:
	{
		TCNT1=val;
		break;
	}
	case TIMER_u8TIMER_2:
	{
		TCNT2=(u8)val;
		break;
	}
	}
}
void Timer_vidSetICR1(u16 val)
{
	ICR1=val;
}
void Timer_vidSetInterrupt(u8 Interrupt_ID)
{
	SET_BIT(SREG,7);/*enable global interrupt*/

if(Interrupt_ID==TIMER_u8T0_CMP_INTERRUPT)
{
	SET_BIT(TIMSK,1);
}
else if(Interrupt_ID==TIMER_u8T0_OV_INTERRUPT)
{
	SET_BIT(TIMSK,0);
}
else if(Interrupt_ID==TIMER_u8T1_OV_INTERRUPT)
{
	SET_BIT(TIMSK,2);
}
else if(Interrupt_ID==TIMER_u8T1B_CMP_INTERRUPT)
{
	SET_BIT(TIMSK,3);
}
else if(Interrupt_ID==TIMER_u8T1A_CMP_INTERRUPT)
{
	SET_BIT(TIMSK,4);
}
else if(Interrupt_ID==TIMER_u8T1_IN_CAP_INTERRUPT)
{
	SET_BIT(TIMSK,5);
}
else if(Interrupt_ID==TIMER_u8T2_OV_INTERRUPT)
{
	SET_BIT(TIMSK,6);
}
else if(Interrupt_ID==TIMER_u8T2_CMP_INTERRUPT)
{
	SET_BIT(TIMSK,7);
}
}
void Timer_vidClearInterrupt(u8 Interrupt_ID)
{
	if(Interrupt_ID==TIMER_u8T0_CMP_INTERRUPT)
	{
		CLEAR_BIT(TIMSK,1);
	}
	else if(Interrupt_ID==TIMER_u8T0_OV_INTERRUPT)
	{
		CLEAR_BIT(TIMSK,0);
	}
	else if(Interrupt_ID==TIMER_u8T1_OV_INTERRUPT)
	{
		CLEAR_BIT(TIMSK,2);
	}
	else if(Interrupt_ID==TIMER_u8T1B_CMP_INTERRUPT)
	{
		CLEAR_BIT(TIMSK,3);
	}
	else if(Interrupt_ID==TIMER_u8T1A_CMP_INTERRUPT)
	{
		CLEAR_BIT(TIMSK,4);
	}
	else if(Interrupt_ID==TIMER_u8T1_IN_CAP_INTERRUPT)
	{
		CLEAR_BIT(TIMSK,5);
	}
	else if(Interrupt_ID==TIMER_u8T2_OV_INTERRUPT)
	{
		CLEAR_BIT(TIMSK,6);
	}
	else if(Interrupt_ID==TIMER_u8T2_CMP_INTERRUPT)
	{
		CLEAR_BIT(TIMSK,7);
	}

}
u8 Timer_u8CheckFlag(u8 Timer_ID)
{
	if(Timer_ID==TIMER_u8T0_CMP_FLAG)
	{
		return GET_BIT(TIFR,0);
	}
	else if(Timer_ID==TIMER_u8T0_OV_FLAG)
	{
		return GET_BIT(TIFR,1);
	}
	else if(Timer_ID==TIMER_u8T1_OV_FLAG)
	{
		return GET_BIT(TIFR,2);
	}
	else if(Timer_ID==TIMER_u8T1B_CMP_FLAG)
	{
		return GET_BIT(TIFR,3);
	}
	else if(Timer_ID==TIMER_u8T1A_CMP_FLAG)
	{
		return GET_BIT(TIFR,4);
	}
	else if(Timer_ID==TIMER_u8T1_IN_CAP_FLAG)
	{
		return GET_BIT(TIFR,5);
	}
	else if(Timer_ID==TIMER_u8T2_OV_FLAG)
	{
		return GET_BIT(TIFR,6);
	}
	else if(Timer_ID==TIMER_u8T2_CMP_FLAG)
	{
		return GET_BIT(TIFR,7);
	}
	return 2;

}
u16  Timer_u16GetTimerValue(u8 Timer_ID)
{
	switch(Timer_ID)
	{
	case TIMER_u8TIMER_0:
	{
		return TCNT0;
	}
	case TIMER_u8TIMER_1A:
	case TIMER_u8TIMER_1B:
	case TIMER_u8TIMER_1:
	{
		return TCNT1;
	}
	case TIMER_u8TIMER_2:
	{
		return TCNT2;
	}
	}
	return 0;

}

