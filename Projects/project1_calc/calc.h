/* 
 * File:   Project1_calculator.h
 * Author: Mayar Mahmoud; 
 *
 * Created on February 27, 2024, 10:00 PM
 */

#ifndef _CALC_H_
#define _CALC_H_
/*---------------------------- INCLUDE --------------------------*/
#include "../../ECU_Layer/Keypad/ECU_keypad.h"
#include "../../ECU_Layer/LCD/ECU_LCD.h"
/*-------------------- SELF-DEFINED DATATYPES -------------------*/
typedef struct 
{
    keypad_t keypad;
    lcd_8b_t lcd;
    
}calculator_t;
/*-------------------------- PROTOTYPES -------------------------*/
Std_ReturnType calculator_initialize(const calculator_t *_calc);
Std_ReturnType calculator_get_key(const calculator_t *_calc,uint8 *_value);


#endif /*_CALC_H_*/