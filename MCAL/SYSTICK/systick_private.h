#ifndef SYSTICK_PRIVATE_H_
#define SYSTICK_PRIVATE_H_

#define SYSTICK_BASE_ADR 0xE000E000

#define STCTRL      *((volatile uint32*)(SYSTICK_BASE_ADR+0x010)) /* SysTick Control and Status Register */
#define STRELOAD    *((volatile uint32*)(SYSTICK_BASE_ADR+0x014)) /* SysTick Reload Value Register */
#define STCURRENT   *((volatile uint32*)(SYSTICK_BASE_ADR+0x018)) /* SysTick Current Value Register */

#define ENABLE_IDX 0
#define INTEN_IDX 1
#define CLK_SRC_IDX 2
#define COUNT_IDX 16


#endif /* SYSTICK_PRIVATE_H_ */
