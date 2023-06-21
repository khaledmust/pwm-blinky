/*
**@file     : button.h
**@brief    : This is header file for the push button API.
**@author   : ANAS MAHMOUD
**@date     : 18 june 2023
**@version  : 0.1
*/

#ifndef BUTTON_H_
#define BUTTON_H_

#include "std_types.h"
#include "GPIO/GPIO.h"
#include "button_config.h"

#define DEBOUNCE_THRESHOLD  5000 //9000

typedef enum {
    BUTTON_NotPressed = 0, BUTTON_Pressed = 1
}en_button_state_t;

/**
 * @brief Initializes the button pin.
 * @param[in] Button_config     Address of the configuration array.
 */
void BUTTON_Init(st_GPIO_config_t *Button_config);

/**
 * @brief Initializes the button pin.
 * @param[in] usr_buttonConfig Address of the configuration array.
 * @param[in] value         Address of the variables to store the state of push button.
 */
void BUTTON_IsPressed( st_GPIO_config_t *usr_buttonConfig, en_button_state_t *value);

#endif
