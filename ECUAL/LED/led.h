#ifndef LED_H_
#define LED_H_

#include "GPIO/GPIO.h"


void Led_Init(st_GPIO_config_t* Led_Config);

void Led_Set_Green(st_GPIO_config_t* Led_Config);

void Led_Set_Blue(st_GPIO_config_t* Led_Config);

void Led_Set_Red(st_GPIO_config_t* Led_Config);

void Leds_on(st_GPIO_config_t* Led_Config);

void Leds_off(st_GPIO_config_t* Led_Config);

#endif
