/*
**@file     : led_config.h
**@brief    : This is source file for configuration of the button.
**@author   : ANAS MAHMOUD
**@date     : 18 june 2023
**@version  : 0.1
*/

#include "button_config.h"

/* User configuration array. */
st_GPIO_config_t usr_button_config [PUSH_BUTTON_NUM] = {
    {PORT_F , PIN4 , INPUT , DRIVE_4mA , PULL_UP, INTERRUPT_ENABLE, EDGE_DETECTION, FALLING_EDGE}
};

