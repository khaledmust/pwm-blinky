#include"led_config.h"

st_GPIO_config_t Led_Config [PORT_PINS_NUM] = {
    {PORT_F, PIN1, OUTPUT, DRIVE_2mA, PULL_DOWN}, //Red Led 
    {PORT_F, PIN2, OUTPUT, DRIVE_4mA, PULL_DOWN}, //Green Led 
    {PORT_F, PIN3, OUTPUT, DRIVE_8mA, PULL_DOWN}, //Blue Led 
};
