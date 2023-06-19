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


void Led_Init(st_GPIO_config_t *ptr_st_LED_config)
{
    /* Variable for counting. */
    uint8 pinCounter = 0;
    for (pinCounter = 0; pinCounter < PORT_PINS_NUM; pinCounter++) {
        GPIO_Init(&ptr_st_LED_config[pinCounter]);
    }
}

void LED_RedOn(st_GPIO_config_t *ptr_st_LED_config)
{
	GPIO_WritePin(&ptr_st_LED_config[0], HIGH);	
	GPIO_WritePin(&ptr_st_LED_config[1], LOW);
	GPIO_WritePin(&ptr_st_LED_config[2], LOW);
}

void LED_BlueOn(st_GPIO_config_t* ptr_st_LED_config)
{	
	GPIO_WritePin(&ptr_st_LED_config[0], LOW);
	GPIO_WritePin(&ptr_st_LED_config[1], HIGH);
    GPIO_WritePin(&ptr_st_LED_config[2], LOW);
}


void LED_GreenOn(st_GPIO_config_t *ptr_st_LED_config)
{	
	GPIO_WritePin(&ptr_st_LED_config[0], LOW);
	GPIO_WritePin(&ptr_st_LED_config[1], LOW);
    GPIO_WritePin(&ptr_st_LED_config[2], HIGH);
}

void LED_AllOn(st_GPIO_config_t *ptr_st_LED_config)
{
	 GPIO_WritePin(&ptr_st_LED_config[0], HIGH);
	 GPIO_WritePin(&ptr_st_LED_config[1], HIGH);
	 GPIO_WritePin(&ptr_st_LED_config[2], HIGH);
}

void LED_AllOff(st_GPIO_config_t *ptr_st_LED_config)
{
	GPIO_WritePin(&ptr_st_LED_config[0], LOW);
	GPIO_WritePin(&ptr_st_LED_config[1], LOW);
	GPIO_WritePin(&ptr_st_LED_config[2], LOW);
}
