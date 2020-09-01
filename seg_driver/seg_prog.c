/*
 * seg_prog.c
 *
 * Created: 9/17/2019 11:17:16 AM
 *  Author: Louda
 */ 


#include "seg_int.h"

void seg_voidinit(void)
{
	DIO_voidInit();
	
	DIO_voidSetPinDir(SEG_A);
	DIO_voidSetPinDir(SEG_B);
	DIO_voidSetPinDir(SEG_C);
	DIO_voidSetPinDir(SEG_D);
	
	DIO_voidSetPinDir(SEG_1_EN);
	DIO_voidSetPinDir(SEG_2_EN);
	
	DIO_voidClrPin(SEG_A);
	DIO_voidClrPin(SEG_B);
	DIO_voidClrPin(SEG_C);
	DIO_voidClrPin(SEG_D);
	
	DIO_voidClrPin(SEG_1_EN);
	DIO_voidClrPin(SEG_2_EN);
		
}


void seg_voiddisplay(u8 seg_num ,u8 display_num)
{
	
	if (seg_num == SEG_1)
	{
		DIO_voidSetPin(SEG_1_EN);
		DIO_voidClrPin(SEG_2_EN);
	}		
	
	else if (seg_num == SEG_2)
	{
		DIO_voidClrPin(SEG_1_EN);
		DIO_voidSetPin(SEG_2_EN);
	}		
	
	
	switch (display_num)
	{
		case (0):
		{
			DIO_voidClrPin(SEG_A);
			DIO_voidClrPin(SEG_B);
			DIO_voidClrPin(SEG_C);
			DIO_voidClrPin(SEG_D);
			break;
		}
			
		case (1):
		{
			DIO_voidSetPin(SEG_A);
			DIO_voidClrPin(SEG_B);
			DIO_voidClrPin(SEG_C);
			DIO_voidClrPin(SEG_D);
			break;
		}
		
		case (2):
		{
			DIO_voidClrPin(SEG_A);
			DIO_voidSetPin(SEG_B);
			DIO_voidClrPin(SEG_C);
			DIO_voidClrPin(SEG_D);
			break;
		}
		
		case (3):
		{
			DIO_voidSetPin(SEG_A);
			DIO_voidSetPin(SEG_B);
			DIO_voidClrPin(SEG_C);
			DIO_voidClrPin(SEG_D);
			break;
		}
		
		case (4):
		{
			DIO_voidClrPin(SEG_A);
			DIO_voidClrPin(SEG_B);
			DIO_voidSetPin(SEG_C);
			DIO_voidClrPin(SEG_D);
			break;
		}
		
		case (5):
		{
			DIO_voidSetPin(SEG_A);
			DIO_voidClrPin(SEG_B);
			DIO_voidSetPin(SEG_C);
			DIO_voidClrPin(SEG_D);
			break;
		}
		
		case (6):
		{
			DIO_voidClrPin(SEG_A);
			DIO_voidSetPin(SEG_B);
			DIO_voidSetPin(SEG_C);
			DIO_voidClrPin(SEG_D);
			break;
		}
		
		case (7):
		{
			DIO_voidSetPin(SEG_A);
			DIO_voidSetPin(SEG_B);
			DIO_voidSetPin(SEG_C);
			DIO_voidClrPin(SEG_D);
			break;
		}
		
		case (8):
		{
			DIO_voidClrPin(SEG_A);
			DIO_voidClrPin(SEG_B);
			DIO_voidClrPin(SEG_C);
			DIO_voidSetPin(SEG_D);
			break;
		}
		
		case (9):
		{
			DIO_voidSetPin(SEG_A);
			DIO_voidClrPin(SEG_B);
			DIO_voidClrPin(SEG_C);
			DIO_voidSetPin(SEG_D);	
			break;
		}
		
		default :
		{
			DIO_voidClrPin(SEG_A);
			DIO_voidClrPin(SEG_B);
			DIO_voidClrPin(SEG_C);
			DIO_voidClrPin(SEG_D);
		}
		
	}
		
}



void seg_voidturnoff(u8 seg_num)
{
	if(seg_num == SEG_1)
		DIO_voidClrPin(SEG_1_EN);
		
	else if(seg_num == SEG_2)
		DIO_voidClrPin(SEG_2_EN);
	
}