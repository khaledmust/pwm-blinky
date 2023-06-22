#include "main.h"

#include "timer.h"

#include "led.h"



//int main(void) {
//    
//    APP_Init();

//    /* Super loop */
//    while (1) {
//        APP_Start();
//    }
//}

st_TIMER_config_t myTimerConfig = {
    .en_TIMER_TimerID           = TIMER00,
    .en_TIMER_Width             = Width_16Bits,
    .en_TIMER_OperationMode     = PeriodicMode,
    .Period                     = temp,
    .en_TIMER_CountDirection    = CountUp,
};


int main(void) {
    Led_Init(usr_led_config);
    TIMER_Init(&myTimerConfig);
    
    while (1) {
        LED_GreenOn(usr_led_config);
        
//        for (long i = 0; i < 2000; i++) {
//            while(TIMER_GetStatus(TIMER0) == TIMER_NotTimeOut) {
//            }
//            TIMER_ClearTimeoutFlag(TIMER0);
//        }
//        
//        LED_AllOff(usr_led_config);
//        
//                for (long i = 0; i < 2000; i++) {
//            while(TIMER_GetStatus(TIMER0) == TIMER_NotTimeOut) {
//            }
//            TIMER_ClearTimeoutFlag(TIMER0);
//        }
        TIMER_DelayMS(&myTimerConfig, 1000);
        LED_AllOff(usr_led_config);
        TIMER_DelayMS(&myTimerConfig, 1000);
    }
}
