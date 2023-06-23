#include "main.h"

int main(void) {
    
    APP_Init();

    /* Super loop */
    while (1) {
        APP_Start();
    }
}



//int main(void) {
//    Led_Init(usr_led_config);
//    TIMER_Init(&myTimerConfig);
//    
//    while (1) {
//        LED_GreenOn(usr_led_config);
//        
////        for (long i = 0; i < 2000; i++) {
////            while(TIMER_GetStatus(TIMER0) == TIMER_NotTimeOut) {
////            }
////            TIMER_ClearTimeoutFlag(TIMER0);
////        }
////        
////        LED_AllOff(usr_led_config);
////        
////                for (long i = 0; i < 2000; i++) {
////            while(TIMER_GetStatus(TIMER0) == TIMER_NotTimeOut) {
////            }
////            TIMER_ClearTimeoutFlag(TIMER0);
////        }
//        TIMER_DelayMS(&myTimerConfig, 150);
//        LED_AllOff(usr_led_config);
//        TIMER_DelayMS(&myTimerConfig, 350);
//    }
//}
