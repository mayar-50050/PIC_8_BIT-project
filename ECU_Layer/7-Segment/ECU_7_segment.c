/* 
 * File:   ECU_7_segment.c
 * Author: Mayar Mahmoud; 
 *
 * Created on February 12, 2024, 2:23 PM
 */
/*---------------------------- INCLUDE --------------------------*/
#include "ECU_7_segment.h"
/*------------------------ STATIC FUNCTIONS  --------------------*/

/*---------------------- FUNCTIONS DEFINITION -------------------*/
Std_ReturnType seven_segment_initialize (const seven_segment_t *_7_segment)
{
    Std_ReturnType ret = E_OK;
    if(_7_segment != NULL)
    {
        ret = gpio_port_direction_initialize(_7_segment->port,PORT_FULL_OUTPUT);
        switch(_7_segment->connection_type)
        {
                case SEVEN_SEGMENT_CA:
                    ret = seven_segment_write (_7_segment,0x00);
                    break;
                case SEVEN_SEGMENT_CC:
                    ret = seven_segment_write (_7_segment,0xFF);
                    break;                  
        }      
    }
    else
    {
        ret = E_NOK;
    }
    return ret;
}
Std_ReturnType seven_segment_write (const seven_segment_t *_7_segment, uint8 _value)
{
    Std_ReturnType ret = E_OK;
    if(_7_segment != NULL)
    {
        if(_7_segment->connection_type == SEVEN_SEGMENT_CC)
        {
            switch(_value)
            {
                case NO_ZERO:
                    ret = gpio_port_write_logic(_7_segment->port,SEVEN_SEGMENT_CC_VALUES[NO_ZERO]);
                    break;
                case NO_ONE:
                    ret = gpio_port_write_logic(_7_segment->port,SEVEN_SEGMENT_CC_VALUES[NO_ONE]);
                    break;
                case NO_TWO:
                    ret = gpio_port_write_logic(_7_segment->port,SEVEN_SEGMENT_CC_VALUES[NO_TWO]);
                    break;
                case NO_THREE:
                    ret = gpio_port_write_logic(_7_segment->port,SEVEN_SEGMENT_CC_VALUES[NO_THREE]);
                    break;
                case NO_FOUR:
                    ret = gpio_port_write_logic(_7_segment->port,SEVEN_SEGMENT_CC_VALUES[NO_FOUR]);
                    break;
                case NO_FIVE:
                    ret = gpio_port_write_logic(_7_segment->port,SEVEN_SEGMENT_CC_VALUES[NO_FIVE]);
                    break;
                case NO_SIX:
                    ret = gpio_port_write_logic(_7_segment->port,SEVEN_SEGMENT_CC_VALUES[NO_SIX]);
                    break;
                case NO_SEVEN:
                    ret = gpio_port_write_logic(_7_segment->port,SEVEN_SEGMENT_CC_VALUES[NO_SEVEN]);
                    break;
                case NO_EIGHT:
                    ret = gpio_port_write_logic(_7_segment->port,SEVEN_SEGMENT_CC_VALUES[NO_EIGHT]);
                    break;    
                case NO_NINE:
                    ret = gpio_port_write_logic(_7_segment->port,SEVEN_SEGMENT_CC_VALUES[NO_NINE]);
                    break;    
                default :
                    ret = gpio_port_write_logic(_7_segment->port,0x00);
                    break;
                            
            }
        }
        else
        {
            switch(_value)
            {
                case NO_ZERO:
                    ret = gpio_port_write_logic(_7_segment->port,SEVEN_SEGMENT_CA_VALUES[NO_ZERO]);
                    break;
                case NO_ONE:
                    ret = gpio_port_write_logic(_7_segment->port,SEVEN_SEGMENT_CA_VALUES[NO_ONE]);
                    break;
                case NO_TWO:
                    ret = gpio_port_write_logic(_7_segment->port,SEVEN_SEGMENT_CA_VALUES[NO_TWO]);
                    break;
                case NO_THREE:
                    ret = gpio_port_write_logic(_7_segment->port,SEVEN_SEGMENT_CA_VALUES[NO_THREE]);
                    break;
                case NO_FOUR:
                    ret = gpio_port_write_logic(_7_segment->port,SEVEN_SEGMENT_CA_VALUES[NO_FOUR]);
                    break;
                case NO_FIVE:
                    ret = gpio_port_write_logic(_7_segment->port,SEVEN_SEGMENT_CA_VALUES[NO_FIVE]);
                    break;
                case NO_SIX:
                    ret = gpio_port_write_logic(_7_segment->port,SEVEN_SEGMENT_CA_VALUES[NO_SIX]);
                    break;
                case NO_SEVEN:
                    ret = gpio_port_write_logic(_7_segment->port,SEVEN_SEGMENT_CA_VALUES[NO_SEVEN]);
                    break;
                case NO_EIGHT:
                    ret = gpio_port_write_logic(_7_segment->port,SEVEN_SEGMENT_CA_VALUES[NO_EIGHT]);
                    break;    
                case NO_NINE:
                    ret = gpio_port_write_logic(_7_segment->port,SEVEN_SEGMENT_CA_VALUES[NO_NINE]);
                    break;    
                default :
                    ret = gpio_port_write_logic(_7_segment->port,0xFF);
                    break;           
            }
        }
    }
    else
    {
        ret = E_NOK;
    }
    return ret;
}