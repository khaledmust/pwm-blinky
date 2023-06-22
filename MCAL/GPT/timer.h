#ifndef TIMER_H_
#define TIMER_H_

#include "std_types.h"

#include "TM4C123.h" /* To get the value of the system clock. */
#define PERIOD (((SystemCoreClock) / (1000)) - 1)

uint32 temp = (((SystemCoreClock) / (1000)) - 1);

/* Write 0x0 to select a 32 bit width, and 0x4 for 16 bit width */
typedef enum {
    Width_16Bits = 0, Width_32Bits = 1
}en_TIMER_Width_t;

typedef enum {
    OneShotMode = 1, PeriodicMode = 2, CaptureMode = 3
}en_TIMER_OperationMode_t;

typedef enum {
    CountDown = 0, CountUp = 1
}en_TIMER_CountDirection_t;

typedef enum {
    TIMER00 = 0, TIMER1 = 1, TIMER2 = 2, TIMER3 = 3, TIMER4 = 4, TIMER5 = 5
}en_TIMER_TimerID_t;

typedef enum {
    TIMER_NotTimeOut = 0, TIMER_TimeOut = 1 
}en_TIMER_Status_t;

typedef struct {
    en_TIMER_TimerID_t          en_TIMER_TimerID;
    en_TIMER_Width_t            en_TIMER_Width;
    en_TIMER_OperationMode_t    en_TIMER_OperationMode;
    uint32                      Period;
    en_TIMER_CountDirection_t   en_TIMER_CountDirection;
}st_TIMER_config_t;

void TIMER_Init(st_TIMER_config_t *ptr_st_TIMER_config);
en_TIMER_Status_t TIMER_GetStatus(en_TIMER_TimerID_t en_TIMER_TimerID);
void TIMER_ClearTimeoutFlag(en_TIMER_TimerID_t en_TIMER_TimerID);
void TIMER_DelayMS(st_TIMER_config_t *ptr_st_TIMER_config, uint32 Period);
#endif /* TIMER_H_ */
