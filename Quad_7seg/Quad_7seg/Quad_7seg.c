/*
 * Quad_7seg.c
 *
 * Created: 3/13/2020 2:57:25 PM
 *  Author: Louda
 */ 


#include "Quad_7seg.h"


static void Quad_7seg_Seg_Display(u8 display_Digit);

void Quad_7seg_Init(void)
{
	
	Dio_SetPinDir(Quad_7SEG_SEG_1_EN);
	Dio_SetPinDir(Quad_7SEG_SEG_2_EN);
	Dio_SetPinDir(Quad_7SEG_SEG_3_EN);
	Dio_SetPinDir(Quad_7SEG_SEG_4_EN);
	
	Dio_ClrPin(Quad_7SEG_SEG_1_EN);
	Dio_ClrPin(Quad_7SEG_SEG_2_EN);
	Dio_ClrPin(Quad_7SEG_SEG_3_EN);
	Dio_ClrPin(Quad_7SEG_SEG_4_EN);
		
}


void Quad_7seg_Num2ArrayOfDigits(u16 Display_num ,u8* ArrayOfDigits)
{
	static u16 reminder = 0;
	
	ArrayOfDigits[0] = (Display_num % 10);
	reminder = (Display_num / 10); 
	ArrayOfDigits[1] = (reminder % 10);
	reminder = (reminder / 10); 
	ArrayOfDigits[2] = (reminder % 10);
	reminder = (reminder / 10);
	ArrayOfDigits[3] = (reminder % 10);
	
}



void Quad_7seg_Display(u8 Seg_Num , u8 Display_Digit)
{
	static u8 seg_counter = 0;

		
	Dio_SetPinDir(Quad_7SEG_A);
	Dio_SetPinDir(Quad_7SEG_B);
	Dio_SetPinDir(Quad_7SEG_C);
	Dio_SetPinDir(Quad_7SEG_D);
	
	
	switch (Seg_Num)
	{
		case (Quad_7SEG_SEG_1):
			Dio_ClrPin(Quad_7SEG_SEG_1_EN);
			Dio_SetPin(Quad_7SEG_SEG_2_EN);
			Dio_SetPin(Quad_7SEG_SEG_3_EN);
			Dio_SetPin(Quad_7SEG_SEG_4_EN);
			Quad_7seg_Seg_Display(Display_Digit);
		
		break;
		
		case (Quad_7SEG_SEG_2):
			Dio_SetPin(Quad_7SEG_SEG_1_EN);
			Dio_ClrPin(Quad_7SEG_SEG_2_EN);
			Dio_SetPin(Quad_7SEG_SEG_3_EN);
			Dio_SetPin(Quad_7SEG_SEG_4_EN);
			Quad_7seg_Seg_Display(Display_Digit);
		
		break;
		
		case (Quad_7SEG_SEG_3):
			Dio_SetPin(Quad_7SEG_SEG_1_EN);
			Dio_SetPin(Quad_7SEG_SEG_2_EN);
			Dio_ClrPin(Quad_7SEG_SEG_3_EN);
			Dio_SetPin(Quad_7SEG_SEG_4_EN);
			Quad_7seg_Seg_Display(Display_Digit);
		
		break;
		
		case (Quad_7SEG_SEG_4):
			Dio_SetPin(Quad_7SEG_SEG_1_EN);
			Dio_SetPin(Quad_7SEG_SEG_2_EN);
			Dio_SetPin(Quad_7SEG_SEG_3_EN);
			Dio_ClrPin(Quad_7SEG_SEG_4_EN);
			Quad_7seg_Seg_Display(Display_Digit);
		
		break;
	}
	
			
}




static void Quad_7seg_Seg_Display(u8 display_Digit)
{
	switch (display_Digit)
	{
		case (0):
		{
			Dio_ClrPin(Quad_7SEG_A);
			Dio_ClrPin(Quad_7SEG_B);
			Dio_ClrPin(Quad_7SEG_C);
			Dio_ClrPin(Quad_7SEG_D);
			break;
		}
			
		case (1):
		{
			Dio_SetPin(Quad_7SEG_A);
			Dio_ClrPin(Quad_7SEG_B);
			Dio_ClrPin(Quad_7SEG_C);
			Dio_ClrPin(Quad_7SEG_D);
			break;
		}
		
		case (2):
		{
			Dio_ClrPin(Quad_7SEG_A);
			Dio_SetPin(Quad_7SEG_B);
			Dio_ClrPin(Quad_7SEG_C);
			Dio_ClrPin(Quad_7SEG_D);
			break;
		}
		
		case (3):
		{
			Dio_SetPin(Quad_7SEG_A);
			Dio_SetPin(Quad_7SEG_B);
			Dio_ClrPin(Quad_7SEG_C);
			Dio_ClrPin(Quad_7SEG_D);
			break;
		}
		
		case (4):
		{
			Dio_ClrPin(Quad_7SEG_A);
			Dio_ClrPin(Quad_7SEG_B);
			Dio_SetPin(Quad_7SEG_C);
			Dio_ClrPin(Quad_7SEG_D);
			break;
		}
		
		case (5):
		{
			Dio_SetPin(Quad_7SEG_A);
			Dio_ClrPin(Quad_7SEG_B);
			Dio_SetPin(Quad_7SEG_C);
			Dio_ClrPin(Quad_7SEG_D);
			break;
		}
		
		case (6):
		{
			Dio_ClrPin(Quad_7SEG_A);
			Dio_SetPin(Quad_7SEG_B);
			Dio_SetPin(Quad_7SEG_C);
			Dio_ClrPin(Quad_7SEG_D);
			break;
		}
		
		case (7):
		{
			Dio_SetPin(Quad_7SEG_A);
			Dio_SetPin(Quad_7SEG_B);
			Dio_SetPin(Quad_7SEG_C);
			Dio_ClrPin(Quad_7SEG_D);
			break;
		}
		
		case (8):
		{
			Dio_ClrPin(Quad_7SEG_A);
			Dio_ClrPin(Quad_7SEG_B);
			Dio_ClrPin(Quad_7SEG_C);
			Dio_SetPin(Quad_7SEG_D);
			break;
		}
		
		case (9):
		{
			Dio_SetPin(Quad_7SEG_A);
			Dio_ClrPin(Quad_7SEG_B);
			Dio_ClrPin(Quad_7SEG_C);
			Dio_SetPin(Quad_7SEG_D);	
			break;
		}
		
		default :
			/* do no thing */
		break;
	}
	
}



void Quad_7seg_TurnOff(void)
{
	Dio_ClrPin(Quad_7SEG_SEG_1_EN);
	Dio_ClrPin(Quad_7SEG_SEG_2_EN);
	Dio_ClrPin(Quad_7SEG_SEG_3_EN);
	Dio_ClrPin(Quad_7SEG_SEG_4_EN);		
}