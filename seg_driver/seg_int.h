/*
 * seg_int.h
 *
 * Created: 9/17/2019 11:17:26 AM
 *  Author: Louda
 */ 


#ifndef SEG_INT_H_
#define SEG_INT_H_


#include "DIO_driver/DIO_int.h"
#include "seg_confg.h"

void seg_voidinit(void);
void seg_voiddisplay(u8 seg_num ,u8 display_num);
void seg_voidturnoff(u8 seg_num);


#endif /* SEG_INT_H_ */