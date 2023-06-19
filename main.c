#include "main.h"
#include "led.h"
#include "led_config.h"
#include "GPIO/GPIO_private.h"

st_GPIO_config_t myConfigArray[PORT_PINS_NUM] = {
    {PORT_A, PIN0, OUTPUT, DRIVE_2mA, PULL_UP},
    {PORT_A, PIN1, OUTPUT, DRIVE_4mA, PULL_UP},
    {PORT_F, PIN1, OUTPUT, DRIVE_2mA, PULL_DOWN},
};

uint8 myVar = 0;

int main(void) {
    
    GPIO_Init(myConfigArray);
   
    while (1);
}
