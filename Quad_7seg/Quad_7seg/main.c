/*
 * Quad_7seg.c
 *
 * Created: 3/13/2020 2:56:26 PM
 *  Author: Louda
 */ 

#include "Quad_7seg.h"


int main(void)
{
	u8 ArrayOfDigits[4];
	u32 counter=0;
	
	Quad_7seg_Init();
	Quad_7seg_Num2ArrayOfDigits(1500 , ArrayOfDigits);
	
    
	while(1)
    { 
		
		Quad_7seg_Display(Quad_7SEG_SEG_1 , ArrayOfDigits[0]);
		for(counter=0 ; counter<0x01000 ; counter++);
		Quad_7seg_Display(Quad_7SEG_SEG_2 , ArrayOfDigits[1]);
		for(counter=0 ; counter<0x01000 ; counter++);
		Quad_7seg_Display(Quad_7SEG_SEG_3 , ArrayOfDigits[2]);
		for(counter=0 ; counter<0x01000 ; counter++);
		Quad_7seg_Display(Quad_7SEG_SEG_4 , ArrayOfDigits[3]);
		for(counter=0 ; counter<0x01000 ; counter++);
    }
}