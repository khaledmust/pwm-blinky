#include "systick.h"
#include "systick_private.h"
#include "common.h"
#include "TM4C123.h" /* To get the value of the system clock. */

void SYSTICK_Init(st_SYSTICK_config_t *ptr_st_SYSTICK_config) {
    if (ptr_st_SYSTICK_config != NULL) {
        
        CLR_BIT(STCTRL, ENABLE_IDX);
        
        /* Clear the STCURRENT register to reset the register and lower the COUNT flag. */
        STCURRENT = 0;
            
        /* Configure the status and control register. */
        SET_BIT(STCTRL,CLK_SRC_IDX); /* Set the clock source as the system clock. */
    
        if (ptr_st_SYSTICK_config->en_SYSTICK_InterruptState == SYSTICK_IntEnable) {
            SET_BIT(STCTRL,INTEN_IDX);
        } else {
            CLR_BIT(STCTRL, INTEN_IDX);
        }
    } else {
        g_SYSTICK_InitStatus = SYSTICK_INIT_FAILED;
    }
    g_SYSTICK_InitStatus = SYSTICK_INIT_SUCCESS;
}

void SYSTICK_DeInit(void) {
    CLR_BIT(STCTRL, ENABLE_IDX);
}


void SYSTICK_StartTimer(void) {
        SET_BIT(STCTRL, ENABLE_IDX);
}

void SYSTICK_StopTimer(void) {
        CLR_BIT(STCTRL, ENABLE_IDX);
}

void SYSTICK_ResetTimer(void) {
    STCURRENT = 0;
}

static void SYSTICK_GetStatus(en_SYSTICK_FlagStatus_t *ptr_flagStatus) {
        if (GET_BIT_STATUS(STCTRL, COUNT_IDX) == 1) {
            *ptr_flagStatus = SYSTICK_FlagSet;
        } else {
            *ptr_flagStatus = SYSTICK_FlagNotSet;
        }
}

void SYSTICK_Delay_ms(uint32 delay_ms) {
    uint8 systick_flagStatus = 0;
    
    /* Calculate the number of tick required to perform the specified delay. */
    uint64 ticksRequired = (uint64)((delay_ms) * (SystemCoreClock / 1000));
    
    /* Load the reload register with the value. */
    STRELOAD = (uint32)ticksRequired - 1;    
   
    /* Clear the STCURRENT register to reset the register and lower the COUNT flag. */
    SYSTICK_ResetTimer();
   

    SYSTICK_StartTimer();
    
    
    
    while (systick_flagStatus == 0) {
    SYSTICK_GetStatus(&systick_flagStatus);
    }
    
    SYSTICK_StopTimer();
    
}
