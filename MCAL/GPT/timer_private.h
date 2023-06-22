#ifndef TIMER_PRIVATE_H_
#define TIMER_PRIVATE_H_

#define RCGCTIMER           *((volatile uint32*)(0x400FE604))

#define TIMER0_BASE_ADDRESS *((volatile uint32*)(0x40030000))
#define TIMER1_BASE_ADDRESS *((volatile uint32*)(0x40031000))
#define TIMER2_BASE_ADDRESS *((volatile uint32*)(0x40032000))
#define TIMER3_BASE_ADDRESS *((volatile uint32*)(0x40033000))
#define TIMER4_BASE_ADDRESS *((volatile uint32*)(0x40034000))
#define TIMER5_BASE_ADDRESS *((volatile uint32*)(0x40035000))

#define TIMER_OFFSET(x)     ((0x40030000)+((x)*0x1000))

#define GPTMCFG(x)          *((volatile uint32*)(TIMER_OFFSET(x)+0x000)) /* GPT Configuration register */
#define GPTMTAMR(x)         *((volatile uint32*)(TIMER_OFFSET(x)+0x004)) /* GPT Timer A */
#define GPTMCTL(x)          *((volatile uint32*)(TIMER_OFFSET(x)+0x00C)) /* GPT Control register */
#define GPTMIMR(x)          *((volatile uint32*)(TIMER_OFFSET(x)+0x018)) /* GPT interrupt mask register */
#define GPTMRIS(x)          *((volatile uint32*)(TIMER_OFFSET(x)+0x01C)) /* GPT raw interrupt status */
#define GPTMTAILR(x)        *((volatile uint32*)(TIMER_OFFSET(x)+0x028)) /* GPT Timer A interval load value */
#define GPTMTAPR(x)         *((volatile uint32*)(TIMER_OFFSET(x)+0x038)) /* GPT Timer A prescaler value */
#define GPTMTAR(x)          *((volatile uint32*)(TIMER_OFFSET(x)+0x048)) /* GPT Timer A current value */
#define GPTMICR(x)          *((volatile uint32*)(TIMER_OFFSET(x)+0x024)) /* GPT Interrupt clear register */


/**
 * @defgroup GPTMTAMR GPT Timer A Bits
 * @{
 */
#define TAMR0   0   /* Timer A mode */
#define TAMR1   1   /* Timer A mode */
#define TACDIR  4   /* Count direction bit */
#define TALID   8   /* Timer A interval load value */
/**@}*/

/**
 * @defgroup GPTMCTL GPT control register bits.
 * @{
 */
#define TAEN    0   /* Timer A enable */
/**@}*/

/**
 * @defgroup GPTMRIS GPT raw interrupt status.
 * @{
 */
#define TATORIS 0 /* Time-out raw interrupt flag */
/**@}*/

/**
 * @defgroup GPTMICR GPT interrupt clear bits.
 * @{
 */
#define TATOCINT    0   /* GPTM Timer A Time-Out Raw Interrupt */
/**@}*/

#endif /* TIMER_PRIVATE_H_ */
