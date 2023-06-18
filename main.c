#include "main.h"

st_GPIO_config_t myConfigArray[PORT_PINS_NUM] = {
    {PORT_A, PIN0, OUTPUT, DRIVE_2mA, PULL_UP},
    {PORT_A, PIN1, OUTPUT, DRIVE_4mA, PULL_UP},
    {PORT_A, PIN4, INPUT, DRIVE_2mA, PULL_UP},
};

int main(void) {
    GPIO_Init(myConfigArray);
    
//    *(volatile uint32*) 0x40004000 = 0x01;
//    *(volatile uint32*) 0x40004004 = 0x01;
//    *(volatile uint32*) 0x40004008 = 0x01;
    
    GPIO_WritePin(&myConfigArray[0], 1);
    
    while (1);
}
