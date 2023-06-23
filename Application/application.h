#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "led.h"
#include "led_config.h"
#include "button.h"
#include "button_config.h"
#include "systick.h"
#include "systick_config.h"
#include "timer.h"
#include "timer_config.h"

typedef enum {
    STAGE_ONE = 1, STAGE_TWO = 2, STAGE_THREE = 3, STAGE_FOUR = 4, STAGE_FIVE = 5
}en_APP_LedSequenceStages;

typedef struct {
    uint16 OnTime_ms;
    uint16 OffTime_ms;
}st_APP_DutyCycle;

typedef struct {
    st_APP_DutyCycle Stage_1;
    st_APP_DutyCycle Stage_2;
    st_APP_DutyCycle Stage_3;
}st_APP_Stages_t;

/**
 * @brief Initializes all the ECUAL.
 */
void APP_Init(void);

/**
 * @brief Starts the application logic.
 */
void APP_Start(void);

#endif /* APPLICATION_H_ */
