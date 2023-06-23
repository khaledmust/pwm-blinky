#include "timer_config.h"

#define PERIOD_1_MS (16000 - 1)

st_TIMER_config_t myTimerConfig = {
    .en_TIMER_TimerID           = TIMER0_ID,
    .en_TIMER_Width             = Width_16Bits,
    .en_TIMER_OperationMode     = PeriodicMode,
    .Period                     = PERIOD_1_MS,
    .en_TIMER_CountDirection    = CountUp,
};
