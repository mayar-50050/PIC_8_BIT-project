/* 
 * File:   ECU_led.c
 * Author: Mayar Mahmoud; 
 *
 * Created on January 27, 2024, 11:34 PM
 */

/*---------------------------- INCLUDE --------------------------*/
#include "ECU_led.h"

/*----------------------------- MACROS --------------------------*/

/*-------------------- SELF-DEFINED DATATYPES -------------------*/

/*------------------------ STATIC FUNCTIONS  --------------------*/

static Std_ReturnType led_change_state(led_t *_led, led_status_t new_state);

/*---------------------- FUNCTIONS DEFINITION -------------------*/


/**
 * @brief LED Initialization  
 * @param _led a pointer to the led @ref led_t 
 * @return Std_ReturnType indicating the progress of the functions (success or fail)
 *         E_OK for success 
 *         E_NOK for fail
 */
Std_ReturnType led_initialize(const led_t *_led)
{
    Std_ReturnType ret = E_OK;
    if(_led != NULL)
    {
        pin_config_t pin =
        {
          .direction = GPIO_DIRECTION_OUTBUT,
          .logic = _led->led_status,
          .port = _led->port_name,
          .pin = _led->pin
        };
        ret = gpio_pin_initialize(&pin);
    }
    else
    {
        ret = E_NOK;
    }
    return ret;
}
/////////////////////////////////////////////////////////////////////////



/**
 * @brief  Output high on the pin (turns on a LED)
 * @param _led a pointer to the led @ref led_t 
 * @return Std_ReturnType indicating the progress of the functions (success or fail)
 *         E_OK for success 
 *         E_NOK for fail 
 */
Std_ReturnType led_turn_on(const led_t *_led)
{
    Std_ReturnType ret = E_OK;
    if(_led != NULL)
    {
        pin_config_t pin =
        {
          .direction = GPIO_DIRECTION_OUTBUT,
          .logic = _led->led_status,
          .port = _led->port_name,
          .pin = _led->pin
        };
        if(_led->led_status == LED_OFF)
        {
            ret = gpio_pin_write_logic(&pin,GPIO_OUTPUT_HIGH);
            ret = led_change_state(_led,LED_ON);
        }
        else
        {}
    }
    else
    {
        ret = E_NOK;
    }
    return ret;
}
/////////////////////////////////////////////////////////////////////////



/**
 * @brief
 * @param _led a pointer to the led @ref led_t 
 * @return Std_ReturnType indicating the progress of the functions (success or fail)
 *         E_OK for success 
 *         E_NOK for fail 
 */
Std_ReturnType led_turn_off(const led_t *_led)
{
    Std_ReturnType ret = E_OK;
    if(_led != NULL)
    {
        pin_config_t pin =
        {
          .direction = GPIO_DIRECTION_OUTBUT,
          .logic = _led->led_status,
          .port = _led->port_name,
          .pin = _led->pin
        };
        if(_led->led_status == LED_ON)
        {
            ret = gpio_pin_write_logic(&pin,GPIO_OUTPUT_LOW); 
            ret = led_change_state(_led,LED_OFF);
        }
        else
        {}
    }
    else
    {
        ret = E_NOK;
    }
    return ret;
}
/////////////////////////////////////////////////////////////////////////



/**
 * @brief  Toggles the state of a LED
 * @param _led a pointer to the led @ref led_t 
 * @return Std_ReturnType indicating the progress of the functions (success or fail)
 *         E_OK for success 
 *         E_NOK for fail 
 */
Std_ReturnType led_toggle(const led_t *_led)
{
    Std_ReturnType ret = E_OK;
    if(_led != NULL)
    {
        pin_config_t pin =
        {
          .direction = GPIO_DIRECTION_OUTBUT,
          .logic = _led->led_status,
          .port = _led->port_name,
          .pin = _led->pin
        };
        
        switch(_led->led_status)
        {
            case LED_OFF:
                ret = led_turn_on(_led);
                break;
            
            case LED_ON:
                ret = led_turn_off(_led);
                break;
                
            default:
                ret = E_NOK;
                break;
        }
    }
    else
    {
        ret = E_NOK;
    }
    return ret;
}
/////////////////////////////////////////////////////////////////////////


/**
 * @brief  Changes the state of the led @ref pointer->led_status
 * @param _led a pointer to the led @ref led_t 
 * @return Std_ReturnType indicating the progress of the functions (success or fail)
 *         E_OK for success 
 *         E_NOK for fail 
 */
static Std_ReturnType led_change_state(led_t *_led, led_status_t new_state)
{
    Std_ReturnType ret = E_OK;
    if(_led != NULL)
    {
        _led->led_status = new_state;
    }
    else
    {
        ret = E_NOK;
    }
    return ret;
}
