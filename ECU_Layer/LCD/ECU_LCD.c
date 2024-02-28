/* 
 * File:   ECU_LCD.c
 * Author: Mayar Mahmoud; 
 *
 * Created on February 24, 2024, 8:18 PM
 */
/*---------------------------- INCLUDE --------------------------*/
#include "ECU_LCD.h"
/*------------------------ STATIC FUNCTIONS  --------------------*/
static Std_ReturnType lcd_send_4_bit(const lcd_4b_t* _lcd, uint8 _data_command);
static Std_ReturnType lcd_send_4bit_enable(const lcd_4b_t* _lcd);
static Std_ReturnType lcd_send_8bit_enable(const lcd_8b_t* _lcd);
static Std_ReturnType lcd_4bit_set_curser(const lcd_4b_t* _lcd, uint8 row, uint8 col);
static Std_ReturnType lcd_8bit_set_curser(const lcd_8b_t* _lcd, uint8 row, uint8 col);


/*---------------------- FUNCTIONS DEFINITION -------------------*/
/**
 * @brief Initialize a character LCD in 4 bit data mode
 * @param _lcd a pointer to the lcd pins configration @ref pin_config_t
 * @return Std_ReturnType indicating the progress of the functions (success or fail)
 *         E_OK for success 
 *         E_NOK for fail
 */
Std_ReturnType lcd_4bit_initialize(const lcd_4b_t* _lcd)
{
    Std_ReturnType ret = E_OK;
    uint8 counter = 0;
    if(_lcd != NULL)
    {
        ret = gpio_pin_initialize(&(_lcd->lcd_rs));
        ret = gpio_pin_initialize(&(_lcd->lcd_rw));
        ret = gpio_pin_initialize(&(_lcd->lcd_en));
        
        for(counter = 0; counter < LCD_4_BIT_MODE; counter++)
        {
            ret = gpio_pin_initialize(&(_lcd->lcd_pins[counter]));
        }
        
        __delay_ms(20);
        ret = lcd_4bit_send_command(_lcd, _LCD_8_BIT_DL_MODE|_LCD_2_LINE_DISPLAY_MODE);
        __delay_ms(5);
        ret = lcd_4bit_send_command(_lcd, _LCD_8_BIT_DL_MODE|_LCD_2_LINE_DISPLAY_MODE);
        __delay_us(150);
        ret = lcd_4bit_send_command(_lcd, _LCD_8_BIT_DL_MODE|_LCD_2_LINE_DISPLAY_MODE);
                
        ret = lcd_4bit_send_command(_lcd, _LCD_CLEAR_SCREEN);
        __delay_ms(2);
        ret = lcd_4bit_send_command(_lcd, _LCD_CURSER_HOME);
        __delay_ms(2);
        ret = lcd_4bit_send_command(_lcd, _LCD_DISPLAY_ON|_LCD_UNDERLINE_CURSER_OFF|_LCD_BLINKING_CURSER_OFF);
        __delay_us(19);
        ret = lcd_4bit_send_command(_lcd, _LCD_ENTRY_MODE_INC_SHIFT_OFF);
        __delay_us(39);
        ret = lcd_4bit_send_command(_lcd, _LCD_4_BIT_DL_MODE|_LCD_2_LINE_DISPLAY_MODE|_LCD_11_DOTS_FORMAT);
        ret = lcd_4bit_set_curser(_lcd,1,1);
    }
    else
    {
        ret = E_NOK;
    }
    return ret;
}
/////////////////////////////////////////////////////////////////////////



/**
 * @brief Functions to send instructions in 4 bit mode
 * @param _lcd a pointer to the lcd pins configration @ref pin_config_t
 * @param _command the command @ref datasheet + macros in ECU_LCD.h
 * @return Std_ReturnType indicating the progress of the functions (success or fail)
 *         E_OK for success 
 *         E_NOK for fail
 */
