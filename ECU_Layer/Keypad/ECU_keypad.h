/* 
 * File:   ECU_keypad.h
 * Author: Mayar Mahmoud; 
 *
 * Created on February 19, 2024, 7:46 PM
 */

#ifndef ECU_KEYPAD_H
#define	ECU_KEYPAD_H

/*---------------------------- INCLUDE --------------------------*/
#include "../../MCAL_Layer/GPIO/HAL_GPIO.h"
#include "ECU_keypad_cfg.h"
/*----------------------------- MACROS --------------------------*/
#define KEYPAD_NUMBER_OF_ROWS           4
#define KEYPAD_NUMBER_OF_COLUMNS        4 

#define KEYPAD_CONNECTION_LOW           0
#define KEYPAD_CONNECTION_HIGH          1

/*-------------------- SELF-DEFINED DATATYPES -------------------*/
uint8 keypad_values[KEYPAD_NUMBER_OF_ROWS][KEYPAD_NUMBER_OF_COLUMNS] = 
                          {{'7', '8', '9', '/'},
                           {'4', '5', '6', '*'},
                           {'1', '2', '3', '-'},
                           {'G', '0', '=', '+'}};
typedef struct 
{
    pin_config_t keypad_rows[KEYPAD_NUMBER_OF_ROWS];        /*@ref: pin_config_t*/
    pin_config_t keypad_columns[KEYPAD_NUMBER_OF_COLUMNS];  /*@ref: pin_config_t*/
    boolean      keypad_connection_type;
}keypad_t;

/*-------------------------- PROTOTYPES -------------------------*/
Std_ReturnType keypad_initialize (const keypad_t *_keypad);
Std_ReturnType keypad_get_value (const keypad_t *_keypad,uint8 *_value);
#endif	/* ECU_KEYPAD_H */

