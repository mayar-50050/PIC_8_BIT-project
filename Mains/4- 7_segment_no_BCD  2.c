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
seven_segment_t seg1 = 
{
    .port = PORTB_INDEX,
    .connection_type = SEVEN_SEGMENT_CA,
};

pin_config_t dp=
{
  .direction = GPIO_DIRECTION_OUTBUT ,
  .logic = GPIO_OUTPUT_HIGH,
  .pin = PIN7,
  .port = PORTB_INDEX
};

uint32 number_h = 80;
uint8 ones = 0, tens = 0, hun=0, thous=0;
uint16 loop = 0;

uint8 number = 10;
float32 div_e = 0;
uint8 int_div = 0;
int main(void) 
{
    application_initialize();
    while(1)
    {    
        while(number != 0)
        {
            
            ones = number % 10;
            tens = (number)/10;
            hun = ((uint8) (div_e * 100.0)) %100;
            thous = ((uint8) (div_e * 1000)) %1000;
            
            gpio_port_write_logic(PORTA_INDEX,0x08);
            seven_segment_write(&seg1,tens);
            while(loop++<500);
            loop = 0;
            
            gpio_port_write_logic(PORTA_INDEX,0x04);
            seven_segment_write(&seg1,ones);
            gpio_pin_write_logic(&dp,GPIO_LOW);
            while(loop++<2000);
            loop = 0;
            
            
            while(loop++<2000);
            loop = 0;
            gpio_port_write_logic(PORTA_INDEX,0x02);
            seven_segment_write(&seg1,hun);
            while(loop++<2000);
            loop = 0;
            
            gpio_port_write_logic(PORTA_INDEX,0x01);
            seven_segment_write(&seg1,thous);
            while(loop++<2000);
            loop = 0;
            
            div_e = (float32 )number/(float32 )2.0;
            number /= 2;
            
        }
        
        
    }
    return (EXIT_SUCCESS);
}

void application_initialize (void)
{
    gpio_port_direction_initialize(PORTC_INDEX,0x00);
    gpio_port_direction_initialize(PORTB_INDEX,0x00);
    gpio_port_direction_initialize(PORTA_INDEX,0xF0);
    gpio_pin_initialize(&dp);
    seven_segment_initialize(&seg1);
}