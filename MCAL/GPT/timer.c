#include "timer.h"
#include "timer_private.h"
#include "common.h"

static void TIMER_EnableClock(en_TIMER_TimerID_t en_TIMER_TimerID) {
    switch(en_TIMER_TimerID) {
        case TIMER0:
            SET_BIT(RCGCTIMER, TIMER0);
            break;
        case TIMER1:
            SET_BIT(RCGCTIMER, TIMER1);
            break;
        case TIMER2:
            SET_BIT(RCGCTIMER, TIMER2);
            break;
        case TIMER3:
            SET_BIT(RCGCTIMER, TIMER3);
            break;
        case TIMER4:
            SET_BIT(RCGCTIMER, TIMER4);
            break;
        case TIMER5:
            SET_BIT(RCGCTIMER, TIMER5);
            break
    }
}

static void TIMER_EnableTimerX(en_TIMER_TimerID_t en_TIMER_TimerID) {
    SET_BIT(GPTMCTL(en_TIMER_TimerID),TAEN);
}

static void TIMER_DisableTimerX(en_TIMER_TimerID_t en_TIMER_TimerID) {
    CLR_BIT(GPTMCTL(en_TIMER_TimerID),TAEN);
}

static void TIMER_WidthSelect(en_TIMER_TimerID_t en_TIMER_TimerID, en_TIMER_Width_t en_TIMER_Width) {
    if (en_TIMER_Width == Width_16Bits) {
        GPTMCFG(en_TIMER_TimerID) = 0x4;
    } else if (en_TIMER_Width == Width_32Bits) {
        GPTMCFG(en_TIMER_TimerID) = 0x0;
    } else {
        /* Invalid Timer width. */
    }
}

static void TIMER_LoadTimer(en_TIMER_TimerID_t en_TIMER_TimerID, uint32 Period) {
    GPTMTAILR(en_TIMER_TimerID) = Period;
}

static void TIMER_OperationMode(en_TIMER_TimerID_t en_TIMER_TimerID, en_TIMER_OperationMode_t en_TIMER_OperationMode) {
    switch (en_TIMER_OperationMode) {
        case OneShotMode:
            CLR_BIT(GPTMTAMR(en_TIMER_TimerID), TAMR1);
            SET_BIT(GPTMTAMR(en_TIMER_TimerID), TAMR0);
            break;
        case PeriodicMode:
            SET_BIT(GPTMTAMR(en_TIMER_TimerID), TAMR1);
            CLR_BIT(GPTMTAMR(en_TIMER_TimerID), TAMR0);
            break;
        case CaptureMode:
            SET_BIT(GPTMTAMR(en_TIMER_TimerID), TAMR1);
            SET_BIT(GPTMTAMR(en_TIMER_TimerID), TAMR0);
            break;
    }
}

static void TIMER_CountDirection(en_TIMER_TimerID_t en_TIMER_TimerID, en_TIMER_CountDirection_t en_TIMER_CountDirection) {
    if (en_TIMER_CountDirection == CountDown) {
        CLR_BIT(GPTMTAMR(en_TIMER_TimerID), TACDIR);
    } else if (en_TIMER_CountDirection == CountUp) {
        SET_BIT(GPTMTAMR(en_TIMER_TimerID), TACDIR);
    } else {
        /* Invalid count direction. */
    }
}

static void TIMER_ClearTimeoutFlag(en_TIMER_TimerID_t en_TIMER_TimerID) {
    SET_BIT(GPTMICR(en_TIMER_TimerID), TATOCINT);
}

en_TIMER_Status_t TIMER_GetStatus(en_TIMER_TimerID_t en_TIMER_TimerID) {
    uint8 TimerStatus = GET_BIT_STATUS(GPTMRIS(en_TIMER_TimerID), TATORIS);
    if (TimerStatus == 0) {
        return TIMER_NotTimeOut;
    } else if (TimerStatus == 1) {
        return TIMER_TimeOut;
    }
}


void TIMER_Init(st_TIMER_config_t st_TIMER_config) {
    /* Enable clock to the timer block. */
    /* Disable the timer. */
    /* Configure the width of the timer. */
    /* Configure the operation mode of the timer. */
    /* Load the value to the timer. */
    /* Clear the flag, this is done by writing a 1 to the register. */
    /* Enable the timer module. */
}
