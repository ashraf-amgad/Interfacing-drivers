/*
 * IR_int.h
 *
 * Created: 10/18/2019 10:24:15 AM
 *  Author: Louda
 */ 


#ifndef IR_INT_H_
#define IR_INT_H_

#include "DIO_driver/DIO_int.h"
#include "EXTINT_driver/EXTINT_int.h"
#include "IR_confg.h"

void IR_voidinit(void);
u8 IR_u8GetStatus(u8);
void IR_voidIR0ISR(void (*IR_func)(void));
void IR_voidIR1ISR(void (*IR_func)(void));


#define IR_DETECT		1
#define IR_NOT_DETECT	0



#endif /* IR_INT_H_ */