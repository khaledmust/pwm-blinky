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

/**
 * @brief Initializes the LED pin using the configuration array.
 * @param[in] ptr_st_LED_config     Address of the configuration array.
 * @return en_GPIO_error_t
 */
void Led_Init(st_GPIO_config_t *ptr_st_LED_config);

/**
 * @brief Turns on the red LED and turns off all the other LEDs.
 * @param[in] ptr_st_LED_config     Address of the configuration array.
 * @return en_GPIO_error_t
 */
void LED_GreenOn(st_GPIO_config_t *ptr_st_LED_config);

/**
 * @brief Turns on the blue LED and turns off all the other LEDs.
 * @param[in] ptr_st_LED_config     Address of the configuration array.
 * @return en_GPIO_error_t
 */
void LED_BlueOn(st_GPIO_config_t *ptr_st_LED_config);

/**
 * @brief Turns on the green LED and turns off all the other LEDs.
 * @param[in] ptr_st_LED_config     Address of the configuration array.
 * @return en_GPIO_error_t
 */
void LED_RedOn(st_GPIO_config_t *ptr_st_LED_config);

/**
 * @brief Turns on all the LEDs.
 * @param[in] ptr_st_LED_config     Address of the configuration array.
 * @return en_GPIO_error_t
 */
void LED_AllOn(st_GPIO_config_t *ptr_st_LED_config);

/**
 * @brief Turns off all the LEDs.
 * @param[in] ptr_st_LED_config     Address of the configuration array.
 * @return en_GPIO_error_t
 */
void LED_AllOff(st_GPIO_config_t *ptr_st_LED_config);

#endif /* LED_H_ */
