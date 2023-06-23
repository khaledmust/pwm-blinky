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

/**
 * @brief Initializes all the ECUAL.
 */
void APP_Init(void);

/**
 * @brief Starts the application logic.
 */
void APP_Start(void);

#endif /* APPLICATION_H_ */
