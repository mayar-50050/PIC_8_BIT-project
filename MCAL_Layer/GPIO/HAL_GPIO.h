/* 
 * File:   HAL_GPIO.h
 * Author: Mayar Mahmoud; 
 *
 * Created on January 27, 2024, 11:17 PM
 */

#ifndef HAL_GPIO_H
#define	HAL_GPIO_H

/*---------------------------- INCLUDE --------------------------*/
#include <stdio.h>
#include <stdlib.h>

#include "HAL_GPIO_cfg.h"
#include "../proc/pic18f4620.h"
#include "../MCAL_std_types.h"
#include "../device_config.h"


/*----------------------------- MACROS --------------------------*/
#define BIT_MASK                    ((uint8) 1 )
#define PORT_PIN_MAX_NUMBER         8
#define PORT_MAX_NUMBER             5
#define PORT_FULL_MASK              0xFF  

#define PORT_FULL_OUTPUT            0x00
#define PORT_FULL_INPUT             0xFF
/*--------------------- FUNCTION LIKE MACROS --------------------*/
#define HWREG8 (_x)                 (*((volatile uint8 *)(_x)))
#define SET_BIT(REG, BIT_POSN)      ((REG |=(BIT_MASK <<BIT_POSN)))
#define CLEAR_BIT(REG, BIT_POSN)    ((REG &= ~(BIT_MASK <<BIT_POSN)))
#define TOGGLE_BIT(REG, BIT_POSN)   ((REG ^=(BIT_MASK <<BIT_POSN)))
#define READ_BIT(REG, BIT_POSN)     ((REG >> BIT_POSN) & BIT_MASK )


/*-------------------- SELF-DEFINED DATATYPES -------------------*/
typedef enum
{
    PORTA_INDEX =0,
    PORTB_INDEX,
    PORTC_INDEX,
    PORTD_INDEX,
    PORTE_INDEX

}port_index_t;

typedef enum
{
    GPIO_PIN0 = 0,
    GPIO_PIN1,
    GPIO_PIN2,        
    GPIO_PIN3,        
    GPIO_PIN4,        
    GPIO_PIN5,        
    GPIO_PIN6,
    GPIO_PIN7

}pin_index_t;

typedef enum 
{
    GPIO_OUTPUT_LOW = 0,
    GPIO_OUTPUT_HIGH

}logic_t;

typedef enum 
{
    GPIO_DIRECTION_OUTBUT = 0,
    GPIO_DIRECTION_INPUT

}direction_t;

typedef struct
{
    uint8 port      : 3;  /*@ref: port_index_t*/
    uint8 pin       : 3;  /*@ref: pin_index_t*/
    uint8 direction : 1;  /*@ref: direction_t*/
    uint8 logic     : 1;  /*@ref: logic_t*/

}pin_config_t;

/*-------------------------- PROTOTYPES -------------------------*/
Std_ReturnType gpio_pin_direction_initialize(const pin_config_t *_pin_config);
Std_ReturnType gpio_pin_get_direction_status(const pin_config_t *_pin_config, direction_t *_direction_status);
Std_ReturnType gpio_pin_write_logic(const pin_config_t *_pin_config, logic_t _logic);
Std_ReturnType gpio_pin_read_logic(const pin_config_t *_pin_config, logic_t *_logic);
Std_ReturnType gpio_pin_toggle_logic(const pin_config_t *_pin_config);
Std_ReturnType gpio_pin_initialize(const pin_config_t *_pin_config);

Std_ReturnType gpio_port_direction_initialize(const port_index_t _port, uint8 _direction);
Std_ReturnType gpio_port_get_direction_status(const port_index_t _port, uint8 *_direction_status);
Std_ReturnType gpio_port_write_logic(const port_index_t _port, uint8 _logic);
Std_ReturnType gpio_port_read_logic(const port_index_t _port, uint8 *_logic);
Std_ReturnType gpio_port_toggle_logic(const port_index_t _port);




#endif	/* HAL_GPIO_H */

