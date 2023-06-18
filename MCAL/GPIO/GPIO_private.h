/*
**@file     : common.h
**@brief    : This is header file for common usage macros and definations
**@author   : ANAS MAHMOUD
**@date     : 13 june 2023
**@version  : 0.1
*/

#include "std_types.h"

/* GPIO registers */

#define GPIO_APB

#ifdef GPIO_APB

#define GPIO_OFFSET(x)  (x<4?((0x40004000)+((x)*0x1000)):((0x40024000)+((x-4)*0x1000)))

#elif GPIO_AHB
#error "Not Supported Yet"
#else 
#error "Please Choose Bus For GPIOs"
#define GPIO_OFFSET 0x40004000

#endif

/**
 * @defgroup GPIORegisters GPIO Registers
 * @{
 */
#define GPIODATA(x)     *((volatile uint32_t*)(GPIO_OFFSET(x)+0x3FC))   /* GPIO Data */
#define GPIODIR(x)      *((volatile uint32_t*)(GPIO_OFFSET(x)+0x400))   /* GPIO Direction */
#define GPIOIS(x)       *((volatile uint32_t*)(GPIO_OFFSET(x)+0x404))   /* GPIO Interrupt Sense */
#define GPIOIBE(x)      *((volatile uint32_t*)(GPIO_OFFSET(x)+0x408))   /* GPIO Interrupt Both Edges */
#define GPIOIEV(x)      *((volatile uint32_t*)(GPIO_OFFSET(x)+0x40C))   /* GPIO Interrupt Event */
#define GPIOIM(x)       *((volatile uint32_t*)(GPIO_OFFSET(x)+0x410))   /* GPIO Interrupt Mask */
#define GPIORIS(x)      *((volatile uint32_t*)(GPIO_OFFSET(x)+0x414))   /* GPIO Raw Interrupt Status */
#define GPIOMIS(x)      *((volatile uint32_t*)(GPIO_OFFSET(x)+0x418))   /* GPIO Masked Interrupt Status */
#define GPIOICR(x)      *((volatile uint32_t*)(GPIO_OFFSET(x)+0x41C))   /* GPIO Interrupt Clear */
#define GPIOAFSEL(x)    *((volatile uint32_t*)(GPIO_OFFSET(x)+0x420))   /* GPIO Alternate Function Select */
#define GPIODR2R(x)     *((volatile uint32_t*)(GPIO_OFFSET(x)+0x500))   /* GPIO 2mA Drive Select */
#define GPIODR4R(x)     *((volatile uint32_t*)(GPIO_OFFSET(x)+0x504))   /* GPIO 4mA Drive Select */
#define GPIODR8R(x)     *((volatile uint32_t*)(GPIO_OFFSET(x)+0x508))   /* GPIO 8mA Drive Select */
#define GPIOODR(x)      *((volatile uint32_t*)(GPIO_OFFSET(x)+0x50C))   /* GPIO Open Drain Select */
#define GPIOPUR(x)      *((volatile uint32_t*)(GPIO_OFFSET(x)+0x510))   /* GPIO Pull-up Select */
#define GPIOPDR(x)      *((volatile uint32_t*)(GPIO_OFFSET(x)+0x514))   /* GPIO Pull-down Select */
#define GPIOSLR(x)      *((volatile uint32_t*)(GPIO_OFFSET(x)+0x518))   /* GPIO Slew Rate Control Select */
#define GPIODEN(x)      *((volatile uint32_t*)(GPIO_OFFSET(x)+0x51C))   /* GPIO Digital Enable */
#define GPIOLOCK(x)     *((volatile uint32_t*)(GPIO_OFFSET(x)+0x520))   /* GPIO Lock */
#define GPIOCR(x)       *((volatile uint32_t*)(GPIO_OFFSET(x)+0x524))   /* GPIO Commit */
#define GPIOAMSEL(x)    *((volatile uint32_t*)(GPIO_OFFSET(x)+0x528))   /* GPIO Analog Mode Select */
/**@}*/

#define RCGCGPIO        *((volatile uint32_t*)(0x400FE608))             /* GPIO Run Mode Clock */
