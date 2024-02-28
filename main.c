/* 
 * File:   main.c
 * Author: Mayar Mahmoud; 
 *
 * Created on January 27, 2024, 9:03 PM
 */
/*---------------------------- INCLUDE --------------------------*/
#include "main.h"
/*---------------------------------------------------------------*/

uint8 cc1[] = {14,10,17,17,17,17,31,0};
uint8 cc2[] = {14,10,17,17,31,31,31,0};
uint8 hh1[] = {6,9,16,16,8,4,2,1};
uint8 hh2[] = {12,18,1,1,2,4,8,16};
//uint8 h1[] = {31,31,27,17,0,17,27,31};
uint8 value;

int main(void) 
{
    ecu_layer_initialize();
    
    
    
    while(1)
    {  
        calculator_get_key(&calc_v1,&value);
        __delay_ms(450);
    }
    return (EXIT_SUCCESS);
}
