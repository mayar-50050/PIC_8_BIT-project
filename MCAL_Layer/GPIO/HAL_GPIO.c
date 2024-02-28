/* 
 * File:   HAL_GPIO.c
 * Author: Mayar Mahmoud; 
 *
 * Created on January 27, 2024, 11:17 PM
 */

/*-------------------- INCLUDE--------------------*/
#include "HAL_GPIO.h"

volatile uint8 *tris_reg[5]={&TRISA, &TRISB, &TRISC, &TRISD, &TRISE};
volatile uint8 *lat_reg[5]={&LATA, &LATB, &LATC, &LATD, &LATE};
volatile uint8 *port_reg[5]={&PORTA, &PORTB, &PORTC, &PORTD, &PORTE}; 

/*---------------------- FUNCTIONS DEFINITION -------------------*/
#if(GPIO_PORT_PIN_CONFIG == CONFIG_ENABLE)
/**
 * @brief:  Initialization of pin direction
 * @param:  _pin_config is a pointer to the pin and holds the port/pin_no/direction/logic data @ref pin_config_t
 * @return: Std_ReturnType indicating the progress of the functions (success or fail)
 *         E_OK for success 
 *         E_NOK for fail
 */
Std_ReturnType gpio_pin_direction_initialize(const pin_config_t *_pin_config)
{
    Std_ReturnType Status = E_OK;

    if(_pin_config == NULL || ((_pin_config->pin) > (PORT_PIN_MAX_NUMBER-1)) || ((_pin_config->port) > (PORT_MAX_NUMBER-1)) )
    {
        Status = E_NOK;
    }

    else
    {
        switch(_pin_config->direction)
        {
            case GPIO_DIRECTION_OUTBUT:
                CLEAR_BIT(*tris_reg[_pin_config->port], _pin_config->pin);
                break;
            case GPIO_DIRECTION_INPUT:
                SET_BIT(*tris_reg[_pin_config->port],_pin_config->pin);
                break;
            default: 
                Status = E_NOK;
                break;
        }
    }
    return Status;
}
/////////////////////////////////////////////////////////////////////////



/**
 * @brief  reads the pin direction (input/output)
 * @param _pin_config an object holding port/pin number @ref pin_config_t
 * @param _direction_status a pointer returning the direction (RBV) @ref direction_t 
 * @return Std_ReturnType indicating the progress of the functions (success or fail)
 *         E_OK for success 
 *         E_NOK for fail
 */
Std_ReturnType gpio_pin_get_direction_status(const pin_config_t *_pin_config, direction_t *_direction_status)
{
    Std_ReturnType Status = E_OK;

    if( (_pin_config != NULL) && (_pin_config->pin < PORT_PIN_MAX_NUMBER) && (_direction_status != NULL))
    {
        *_direction_status = READ_BIT(*tris_reg[_pin_config->port],_pin_config->pin );
    }
    else
    {
        Status = E_NOK;
    }
    return Status;
}
/////////////////////////////////////////////////////////////////////////



/**
 * @brief   outputs high/low voltage from a pin
 * @param   _pin_config is a pointer to the pin and holds the port/pin_no/direction/logic data @ref pin_config_t
 * @param   _logic the voltage value @ref logic_t
 * @return  Std_ReturnType indicating the progress of the functions (success or fail)
 *         E_OK for success 
 *         E_NOK for fail
 */
Std_ReturnType gpio_pin_write_logic(const pin_config_t *_pin_config, logic_t _logic)
{
    Std_ReturnType Status = E_OK;
    if(_pin_config != NULL && (_pin_config->direction == GPIO_DIRECTION_OUTBUT) && (_pin_config->pin < PORT_PIN_MAX_NUMBER))
    {
        switch(_logic)
        {
            case GPIO_OUTPUT_LOW:
                CLEAR_BIT(*lat_reg[_pin_config->port],(_pin_config->pin));
                break;
            case GPIO_OUTPUT_HIGH:
                SET_BIT(*lat_reg[_pin_config->port],(_pin_config->pin));
                break;
            default:
                Status = E_NOK;
                break;
        }
    }
    else
    {
        Status = E_NOK;
    }
    return Status;
}
/////////////////////////////////////////////////////////////////////////



/**
 * @brief   reads pin logic (high/low voltage)
 * @param   _pin_config an object holding port/pin number @ref pin_config_t
 * @param   _logic a pointer returning the logic (RBV) @ref logic_t
 * @return  Std_ReturnType indicating the progress of the functions (success or fail)
 *           E_OK for success 
 *           E_NOK for fail
 */
Std_ReturnType gpio_pin_read_logic(const pin_config_t *_pin_config, logic_t *_logic)
{
    Std_ReturnType Status = E_OK;
    if( (_pin_config != NULL) && (_pin_config->pin < PORT_PIN_MAX_NUMBER) && (_logic != NULL))
    {
        *_logic = READ_BIT(*port_reg[_pin_config->port],_pin_config->pin);
    }
    else
    {
        Status = E_NOK;
    }
    return Status;
}
/////////////////////////////////////////////////////////////////////////



