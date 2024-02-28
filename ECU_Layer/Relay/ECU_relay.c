/* 
 * File:   ECU_relay.c
 * Author: Mayar Mahmoud; 
 *
 * Created on February 10, 2024, 1:41 PM
 */
/*---------------------------- INCLUDE --------------------------*/
#include "ECU_relay.h"

/*------------------------ STATIC FUNCTIONS  --------------------*/
static Std_ReturnType relay_toggle_status(relay_t *_relay);

/*---------------------- FUNCTIONS DEFINITION -------------------*/
/**
 * @brief Initialize the relay, pin to OUTPUT and state ON or OFF
 * @param _relay a pointer to relay object
 * @return Std_ReturnType indicating the progress of the functions (success or fail)
 *         E_OK for success 
 *         E_NOK for fail
 */
Std_ReturnType relay_initialize(const relay_t *_relay)
{
    Std_ReturnType ret = E_OK;
    if( _relay != NULL )
    {
        pin_config_t relay_pin =
        {
          .port = _relay->relay_port,
          .pin = _relay->relay_pin,
          .direction = GPIO_DIRECTION_OUTBUT,
          .logic = _relay->relay_status
        };
        
        ret = gpio_pin_initialize( &relay_pin );
    }
    else
    {
        ret = E_NOK;
    }
    return ret;
}
/////////////////////////////////////////////////////////////////////////


/**
 * @brief Turn the relay ON
 * @param _relay a pointer to relay object
 * @return Std_ReturnType indicating the progress of the functions (success or fail)
 *         E_OK for success 
 *         E_NOK for fail
 */
Std_ReturnType relay_turn_on(const relay_t *_relay)
{
    Std_ReturnType ret = E_OK;
    if( _relay != NULL )
    {
        pin_config_t relay_pin =
        {
          .port = _relay->relay_port,
          .pin = _relay->relay_pin,
          .direction = GPIO_DIRECTION_OUTBUT,
          .logic = _relay->relay_status
        };
        
        if(_relay->relay_status == RELAY_OFF_STATUS)
        {
            ret = gpio_pin_write_logic(&relay_pin,GPIO_OUTPUT_HIGH);
            ret = relay_toggle_status(_relay);
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
 * @brief  Turns the relay OFF
 * @param _relay a pointer to relay object
 * @return Std_ReturnType indicating the progress of the functions (success or fail)
 *         E_OK for success 
 *         E_NOK for fail
 */
Std_ReturnType relay_turn_off(const relay_t *_relay)
{
    Std_ReturnType ret = E_OK;
    if( _relay != NULL )
    {
        pin_config_t relay_pin =
        {
          .port = _relay->relay_port,
          .pin = _relay->relay_pin,
          .direction = GPIO_DIRECTION_OUTBUT,
          .logic = _relay->relay_status
        };
        
        if(_relay->relay_status == RELAY_ON_STATUS)
        {
            ret = gpio_pin_write_logic(&relay_pin,GPIO_OUTPUT_LOW);
            ret = relay_toggle_status(_relay);
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
 * @brief changes member element (relay_status) @ref relay_t
 * @param _relay a pointer to relay object
 * @return Std_ReturnType indicating the progress of the functions (success or fail)
 *         E_OK for success 
 *         E_NOK for fail
 */
static Std_ReturnType relay_toggle_status(relay_t *_relay)
{
    Std_ReturnType ret = E_OK;
    if( _relay != NULL )
    {
        _relay->relay_status = !_relay->relay_status;
    }
    else
    {
        ret = E_NOK;
    }
    return ret;
}