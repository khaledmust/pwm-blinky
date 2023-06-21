#ifndef SYSTICK_H_
#define SYSTICK_H_

#include "std_types.h"

#define SYS_CLOCK_F 16000000

static uint8 g_SYSTICK_InitStatus = 0;

typedef enum {
    SYSTICK_IntDisable = 0, SYSTICK_IntEnable = 1
}en_SYSTICK_InterruptState_t;

typedef enum {
    SYSTICK_FlagNotSet = 0, SYSTICK_FlagSet= 1
}en_SYSTICK_FlagStatus_t;

typedef enum {
    SYSTICK_INIT_FAILED     =   200,
    SYSTICK_INIT_SUCCESS    =   201,
    SYSTICK_START_FAILED    =   202,
    SYSTICK_START_SUCCESS   =   203,
    SYSTICK_STOP_FAILED     =   204,
    SYSTICK_STOP_SUCCESS    =   205,
}en_SYSTICK_Status;


typedef struct {
    uint32 delay_ms;
    en_SYSTICK_InterruptState_t en_SYSTICK_InterruptState;
    
}st_SYSTICK_config_t;

/**
 * @brief Initializes the SysTick timer module.
 * @param[in] ptr_st_SYSTICK_config     Address of the configuration array.
 */
void SYSTICK_Init(st_SYSTICK_config_t *ptr_st_SYSTICK_config);

/**
 * @brief De-Initializes the SysTick timer module.
 */
void SYSTICK_DeInit(void);

/**
 * @brief Enables the SysTick timer module.
 */
void SYSTICK_StartTimer(void);

/**
 * @brief Disables the SysTick timer module.
 */
void SYSTICK_ResetTimer(void);

/**
 * @brief Stops the SysTick timer module.
 */
void SYSTICK_StopTimer(void);

/**
 * @brief Creates a blocking delay with the period specified.
 * @param[in] delay_ms  Specified period in milli-seconds.
 */
void SYSTICK_Delay_ms(uint32 delay_ms);

#endif /* SYSTICK_H_ */
