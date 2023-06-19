/*
**@file     : button_config.h
**@brief    : This is header file for configuration of the LED.
**@author   : ANAS MAHMOUD
**@date     : 18 june 2023
**@version  : 0.1
*/

#ifndef BUTTON_CONFIG_H_
#define BUTTON_CONFIG_H_

#include "GPIO/GPIO.h"
#include "button.h"

#define PUSH_BUTTON_NUM 1

extern st_GPIO_config_t usr_button_config [PUSH_BUTTON_NUM];

#endif /* BUTTON_CONFIG_H_ */
