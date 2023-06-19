/*
**@file     : led_config.h
**@brief    : This is header file for configuration of the LED.
**@author   : ANAS MAHMOUD
**@date     : 18 june 2023
**@version  : 0.1
*/

#ifndef LED_CONFIG_H_
#define LED_CONFIG_H_

#include "GPIO/GPIO.h"

#define PORT_PINS_NUM 3
extern st_GPIO_config_t usr_led_config [PORT_PINS_NUM];

#endif /* LED_CONFIG_H_ */
