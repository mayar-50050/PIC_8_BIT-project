/* 
 * File:   ECU_LCD.h
 * Author: Mayar Mahmoud; 
 *
 * Created on February 24, 2024, 8:18 PM
 */

#ifndef ECU_LCD_H
#define	ECU_LCD_H
/*---------------------------- INCLUDE --------------------------*/
#include "../../MCAL_Layer/GPIO/HAL_GPIO.h"
#include "ECU_LCD_cfg.h"
/*----------------------------- MACROS --------------------------*/
#define LCD_4_BIT_MODE                      0x04U
#define LCD_8_BIT_MODE                      0x08U

#define LCD_RS_INSTRUCTION                  0x00
#define LCD_RS_DATA                         0x01

#define ROW1                                1
#define ROW2                                2
#define ROW3                                3
#define ROW4                                4


/*CLEAR SCREEN COMMAND*/
#define _LCD_CLEAR_SCREEN                   0x01

/*SEND CURSER HOME COMMAND*/
#define _LCD_CURSER_HOME                    0x02

/*ENTRY MODE SET COMMANDS*/
/*DO-NOT OR*/
#define _LCD_ENTRY_MODE_DEC_SHIFT_OFF       0x04
#define _LCD_ENTRY_MODE_DEC_SHIFT_ON        0x05
#define _LCD_ENTRY_MODE_INC_SHIFT_OFF       0x06
#define _LCD_ENTRY_MODE_INC_SHIFT_ON        0x07

/*DISPLAY ON/OFF CONTROL*/
/*UNDRLINE CURSER CONTROL*/
/*BLINKING CURSER CONTROL*/
#define _LCD_DISPLAY_ON                     0x0C
#define _LCD_DISPLAY_OFF                    0x08
#define _LCD_UNDERLINE_CURSER_ON            0x0A
#define _LCD_UNDERLINE_CURSER_OFF           0x08
#define _LCD_BLINKING_CURSER_ON             0x09
#define _LCD_BLINKING_CURSER_OFF            0x08

/*CURSER OR DISPLAY SHIFT*/
#define _LCD_CURSER_MOVE_SHIFT_LEFT         0x10
#define _LCD_CURSER_MOVE_SHIFT_RIGHT        0x14
#define _LCD_DISPLAY_SHIFT_LEFT             0x18
#define _LCD_DISPLAY_SHIFT_RIGHT            0X1C

/*FUNCTION SET*/
/*DATA LENGTH MODE*/
/*NUMBER OF LINES MODE*/
/*NUMBER OF DOT MATRIX MODE*/
#define _LCD_8_BIT_DL_MODE                  0x30
#define _LCD_4_BIT_DL_MODE                  0x20
#define _LCD_1_LINE_DISPLAY_MODE            0x20
#define _LCD_2_LINE_DISPLAY_MODE            0x28
#define _LCD_8_DOTS_FORMAT                  0x20
#define _LCD_11_DOTS_FORMAT                 0x24

/*SET CGRAM ADDRESS*/
#define _LCD_CGRAM_SET_ADDRESS              0x40

/*SET DDRAM ADDRESS*/
#define _LCD_DDRAM_SET_ADDRESS              0x80

/*-------------------- SELF-DEFINED DATATYPES -------------------*/
typedef struct
{
    pin_config_t lcd_rs;
    pin_config_t lcd_en;
    pin_config_t lcd_rw;
    pin_config_t lcd_pins[LCD_4_BIT_MODE];
    
}lcd_4b_t;


typedef struct
{
    pin_config_t lcd_rs;
    pin_config_t lcd_en;
    pin_config_t lcd_rw;
    pin_config_t lcd_pins[LCD_8_BIT_MODE];
    
}lcd_8b_t;

/*-------------------------- PROTOTYPES -------------------------*/
Std_ReturnType lcd_4bit_initialize(const lcd_4b_t* _lcd);
Std_ReturnType lcd_4bit_send_command(const lcd_4b_t* _lcd, uint8 _command);
Std_ReturnType lcd_4bit_send_data(const lcd_4b_t* _lcd, uint8 _data);
Std_ReturnType lcd_4bit_send_data_pos(const lcd_4b_t* _lcd, uint8 _row, uint8 _col, uint8 _data);
Std_ReturnType lcd_4bit_send_string(const lcd_4b_t* _lcd, uint8 *_str);
Std_ReturnType lcd_4bit_send_string_pos(const lcd_4b_t* _lcd, uint8 _row, uint8 _col, uint8 *_str);
Std_ReturnType lcd_4bit_send_custome_char(const lcd_4b_t* _lcd, uint8 _row, uint8 _col, 
                                          const uint8 _data[], uint8 mem_pos);

Std_ReturnType lcd_8bit_initialize(const lcd_8b_t* _lcd);
Std_ReturnType lcd_8bit_send_command(const lcd_8b_t* _lcd, uint8 _command);
Std_ReturnType lcd_8bit_send_data(const lcd_8b_t* _lcd, uint8 _data);
Std_ReturnType lcd_8bit_send_data_pos(const lcd_8b_t* _lcd, uint8 _row, uint8 _col, uint8 _data);
Std_ReturnType lcd_8bit_send_string(const lcd_8b_t* _lcd, uint8 *_str);
Std_ReturnType lcd_8bit_send_string_pos(const lcd_8b_t* _lcd, uint8 _row, uint8 _col, uint8 *_str);
Std_ReturnType lcd_8bit_send_custome_char(const lcd_8b_t* _lcd, uint8 _row, uint8 _col, 
                                          const uint8 _data[], uint8 mem_pos);

void convert_byte_to_string(uint8 value, uint8 *str);
void convert_short_to_string(uint16 value, uint8 *str);
void convert_int_to_string(uint32 value, uint8 *str);

#ifdef LCD_READ_WRITE
Std_ReturnType lcd_read_busy_flag_address_counter();
Std_ReturnType lcd_read_data();
#endif



#endif	/* ECU_LCD_H */

