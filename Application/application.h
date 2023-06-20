#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "led.h"
#include "led_config.h"
#include "button.h"
#include "button_config.h"

/**
 * @brief Initializes all the ECUAL.
 */
void APP_Init(void);

/**
 * @brief Starts the application logic.
 */
void APP_Start(void);

#endif /* APPLICATION_H_ */
