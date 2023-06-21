#ifndef SYSTICK_H_
#define SYSTICK_H_

#include "std_types.h"

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

void SYSTICK_Init(st_SYSTICK_config_t *ptr_st_SYSTICK_config);
void SYSTICK_DeInit(void);
void SYSTICK_StartTimer(void);
void SYSTICK_ResetTimer(void);
void SYSTICK_StopTimer(void);
void SYSTICK_Delay_ms(uint32 delay_ms);

#endif /* SYSTICK_H_ */
