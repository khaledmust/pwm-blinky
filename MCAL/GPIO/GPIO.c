
#include "./GPIO.h"
#include "GPIO_private.h"

#define	PORT_LOCK_VALUE     (uint32_t)(0x4C4F434B)
#define BIT_MASKING_OFFSET  (uint8_t)(2)
#define PCTL_PIN_MASK       (uint32_t)(0x0000000F)
#define PCTL_PIN_BIT_NUM    (uint8_t)(4)
#define MIN_PCTL_VAL        (uint8_t)(1)
#define MAX_PCTL_VAL        (uint8_t)(15)

/**
 * @brief Enables the clock source to the GPIO module.
 * @param[in] en_GPIO_port      Port number to be configured.
 * @return en_GPIO_error_t
 */
static en_GPIO_error_t GPIO_EnableClock(en_GPIO_port_t en_GPIO_port) {
    SET_BIT(RCGCGPIO, en_GPIO_port);
    return GPIO_STATUS_SUCCESS;
}

/**
 * @brief Sets the direction of the specified pin.
 * @param[in] en_GPIO_port      Port number to be configured.
 * @param[in] en_GPIO_pin       Pin number to be configured.
 * @param[in] en_GPIO_pinDir    Direction of the specified pin.
 * @return en_GPIO_error_t
 */
static en_GPIO_error_t GPIO_SetDirection(en_GPIO_port_t en_GPIO_port, en_GPIO_pin_t en_GPIO_pin, en_GPIO_pinDir_t en_GPIO_pinDir) {
    if (en_GPIO_pinDir == OUTPUT) {
        SET_BIT(GPIODIR(en_GPIO_port), en_GPIO_pin);
        return GPIO_STATUS_SUCCESS;
    } else if (en_GPIO_pinDir == INPUT) {
        CLR_BIT(GPIODIR(en_GPIO_port), en_GPIO_pin);
        return GPIO_STATUS_SUCCESS;
    } else {
        return GPIO_STATUS_SET_DIRECTION_FAILED;
    }
}

/**
 * @brief Sets the drive current of the specified pin.
 * @param[in] en_GPIO_port          Port number to be configured.
 * @param[in] en_GPIO_pin           Pin number to be configured.
 * @param[in] en_GPIO_driveCurrent  The drive current.
 * @return en_GPIO_error_t
 */
static en_GPIO_error_t GPIO_SetDriveCurrent(en_GPIO_port_t en_GPIO_port, en_GPIO_pin_t en_GPIO_pin, en_GPIO_driveCurrent_t en_GPIO_driveCurrent) {
    switch (en_GPIO_driveCurrent) {
        case DRIVE_2mA:
            SET_BIT(GPIODR2R(en_GPIO_port), en_GPIO_pin);
            CLR_BIT(GPIODR4R(en_GPIO_port), en_GPIO_pin);
            CLR_BIT(GPIODR8R(en_GPIO_port), en_GPIO_pin);
            break;
        case DRIVE_4mA:
            CLR_BIT(GPIODR2R(en_GPIO_port), en_GPIO_pin);
            SET_BIT(GPIODR4R(en_GPIO_port), en_GPIO_pin);
            CLR_BIT(GPIODR8R(en_GPIO_port), en_GPIO_pin);
            break;
        case DRIVE_8mA:
            CLR_BIT(GPIODR2R(en_GPIO_port), en_GPIO_pin);
            CLR_BIT(GPIODR4R(en_GPIO_port), en_GPIO_pin);
            SET_BIT(GPIODR8R(en_GPIO_port), en_GPIO_pin);
            break;
        default:
            return GPIO_STATUS_SET_DRIVE_CURRENT_FAILED;
    }
    return GPIO_STATUS_SUCCESS;
}

/**
 * @brief Sets the pull state of the specified pin.
 * @param[in] en_GPIO_port          Port number to be configured.
 * @param[in] en_GPIO_pin           Pin number to be configured.
 * @param[in] en_GPIO_pull          The pull state of the pin.
 * @return en_GPIO_error_t
 */
static en_GPIO_error_t GPIO_SetPull(en_GPIO_port_t en_GPIO_port, en_GPIO_pin_t en_GPIO_pin, en_GPIO_pull_t en_GPIO_pull) {
    switch (en_GPIO_pull) {
        case PULL_UP:
            SET_BIT(GPIOPUR(en_GPIO_port), en_GPIO_pin);
            break;
        case PULL_DOWN:
            SET_BIT(GPIOPDR(en_GPIO_port), en_GPIO_pin);
            break;
        case OPEN_DRAIN:
            SET_BIT(GPIOODR(en_GPIO_port), en_GPIO_pin);
            break;
        default:
            return GPIO_STATUS_SET_PULL_FAILED;
    }
    return GPIO_STATUS_SUCCESS;
}

/**
 * @brief Configure the specified pin as digital.
 * @param[in] en_GPIO_port          Port number to be configured.
 * @param[in] en_GPIO_pin           Pin number to be configured.
 * @return en_GPIO_error_t
 */
static en_GPIO_error_t GPIO_DigitalEnable(en_GPIO_port_t en_GPIO_port, en_GPIO_pin_t en_GPIO_pin) {
    SET_BIT(GPIODEN(en_GPIO_port), en_GPIO_pin);
    return GPIO_STATUS_SUCCESS;
}

