/* 
 * File:   ECU_button.h
 * Author: Mayar Mahmoud; 
 *
 * Created on February 9, 2024, 8:06 AM
 */

#ifndef ECU_BUTTON_H
#define	ECU_BUTTON_H
/*---------------------------- INCLUDE --------------------------*/
#include "../../MCAL_Layer/GPIO/HAL_GPIO.h"
#include "ECU_button_config.h"

/*----------------------------- MACROS --------------------------*/
/*-------------------- SELF-DEFINED DATATYPES -------------------*/
typedef enum
{
    BUTTON_RELEASED,
    BUTTON_PRESSED
}button_state_t;

typedef enum
{
    BUTTON_ACTIVE_LOW,
    BUTTON_ACTIVE_HIGH
}
button_connection_t;

typedef struct
{
    pin_config_t button_pin;
    button_state_t button_state ;
    button_connection_t button_connection ;
    
}button_t;

/*-------------------------- PROTOTYPES -------------------------*/
Std_ReturnType button_initialize (const button_t *_btn);
Std_ReturnType button_read_state (const button_t *_btn, button_state_t *_btn_state);



#endif	/* ECU_BUTTON_H */

