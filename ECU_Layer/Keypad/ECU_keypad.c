/* 
 * File:   ECU_keypad.c
 * Author: Mayar Mahmoud; 
 *
 * Created on February 19, 2024, 7:46 PM
 */

/*---------------------------- INCLUDE --------------------------*/
#include "ECU_keypad.h"

/*------------------------ STATIC FUNCTIONS  --------------------*/
//static Std_ReturnType keypad_toggle_state (void);

/*---------------------- FUNCTIONS DEFINITION -------------------*/
/**
 * @brief Initialize the keypad_t object pins 
 * @param _keypad a pointer to a structure of DT keypad_t     /// @ref: keypad_t 
 * @return Std_ReturnType indicating the progress of the functions (success or fail)
 *         E_OK for success 
 *         E_NOK for fail
 */
Std_ReturnType keypad_initialize (const keypad_t *_keypad)
{
    Std_ReturnType ret = E_OK;
    uint8 counter = 0;
    if(_keypad != NULL)
    {
        /*   INITIALIZATION OF ROWS   */
        for(counter = 0; counter < KEYPAD_NUMBER_OF_ROWS; counter++)
        {
            ret = gpio_pin_initialize(&(_keypad->keypad_rows[counter]));
        }
        /*   INITIALIZATION OF COLUMNS  */
        for(counter = 0; counter < KEYPAD_NUMBER_OF_COLUMNS; counter++)
        {
            ret = gpio_pin_direction_initialize(&(_keypad->keypad_columns[counter]));
        }
        
    }
    else
    {
        ret = E_NOK;
    }
    return ret;
}
////////////////////////////////////////////////////////////




/**
 * @brief return the pressed button value
 * @param _keypad a pointer to a structure of DT keypad_t     /// @ref: keypad_t
 * @param _value a container to hold the value
 * @return Std_ReturnType indicating the progress of the functions (success or fail)
 *         E_OK for success 
 *         E_NOK for fail
 * TO_DO: 1- ON/OFF button
 *        2- while ->  write in _value litter U for unpressed  
 */
Std_ReturnType keypad_get_value (const keypad_t *_keypad,uint8 *_value)
{
    Std_ReturnType ret = E_OK;
    
    boolean is_pressed = 0;
    logic_t col_state = GPIO_LOW;
    uint16 row_counter = 0;
    uint16 col_counter = 0;
    
    if(_keypad != NULL && _value != NULL)
    {
        while(is_pressed == 0)
        {
            if (_keypad->keypad_connection_type == KEYPAD_CONNECTION_LOW)
            {
                for (row_counter = 0; row_counter < KEYPAD_NUMBER_OF_ROWS; row_counter++)
                {
                    ret = gpio_pin_write_logic(&(_keypad->keypad_rows[row_counter]),GPIO_OUTPUT_HIGH);

                    for(col_counter = 0; col_counter < KEYPAD_NUMBER_OF_COLUMNS; col_counter++)
                    {
                        ret = gpio_pin_read_logic(&(_keypad->keypad_columns[col_counter]),&col_state);
                        if(col_state == GPIO_HIGH)
                        {
                            *_value = keypad_values[row_counter][col_counter];
                            is_pressed = 1;
                            if(*_value == 'G')
                            {
                                //ret = keypad_toggle_state();
                            }
                            break;
                        }
                    }
                    ret = gpio_pin_write_logic(&(_keypad->keypad_rows[row_counter]),GPIO_OUTPUT_LOW);
                    if(col_state == GPIO_HIGH)
                    {
                        break;
                    }
                }
            }
            else
            {
                if(_keypad->keypad_connection_type == KEYPAD_CONNECTION_HIGH)
                {
                    for (row_counter = 0; row_counter < KEYPAD_NUMBER_OF_ROWS; row_counter++)
                    {
                        ret = gpio_pin_write_logic(&(_keypad->keypad_rows[row_counter]),GPIO_OUTPUT_LOW);

                        for(col_counter = 0; col_counter < KEYPAD_NUMBER_OF_COLUMNS; col_counter++)
                        {
                            ret = gpio_pin_read_logic(&(_keypad->keypad_columns[col_counter]),&col_state);
                            if(col_state == GPIO_LOW)
                            {
                                *_value = keypad_values[row_counter][col_counter];
                                is_pressed = 1;
                                if(*_value == 'G')
                                {
                                    //ret = keypad_toggle_state();
                                }
                                break;
                            }
                        }
                        ret = gpio_pin_write_logic(&(_keypad->keypad_rows[row_counter]),GPIO_OUTPUT_HIGH);
                        if(col_state == GPIO_LOW)
                        {
                            break;
                        }
                    }
                }

                else
                { /*NOTHING*/}
            }
        }
    }
    else
    {
        ret = E_NOK;
    }
    return ret;
}