/*
 * sram_test.c
 *
 * Created: 3/11/2020 1:12:53 AM
 *  Author: Louda
 */ 

#include "Sram_driver/sram.h"



int main(void)
{
	u32 counter = 0;
	u32 address = 0x1ffff;
	u8 ch = 0x55;
	u8 data_read = 0;
	
	Dio_Init();
	Sram_Init();
	
    while(1)
    {
		
		
		Sram_Write(ch ,address);
		address++;
		ch++;		
        //for (counter=0 ; counter<0x10000 ;counter++);
// 		data_read = Sram_ReadData(address);
// 		DIO_PORTA = data_read;
		
    }
	
}