Std_ReturnType lcd_4bit_send_command(const lcd_4b_t* _lcd, uint8 _command)
{
    Std_ReturnType ret = E_OK;
        
    if(_lcd != NULL)
    {
        ret = gpio_pin_write_logic(&(_lcd->lcd_rs),GPIO_OUTPUT_LOW);
        ret = lcd_send_4_bit(_lcd,(uint8)(_command >> 4));
        ret = lcd_send_4bit_enable(_lcd);
        ret = lcd_send_4_bit(_lcd,_command);
        ret = lcd_send_4bit_enable(_lcd);
    }
    else
    {
        ret = E_NOK;
    }
    return ret;
}
/////////////////////////////////////////////////////////////////////////



/**
 * @brief Send data in 4 bit mode
 * @param _lcd a pointer to the lcd pins configration @ref pin_config_t
 * @param _data the ascii code to the characters 
 * @return Std_ReturnType indicating the progress of the functions (success or fail)
 *         E_OK for success 
 *         E_NOK for fail
 */
Std_ReturnType lcd_4bit_send_data(const lcd_4b_t* _lcd, uint8 _data)
{
    Std_ReturnType ret = E_OK;
    if(_lcd != NULL)
    {
        ret = gpio_pin_write_logic(&(_lcd->lcd_rs),GPIO_OUTPUT_HIGH);
        ret = lcd_send_4_bit(_lcd,(_data >> 4));
        ret = lcd_send_4bit_enable(_lcd);
        ret = lcd_send_4_bit(_lcd,_data);
        ret = lcd_send_4bit_enable(_lcd);
    }
    else
    {
        ret = E_NOK;
    }
    return ret;
}
/////////////////////////////////////////////////////////////////////////



/**
 * @brief To start writnig data at an exact position one character
 * @param _lcd a pointer to the lcd pins configration @ref pin_config_t
 * @param _row at which row
 * @param _col at which columne
 * @param _data the ascii code to the characters 
 * @return Std_ReturnType indicating the progress of the functions (success or fail)
 *         E_OK for success 
 *         E_NOK for fail
 */
Std_ReturnType lcd_4bit_send_data_pos(const lcd_4b_t* _lcd, uint8 _row, uint8 _col, uint8 _data)
{
    Std_ReturnType ret = E_OK;
    if(_lcd != NULL)
    {
        ret = lcd_4bit_set_curser(_lcd,_row,_col);
        ret = lcd_4bit_send_data(_lcd,_data);
    }
    else
    {
        ret = E_NOK;
    }
    return ret;
}
/////////////////////////////////////////////////////////////////////////



/**
 * @brife to write a string at once
 * @param _lcd a pointer to the lcd pins configration @ref pin_config_t
 * @param _str a pointer to the string
 * @return Std_ReturnType indicating the progress of the functions (success or fail)
 *         E_OK for success 
 *         E_NOK for fail 
 */
Std_ReturnType lcd_4bit_send_string(const lcd_4b_t* _lcd, uint8 *_str)
{
    Std_ReturnType ret = E_OK;
    uint8 counter = 0;
    if(_lcd != NULL)
    {
        while(_str[counter]!='\0')
        {
            ret = lcd_4bit_send_data(_lcd, _str[counter]);
            counter++;
        }
    }
    else
    {
        ret = E_NOK;
    }
    return ret;
}
/////////////////////////////////////////////////////////////////////////



/**
 * @brief write a string at an exact position in 4-bit mode
 * @param _lcd a pointer to the lcd pins configration @ref pin_config_t
 * @param _row number or row
 * @param _col number of coulmne
 * @param _str a pointer to the string
 * @return Std_ReturnType indicating the progress of the functions (success or fail)
 *         E_OK for success 
 *         E_NOK for fail
 */
Std_ReturnType lcd_4bit_send_string_pos(const lcd_4b_t* _lcd, uint8 _row, uint8 _col, uint8 *_str)
{
    Std_ReturnType ret = E_OK;
    if(_lcd != NULL)
    {
        ret = lcd_4bit_set_curser(_lcd,_row,_col);
        ret = lcd_4bit_send_string(_lcd,_str);
    }
    else
    {
        ret = E_NOK;
    }
    return ret;
}
/////////////////////////////////////////////////////////////////////////



