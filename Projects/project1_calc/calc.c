/* 
 * File:   Project1_calculator.c
 * Author: Mayar Mahmoud; 
 *
 * Created on February 27, 2024, 10:00 PM
 */

/*---------------------------- INCLUDE --------------------------*/
#include "calc.h"

/*-------------------------PINS initialize-----------------------*/

/*---------------------- FUNCTIONS DEFINITION -------------------*/
Std_ReturnType calculator_initialize(const calculator_t *_calc)
{
    Std_ReturnType ret = E_OK;
    if(_calc != NULL)
    {
        ret = keypad_initialize(&(_calc->keypad));
        ret &=lcd_8bit_initialize(&(_calc->lcd)); 
    }
    else
    {
        ret = E_NOK;
    }
    return ret;
}


Std_ReturnType calculator_get_key(const calculator_t *_calc,uint8 *_value)
{
    Std_ReturnType ret = E_OK;
    uint8 value;
    if(_calc != NULL)
    {
        ret = keypad_get_value(&(_calc->keypad), _value);
        ret &= lcd_8bit_send_data(&(_calc->lcd),*_value);
    }
    else
    {
        ret = E_NOK;
    }
    return ret;
}