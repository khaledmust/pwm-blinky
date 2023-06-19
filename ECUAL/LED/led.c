#include "led.h"
#include "common.h"

void Led_Init(st_GPIO_config_t* Led_Config)
{
	GPIO_Init(Led_Config);
}


void Led_Set_Red(st_GPIO_config_t* Led_Config)
{
	GPIO_WritePin(&Led_Config[0],HIGH);
	GPIO_WritePin(&Led_Config[1],LOW);
	GPIO_WritePin(&Led_Config[2],LOW);
}


void Led_Set_Green(st_GPIO_config_t* Led_Config)
{
	GPIO_WritePin(&Led_Config[1],HIGH);	
	GPIO_WritePin(&Led_Config[0],LOW);
	GPIO_WritePin(&Led_Config[2],LOW);
}


void Led_Set_Blue(st_GPIO_config_t* Led_Config)
{

	GPIO_WritePin(&Led_Config[2],HIGH);
	GPIO_WritePin(&Led_Config[0],LOW);
	GPIO_WritePin(&Led_Config[1],LOW);
}


void Leds_on(st_GPIO_config_t* Led_Config)
{
	 GPIO_WritePin(&Led_Config[0],HIGH);
	 GPIO_WritePin(&Led_Config[1],HIGH);
	 GPIO_WritePin(&Led_Config[2],HIGH);
}



void Leds_off(st_GPIO_config_t* Led_Config)
{
	GPIO_WritePin(&Led_Config[0],LOW);
	GPIO_WritePin(&Led_Config[1],LOW);
	GPIO_WritePin(&Led_Config[2],LOW);
}




