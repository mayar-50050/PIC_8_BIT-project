/* 
 * File:   ECU_dc_motor.c
 * Author: Mayar Mahmoud; 
 *
 * Created on February 10, 2024, 5:00 PM
 */

/*---------------------------- INCLUDE --------------------------*/
#include "ECU_dc_motor.h"

/*------------------------ STATIC FUNCTIONS  --------------------*/

/*---------------------- FUNCTIONS DEFINITION -------------------*/
/**
 * 
 * @param _dc_motor
 * @return 
 */
Std_ReturnType dc_motor_initialize ( dc_motor_t *_dc_motor)
{
    Std_ReturnType ret = E_OK;
    if(_dc_motor != NULL)
    {
        _dc_motor->pins[DC_MOTOR_PIN_1].direction = GPIO_DIRECTION_OUTBUT;
        _dc_motor->pins[DC_MOTOR_PIN_2].direction = GPIO_DIRECTION_OUTBUT;
        _dc_motor->pins[DC_MOTOR_PIN_1].logic = GPIO_OUTPUT_LOW;
        _dc_motor->pins[DC_MOTOR_PIN_2].logic = GPIO_OUTPUT_LOW;
        
        ret = gpio_pin_initialize( &(_dc_motor->pins[DC_MOTOR_PIN_1]));
        ret = gpio_pin_initialize( &(_dc_motor->pins[DC_MOTOR_PIN_2]));
        
        if (_dc_motor->motor_state == DC_MOTOR_ON_STATE)
        {
            switch(_dc_motor->motor_direction)
            {
                case DC_MOTOR_DIRECTION_FORWORD:
                    ret = dc_motor_move_right(_dc_motor);
                    break;
                case DC_MOTOR_DIRECTION_BACKWORD:
                    ret = dc_motor_move_left(_dc_motor);
                    break;
                default :
                    ret = E_NOK;
                    break;
            }
        }
        else
        { /*NOTHING */}
    }
    else
    {
        ret = E_NOK;
    }
    return ret;
}
/////////////////////////////////////////////////////////////////////////



/**
 * 
 * @param _dc_motor
 * @return 
 */
Std_ReturnType dc_motor_move_right (const dc_motor_t *_dc_motor)
{
    Std_ReturnType ret = E_OK;
    if(_dc_motor != NULL)
    {
        ret = gpio_pin_write_logic(&(_dc_motor->pins[DC_MOTOR_PIN_1]),GPIO_HIGH);
        ret = gpio_pin_write_logic(&(_dc_motor->pins[DC_MOTOR_PIN_2]),GPIO_LOW);
        
    }
    else
    {
        ret = E_NOK;
    }
    return ret;
}
/////////////////////////////////////////////////////////////////////////



/**
 * 
 * @param _dc_motor
 * @return 
 */
Std_ReturnType dc_motor_move_left (const dc_motor_t *_dc_motor)
{
    Std_ReturnType ret = E_OK;
    if(_dc_motor != NULL)
    {
        ret = gpio_pin_write_logic(&(_dc_motor->pins[DC_MOTOR_PIN_1]),GPIO_LOW);
        ret = gpio_pin_write_logic(&(_dc_motor->pins[DC_MOTOR_PIN_2]),GPIO_HIGH);
    }
    else
    {
        ret = E_NOK;
    }
    return ret;
}
/////////////////////////////////////////////////////////////////////////



/**
 * 
 * @param _dc_motor
 * @return 
 */
Std_ReturnType dc_motor_stop (const dc_motor_t *_dc_motor)
{
    Std_ReturnType ret = E_OK;
    if(_dc_motor != NULL)
    {
        ret = gpio_pin_write_logic(&(_dc_motor->pins[DC_MOTOR_PIN_1]),GPIO_LOW);
        ret = gpio_pin_write_logic(&(_dc_motor->pins[DC_MOTOR_PIN_2]),GPIO_LOW);
    }
    else
    {
        ret = E_NOK;
    }
    return ret;
}
/////////////////////////////////////////////////////////////////////////



/**
 * 
 * @param _dc_motor
 * @return 
 */
Std_ReturnType dc_motor_break (const dc_motor_t *_dc_motor)
{
    Std_ReturnType ret = E_OK;
    if(_dc_motor != NULL)
    {
        ret = gpio_pin_write_logic(&(_dc_motor->pins[DC_MOTOR_PIN_1]),GPIO_HIGH);
        ret = gpio_pin_write_logic(&(_dc_motor->pins[DC_MOTOR_PIN_2]),GPIO_HIGH);
    }
    else
    {
        ret = E_NOK;
    }
    return ret;
}
/////////////////////////////////////////////////////////////////////////