#include "application.h"

uint8 static g_APP_SequenceState = 0;

st_APP_Stages_t AppStages = {
    .Stage_1.OnTime_ms = 150, .Stage_1.OffTime_ms = 350,
    .Stage_2.OnTime_ms = 300, .Stage_2.OffTime_ms = 200,
    .Stage_3.OnTime_ms = 450, .Stage_3.OffTime_ms = 50
};

static void ButtonInterrupt(void) {
        g_APP_SequenceState++;
}

void APP_Init(void) {
    Led_Init(usr_led_config);
    BUTTON_Init(usr_button_config);
    TIMER_Init(&myTimerConfig);
    GPIO_PortF_SetCallBack(ButtonInterrupt);
}

void APP_Start(void) {
    switch (g_APP_SequenceState) {
        case STAGE_ONE:
            LED_GreenOn(usr_led_config);
            TIMER_DelayMS(&myTimerConfig, AppStages.Stage_1.OnTime_ms);
            LED_AllOff(usr_led_config);
            TIMER_DelayMS(&myTimerConfig, AppStages.Stage_1.OffTime_ms);
            break;
        case STAGE_TWO:
            LED_GreenOn(usr_led_config);
            TIMER_DelayMS(&myTimerConfig, AppStages.Stage_2.OnTime_ms);
            LED_AllOff(usr_led_config);
            TIMER_DelayMS(&myTimerConfig, AppStages.Stage_2.OffTime_ms);
            break;
        case STAGE_THREE:
            LED_GreenOn(usr_led_config);
                TIMER_DelayMS(&myTimerConfig, AppStages.Stage_3.OnTime_ms);
                LED_AllOff(usr_led_config);
                TIMER_DelayMS(&myTimerConfig, AppStages.Stage_3.OffTime_ms);
            break;
        case STAGE_FOUR:
            LED_AllOff(usr_led_config);
            break;
        case STAGE_FIVE:
            g_APP_SequenceState = 0;
        break;
    }
}

