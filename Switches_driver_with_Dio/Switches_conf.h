/*
 * Switches_conf.h
 *
 * Created: 9/17/2019 7:19:22 AM
 *  Author: Louda
 */ 

#include "DIO_driver/DIO_conf.h"

#ifndef SWITCHES_CONF_H_
#define SWITCHES_CONF_H_


#define  SWITCH_PULL_UP		    1
#define	 SWITCH_PULL_DOWN		0

#define  SWITCH_PRESSED			HIGH
#define	 SWITCH_NOT_PRESSED		LOW



#define SWITCH_1			      DIO_PORTB_PIN0
#define SWITCH_1_MODE			  SWITCH_PULL_UP

/* don't forget to connect the external pull down resistor in case of pull down mode */ 
#define SWITCH_2				  DIO_PORTB_PIN1
#define SWITCH_2_MODE			  SWITCH_PULL_DOWN

#define SWITCH_3				  DIO_PORTB_PIN2
#define SWITCH_3_MODE			  SWITCH_PULL_UP



#endif /* SWITCHES_CONF_H_ */