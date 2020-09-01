/*
 * Switches_prog.c
 *
 * Created: 9/17/2019 7:18:27 AM
 *  Author: Louda
 */ 

#include "Switches_int.h"



void Switches_voidinit(void)
{
	DIO_voidInit();
	DIO_voidClrPinDir(SWITCH_1);
	DIO_voidClrPinDir(SWITCH_2);
	DIO_voidClrPinDir(SWITCH_3);
	
	#if (SWITCH_1_MODE == SWITCH_PULL_UP)
		DIO_voidSetPin(SWITCH_1);
	#else
		DIO_voidClrPin(SWITCH_1);
	#endif
		
		
	#if (SWITCH_2_MODE == SWITCH_PULL_UP)
		DIO_voidSetPin(SWITCH_2);
	#else
		DIO_voidClrPin(SWITCH_2);
	#endif
	
	
	#if (SWITCH_3_MODE == SWITCH_PULL_UP)
		DIO_voidSetPin(SWITCH_3);
	#else
		DIO_voidClrPin(SWITCH_3);
	#endif
	
}


u8 Switches_u8GetStatus(u8 Switch_num)
{
	if (Switch_num == SWITCH_1)
	{
		if ( SWITCH_1_MODE == SWITCH_PULL_DOWN )
		{
			if ( DIO_u8ReadPinVal(Switch_num)  == HIGH)
				return(SWITCH_PRESSED);
		
			else
				return(SWITCH_NOT_PRESSED);
		}
		else
		{
			if ( DIO_u8ReadPinVal(Switch_num)  == LOW)
				return(SWITCH_PRESSED);
			
			else
				return(SWITCH_NOT_PRESSED);
		}
	}
	
	else if (Switch_num == SWITCH_2)
	{
		if ( SWITCH_2_MODE == SWITCH_PULL_DOWN )
		{
			if ( DIO_u8ReadPinVal(Switch_num)  == HIGH)
				return(SWITCH_PRESSED);
			
			else
				return(SWITCH_NOT_PRESSED);
		}
		else
		{
			if ( DIO_u8ReadPinVal(Switch_num)  == LOW)
				return(SWITCH_PRESSED);
				
			else
				return(SWITCH_NOT_PRESSED);		
		}
	}
	
	else	// (Switch_num == SWITCH_3)
	{
		if ( SWITCH_3_MODE == SWITCH_PULL_DOWN )
		{
			if ( DIO_u8ReadPinVal(Switch_num)  == HIGH)
				return(SWITCH_PRESSED);
			
			else
				return(SWITCH_NOT_PRESSED);
		}
		else
		{
			if ( DIO_u8ReadPinVal(Switch_num)  == LOW)
				return(SWITCH_PRESSED);
			
			else
				return(SWITCH_NOT_PRESSED);
		}
		
			
	}
	
}


