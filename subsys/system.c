#include "system.h"
#include "types.h"
#include "register.h"



void config_systemclock(void){
    //config the system clock and set it to 84Mhz

    // config the flash registers
    FLASH_ACR_R->PRFTEN     = 0x01U;
    FLASH_ACR_R->ICEN       = 0x01U;
    FLASH_ACR_R->DCEN       = 0x01U;

    RCC_APB1ENR_R->PWR_EN    = 0x01U;   // enable clock for power
    
    FLASH_ACR_R->LATENCY    = 0x01;
    PWR_CR_R->VOS           = 0x02;     // set voltage scaling to 2
    RCC_CR_R->HSEON         = 0x1;      // enable HSE(high speed external clock).
    while(!RCC_CR_R->HSERDY);           // wait for HSE to come up

    RCC_PLLCFGR_R->PLLSRC   = 0x1;      // set clock source as HSE clock.

    RCC_PLLCFGR_R->PLLM     = 0x19;     // for dividing system clock(25MHz) by 25(0x1A) to get 1MHz.
    RCC_PLLCFGR_R->PLLN     = 0xA8;     // for multiplying the value in PLLM by 168 to get to 168 MHz.
    RCC_PLLCFGR_R->PLLP     = 0x0;      // this is to divide PLLM by 2 to get 84MHz.
    RCC_PLLCFGR_R->PLLQ     = 0x4;

    RCC_CR_R->PLLON         = 0x01U;  // enable PLL
    while(RCC_CR_R->PLLRDY);
    while(!PWR_CSR_R->VOSRDY == 0);

    RCC_CFGR_R->HPRE        = 0x0;      // set AHB prescaler(AHB) to 0.
    RCC_CFGR_R->PPRE1       = 0x4;      // set APB prescaler(APB1) to 4 to divide it by 2.
    RCC_CFGR_R->PPRE2       = 0x0;      // set APB prescaler(APB2) to 0 to divide it by 1.

    RCC_CFGR_R->SW          = 0x2;      // set system clock as PLL
    while(RCC_CFGR_R->SWS != 0x2);
}

