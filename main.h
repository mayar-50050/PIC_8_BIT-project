/* 
 * File:   main.h
 * Author: Mayar Mahmoud; 
 *
 * Created on January 27, 2024, 11:40 PM
 */

#ifndef MAIN_H
#define	MAIN_H

/*---------------------------- INCLUDE --------------------------*/
#include "ECU_Layer/ECU_layer_init.h"
/*----------------------------- MACROS --------------------------*/
#ifndef _XTAL_FREQ
#define _XTAL_FREQ 4000000UL
#endif
/*-------------------------- PROTOTYPES -------------------------*/
/*-------------------- SELF-DEFINED DATATYPES -------------------*/
extern Std_ReturnType program_state;
//extern lcd_8b_t lcd_8;
//extern lcd_4b_t lcd_4;
extern calculator_t calc_v1;
#endif	/* MAIN_H */

