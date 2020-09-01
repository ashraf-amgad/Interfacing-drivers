/*
 * Switches_int.h
 *
 * Created: 9/17/2019 7:18:47 AM
 *  Author: Louda
 */ 


#ifndef SWITCHES_INT_H_
#define SWITCHES_INT_H_


#include "DIO_driver/DIO_int.h"
#include "Switches_conf.h"


void Switches_voidinit(void);
u8 Switches_u8GetStatus(u8 Switch_num);




#endif /* SWITCHES_INT_H_ */