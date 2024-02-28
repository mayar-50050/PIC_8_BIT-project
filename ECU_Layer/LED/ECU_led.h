/* 
 * File:   ECU_led.h
 * Author: Mayar Mahmoud; 
 *
 * Created on January 27, 2024, 11:34 PM
 */

#ifndef ECU_LED_H
#define	ECU_LED_H

/*---------------------------- INCLUDE --------------------------*/
#include "../../MCAL_Layer/GPIO/HAL_GPIO.h"
#include "ECU_led_config.h"

/*----------------------------- MACROS --------------------------*/
/*-------------------- SELF-DEFINED DATATYPES -------------------*/
typedef enum
{
    LED_OFF,
    LED_ON
}led_status_t;

typedef struct
{
    uint8 port_name : 3;
    uint8 pin       : 3;
    uint8 led_status: 1;
    uint8           : 1;
}led_t;
/*-------------------------- PROTOTYPES -------------------------*/
Std_ReturnType led_initialize(const led_t *_led);
Std_ReturnType led_turn_on(const led_t *_led);
Std_ReturnType led_turn_off(const led_t *_led);
Std_ReturnType led_toggle(const led_t *_led);


#endif	/* ECU_LED_H */