/**
 * @brief   toggles a pin logic
 * @param   _pin_config an object holding port/pin number @ref pin_config_t
 * @return  Std_ReturnType indicating the progress of the functions (success or fail)
 *          E_OK for success 
 *          E_NOK for fail
 */
Std_ReturnType gpio_pin_toggle_logic(const pin_config_t *_pin_config)
{
    Std_ReturnType Status = E_OK;
    if(_pin_config != NULL)
    {
        TOGGLE_BIT(*lat_reg[_pin_config->port], _pin_config->pin);
    }
    else
    {
        Status = E_NOK;
    }
    return Status;
}
/////////////////////////////////////////////////////////////////////////



/**
 * @brief Initialization pins output pins
 * @param _pin_config an object holding port/pin number and pin-logic @ref pin_config_t
 * @return Std_ReturnType indicating the progress of the functions (success or fail)
 *         E_OK for success 
 *         E_NOK for fail
 * 
 * 
 *  ///////////  ONLY USE IN OUTPUT PINS AS IT WRITES LOGIC  ///////////
 */
Std_ReturnType gpio_pin_initialize(const pin_config_t *_pin_config) 
{
    Std_ReturnType Status = E_OK;
    if(_pin_config != NULL)
    {
        gpio_pin_direction_initialize(_pin_config);
        gpio_pin_write_logic(_pin_config,(_pin_config->logic));
    }
    else
    {
        Status = E_NOK;
    }
    return Status;
}
/////////////////////////////////////////////////////////////////////////
#endif
/////////////////////////////////////////////////////////////////////////



#if(GPIO_PORT_CONFIG == CONFIG_ENABLE)
/**
 * @brief Initialization  of a port
 * @param _port the meant port @ref port_index_t
 * @param _direction port-bit long variable holds the Initialization 
 * @return Std_ReturnType indicating the progress of the functions (success or fail)
 *         E_OK for success 
 *         E_NOK for fail
 */
Std_ReturnType gpio_port_direction_initialize(const port_index_t _port, uint8 _direction)
{
    Std_ReturnType Status = E_OK;
    if((_port < PORT_MAX_NUMBER))
    {
        *(tris_reg[_port]) = _direction;
    }
    else
    {
        Status = E_NOK;
    }
    return Status;
}
/////////////////////////////////////////////////////////////////////////



/**
 * @brief   returns the direction of a port 
 * @param   _port the meant port @ref port_index_t
 * @param   _direction_status a pointer to a variable to return the direction 
 * @return  Std_ReturnType indicating the progress of the functions (success or fail)
 *          E_OK for success 
 *          E_NOK for fail
 */
Std_ReturnType gpio_port_get_direction_status(const port_index_t _port, uint8 *_direction_status)
{
    Std_ReturnType Status = E_OK;
    if((_direction_status != NULL) && (_port < PORT_MAX_NUMBER))
    {
        *_direction_status = *(tris_reg[_port]);
    }
    else
    {
        Status = E_NOK;
    }
    return Status;
}
/////////////////////////////////////////////////////////////////////////



/**
 * @brief   Writes logic on port pins
 * @param   _port the meant port @ref port_index_t
 * @param   _logic is the logic on pins @ref _logic
 * @return  Std_ReturnType indicating the progress of the functions (success or fail)
 *          E_OK for success 
 *          E_NOK for fail
 */
Std_ReturnType gpio_port_write_logic(const port_index_t _port, uint8 _logic)
{
    Std_ReturnType Status = E_OK;
    if((_port < PORT_MAX_NUMBER) )
    {
        *lat_reg[_port] = _logic;
    }
    else
    {
        Status = E_NOK;
    }
    return Status;
}
/////////////////////////////////////////////////////////////////////////



/**
 * @brief   reads logic of ports
 * @param _port the meant port @ref port_index_t
 * @param _logic a pointer to hold the the logic 
 * @return Std_ReturnType indicating the progress of the functions (success or fail)
 *         E_OK for succes 
 *         E_NOK for fail
 */
Std_ReturnType gpio_port_read_logic(const port_index_t _port, uint8 *_logic)
{
    Std_ReturnType Status = E_OK;
    if((_port < PORT_MAX_NUMBER) )
    {
        *_logic = *lat_reg[_port] ;
    }
    else
    {
        Status = E_NOK;
    }
    return Status;
}
/////////////////////////////////////////////////////////////////////////



/**
 * @brief
 * @param _port
 * @return Std_ReturnType indicating the progress of the functions (success or fail)
 *         E_OK for succes 
 *         E_NOK for fail
 */
Std_ReturnType gpio_port_toggle_logic(const port_index_t _port)
{
    Std_ReturnType Status = E_OK;
    if((_port < PORT_MAX_NUMBER) )
    {
        *lat_reg[_port] ^= PORT_FULL_MASK;
    }
    else
    {
        Status = E_NOK;
    }
    return Status;
}
/////////////////////////////////////////////////////////////////////////


#endif