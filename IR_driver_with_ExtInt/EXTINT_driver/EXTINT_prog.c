/*
 * EXT_INT_prog.c
 *
 * Created: 9/24/2019 3:43:33 PM
 *  Author: Louda
 */ 

#include <avr/interrupt.h>
#include "EXTINT_int.h"

static void (*fptr_INT0)(void) = '\0';
static void (*fptr_INT1)(void) = '\0';
static void (*fptr_INT2)(void) = '\0';


void EXTINT_voidInit(void)
{
	DIO_voidInit();
	
	#if (EXTINT_0_INIT == INIT)
		DIO_voidClrPinDir(EXTINT_0_PIN);
		GENERAL_INT_CONTROL_REG |= (1<<INT_0_EN);
	#endif
		
	#if (EXTINT_1_INIT == INIT)
		DIO_voidClrPinDir(EXTINT_1_PIN);
		GENERAL_INT_CONTROL_REG |= (1<<INT_1_EN);
	#endif  
	
	#if (EXTINT_2_INIT == INIT)
		DIO_voidClrPinDir(EXTINT_2_PIN);
		GENERAL_INT_CONTROL_REG |= (1<<INT_2_EN);
	#endif
	
	
	
	#if (EXTINT_0_MODE == EXTINT_MODE_FALLING_EDGE)
	MCU_CONTROL_REG &= ~(1<<INT_SENSE_CONTROL_INT0_0);
	MCU_CONTROL_REG |= (1<<INT_SENSE_CONTROL_INT0_1);
	
	#elif (EXTINT_0_MODE == EXTINT_MODE_LOW_LEVEL)
	MCU_CONTROL_REG &= ~(1<<INT_SENSE_CONTROL_INT0_0);
	MCU_CONTROL_REG &= ~(1<<INT_SENSE_CONTROL_INT0_1);
	
	#elif (EXTINT_0_MODE == EXTINT_MODE_RISING_EDGE)
	MCU_CONTROL_REG |= (1<<INT_SENSE_CONTROL_INT0_0);
	MCU_CONTROL_REG |= (1<<INT_SENSE_CONTROL_INT0_1);
	
	#else				//	 (EXTINT_0_MODE == EXTINT_MODE_ANY_LOGICAL_CHANGE)
	MCU_CONTROL_REG |= (1<<INT_SENSE_CONTROL_INT0_0);
	MCU_CONTROL_REG &= ~(1<<INT_SENSE_CONTROL_INT0_1);

	#endif
	
	
	
	
	#if (EXTINT_1_MODE == EXTINT_MODE_FALLING_EDGE)
	MCU_CONTROL_REG &= ~(1<<INT_SENSE_CONTROL_INT0_0);
	MCU_CONTROL_REG |= (1<<INT_SENSE_CONTROL_INT0_1);
	
	#elif (EXTINT_1_MODE == EXTINT_MODE_LOW_LEVEL)
	MCU_CONTROL_REG &= ~(1<<INT_SENSE_CONTROL_INT1_0);
	MCU_CONTROL_REG &= ~(1<<INT_SENSE_CONTROL_INT1_1);
	
	#elif (EXTINT_1_MODE == EXTINT_MODE_RISING_EDGE)
	MCU_CONTROL_REG |= (1<<INT_SENSE_CONTROL_INT0_0);
	MCU_CONTROL_REG |= (1<<INT_SENSE_CONTROL_INT0_1);
	
	#else				//	 (EXTINT_0_MODE == EXTINT_MODE_ANY_LOGICAL_CHANGE)
	MCU_CONTROL_REG |= (1<<INT_SENSE_CONTROL_INT1_0);
	MCU_CONTROL_REG &= ~(1<<INT_SENSE_CONTROL_INT1_1);

	#endif
	
	
	
	#if (EXTINT_2_MODE == EXTINT_MODE_HIGH_LEVEL)
	MCU_CONTROL_STATUS_REG |= (1<<INT_SENSE_CONTROL_INT2);
	
	#else				// (EXTINT_2_MODE == EXTINT_MODE_LOW_LEVEL)
	MCU_CONTROL_STATUS_REG &= ~(1<<INT_SENSE_CONTROL_INT2);

	#endif
	
	SetGlobalInt();
}





void EXTINT_voidINT0ISR(void (*interrupt_func)(void))
{
	fptr_INT0 = interrupt_func;
}
	
	
void EXTINT_voidINT1ISR(void (*interrupt_func)(void))
{
	fptr_INT1 = interrupt_func;
}


void EXTINT_voidINT2ISR(void (*interrupt_func)(void))
{
	fptr_INT2 = interrupt_func;
}
	


u8 EXTINT_u8GetIntFlagStatus(u8 INT_Flag_Num)
{
	return ( (GENERAL_INT_FLAG_REG & (1<<INT_Flag_Num) ) );
}



void SetGlobalInt(void)
{
	asm ("sei");
}


 //ISR(INT0_vect)
 //{
 	//fptr_INT0();
 //}
 //
 //
 //
 //ISR(INT1_vect)
 //{
 	//fptr_INT1();
 //}
 //
 //
 //
 //ISR(INT2_vect)
 //{
 	//fptr_INT2();
 //}

void INT0_vect (void)
{
	fptr_INT0();
}

void INT1_vect (void)
{
	fptr_INT1();
}


void INT2_vect (void)
{
	fptr_INT2();	
}
 
 