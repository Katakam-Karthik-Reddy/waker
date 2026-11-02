#include <stdbool.h>

#include "gpio.h"
#include "types.h"
#include "timer.h"
#include "system.h"
#include "core.h"
#include "utils.h"
#include "gpio.h"
#include "app.h"
#include "systick.h"


static uint32_t rotary_press_last_ms = 0;

void setup_rotary_encoder_as_ISR(void){

    // enable GPIO A
    enable_GPIO_ports('A');

    // setting up the GPIO pin PA2
    GPIO_A_MODER_R->MODER2          = INPUT;
    GPIO_A_OSPEEDR_R->OSPEEDR2      = VERY_HIGH_SPEED;
    GPIO_A_PUPDR_R->PUPDR2          = PULL_UP;

    // Enabling the clock for syscfg
    if(RCC_APB2ENR_R->SYSCFG_EN != 0x1U){
        RCC_APB2ENR_R->SYSCFG_EN = 0x01U;
    }

    // enable interrupt for PA0
    SYSCFG_EXTICR1_R->EXTI0     = 0x0000;
    EXTI_IMR_R->MR0             = 0x01U;
    EXTI_RTSR_R->TR0            = 0x01U;
    EXTI_FTSR_R->TR0            = 0x01U;
    NVIC_IPR_R[6]               = 0x0U;
    NVIC_ISER_R[0]              = 0x1U << 6U;

    // enable interrupt for PA1
    SYSCFG_EXTICR1_R->EXTI1     = 0x0000;
    EXTI_IMR_R->MR1             = 0x01U;
    EXTI_RTSR_R->TR1            = 0x01U;
    EXTI_FTSR_R->TR1            = 0x01U;
    NVIC_IPR_R[7]               = 0x0U;
    NVIC_ISER_R[0]              = 0x1U << 7U;

    // enable interrupt for PA2
    SYSCFG_EXTICR1_R->EXTI2     = 0x0000;
    EXTI_IMR_R->MR2             = 0x01U;
    EXTI_FTSR_R->TR2            = 0x01U;
    EXTI_RTSR_R->TR2            = 0x00U;
    NVIC_IPR_R[8]               = 0x0U; // set the priority of the interrupt
    NVIC_ISER_R[0]              = 0x1U << 8U;   // enable the interrupt

    *AIRCR_R                    = (AIRCR_T){.VECTKEY=0x5FA, .PRIGROUP=3};
}


void EXTI0_IRQHandler(void){
    if(EXTI_PR_R->PR0 != 0x0U){
        EXTI_PR_R->PR0          = 0x1U;
        rotary_change_Handler();
    }
}

void EXTI1_IRQHandler(void){
    if(EXTI_PR_R->PR1 != 0x0U){
        EXTI_PR_R->PR1          = 0x1U;
        rotary_change_Handler();
    }
}

void EXTI2_IRQHandler(void){
    uint32_t now = MS_TICKS;
    if((now - rotary_press_last_ms) < DEBOUNCE_MS){
        // writef("this waste interrupt");
        EXTI_PR_R->PR2          = 0x01U;
        return;
    }
    rotary_press_last_ms = MS_TICKS;
    if(EXTI_PR_R->PR2 != 0x0U){
        EXTI_PR_R->PR2          = 0x01U;
        // writef("pressed on tick %d", MS_TICKS);
        rotary_button_press_Handler();
    }
}

void setup_encoder(){
    
    // enable GPIO A
    enable_GPIO_ports('A');
    
    // this is for rotoary encoder input channels
    GPIO_A_MODER_R->MODER0          = ALTERNATE_FUNCTION;
    GPIO_A_MODER_R->MODER1          = ALTERNATE_FUNCTION;
    GPIO_A_OSPEEDR_R->OSPEEDR0      = VERY_HIGH_SPEED;
    GPIO_A_OSPEEDR_R->OSPEEDR1      = VERY_HIGH_SPEED;
    GPIO_A_PUPDR_R->PUPDR0          = PULL_UP;
    GPIO_A_PUPDR_R->PUPDR1          = PULL_UP;
    GPIO_A_AFRL_R->AFRL0            = AF1;
    GPIO_A_AFRL_R->AFRL1            = AF1;

    // setting the register for time2 and config as encoder_mode 3
    RCC_APB1ENR_R->TIM2_EN          = 0x01U; // enable the timer
    TIM2_SMCR_R->SMS                = Encoder_mode_3; // make it as encoder mode 3 (read both ways)
    TIM2_CCMR1_R->CC1S              = IC1_TI1; // map the input channel 1 to Timer input channel 1
    TIM2_CCMR1_R->CC2S              = IC2_TI2; // map the input channel 2 to Timer input channel 2
    TIM2_CCER_R->CC1P               = NON_INVERTED_RISING_EDGE; // set to rising edge and non inverted
    TIM2_CCER_R->CC2P               = NON_INVERTED_RISING_EDGE; // set to rising edge and non inverted

    TIM2_ARR_R->ARR                 = 0xFFFFFFFF; // set 4,294,967,295 as auto reload register
    TIM2_CNT_R->CNT                 = 0; // set the initial counter value to 0

    TIM2_CR1_R->CEN                 = 0x01U; // enable the counter

    setup_rotary_encoder_as_ISR();
}


int32_t get_counter_value(){
    return TIM2_CNT_R->CNT/2;
}

int32_t get_counter_direction(){
    return TIM2_CR1_R->DIR;
}


void setup_servo(void){
    // enable GPIO A
    enable_GPIO_ports('A');

    // this is for rotoary encoder input channels PA6
    GPIO_A_MODER_R->MODER6          = ALTERNATE_FUNCTION;
    GPIO_A_OSPEEDR_R->OSPEEDR6      = HIGH_SPEED;
    GPIO_A_AFRL_R->AFRL6            = AF2;

    // enable the TIM3
    RCC_APB1ENR_R->TIM3_EN          = 0x01U;

    // config the timer clock and ARR 
    TIM3_PSC_R->PSC                 = 42-1;  // 84MHz / 84 = 1 MHz
    TIM3_ARR_R->ARR                 = 20000-1;

    // config the TIM3 channel 1 as PWM Mode 1
    TIM3_CCMR1_R->CC1S              = 0x00U;
    TIM3_CCMR1_R->OC1M              = 0x06U;
    TIM3_CCMR1_R->OC1PE             = 0x01U;

    TIM3_CCER_R->CC1E               = 0x01U;
    TIM3_CR1_R->ARPE                = 0x01U;
    TIM3_CR1_R->CEN                 = 0x01U;

    TIM3_CCR1_R->CCR1               = 900;
}