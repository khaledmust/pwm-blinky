#include "application.h"

uint8 static g_APP_SequenceState = 0;
en_button_state_t static g_APP_ButtonState = 0;
uint8 static g_APP_ButtonLastState = 0;
uint8 static g_APP_DebounceFlag = 0;

void APP_Init(void) {
    Led_Init(usr_led_config);
    BUTTON_Init(usr_button_config);
}

void APP_Start(void) {
    do {
        BUTTON_IsPressed(&usr_button_config[0], &g_APP_ButtonState);
        if (g_APP_ButtonState == BUTTON_Pressed && g_APP_DebounceFlag == 0) {
            g_APP_SequenceState++;
            g_APP_DebounceFlag = 1;
        }
    } while (g_APP_ButtonState == BUTTON_NotPressed);
    
    switch (g_APP_SequenceState) {
        case 1:
            LED_AllOff(usr_led_config);
            LED_RedOn(usr_led_config);
            g_APP_DebounceFlag = 0;
            break;
        case 2:
            LED_AllOff(usr_led_config);
            LED_GreenOn(usr_led_config);
            g_APP_DebounceFlag = 0;
            break;
        case 3:
            LED_AllOff(usr_led_config);
            LED_BlueOn(usr_led_config);
            g_APP_DebounceFlag = 0;
            break;
        case 4:
            LED_AllOn(usr_led_config);
            g_APP_DebounceFlag = 0;
            break;
        case 5:
            LED_AllOff(usr_led_config);
            g_APP_DebounceFlag = 0;
            break;
        case 6:
            g_APP_SequenceState = 0;
            g_APP_DebounceFlag = 0;
            break;

    }
}