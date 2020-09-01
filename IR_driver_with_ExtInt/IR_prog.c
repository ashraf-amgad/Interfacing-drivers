/*
 * IR_prog.c
 *
 * Created: 10/18/2019 10:23:59 AM
 *  Author: Louda
 */ 

#include "IR_int.h"


void IR_voidinit(void)
{
	DIO_voidInit();
	EXTINT_voidInit();
	
	#if (IR_0_INIT == IR_INIT)
		DIO_voidClrPinDir( IR_0 );
	#endif
		
	#if (IR_1_INIT == IR_INIT)
		DIO_voidClrPinDir( IR_1 );
	#endif
	
}


void IR_voidIR0ISR(void (*IR_func)(void))
{
	#if (IR_0 == EXTINT_0_PIN)
		EXTINT_voidINT0ISR( IR_func );
		
	#elif (IR_0 == EXTINT_1_PIN)
		EXTINT_voidINT1ISR( IR_func );
		
	#else			// (IR_0 == EXTINT_2_PIN)
		EXTINT_voidINT2ISR( IR_func );
	#endif
}

void IR_voidIR1ISR(void (*IR_func)(void))
{
	#if (IR_1 == EXTINT_0_PIN)
		EXTINT_voidINT0ISR( IR_func );
	
	#elif (IR_1 == EXTINT_1_PIN)
		EXTINT_voidINT1ISR( IR_func );
	
	#else			// (IR_1 == EXTINT_2_PIN)
		EXTINT_voidINT2ISR( IR_func );
	#endif
}
