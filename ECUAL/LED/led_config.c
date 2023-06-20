/*
**@file     : led_config.c
**@brief    : This is source file for the configuration of the LED.
**@author   : ANAS MAHMOUD
**@date     : 18 june 2023
**@version  : 0.1
*/

#include "led_config.h"

/* User configuration array. */
st_GPIO_config_t usr_led_config [PORT_PINS_NUM] = {
    {PORT_F, PIN1, OUTPUT,DRIVE_2mA, PULL_DOWN},   /* Red Led */ 
    {PORT_F, PIN2, OUTPUT,DRIVE_4mA, PULL_DOWN},   /* Blue Led */
    {PORT_F, PIN3, OUTPUT,DRIVE_8mA, PULL_DOWN}   /* Geen Led */
};

