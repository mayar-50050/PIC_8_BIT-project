/* 
 * File:   ECU_relay.h
 * Author: Mayar Mahmoud; 
 *
 * Created on February 10, 2024, 1:41 PM
 */

#ifndef ECU_RELAY_H
#define	ECU_RELAY_H

/*---------------------------- INCLUDE --------------------------*/
#include "../../MCAL_Layer/GPIO/HAL_GPIO.h"
#include "ECU_relay_conf.h"

/*----------------------------- MACROS --------------------------*/
#define RELAY_ON_STATUS         0x01U
#define RELAY_OFF_STATUS        0x00U
/*-------------------- SELF-DEFINED DATATYPES -------------------*/
typedef struct
{
    uint8 relay_port    : 3;
    uint8 relay_pin     : 3;
    uint8 relay_status  : 1;
    uint8               : 1;
}relay_t;

/*-------------------------- PROTOTYPES -------------------------*/
Std_ReturnType relay_initialize(const relay_t *_relay);
Std_ReturnType relay_turn_on(const relay_t *_relay);
Std_ReturnType relay_turn_off(const relay_t *_relay);


#endif	/* ECU_RELAY_H */

