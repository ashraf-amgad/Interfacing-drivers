/*
 * Led_driver.c
 *
 * Created: 3/14/2020 3:30:05 PM
 *  Author: Louda
 */ 

#include "Leds_driver/Leds.h"

int main(void)
{
	Dio_Init();
	Leds_Init();
	
	u32 counter;
    while(1)
    {
        for (counter=0 ; counter<0xffff ; counter++);
        Leds_LedOn(LED_FREQ);
		Leds_LedOff(LED_PLAY);
		Leds_LedOff(LED_REC);
		
		for (counter=0 ; counter<0xffff ; counter++);
        Leds_LedOff(LED_FREQ);
		Leds_LedOn(LED_PLAY);
		Leds_LedOff(LED_REC);
		
		for (counter=0 ; counter<0xffff ; counter++);
        Leds_LedOff(LED_FREQ);
		Leds_LedOff(LED_PLAY);
		Leds_LedOn(LED_REC);
    }
}