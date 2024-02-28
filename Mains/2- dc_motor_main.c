/* 
 * File:   main.c
 * Author: Mayar Mahmoud; 
 *
 * Created on January 27, 2024, 9:03 PM
 */
/*---------------------------- INCLUDE --------------------------*/
#include "main.h"
/*---------------------------------------------------------------*/

Std_ReturnType program_state = E_NOK;

led_t led_1 =
{
  .port_name = PORTC_INDEX,
  .pin = PIN0,
  .led_status = LED_OFF
};

led_t led_2 =
{
  .port_name = PORTC_INDEX,
  .pin = PIN1,
  .led_status = LED_OFF
};

led_t led_3 =
{
  .port_name = PORTC_INDEX,
  .pin = PIN2,
  .led_status = LED_OFF
};

led_t led_4 =
{
  .port_name = PORTC_INDEX,
  .pin = PIN3,
  .led_status = LED_OFF
};

relay_t relay1 =
{
    .relay_port = PORTB_INDEX,
    .relay_pin = PIN0,
    .relay_status = RELAY_OFF_STATUS
};

dc_motor_t motor1 = 
{
    .pins[DC_MOTOR_PIN_1 ].port = PORTC_INDEX,
    .pins[DC_MOTOR_PIN_1 ].pin = PIN0,
    .pins[DC_MOTOR_PIN_2 ].port = PORTC_INDEX,
    .pins[DC_MOTOR_PIN_2 ].pin = PIN1,
    
    .motor_state = DC_MOTOR_ON_STATE,
    .motor_direction = DC_MOTOR_DIRECTION_FORWORD
};

dc_motor_t motor2 = 
{
    .pins[DC_MOTOR_PIN_1 ].port = PORTC_INDEX,
    .pins[DC_MOTOR_PIN_1 ].pin = PIN2,
    .pins[DC_MOTOR_PIN_2 ].port = PORTC_INDEX,
    .pins[DC_MOTOR_PIN_2 ].pin = PIN3,
    
    .motor_state = DC_MOTOR_ON_STATE,
    .motor_direction = DC_MOTOR_DIRECTION_BACKWORD
};
pin_config_t enable_motor_1 =
{
    .port = PORTD_INDEX,
    .pin = PIN0,
    .logic = GPIO_OUTPUT_LOW,
    .direction = GPIO_DIRECTION_OUTBUT
};
pin_config_t enable_motor_2 =
{
    .port = PORTD_INDEX,
    .pin = PIN1,
    .logic = GPIO_OUTPUT_LOW,
    .direction = GPIO_DIRECTION_OUTBUT
};

int main(void) 
{
    application_initialize();

    while(1)
    {
        gpio_pin_write_logic(&enable_motor_1,0x01);
        gpio_pin_write_logic(&enable_motor_2,0x01);
        __delay_ms(5000);
        dc_motor_stop(& motor1);
        dc_motor_stop(& motor2);
        __delay_ms(5000);
        dc_motor_move_left(& motor1);
        dc_motor_move_right(& motor2);
        __delay_ms(5000);
        dc_motor_move_right(& motor1);
        dc_motor_move_left(& motor2);
        __delay_ms(5000);
        dc_motor_break(& motor1);
        dc_motor_break(& motor2);
        __delay_ms(5000);
        gpio_pin_write_logic(&enable_motor_1,0x00);
        gpio_pin_write_logic(&enable_motor_2,0x00);
        __delay_ms(5000);
    }
    return (EXIT_SUCCESS);
}

void application_initialize (void)
{
    gpio_pin_initialize(&enable_motor_1);
    gpio_pin_initialize(&enable_motor_2);
//    program_state = led_initialize(& led_1);
//    program_state = led_initialize(& led_2);
//    program_state = led_initialize(& led_3);
//    program_state = led_initialize(& led_4);
    //program_state = relay_initialize(& relay1);
    program_state = dc_motor_initialize(& motor1 );
    program_state = dc_motor_initialize(& motor2 );
}