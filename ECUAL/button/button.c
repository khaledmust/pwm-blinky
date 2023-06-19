/*
**@file     : button.h
**@brief    : This is source file for the push button API.
**@author   : ANAS MAHMOUD
**@date     : 18 june 2023
**@version  : 0.1
*/

#include "button.h"

void BUTTON_Init(st_GPIO_config_t *usr_buttonConfig)
{
    uint8 pinCounter = 0;
    for (pinCounter = 0; pinCounter < PUSH_BUTTON_NUM; pinCounter++) {
        GPIO_Init(&usr_buttonConfig[pinCounter]);
    }
}

void BUTTON_IsPressed(st_GPIO_config_t *usr_buttonConfig, en_button_state_t *buttonState)
{
    uint8 tmpValue = 0;
    GPIO_ReadPin(usr_buttonConfig, &tmpValue);
    
    if (tmpValue == HIGH) {
        *buttonState = BUTTON_NotPressed;
    } else {
        *buttonState = BUTTON_Pressed;
    }
} 

