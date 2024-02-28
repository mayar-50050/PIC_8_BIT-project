/* 
 * File:   ECU_dc_motor.h
 * Author: Mayar Mahmoud; 
 *
 * Created on February 10, 2024, 5:00 PM
 */

#ifndef ECU_DC_MOTOR_H
#define	ECU_DC_MOTOR_H

/*---------------------------- INCLUDE --------------------------*/
#include "ECU_dc_motor_cfg.h"
#include "../../MCAL_Layer/GPIO/HAL_GPIO.h"

/*----------------------------- MACROS --------------------------*/
#define DC_MOTOR_ON_STATE               0x01U
#define DC_MOTOR_OFF_STATE              0x00U

#define DC_MOTOR_DIRECTION_FORWORD      0x00U
#define DC_MOTOR_DIRECTION_BACKWORD     0x01U

#define DC_MOTOR_PIN_1                  0x00U
#define DC_MOTOR_PIN_2                  0x01U
/*-------------------- SELF-DEFINED DATATYPES -------------------*/

typedef struct
{
    pin_config_t pins[2]; 
    uint8 motor_state;
    uint8 motor_direction; 
}dc_motor_t;

/*-------------------------- PROTOTYPES -------------------------*/
Std_ReturnType dc_motor_initialize ( dc_motor_t *_dc_motor);
Std_ReturnType dc_motor_move_right (const dc_motor_t *_dc_motor);
Std_ReturnType dc_motor_move_left (const dc_motor_t *_dc_motor);
Std_ReturnType dc_motor_stop (const dc_motor_t *_dc_motor);
Std_ReturnType dc_motor_break (const dc_motor_t *_dc_motor);


/////////////////////////////////////////////////////////////////////////

#endif	/* ECU_DC_MOTOR_H */

