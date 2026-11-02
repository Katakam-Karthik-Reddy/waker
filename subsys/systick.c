#include <stdint.h>

#include "systick.h"
#include "core.h"
#include "uart.h"
#include "utils.h"
#include "system.h"
#include "app.h"

volatile uint32_t MS_TICKS = 0;

void SysTick_Handler(void){
    // for every ISR increment the variable(triggered every ms).
    MS_TICKS++;
    mainSV_Handler();
}


void config_systick(void){
    MS_TICKS = 0;

    // disable the systick for a movement, while configuring the systick.
    SYST_CSR_R->ENABLE          = 0x0U;
    // for every clock cycle this value will get decresed, when this get to 0 one ms is done.
    SYST_RVR_R->RELOAD          = (84000000/1000U) - 1U;

    // set the counter value to 0
    SYST_CVR_R->CURRENT         = 0x0U;
    // SYST_CSR_R->COUNTFLAG       = 0x01U;
    // enable clock source
    SYST_CSR_R->CLOCKSOURCE     = 0x01U;
    // enable the interrupt
    SYST_CSR_R->TICKINT         = 0x01U;
    // enable the systick
    SYST_CSR_R->ENABLE          = 0x01U;
}

void delay_ms(uint32_t ms){
    uint32_t start = MS_TICKS;
    while((MS_TICKS - start) < ms){
        __asm volatile ("wfi");
    }
}