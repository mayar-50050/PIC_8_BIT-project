/* 
 * File:   HAL_GPIO_cfg.h
 * Author: Mayar Mahmoud; 
 *
 * Created on February 5, 2024, 3:55 AM
 */

#ifndef HAL_GPIO_CFG_H
#define	HAL_GPIO_CFG_H

#define CONFIG_ENABLE   0x01
#define CONFIG_DISABLE  0x00

#define GPIO_PORT_PIN_CONFIG             CONFIG_ENABLE
#define GPIO_PORT_CONFIG                 CONFIG_ENABLE


#define PIN_NAME                         0x01
#if (PIN_NAME)
#define PIN0                             GPIO_PIN0
#define PIN1                             GPIO_PIN1
#define PIN2                             GPIO_PIN2
#define PIN3                             GPIO_PIN3
#define PIN4                             GPIO_PIN4
#define PIN5                             GPIO_PIN5
#define PIN6                             GPIO_PIN6
#define PIN7                             GPIO_PIN7

#define GPIO_HIGH                        GPIO_OUTPUT_HIGH
#define GPIO_LOW                         GPIO_OUTPUT_LOW
#endif


#endif	/* HAL_GPIO_CFG_H */

