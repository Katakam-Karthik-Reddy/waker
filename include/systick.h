#ifndef SYSTICK_H
#define SYSTICK_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>


extern volatile uint32_t MS_TICKS;

/**
 * @brief ISR for incrementing the MS_TICKS
 * @param void
 * @return void
 */
void SysTick_Handler(void);

/**
 * @brief config the systick registers
 * 
 * @param none
 * @return * void 
 */
void config_systick(void);

/**
 * @brief wait for time to elapse for a given time
 * @param value in milliseconds
 * @return void
 */
void delay_ms(uint32_t ms);

#ifdef __cplusplus
}
#endif

#endif // SYSTICK_H