en_GPIO_error_t GPIO_Init(const st_GPIO_config_t *ptr_st_GPIO_config) {
    
    /* Variable for loop counter */
    uint8 u8_pinCounter = 0;
    
    /* Variable for the current API status */
    en_GPIO_error_t en_GPIO_error_CurrentError = 0;
    
    if (ptr_st_GPIO_config != NULL) {
        
        for (u8_pinCounter = 0; u8_pinCounter < PORT_PINS_NUM; u8_pinCounter++) {
            /* 1. Enable the clodk to the port */
            en_GPIO_error_CurrentError = GPIO_EnableClock(ptr_st_GPIO_config[u8_pinCounter].en_GPIO_port);
            if (en_GPIO_error_CurrentError != GPIO_STATUS_SUCCESS) {
                return GPIO_STATUS_CLOCK_FAILED;
            }
            
            /* 2. Set the direction of the GPIO port pins */
            en_GPIO_error_CurrentError = GPIO_SetDirection(ptr_st_GPIO_config[u8_pinCounter].en_GPIO_port, ptr_st_GPIO_config[u8_pinCounter].en_GPIO_pin, ptr_st_GPIO_config[u8_pinCounter].en_GPIO_pinDir);
            if (en_GPIO_error_CurrentError != GPIO_STATUS_SUCCESS) {
                return en_GPIO_error_CurrentError;
            }
            
            /* 3. Set the drive strenght of the pin */
            en_GPIO_error_CurrentError = GPIO_SetDriveCurrent(ptr_st_GPIO_config[u8_pinCounter].en_GPIO_port, ptr_st_GPIO_config[u8_pinCounter].en_GPIO_pin, ptr_st_GPIO_config[u8_pinCounter].en_GPIO_driveCurrent);
            if (en_GPIO_error_CurrentError != GPIO_STATUS_SUCCESS) {
                return en_GPIO_error_CurrentError;
            }
            
            /* 4. Set the pull state for the pin */
            en_GPIO_error_CurrentError = GPIO_SetPull(ptr_st_GPIO_config[u8_pinCounter].en_GPIO_port, ptr_st_GPIO_config[u8_pinCounter].en_GPIO_pin, ptr_st_GPIO_config[u8_pinCounter].en_GPIO_pull);
            if (en_GPIO_error_CurrentError != GPIO_STATUS_SUCCESS) {
                return en_GPIO_error_CurrentError;
            }
            
            /* 5. Enable the GPIO pin as digital */
            en_GPIO_error_CurrentError = GPIO_DigitalEnable(ptr_st_GPIO_config[u8_pinCounter].en_GPIO_port, ptr_st_GPIO_config[u8_pinCounter].en_GPIO_pin);
            if (en_GPIO_error_CurrentError != GPIO_STATUS_SUCCESS) {
                return en_GPIO_error_CurrentError;
            }
        }
    }
    return GPIO_STATUS_SUCCESS;
}

en_GPIO_error_t GPIO_ReadPin(const st_GPIO_config_t *ptr_st_GPIO_config, uint8_t *ptr_pinValue) {
    if (ptr_st_GPIO_config->en_GPIO_pinDir == INPUT) {
        switch (ptr_st_GPIO_config->en_GPIO_port) {
            case PORT_A:
                *ptr_pinValue = GET_BIT_STATUS(PORT_A, ptr_st_GPIO_config->en_GPIO_pin);
                break;
            case PORT_B:
                *ptr_pinValue = GET_BIT_STATUS(PORT_B, ptr_st_GPIO_config->en_GPIO_pin);
                break;
            case PORT_C:
                *ptr_pinValue = GET_BIT_STATUS(PORT_C, ptr_st_GPIO_config->en_GPIO_pin);
                break;
            case PORT_D:
                *ptr_pinValue = GET_BIT_STATUS(PORT_D, ptr_st_GPIO_config->en_GPIO_pin);
                break;
            case PORT_E:
                *ptr_pinValue = GET_BIT_STATUS(PORT_E, ptr_st_GPIO_config->en_GPIO_pin);
                break;
            case PORT_F:
                *ptr_pinValue = GET_BIT_STATUS(PORT_F, ptr_st_GPIO_config->en_GPIO_pin);
                break;
            default:
                return GPIO_STATUS_INVALID_PORT_NUM;
        }
    } else {
        return GPIO_STATUS_INVALID_PIN_DIR;
    }
    return GPIO_STATUS_SUCCESS;
}


en_GPIO_error_t GPIO_WritePin(const st_GPIO_config_t *ptr_st_GPIO_config, uint8 pinValue) {
    
    /* Variable for the address bus mask. */
    uint8_t busMask = pinValue << 2;
    
    if (ptr_st_GPIO_config->en_GPIO_pinDir == INPUT) {
        switch (ptr_st_GPIO_config->en_GPIO_port) {
            case PORT_A:
                break;
            case PORT_B:
                break;
            case PORT_C:
                break;
            case PORT_D:
                break;
            case PORT_E:
                break;
            case PORT_F:
                break;
            default:
                return GPIO_STATUS_INVALID_PORT_NUM;
        }
    } else {
        return GPIO_STATUS_INVALID_PIN_DIR;
    }
    return GPIO_STATUS_SUCCESS;
}
