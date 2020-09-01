/*
 * Leds.c
 *
 * Created: 9/17/2019 9:46:25 AM
 *  Author: Louda
 */ 
#include "Leds.h"


void Leds_Init(void)
{
	
	Dio_SetPinDir(LED_REC);
	Dio_SetPinDir(LED_PLAY);
	Dio_SetPinDir(LED_FREQ);
	
	Dio_ClrPin(LED_REC);
	Dio_ClrPin(LED_PLAY);
	Dio_ClrPin(LED_FREQ);
	
}



void Leds_LedOn(u8 Led_num)
{
	Dio_SetPin(Led_num);
}



void Leds_LedOff(u8 Led_num)
{
	Dio_ClrPin(Led_num);
}