/* 
 * File:   ECU_button.c
 * Author: Mayar Mahmoud; 
 *
 * Created on February 9, 2024, 8:06 AM
 */
/*---------------------------- INCLUDE --------------------------*/
#include "ECU_button.h"
/*------------------------ STATIC FUNCTIONS  --------------------*/

/*---------------------- FUNCTIONS DEFINITION -------------------*/

/**
 * @brief Initialization of a button
 * @param _btn a pointer to the button @ref button_t
 * @return Std_ReturnType indicating the progress of the functions (success or fail)
 *         E_OK for success 
 *         E_NOK for fail
 */
Std_ReturnType button_initialize (const button_t *_btn)
{
    Std_ReturnType ret = E_OK;
    if(_btn != NULL)
    {
        gpio_pin_direction_initialize(&(_btn->button_pin));
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
 * @param _btn
 * @param _btn_state
 * @return Std_ReturnType indicating the progress of the functions (success or fail)
 *         E_OK for success 
 *         E_NOK for fail
 */
Std_ReturnType button_read_state (const button_t *_btn, button_state_t *_btn_state)
{
    Std_ReturnType ret = E_OK;
    logic_t btn_logic = GPIO_LOW;
    
    if( (_btn != NULL) && (_btn_state != NULL) )
    {
        ret = gpio_pin_read_logic(&(_btn->button_pin), &btn_logic);
        if( BUTTON_ACTIVE_HIGH  == _btn->button_connection)
        {
            if( GPIO_HIGH == btn_logic)
            { *_btn_state = BUTTON_PRESSED; }
            else
            { *_btn_state = BUTTON_RELEASED;}
        }
        else
        { 
            if( BUTTON_ACTIVE_LOW == _btn->button_connection)
            {
                if( GPIO_LOW == btn_logic)
                { *_btn_state = BUTTON_PRESSED; }
                else
                { *_btn_state = BUTTON_RELEASED;}
            }
            else
            { /* NOTHING */}
        }
    }
    else
    {
        ret = E_NOK;
    }
    return ret;
}