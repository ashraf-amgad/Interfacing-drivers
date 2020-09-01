/*
 * EXT_INT_int.h
 *
 * Created: 9/24/2019 4:09:51 PM
 *  Author: Louda
 */ 


#ifndef EXT_INT_INT_H_
#define EXT_INT_INT_H_

#include "../DIO_driver/DIO_int.h"
#include "EXTINT_confg.h"
#include "EXTINT_priv.h"

void EXTINT_voidInit(void);
void EXTINT_voidINT0ISR(void (*interrupt_func)(void));
void EXTINT_voidINT1ISR(void (*interrupt_func)(void));
void EXTINT_voidINT2ISR(void (*interrupt_func)(void));
u8   EXTINT_u8GetIntFlagStatus(u8 INT_Flag_Num);

void INT0_vect (void) __attribute__ ( (signal) );
void INT1_vect (void) __attribute__ ( (signal) );
void INT2_vect (void) __attribute__ ( (signal) );
void SetGlobalInt(void);



#define  HIGH			1
#define  LOW			0


/*	these are bits numbers in the registers */
#define GENERAL_INT_EN					7

#define INT_SENSE_CONTROL_INT0_0		0
#define INT_SENSE_CONTROL_INT0_1		1
#define INT_SENSE_CONTROL_INT1_0		2
#define INT_SENSE_CONTROL_INT1_1		3

#define INT_SENSE_CONTROL_INT2			6	

#define INT_1_EN						7
#define INT_0_EN						6
#define INT_2_EN						5

#define INT_1_FLAG						7
#define INT_0_FLAG						6
#define INT_2_FLAG						5








#endif /* EXT_INT_INT_H_ */