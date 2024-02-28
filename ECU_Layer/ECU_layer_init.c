/* 
 * File:   ECU_layer_init.c
 * Author: Mayar Mahmoud; 
 *
 * Created on February 22, 2024, 2:04 AM
 */

/*---------------------------- INCLUDE --------------------------*/
#include "ECU_layer_init.h"
/*--------------------------------------------------------------*/
Std_ReturnType program_state = E_NOK;
//
//lcd_4b_t lcd_4 =
//{
//    .lcd_rs.direction = GPIO_DIRECTION_OUTBUT,
//    .lcd_rs.logic = LCD_RS_INSTRUCTION,
//    .lcd_rs.pin = PIN0,
//    .lcd_rs.port = PORTA_INDEX,
//    
//    .lcd_rw.direction = GPIO_DIRECTION_OUTBUT,
//    .lcd_rw.logic = GPIO_OUTPUT_LOW,
//    .lcd_rw.pin = PIN1,
//    .lcd_rw.port = PORTA_INDEX,
//    
//    .lcd_en.direction = GPIO_DIRECTION_OUTBUT,
//    .lcd_en.logic = GPIO_OUTPUT_HIGH,
//    .lcd_en.pin = PIN2,
//    .lcd_en.port = PORTA_INDEX,
//    ///////////////////////////////////////////////////////
//    .lcd_pins[0].direction = GPIO_DIRECTION_OUTBUT,
//    .lcd_pins[0].logic = GPIO_OUTPUT_LOW,
//    .lcd_pins[0].pin = PIN0,
//    .lcd_pins[0].port = PORTB_INDEX,
//    
//    .lcd_pins[1].direction = GPIO_DIRECTION_OUTBUT,
//    .lcd_pins[1].logic = GPIO_OUTPUT_LOW,
//    .lcd_pins[1].pin = PIN1,
//    .lcd_pins[1].port = PORTB_INDEX,
//    
//    .lcd_pins[2].direction = GPIO_DIRECTION_OUTBUT,
//    .lcd_pins[2].logic = GPIO_OUTPUT_LOW,
//    .lcd_pins[2].pin = PIN2,
//    .lcd_pins[2].port = PORTB_INDEX,
//    
//    .lcd_pins[3].direction = GPIO_DIRECTION_OUTBUT,
//    .lcd_pins[3].logic = GPIO_OUTPUT_LOW,
//    .lcd_pins[3].pin = PIN3,
//    .lcd_pins[3].port = PORTB_INDEX,
//};
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//lcd_8b_t lcd_8 =
//{
//    .lcd_rs.direction = GPIO_DIRECTION_OUTBUT,
//    .lcd_rs.logic = LCD_RS_INSTRUCTION,
//    .lcd_rs.pin = PIN0,
//    .lcd_rs.port = PORTC_INDEX,
//    
//    .lcd_rw.direction = GPIO_DIRECTION_OUTBUT,
//    .lcd_rw.logic = GPIO_OUTPUT_LOW,
//    .lcd_rw.pin = PIN1,
//    .lcd_rw.port = PORTC_INDEX,
//    
//    .lcd_en.direction = GPIO_DIRECTION_OUTBUT,
//    .lcd_en.logic = GPIO_OUTPUT_HIGH,
//    .lcd_en.pin = PIN2,
//    .lcd_en.port = PORTC_INDEX,
//    ///////////////////////////////////////////////////////
//    .lcd_pins[0].direction = GPIO_DIRECTION_OUTBUT,
//    .lcd_pins[0].logic = GPIO_OUTPUT_LOW,
//    .lcd_pins[0].pin = PIN0,
//    .lcd_pins[0].port = PORTD_INDEX,
//    
//    .lcd_pins[1].direction = GPIO_DIRECTION_OUTBUT,
//    .lcd_pins[1].logic = GPIO_OUTPUT_LOW,
//    .lcd_pins[1].pin = PIN1,
//    .lcd_pins[1].port = PORTD_INDEX,
//    
//    .lcd_pins[2].direction = GPIO_DIRECTION_OUTBUT,
//    .lcd_pins[2].logic = GPIO_OUTPUT_LOW,
//    .lcd_pins[2].pin = PIN2,
//    .lcd_pins[2].port = PORTD_INDEX,
//    
//    .lcd_pins[3].direction = GPIO_DIRECTION_OUTBUT,
//    .lcd_pins[3].logic = GPIO_OUTPUT_LOW,
//    .lcd_pins[3].pin = PIN3,
//    .lcd_pins[3].port = PORTD_INDEX,
//    
//    .lcd_pins[4].direction = GPIO_DIRECTION_OUTBUT,
//    .lcd_pins[4].logic = GPIO_OUTPUT_LOW,
//    .lcd_pins[4].pin = PIN4,
//    .lcd_pins[4].port = PORTD_INDEX,
//        
//    .lcd_pins[5].direction = GPIO_DIRECTION_OUTBUT,
//    .lcd_pins[5].logic = GPIO_OUTPUT_LOW,
//    .lcd_pins[5].pin = PIN5,
//    .lcd_pins[5].port = PORTD_INDEX,
//    
//    .lcd_pins[6].direction = GPIO_DIRECTION_OUTBUT,
//    .lcd_pins[6].logic = GPIO_OUTPUT_LOW,
//    .lcd_pins[6].pin = PIN6,
//    .lcd_pins[6].port = PORTD_INDEX,
//    
//    .lcd_pins[7].direction = GPIO_DIRECTION_OUTBUT,
//    .lcd_pins[7].logic = GPIO_OUTPUT_LOW,
//    .lcd_pins[7].pin = PIN7,
//    .lcd_pins[7].port = PORTD_INDEX,
//    
//};

