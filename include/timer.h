#ifndef TIMER_H
#define TIMER_H


#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "register.h"
#include <stdbool.h>


#define DEBOUNCE_MS     250  // this 250 ms for button debounce issue


/*****************************************************************************
* typedef differnt resigters
*****************************************************************************/

typedef struct {
    uint32_t CEN            :1;
    uint32_t UDIS           :1;
    uint32_t URS            :1;
    uint32_t OPM            :1;
    uint32_t DIR            :1;
    uint32_t CMS            :2;
    uint32_t ARPE           :1;
    uint32_t CKD            :2;
    uint32_t Reserved_11_16 :6;
} TIM_CR1_T;

typedef struct {
    uint32_t SMS            :3;
    uint32_t Reserved_3     :1;
    uint32_t TS             :3;
    uint32_t MSM            :1;
    uint32_t ETF            :4;
    uint32_t ETPS           :2;
    uint32_t ECE            :1;
    uint32_t ETP            :1;
} TIM_SMCR_T;


typedef struct {
    uint32_t CC1S           :2;
    uint32_t OC1FE          :1;
    uint32_t OC1PE          :1;
    uint32_t OC1M           :3;
    uint32_t OC1CE          :1;
    uint32_t CC2S           :2;
    uint32_t OC2FE          :1;
    uint32_t OC2PE          :1;
    uint32_t OC2M           :3;
    uint32_t OC2CE          :1;
} TIM_CCMR1_T;

typedef struct {
    uint32_t CC1E           :1;
    uint32_t CC1P           :1;
    uint32_t Reserved_2     :1;
    uint32_t CC1NP          :1;
    uint32_t CC2E           :1;
    uint32_t CC2P           :1;
    uint32_t Reserved_6     :1;
    uint32_t CC2NP          :1;
    uint32_t CC3E           :1;
    uint32_t CC3P           :1;
    uint32_t Reserved_10    :1;
    uint32_t CC3NP          :1;
    uint32_t CC4E           :1;
    uint32_t CC4P           :1;
    uint32_t Reserved_14    :1;
    uint32_t CC4NP          :1;
} TIM_CCER_T;

typedef struct {
    uint32_t ARR            :32;
} TIM_ARR_T;

typedef struct {
    uint32_t CNT            :32;
} TIM_CNT_T;

typedef struct {
    uint32_t PSC            :16;
    uint32_t Reserved_17_31 :16;
}  TIM_PSC_T;

typedef struct {
    uint32_t CCR1           :32;
} TIM_CCR1_T;

/*****************************************************************************
* defination with register value set
*****************************************************************************/

// timer 2

#define TIM2_SMCR_R                 ((volatile TIM_SMCR_T*)(TIM2_SMCR))

#define TIM2_CCMR1_R                ((volatile TIM_CCMR1_T*)(TIM2_CCMR1))

#define TIM2_CCER_R                 ((volatile TIM_CCER_T*)(TIM2_CCER))

#define TIM2_ARR_R                  ((volatile TIM_ARR_T*)(TIM2_ARR))

#define TIM2_CNT_R                  ((volatile TIM_CNT_T*)(TIM2_CNT))

#define TIM2_CR1_R                  ((volatile TIM_CR1_T*)(TIM2_CR1))

// timer 3

#define TIM3_SMCR_R                 ((volatile TIM_SMCR_T*)(TIM3_SMCR))

#define TIM3_CCMR1_R                ((volatile TIM_CCMR1_T*)(TIM3_CCMR1))

#define TIM3_CCER_R                 ((volatile TIM_CCER_T*)(TIM3_CCER))

#define TIM3_CNT_R                  ((volatile TIM_CNT_T*)(TIM3_CNT))

#define TIM3_CR1_R                  ((volatile TIM_CR1_T*)(TIM3_CR1))

#define TIM3_PSC_R                  ((volatile TIM_PSC_T*)(TIM3_PSC))

#define TIM3_ARR_R                  ((volatile TIM_ARR_T*)(TIM3_ARR))

#define TIM3_CCR1_R                 ((volatile TIM_CCR1_T*)(TIM3_CCR1))

/******************************************************************************
 * functions
 *****************************************************************************/

void setup_rotary_encoder_as_ISR(void);

void setup_encoder();

void EXTI0_IRQHandler(void) __attribute__((interrupt));

void EXTI1_IRQHandler(void) __attribute__((interrupt));

void EXTI2_IRQHandler(void) __attribute__((interrupt));

int32_t get_counter_value();

int32_t get_counter_direction();

void setup_servo(void);

#ifdef __cplusplus
}
#endif

#endif  /* TIMER_H */