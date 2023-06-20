/*
**@file     : button.h
**@brief    : This is source file for the push button API.
**@author   : ANAS MAHMOUD
**@date     : 18 june 2023
**@version  : 0.1
*/

#include "button.h"
static uint16 debounceCount = 0;

static void BUTTON_Debounce(st_GPIO_config_t *usr_buttonConfig, en_button_state_t *buttonState) {
    en_button_state_t currentState = 0;
    en_button_state_t previousState = 0;
    
    uint8 tmpValue = 0;
    
    GPIO_ReadPin(usr_buttonConfig, &tmpValue);
    
    if (tmpValue == HIGH) {
        currentState = BUTTON_NotPressed;
    } else {
        currentState = BUTTON_Pressed;
    }
    
    if (currentState != previousState) {
        debounceCount++;
    } else {
        debounceCount = 0;
    }
    
    if (debounceCount >= DEBOUNCE_THRESHOLD) {
        debounceCount = 0;
        previousState = currentState;
        *buttonState = BUTTON_Pressed;
    } else {
        *buttonState = BUTTON_NotPressed;
    }
}

void BUTTON_Init(st_GPIO_config_t *usr_buttonConfig)
{
    uint8 pinCounter = 0;
    for (pinCounter = 0; pinCounter < PUSH_BUTTON_NUM; pinCounter++) {
        GPIO_Init(&usr_buttonConfig[pinCounter]);
    }
}


void BUTTON_IsPressed(st_GPIO_config_t *usr_buttonConfig, en_button_state_t *buttonState) {
    BUTTON_Debounce(usr_buttonConfig, buttonState);
}

//void BUTTON_IsPressed(st_GPIO_config_t *usr_buttonConfig, en_button_state_t *buttonState)
//{
//    uint8 tmpValue = 0;
//    GPIO_ReadPin(usr_buttonConfig, &tmpValue);
//    
//    if (tmpValue == HIGH) {
//        *buttonState = BUTTON_NotPressed;
//    } else {
//        *buttonState = BUTTON_Pressed;
//    }
//} 

