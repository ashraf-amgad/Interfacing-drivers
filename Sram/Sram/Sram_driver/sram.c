/*
 * sram_prog.c
 *
 * Created: 3/11/2020 1:15:17 AM
 *  Author: Louda
 */ 


#include "sram.h"



void Sram_Init(void)
{
	Dio_SetPinDir(SRAM_READ_PIN);
	Dio_SetPinDir(SRAM_LATCH_EN_PIN);
	Dio_SetPinDir(SRAM_WRITE_PIN);
	
	Dio_SetPin(SRAM_READ_PIN);
	Dio_SetPin(SRAM_LATCH_EN_PIN);
	Dio_SetPin(SRAM_WRITE_PIN);
}


void Sram_Write(u8 data , u32 address)
{
	u32 counter=0;
	
	/* start writing */
	Dio_ClrPin(SRAM_WRITE_PIN);
	Dio_SetPin(SRAM_READ_PIN);	
	/* set latch enable (enable latch) */
	Dio_SetPin(SRAM_LATCH_EN_PIN);
	
	/* output address */
	Set_Port(SRAM_AD_DIRECTION_REG , 0xff);
	Set_Port(SRAM_AD_OUTPUT_REG , (u8)address);
	Set_Port(SRAM_A8_A15_DIRECTION_REG , 0xff);
	Set_Port(SRAM_A8_A15_OUTPUT_REG , (u8)(address >> 8));
	Dio_SetPinDir(SRAM_A16_PIN);
	
	if ((address >> 16) & 0x01)
	{
		Dio_SetPin(SRAM_A16_PIN); 
	}
	
	else 
	{
		Dio_ClrPin(SRAM_A16_PIN);
	}

	for (counter=0 ; counter<62345 ;counter++);	
	/* clear latch enable (disable latch) */
	Dio_ClrPin(SRAM_LATCH_EN_PIN);
	
	for (counter=0 ; counter<62345 ;counter++);
	
	/* output data */
	Set_Port(SRAM_AD_DIRECTION_REG , 0xff);
	Set_Port(SRAM_AD_OUTPUT_REG , 0x00);
	Set_Port(SRAM_AD_OUTPUT_REG , data);
	
	
	
	/* stop writing */
	Dio_SetPin(SRAM_WRITE_PIN);
			
}







u8 Sram_ReadData(u32 address)
{
	u8 temp_data=0;
	
	Dio_SetPin(SRAM_READ_PIN);
	/* set latch enable (enable latch) */
	Dio_SetPin(SRAM_LATCH_EN_PIN);
	
	/* output address */
	Set_Port(SRAM_AD_DIRECTION_REG , 0xff);
	Set_Port(SRAM_AD_OUTPUT_REG , (u8)(address));
	Set_Port(SRAM_A8_A15_OUTPUT_REG , (u8)(address >> 8));
	Dio_SetPinDir(SRAM_A16_PIN);
	
	if ((address >> 16) & 0x01)
	{
		Dio_SetPin(SRAM_A16_PIN);
	}
	
	else 
	{
		Dio_ClrPin(SRAM_A16_PIN);
	}
	
	
	
	/* clear latch enable (disable latch) */
	Dio_ClrPin(SRAM_LATCH_EN_PIN);
	Set_Port(SRAM_AD_DIRECTION_REG , 0x00);
	
	/* start reading */
	Dio_ClrPin(SRAM_READ_PIN);
	
	temp_data = SRAM_AD_INPUT_REG;
		
	/* stop reading */
	Dio_SetPinDir(SRAM_READ_PIN);
	
	return(temp_data);
}