/**
 * @brief Write a custom character into CGRAM and display it 
 * @param _lcd a pointer to the lcd pins configration @ref pin_config_t
 * @param _row number or row
 * @param _col number of coulmne
 * @param _data an array holding the character-map
 * @param mem_pos which memory position of the CGRAM
 * @return Std_ReturnType indicating the progress of the functions (success or fail)
 *         E_OK for success 
 *         E_NOK for fail
 */
Std_ReturnType lcd_4bit_send_custome_char(const lcd_4b_t* _lcd, uint8 _row, uint8 _col, 
                                          const uint8 _data[], uint8 mem_pos)
{
    Std_ReturnType ret = E_OK;
    uint8 counter = 0;
    
    if((_lcd != NULL) && ((mem_pos > 0) && (mem_pos < 9)))
    {
        mem_pos--;
        ret = lcd_4bit_send_command(_lcd,(_LCD_CGRAM_SET_ADDRESS + ((mem_pos*8))));
        for(counter = 0; counter < 8 ; counter++) 
        {
            ret = lcd_4bit_send_data(_lcd,_data[counter]);
        }
        ret = lcd_4bit_set_curser(_lcd,_row,_col);
        ret = lcd_4bit_send_data(_lcd,mem_pos);
        
    }
    else
    {
        ret = E_NOK;
    }
    return ret;
}
/////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////
/**
 * @brief Initialize a character LCD in 8-bit data mode
 * @param _lcd a pointer to the lcd pins configration @ref pin_config_t
 * @return Std_ReturnType indicating the progress of the functions (success or fail)
 *         E_OK for success 
 *         E_NOK for fail
 */
Std_ReturnType lcd_8bit_initialize(const lcd_8b_t* _lcd)
{
    Std_ReturnType ret = E_OK;
    uint8 counter = 0;
    if(_lcd != NULL)
    {
        ret = gpio_pin_initialize(&(_lcd->lcd_rs));
        ret = gpio_pin_initialize(&(_lcd->lcd_rw));
        ret = gpio_pin_initialize(&(_lcd->lcd_en));
        
        for(counter = 0; counter < LCD_8_BIT_MODE; counter++)
        {
            ret = gpio_pin_initialize(&(_lcd->lcd_pins[counter]));
        }
        
        __delay_ms(20);
        ret = lcd_8bit_send_command(_lcd, _LCD_8_BIT_DL_MODE|_LCD_2_LINE_DISPLAY_MODE);
        __delay_ms(5);
        ret = lcd_8bit_send_command(_lcd, _LCD_8_BIT_DL_MODE|_LCD_2_LINE_DISPLAY_MODE);
        __delay_us(150);
        ret = lcd_8bit_send_command(_lcd, _LCD_8_BIT_DL_MODE|_LCD_2_LINE_DISPLAY_MODE);
                
        ret = lcd_8bit_send_command(_lcd, _LCD_CLEAR_SCREEN);
        __delay_ms(2);
        ret = lcd_8bit_send_command(_lcd, _LCD_CURSER_HOME);
        __delay_ms(2);
        ret = lcd_8bit_send_command(_lcd, _LCD_DISPLAY_ON|_LCD_UNDERLINE_CURSER_OFF|_LCD_BLINKING_CURSER_ON);
        __delay_us(19);
        ret = lcd_8bit_send_command(_lcd, _LCD_ENTRY_MODE_INC_SHIFT_OFF);
        __delay_us(39);
        ret = lcd_8bit_send_command(_lcd, _LCD_8_BIT_DL_MODE|_LCD_2_LINE_DISPLAY_MODE|_LCD_8_DOTS_FORMAT);
    }
    else
    {
        ret = E_NOK;
    }
    return ret;
}
/////////////////////////////////////////////////////////////////////////



/**
 * @brief send commands in 8 bit mode
 * @param _lcd a pointer to the lcd pins configration @ref pin_config_t
 * @param _command the command @ref datasheet + macros in ECU_LCD.h
 * @return Std_ReturnType indicating the progress of the functions (success or fail)
 *         E_OK for success 
 *         E_NOK for fail
 */