calculator_t calc_v1 = {
  .keypad.keypad_connection_type = KEYPAD_CONNECTION_LOW,
  
  .keypad.keypad_rows[0].port = PORTA_INDEX,
  .keypad.keypad_rows[0].pin = PIN0,
  .keypad.keypad_rows[0].direction = GPIO_DIRECTION_OUTBUT,
  .keypad.keypad_rows[0].logic = GPIO_OUTPUT_LOW,
  
  .keypad.keypad_rows[1].port = PORTA_INDEX,
  .keypad.keypad_rows[1].pin = PIN1,
  .keypad.keypad_rows[1].direction = GPIO_DIRECTION_OUTBUT,
  .keypad.keypad_rows[1].logic = GPIO_OUTPUT_LOW,
  
  .keypad.keypad_rows[2].port = PORTA_INDEX,
  .keypad.keypad_rows[2].pin = PIN2,
  .keypad.keypad_rows[2].direction = GPIO_DIRECTION_OUTBUT,
  .keypad.keypad_rows[2].logic = GPIO_OUTPUT_LOW,
  
  .keypad.keypad_rows[3].port = PORTA_INDEX,
  .keypad.keypad_rows[3].pin = PIN3,
  .keypad.keypad_rows[3].direction = GPIO_DIRECTION_OUTBUT,
  .keypad.keypad_rows[3].logic = GPIO_OUTPUT_LOW,
  
  .keypad.keypad_columns[0].port = PORTB_INDEX,
  .keypad.keypad_columns[0].pin = PIN0,
  .keypad.keypad_columns[0].direction = GPIO_DIRECTION_INPUT,
  .keypad.keypad_columns[0].logic = GPIO_OUTPUT_LOW,
  
    .keypad.keypad_columns[1].port = PORTB_INDEX,
  .keypad.keypad_columns[1].pin = PIN1,
  .keypad.keypad_columns[1].direction = GPIO_DIRECTION_INPUT,
  .keypad.keypad_columns[1].logic = GPIO_OUTPUT_LOW,
  
  .keypad.keypad_columns[2].port = PORTB_INDEX,
  .keypad.keypad_columns[2].pin = PIN2,
  .keypad.keypad_columns[2].direction = GPIO_DIRECTION_INPUT,
  .keypad.keypad_columns[2].logic = GPIO_OUTPUT_LOW,
  
  .keypad.keypad_columns[3].port = PORTB_INDEX,
  .keypad.keypad_columns[3].pin = PIN3,
  .keypad.keypad_columns[3].direction = GPIO_DIRECTION_INPUT,
  .keypad.keypad_columns[3].logic = GPIO_OUTPUT_LOW,
  //////////////////////////////////////////////////
  .lcd.lcd_rs.port = PORTC_INDEX,
  .lcd.lcd_rs.pin = PIN0,
  .lcd.lcd_rs.direction = GPIO_DIRECTION_OUTBUT,
  .lcd.lcd_rs.logic = GPIO_OUTPUT_LOW,
  
  .lcd.lcd_rw.port = PORTC_INDEX,
  .lcd.lcd_rw.pin = PIN1,
  .lcd.lcd_rw.direction = GPIO_DIRECTION_OUTBUT,
  .lcd.lcd_rw.logic = GPIO_OUTPUT_LOW,
  
  .lcd.lcd_en.port = PORTC_INDEX,
  .lcd.lcd_en.pin = PIN2,
  .lcd.lcd_en.direction = GPIO_DIRECTION_OUTBUT,
  .lcd.lcd_en.logic = GPIO_OUTPUT_LOW,
  
  .lcd.lcd_pins[0].port = PORTD_INDEX,
  .lcd.lcd_pins[0].pin = PIN0,
  .lcd.lcd_pins[0].direction = GPIO_DIRECTION_OUTBUT,
  .lcd.lcd_pins[0].logic = GPIO_OUTPUT_LOW,
  
  .lcd.lcd_pins[1].port = PORTD_INDEX,
  .lcd.lcd_pins[1].pin = PIN1,
  .lcd.lcd_pins[1].direction = GPIO_DIRECTION_OUTBUT,
  .lcd.lcd_pins[1].logic = GPIO_OUTPUT_LOW,
  
  .lcd.lcd_pins[2].port = PORTD_INDEX,
  .lcd.lcd_pins[2].pin = PIN2,
  .lcd.lcd_pins[2].direction = GPIO_DIRECTION_OUTBUT,
  .lcd.lcd_pins[2].logic = GPIO_OUTPUT_LOW,
  
  .lcd.lcd_pins[3].port = PORTD_INDEX,
  .lcd.lcd_pins[3].pin = PIN3,
  .lcd.lcd_pins[3].direction = GPIO_DIRECTION_OUTBUT,
  .lcd.lcd_pins[3].logic = GPIO_OUTPUT_LOW,
  
  .lcd.lcd_pins[4].port = PORTD_INDEX,
  .lcd.lcd_pins[4].pin = PIN4,
  .lcd.lcd_pins[4].direction = GPIO_DIRECTION_OUTBUT,
  .lcd.lcd_pins[4].logic = GPIO_OUTPUT_LOW,
  
  .lcd.lcd_pins[5].port = PORTD_INDEX,
  .lcd.lcd_pins[5].pin = PIN5,
  .lcd.lcd_pins[5].direction = GPIO_DIRECTION_OUTBUT,
  .lcd.lcd_pins[5].logic = GPIO_OUTPUT_LOW,
  
  .lcd.lcd_pins[6].port = PORTD_INDEX,
  .lcd.lcd_pins[6].pin = PIN6,
  .lcd.lcd_pins[6].direction = GPIO_DIRECTION_OUTBUT,
  .lcd.lcd_pins[6].logic = GPIO_OUTPUT_LOW,
  
  .lcd.lcd_pins[7].port = PORTD_INDEX,
  .lcd.lcd_pins[7].pin = PIN7,
  .lcd.lcd_pins[7].direction = GPIO_DIRECTION_OUTBUT,
  .lcd.lcd_pins[7].logic = GPIO_OUTPUT_LOW,
};



/*------------------------------------------------------*/
void ecu_layer_initialize (void)
{
//    program_state = lcd_4bit_initialize(&lcd_4);
//    program_state = lcd_8bit_initialize(&lcd_8);
    program_state = calculator_initialize(&calc_v1);
}

