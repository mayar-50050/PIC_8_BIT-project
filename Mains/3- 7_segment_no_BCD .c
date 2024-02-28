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

seven_segment_t seg1=
{
    .port = PORTC_INDEX,
    .connection_type = SEVEN_SEGMENT_CA,
    .number_of_digits = 2
};

seven_segment_t seg2=
{
    .port = PORTD_INDEX,
    .connection_type = SEVEN_SEGMENT_CC,
    .number_of_digits = 2
};

pin_config_t enable_seg_1 = 
{
  .port = PORTE_INDEX,
  .pin =  PIN0,
  .direction = GPIO_DIRECTION_OUTBUT,
  .logic = GPIO_OUTPUT_LOW
};

pin_config_t enable_seg_2 = 
{
  .port = PORTE_INDEX,
  .pin =  PIN1,
  .direction = GPIO_DIRECTION_OUTBUT,
  .logic = GPIO_OUTPUT_HIGH
};

uint8 counter = 0;

int main(void) 
{
    application_initialize();
    while(1)
    {    
        for(counter = 0; counter<10; counter++)
        {
            program_state = seven_segment_write(&seg1,counter);
            program_state = seven_segment_write(&seg2,counter);
            __delay_ms(2000);
        }
    }
    return (EXIT_SUCCESS);
}

void application_initialize (void)
{
    program_state = gpio_pin_direction_initialize(&enable_seg_1);
    program_state = gpio_pin_direction_initialize(&enable_seg_2);
    program_state = seven_segment_initialize(&seg1);
    program_state = seven_segment_initialize(&seg2);
}