Std_ReturnType lcd_8bit_send_command(const lcd_8b_t* _lcd, uint8 _command)
{
    Std_ReturnType ret = E_OK;
    uint8 counter = 0;
    
    if(_lcd != NULL)
    {
        ret = gpio_pin_write_logic(&(_lcd->lcd_rs),GPIO_OUTPUT_LOW);
        for(counter = 0; counter < LCD_8_BIT_MODE; counter++)
        {
            ret = gpio_pin_write_logic(&(_lcd->lcd_pins[counter]),(logic_t)((_command >> counter) & 1));
        }
        
        ret = lcd_send_8bit_enable(_lcd);
    }
    else
    {
        ret = E_NOK;
    }
    return ret;
}
/////////////////////////////////////////////////////////////////////////



/**
 * @brief send data in 8 bit mode
 * @param _lcd a pointer to the lcd pins configration @ref pin_config_t
 * @param _data the data (a character) 
 * @return Std_ReturnType indicating the progress of the functions (success or fail)
 *         E_OK for success 
 *         E_NOK for fail
 */
Std_ReturnType lcd_8bit_send_data(const lcd_8b_t* _lcd, uint8 _data)
{
    Std_ReturnType ret = E_OK;
    uint8 counter = 0;
    if(_lcd != NULL)
    {
        ret = gpio_pin_write_logic(&(_lcd->lcd_rs),GPIO_OUTPUT_HIGH);
        for(counter = 0; counter < LCD_8_BIT_MODE; counter++)
        {
            ret = gpio_pin_write_logic(&(_lcd->lcd_pins[counter]),(logic_t)((_data >> counter) & 1));
        }
        ret = lcd_send_8bit_enable(_lcd);
    }
    else
    {
        ret = E_NOK;
    }
    return ret;
}
/////////////////////////////////////////////////////////////////////////



/**
 * @brief write one character at an exact position
 * @param _lcd a pointer to the lcd pins configration @ref pin_config_t
 * @param _row number or row
 * @param _col number of coulmne
 * @param _data the character
 * @return Std_ReturnType indicating the progress of the functions (success or fail)
 *         E_OK for success 
 *         E_NOK for fail
 */
Std_ReturnType lcd_8bit_send_data_pos(const lcd_8b_t* _lcd, uint8 _row, uint8 _col, uint8 _data)
{
    Std_ReturnType ret = E_OK;
    if(_lcd != NULL)
    {
        ret = lcd_8bit_set_curser(_lcd,_row,_col);
        ret = lcd_8bit_send_data(_lcd,_data);
    }
    else
    {
        ret = E_NOK;
    }
    return ret;
}
/////////////////////////////////////////////////////////////////////////



/**
 * @brief write a string at once
 * @param _lcd a pointer to the lcd pins configration @ref pin_config_t
 * @param _str a pointer to the string
 * @return Std_ReturnType indicating the progress of the functions (success or fail)
 *         E_OK for success 
 *         E_NOK for fail
 */
Std_ReturnType lcd_8bit_send_string(const lcd_8b_t* _lcd, uint8 *_str)
{
    Std_ReturnType ret = E_OK;
    uint8 counter = 0;
    if(_lcd != NULL)
    {
        while(_str[counter]!='\0')
        {
            ret = lcd_8bit_send_data(_lcd, _str[counter]);
            counter++;
        }
    }
    else
    {
        ret = E_NOK;
    }
    return ret;
}
/////////////////////////////////////////////////////////////////////////



/**
 * @brief write a string at once at an exact position
 * @param _lcd a pointer to the lcd pins configration @ref pin_config_t
 * @param _row number or row
 * @param _col number of coulmne
 * @param _str a pointer to the string
 * @return Std_ReturnType indicating the progress of the functions (success or fail)
 *         E_OK for success 
 *         E_NOK for fail
 */
