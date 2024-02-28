/* 
 * File:   ECU_7_segment.h
 * Author: Mayar Mahmoud; 
 *
 * Created on February 12, 2024, 2:23 PM
 */

#ifndef ECU_7_SEGMENT_H
#define	ECU_7_SEGMENT_H

/*---------------------------- INCLUDE --------------------------*/
#include "ECU_7_segment_cfg.h"
#include "../../MCAL_Layer/GPIO/HAL_GPIO.h"
/*----------------------------- MACROS --------------------------*/
#define SEVEN_SEGMENT_DICIMAL_VALUE        0x00U
#define SEVEN_SEGMENT_NOT_DICIMAL_VALUE    0x01U

#define SEVEN_SEGMENT_DP_MASK_CC           0x80U
#define SEVEN_SEGMENT_DP_MASK_CA           0x7FU

#define SEVEN_SEGMENT_DP_ON_CC(_value)     ((_value) |= SEVEN_SEGMENT_DP_MASK_CC)
#define SEVEN_SEGMENT_DP_ON_CA(_value)     ((_value) |= SEVEN_SEGMENT_DP_MASK_CA)
/*---------------- SEVEN SEGMENT VALUES PATTREN -----------------*/
uint8 SEVEN_SEGMENT_CC_VALUES[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07,  0x7F, 0x6F};
uint8 SEVEN_SEGMENT_CA_VALUES[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8,  0x80, 0x90};
/*-------------------- SELF-DEFINED DATATYPES -------------------*/
typedef enum
{
    SEVEN_SEGMENT_CA = 0,
    SEVEN_SEGMENT_CC
            
}seven_segment_connection_t;

typedef enum
{
    NO_ZERO = 0,
    NO_ONE,
    NO_TWO,
    NO_THREE,
    NO_FOUR,
    NO_FIVE,
    NO_SIX,
    NO_SEVEN,
    NO_EIGHT,
    NO_NINE
            
}seven_segment_values_t;

typedef struct
{
    uint8                   port             :3;
    boolean                 connection_type  :1;
    boolean                 dp_led_on        :1;
    uint8                   number_of_digits :3;
}seven_segment_t;
/*-------------------------- PROTOTYPES -------------------------*/

Std_ReturnType seven_segment_initialize (const seven_segment_t *_7_segment);
Std_ReturnType seven_segment_write (const seven_segment_t *_7_segment, uint8 _value);

#endif	/* ECU_7_SEGMENT_H */

