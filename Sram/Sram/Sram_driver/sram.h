/*
 * sram_int.h
 *
 * Created: 3/11/2020 1:14:33 AM
 *  Author: Louda
 */ 


#ifndef SRAM_INT_H_
#define SRAM_INT_H_

#include "../Dio_driver/Dio.h"



#define SRAM_AD_OUTPUT_REG				DIO_PORTB
#define SRAM_AD_INPUT_REG				DIO_PINB
#define SRAM_AD_DIRECTION_REG			DIO_DDRB

#define SRAM_A8_A15_OUTPUT_REG			DIO_PORTC
#define SRAM_A8_A15_DIRECTION_REG		DIO_DDRC

#define SRAM_A16_PIN					DIO_PORTD_PIN0
//#define SRAM_A16_OUTPUT_REG				DIO_PORTD
//#define SRAM_A16_DIRECTION_REG			DIO_DDRD


#define SRAM_LATCH_EN_PIN				DIO_PORTD_PIN1
//#define SRAM_LATCH_EN_OUTPUT_REG		DIO_PORTD
//#define SRAM_LATCH_EN_DIRECTION_REG		DIO_DDRD

#define SRAM_WRITE_PIN					DIO_PORTD_PIN2 
//#define SRAM_WRITE_OUTPUT_REG			DIO_PORTD
//#define SRAM_WRITE_DIRECTION_REG		DIO_DDRD

#define SRAM_READ_PIN					DIO_PORTD_PIN3
//#define SRAM_READ_OUTPUT_REG			DIO_PORTD
//#define SRAM_READ_DIRECTION_REG			DIO_DDRD



void Sram_Init(void);
void Sram_Write(u8 data , u32 address);
u8 Sram_ReadData(u32 address);



#endif /* SRAM_INT_H_ */