Std_ReturnType lcd_8bit_send_string_pos(const lcd_8b_t* _lcd, uint8 _row, uint8 _col, uint8 *_str)
{
    Std_ReturnType ret = E_OK;
    if(_lcd != NULL)
    {
        ret = lcd_8bit_set_curser(_lcd,_row,_col);
        ret = lcd_8bit_send_string(_lcd,_str);
    }
    else
    {
        ret = E_NOK;
    }
    return ret;
}
/////////////////////////////////////////////////////////////////////////


/**
 * @brief Write a custom character into CGRAM and display it 
 * @param _lcd a pointer to the lcd pins configration @ref pin_config_t
 * @param _row number or row
 * @param _col number of coulmne
 * @param _data an array holding the character-map
 * @param mem_pos which memory position of the CGRAM
 * @return Std_ReturnType indicating the progress of the functions (success or fail)
 *         E_OK for success 
 *         E_NOK for fail
 */
Std_ReturnType lcd_8bit_send_custome_char(const lcd_8b_t* _lcd, uint8 _row, uint8 _col, 
                                          const uint8 _data[], uint8 mem_pos)
{
    Std_ReturnType ret = E_OK;
    uint8 counter = 0;
    mem_pos--;
    if((_lcd != NULL) && ((mem_pos > 0) && (mem_pos < 9)))
    {
        
        ret = lcd_8bit_send_command(_lcd,(_LCD_CGRAM_SET_ADDRESS + ((mem_pos*8))));
        for(counter = 0; counter < LCD_8_BIT_MODE ; counter++) 
        {
            ret = lcd_8bit_send_data(_lcd,_data[counter]);
        }
        ret = lcd_8bit_set_curser(_lcd,_row,_col);
        ret = lcd_8bit_send_data(_lcd,mem_pos);
        
    }
    else
    {
        ret = E_NOK;
    }
    return ret;
}
/////////////////////////////////////////////////////////////////////////


/**
 * 
 * @param value
 * @param str
 */
void convert_byte_to_string(uint8 value, uint8 *str)
{
    str = memset(str,'\0',4);
    for (int i=3; i>0; i--)
    {
        str[i-1] = ((value%10) + '0');
        value /= 10;
    }
}
/////////////////////////////////////////////////////////////////////////

/**
 * 
 * @param value
 * @param str
 */
void convert_short_to_string(uint16 value, uint8 *str)
{
    str = memset(str,'\0',6);
    for (int i=5; i>0; i--)
    {
        str[i-1] = ((value%10) + '0');
        value /= 10;
    }
}
/////////////////////////////////////////////////////////////////////////


/**
 * 
 * @param value
 * @param str
 */
void convert_int_to_string(uint32 value, uint8 *str)
{
    str = memset(str,'\0',11);
    for (int i=10; i>0; i--)
    {
        str[i-1] = ((value%10) + '0');
        value /= 10;
    }
}
/////////////////////////////////////////////////////////////////////////
#ifdef LCD_READ_WRITE

Std_ReturnType lcd_read_busy_flag_address_counter()
{}
Std_ReturnType lcd_read_data()
{}
#endif



/**
 * @brief devide a 8-bit data/command int 4-bit * 2
 * @param _lcd a pointer to the lcd pins configration @ref pin_config_t
 * @param _data_command the data/command to devide
 * @return Std_ReturnType indicating the progress of the functions (success or fail)
 *         E_OK for success 
 *         E_NOK for fail
 */
static Std_ReturnType lcd_send_4_bit(const lcd_4b_t* _lcd, uint8 _data_command)
{
    Std_ReturnType ret = E_OK;
    if(_lcd != NULL)
    {
        ret = gpio_pin_write_logic(&(_lcd->lcd_pins[0]),((_data_command >> 0) & (uint8)0x01));
        ret &= gpio_pin_write_logic(&(_lcd->lcd_pins[1]),((_data_command >> 1) & (uint8)0x01));
        ret &= gpio_pin_write_logic(&(_lcd->lcd_pins[2]),((_data_command >> 2) & (uint8)0x01));
        ret &= gpio_pin_write_logic(&(_lcd->lcd_pins[3]),((_data_command >> 3) & (uint8)0x01));
    }
    else
    {
        ret = E_NOK;
    }
    return ret;
}
/////////////////////////////////////////////////////////////////////////


