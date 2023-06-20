/*
**@file     : led.h
**@brief    : This is source file for the LED API.
**@author   : ANAS MAHMOUD
**@date     : 18 june 2023
**@version  : 0.1
*/


#include "led.h"
#include "common.h"
#include "led_config.h"

/**
 * @brief Initializes the LED pin using the configuration array.
 * The function operates by using the GPIO_Init( ), where is loops over the the memebers of the array.
 * @param[in] ptr_st_LED_config     Address of the configuration array.
 * @return en_GPIO_error_t
 */
void Led_Init(st_GPIO_config_t *ptr_st_LED_config)
{
    /* Variable for counting. */
    uint8 pinCounter = 0;
    for (pinCounter = 0; pinCounter < PORT_PINS_NUM; pinCounter++) {
        GPIO_Init(&ptr_st_LED_config[pinCounter]);
    }
}

/**
 * @brief Turns on the red LED and turns off all the other LEDs.
 * @param[in] ptr_st_LED_config     Address of the configuration array.
 * @return en_GPIO_error_t
 */
void LED_RedOn(st_GPIO_config_t *ptr_st_LED_config)
{
	GPIO_WritePin(&ptr_st_LED_config[0], HIGH);	
	GPIO_WritePin(&ptr_st_LED_config[1], LOW);
	GPIO_WritePin(&ptr_st_LED_config[2], LOW);
}

/**
 * @brief Turns on the blue LED and turns off all the other LEDs.
 * @param[in] ptr_st_LED_config     Address of the configuration array.
 * @return en_GPIO_error_t
 */
void LED_BlueOn(st_GPIO_config_t* ptr_st_LED_config)
{	
	GPIO_WritePin(&ptr_st_LED_config[0], LOW);
	GPIO_WritePin(&ptr_st_LED_config[1], HIGH);
    GPIO_WritePin(&ptr_st_LED_config[2], LOW);
}

/**
 * @brief Turns on the green LED and turns off all the other LEDs.
 * @param[in] ptr_st_LED_config     Address of the configuration array.
 * @return en_GPIO_error_t
 */
void LED_GreenOn(st_GPIO_config_t *ptr_st_LED_config)
{	
	GPIO_WritePin(&ptr_st_LED_config[0], LOW);
	GPIO_WritePin(&ptr_st_LED_config[1], LOW);
    GPIO_WritePin(&ptr_st_LED_config[2], HIGH);
}

/**
 * @brief Turns on all the LEDs.
 * @param[in] ptr_st_LED_config     Address of the configuration array.
 * @return en_GPIO_error_t
 */
void LED_AllOn(st_GPIO_config_t *ptr_st_LED_config)
{
	 GPIO_WritePin(&ptr_st_LED_config[0], HIGH);
	 GPIO_WritePin(&ptr_st_LED_config[1], HIGH);
	 GPIO_WritePin(&ptr_st_LED_config[2], HIGH);
}

/**
 * @brief Turns off all the LEDs.
 * @param[in] ptr_st_LED_config     Address of the configuration array.
 * @return en_GPIO_error_t
 */
void LED_AllOff(st_GPIO_config_t *ptr_st_LED_config)
{
	GPIO_WritePin(&ptr_st_LED_config[0], LOW);
	GPIO_WritePin(&ptr_st_LED_config[1], LOW);
	GPIO_WritePin(&ptr_st_LED_config[2], LOW);
}
