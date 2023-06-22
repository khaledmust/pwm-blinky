#include "timer.h"
#include "timer_private.h"
#include "common.h"

#define TIMER_16_BITS_MAX_TICKS 0x10000 /* 65536 */
#define TIMER_32_BITS_MAX_TICKS 0x100000000 /* 4294967296  */

/**
 * @brief Enables the clock access to the timer block.
 * @param[in] en_TIMER_TimerID Timer ID to be configured.
 */
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
            break;
    }
}

/**
 * @brief Enables the clock block of the specified timer.
 * @param[in] en_TIMER_TimerID Timer ID to be configured.
 */
static void TIMER_EnableTimerX(en_TIMER_TimerID_t en_TIMER_TimerID) {
    SET_BIT(GPTMCTL(en_TIMER_TimerID),TAEN);
}

/**
 * @brief Disables the clock block of the specified timer.
 * @param[in] en_TIMER_TimerID Timer ID to be configured.
 */
static void TIMER_DisableTimerX(en_TIMER_TimerID_t en_TIMER_TimerID) {
    CLR_BIT(GPTMCTL(en_TIMER_TimerID),TAEN);
}

/**
 * @brief Sets the width of the timer.
 * @param[in] en_TIMER_TimerID  Timer ID to be configured.
 * @param[in] en_TIMER_Width    Timer width as either 16bits or 32bits.
 */
static void TIMER_WidthSelect(en_TIMER_TimerID_t en_TIMER_TimerID, en_TIMER_Width_t en_TIMER_Width) {
    if (en_TIMER_Width == Width_16Bits) {
        GPTMCFG(en_TIMER_TimerID) = 0x4;
    } else if (en_TIMER_Width == Width_32Bits) {
        GPTMCFG(en_TIMER_TimerID) = 0x0;
    } else {
        /* Invalid Timer width. */
    }
}

/**
 * @brief Loads the specified timer with the delayed period value.
 * @param[in] en_TIMER_TimerID  Timer ID to be configured.
 * @param[in] Period            Time value to be loaded into the timer.
 */
static void TIMER_LoadTimer(en_TIMER_TimerID_t en_TIMER_TimerID, uint32 Period) {
    GPTMTAILR(en_TIMER_TimerID) = Period;
}

/**
 * @brief Sets the operation mode of the specified timer.
 * @param[in] en_TIMER_TimerID          Timer ID to be configured.
 * @param[in] en_TIMER_OperationMode    Timer operation mode @ref en_TIMER_OperationMode_t.
 */
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

/**
 * @brief Sets the count direction of the specified timer.
 * @param[in] en_TIMER_TimerID              Timer ID to be configured.
 * @param[in] en_TIMER_CountDirection       Timer count direction @ref en_TIMER_CountDirection_t.
 */
static void TIMER_CountDirection(en_TIMER_TimerID_t en_TIMER_TimerID, en_TIMER_CountDirection_t en_TIMER_CountDirection) {
    if (en_TIMER_CountDirection == CountDown) {
        CLR_BIT(GPTMTAMR(en_TIMER_TimerID), TACDIR);
    } else if (en_TIMER_CountDirection == CountUp) {
        SET_BIT(GPTMTAMR(en_TIMER_TimerID), TACDIR);
    } else {
        /* Invalid count direction. */
    }
}

/**
 * @brief Clears the timer-out flag of the specified timer.
 * @param[in] en_TIMER_TimerID              Timer ID to be configured.
 */
 void TIMER_ClearTimeoutFlag(en_TIMER_TimerID_t en_TIMER_TimerID) {
    SET_BIT(GPTMICR(en_TIMER_TimerID), TATOCINT);
     GPTMICR(en_TIMER_TimerID) = 0x01;
}


/**
 * @brief Initializes the specific timer.
 * @param[in] ptr_st_TIMER_config   Address of the configuration structure of the specified timer.  
 */
void TIMER_Init(st_TIMER_config_t *ptr_st_TIMER_config) {
    
    /* Enable clock to the timer block. */
    TIMER_EnableClock(ptr_st_TIMER_config->en_TIMER_TimerID);
    /* Disable the timer. */
    TIMER_DisableTimerX(ptr_st_TIMER_config->en_TIMER_TimerID);
    /* Configure the width of the timer. */
    TIMER_WidthSelect(ptr_st_TIMER_config->en_TIMER_TimerID, ptr_st_TIMER_config->en_TIMER_Width);
    /* Configure the operation mode of the timer. */
    TIMER_OperationMode(ptr_st_TIMER_config->en_TIMER_TimerID, ptr_st_TIMER_config->en_TIMER_OperationMode);
    /* Configure the countdirection. */
    TIMER_CountDirection(ptr_st_TIMER_config->en_TIMER_TimerID, ptr_st_TIMER_config->en_TIMER_CountDirection);
    /* Load the value to the timer. */
    TIMER_LoadTimer(ptr_st_TIMER_config->en_TIMER_TimerID, ptr_st_TIMER_config->Period);
    /* Clear the flag, this is done by writing a 1 to the register. */
    TIMER_ClearTimeoutFlag(ptr_st_TIMER_config->en_TIMER_TimerID);
    /* Enable the timer module. */
    TIMER_EnableTimerX(ptr_st_TIMER_config->en_TIMER_TimerID);
}

/**
 * @brief Gets the status of the time-out flag of the specified timer.
 * @param[in] en_TIMER_TimerID  Timer ID to be configured.
 * @return en_TIMER_Status_t    Time-out flag status.    
 */
en_TIMER_Status_t TIMER_GetStatus(en_TIMER_TimerID_t en_TIMER_TimerID) {
    uint8 TimerStatus = GET_BIT_STATUS(GPTMRIS(en_TIMER_TimerID), TATORIS);
    if (TimerStatus == 0) {
        return TIMER_NotTimeOut;
    } else if (TimerStatus == 1) {
        return TIMER_TimeOut;
    }
}

void TIMER_DelayMS(st_TIMER_config_t *ptr_st_TIMER_config, uint32 Period) {
    uint16 OverFlowCounter = 0;
    for (OverFlowCounter = 0; OverFlowCounter < Period; OverFlowCounter++) {
        while (TIMER_GetStatus(ptr_st_TIMER_config->en_TIMER_TimerID) == TIMER_NotTimeOut) {
        }
        TIMER_ClearTimeoutFlag(ptr_st_TIMER_config->en_TIMER_TimerID);
    }
}
