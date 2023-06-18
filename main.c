#include "main.h"

st_GPIO_config_t myConfigArray[PORT_PINS_NUM] = {
    {PORT_A, PIN0, OUTPUT, DRIVE_2mA, PULL_UP},
    {PORT_A, PIN1, OUTPUT, DRIVE_4mA, PULL_DOWN},
    {PORT_A, PIN2, INPUT, DRIVE_2mA, PULL_UP},
};

int main(void) {
    GPIO_Init(myConfigArray);
    
    while (1);
}
