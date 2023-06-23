#include "timer_config.h"

st_TIMER_config_t myTimerConfig = {
    .en_TIMER_TimerID           = TIMER0_ID,
    .en_TIMER_Width             = Width_16Bits,
    .en_TIMER_OperationMode     = PeriodicMode,
    .Period                     = (16000 - 1),
    .en_TIMER_CountDirection    = CountUp,
};
