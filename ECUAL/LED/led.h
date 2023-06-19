/*
**@file     : led.h
**@brief    : This is header file for the LED API.
**@author   : ANAS MAHMOUD
**@date     : 18 june 2023
**@version  : 0.1
*/


#ifndef LED_H_
#define LED_H_

#include "GPIO/GPIO.h"

void Led_Init(st_GPIO_config_t *ptr_st_LED_config);

void LED_GreenOn(st_GPIO_config_t *ptr_st_LED_config);

void LED_BlueOn(st_GPIO_config_t *ptr_st_LED_config);

void LED_RedOn(st_GPIO_config_t *ptr_st_LED_config);

void LED_AllOn(st_GPIO_config_t *ptr_st_LED_config);

void LED_AllOff(st_GPIO_config_t *ptr_st_LED_config);

#endif /* LED_H_ */