/**
 * @brief assert the enable signal in 4-bit mode
 * @param _lcd a pointer to the LCD pins configration @ref pin_config_t
 * @return Std_ReturnType indicating the progress of the functions (success or fail)
 *         E_OK for success 
 *         E_NOK for fail
 */
static Std_ReturnType lcd_send_4bit_enable(const lcd_4b_t* _lcd)
{
    Std_ReturnType ret = E_OK;
    if(_lcd != NULL)
    {
        ret = gpio_pin_write_logic(&(_lcd->lcd_en),GPIO_OUTPUT_HIGH);
        __delay_us(2);
        ret = gpio_pin_write_logic(&(_lcd->lcd_en),GPIO_OUTPUT_LOW);
    }
    else
    {
        ret = E_NOK;
    }
    return ret;
}
/////////////////////////////////////////////////////////////////////////



/**
 * @brief assert the enable signal
 * @param _lcd a pointer to the LCD pins configration @ref pin_config_t
 * @return Std_ReturnType indicating the progress of the functions (success or fail)
 *         E_OK for success 
 *         E_NOK for fail
 */
static Std_ReturnType lcd_send_8bit_enable(const lcd_8b_t* _lcd)
{
    Std_ReturnType ret = E_OK;
    if(_lcd != NULL)
    {
        ret = gpio_pin_write_logic(&(_lcd->lcd_en),GPIO_OUTPUT_HIGH);
        __delay_us(2);
        ret = gpio_pin_write_logic(&(_lcd->lcd_en),GPIO_OUTPUT_LOW);
    }
    else
    {
        ret = E_NOK;
    }
    return ret;
}
/////////////////////////////////////////////////////////////////////////


/**
 * @brief Set the curser to an exact position on the screen
 * @param _lcd a pointer to the lcd pins configration @ref pin_config_t
 * @param row number or row
 * @param col number of coulmne
 * @return Std_ReturnType indicating the progress of the functions (success or fail)
 *         E_OK for success 
 *         E_NOK for fail
 */
static Std_ReturnType lcd_4bit_set_curser(const lcd_4b_t* _lcd, uint8 row, uint8 col)
{
    Std_ReturnType ret = E_OK;
    if(_lcd != NULL)
    {
        col--;
        switch(row)
        {
            case ROW1:
                ret = lcd_4bit_send_command(_lcd,(0x80 + col));
                break;
            case ROW2:
                ret = lcd_4bit_send_command(_lcd,(0xC0 + col));
                break;
            case ROW3:
                ret = lcd_4bit_send_command(_lcd,(0x94 + col));
                break;
            case ROW4:
                ret = lcd_4bit_send_command(_lcd,(0xD4 + col));
                break;
        }
    }
    else
    {
        ret = E_NOK;
    }
    return ret;
}
/////////////////////////////////////////////////////////////////////////



/**
 * @brief Set the curser to an exact position on the screen in 8-bit mode
 * @param _lcd a pointer to the LCD pins configration @ref pin_config_t
 * @param row number or row
 * @param col number of coulmne
 * @return Std_ReturnType indicating the progress of the functions (success or fail)
 *         E_OK for success 
 *         E_NOK for fail
 */
static Std_ReturnType lcd_8bit_set_curser(const lcd_8b_t* _lcd, uint8 row, uint8 col)
{
    Std_ReturnType ret = E_OK;
    if(_lcd != NULL)
    {
        col--;
        switch(row)
        {
            case ROW1:
                ret = lcd_8bit_send_command(_lcd,(0x80 + col));
                break;
            case ROW2:
                ret = lcd_8bit_send_command(_lcd,(0xC0 + col));
                break;
            case ROW3:
                ret = lcd_8bit_send_command(_lcd,(0x94 + col));
                break;
            case ROW4:
                ret = lcd_8bit_send_command(_lcd,(0xD4 + col));
                break;
            default:
                ret = E_NOK;
                break;
        }
    }
    else
    {
        ret = E_NOK;
    }
    return ret;
}