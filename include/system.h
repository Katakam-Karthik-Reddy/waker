#ifndef SYSTEM_H
#define SYSTEM_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "register.h"


typedef struct {
    uint32_t TIM2_EN            :1;
    uint32_t TIM3_EN            :1;
    uint32_t TIM4_EN            :1;
    uint32_t TIM5_EN            :1;
    uint32_t Reserved_4_10      :7;
    uint32_t WWDG_EN            :1;
    uint32_t Reserved_12_13     :2;
    uint32_t SPI2_EN            :1;
    uint32_t SPI3_EN            :1;
    uint32_t Reserved_16        :1;
    uint32_t USART2_EN          :1;
    uint32_t Reserved_18_20     :3;
    uint32_t I2C1_EN            :1;
    uint32_t I2C2_EN            :1;
    uint32_t i2C3_EN            :1;
    uint32_t Reserved_24_27     :4;
    uint32_t PWR_EN             :1;
    uint32_t Reserved_29_31     :3;
} RCC_APB1EN_T;

typedef struct {
    uint32_t GPIOA_EN           :1;
    uint32_t GPIOB_EN           :1;
    uint32_t GPIOC_EN           :1;
    uint32_t GPIOD_EN           :1;
    uint32_t GPIOE_EN           :1;
    uint32_t Reserved_5_6       :2;
    uint32_t GPIOH_EN           :1;
    uint32_t Reserved_8_11      :4;
    uint32_t CRC_EN             :1;
    uint32_t Reserved_13_20     :8;
    uint32_t DMA1_EN            :1;
    uint32_t DMA2_EN            :1;
    uint32_t Reserved_23_31     :9;
} RCC_AHB1EN_T;

typedef struct {
    uint32_t TIM1_EN            :1;
    uint32_t Reserved_1_3       :3;
    uint32_t USART1_EN          :1;
    uint32_t USART6_EN          :1;
    uint32_t Reserved_6_7       :2;
    uint32_t ADC1_EN            :1;
    uint32_t Reserved_9_10      :2;
    uint32_t SDIO_EN            :1;
    uint32_t SPI1_EN            :1;
    uint32_t SPI4_EN            :1;
    uint32_t SYSCFG_EN          :1;
    uint32_t Reserved_15        :1;
    uint32_t TIM9_EN            :1;
    uint32_t TIM10_EN           :1;
    uint32_t TIM11_EN           :1;
    uint32_t Reserved_19_31     :13;
} RCC_APB2EN_T;

typedef struct {
    uint32_t EXTI0              :4;
    uint32_t EXTI1              :4;
    uint32_t EXTI2              :4;
    uint32_t EXTI3              :4;
    uint32_t Reserved_16_31     :16;
} SYSCFG_EXTCR1_T;



typedef struct {
    uint32_t MR0                :1;
    uint32_t MR1                :1;
    uint32_t MR2                :1;
    uint32_t MR3                :1;
    uint32_t MR4                :1;
    uint32_t MR5                :1;
    uint32_t MR6                :1;
    uint32_t MR7                :1;
    uint32_t MR8                :1;
    uint32_t MR9                :1;
    uint32_t MR10               :1;
    uint32_t MR11               :1;
    uint32_t MR12               :1;
    uint32_t MR13               :1;
    uint32_t MR14               :1;
    uint32_t MR15               :1;
    uint32_t MR16               :1;
    uint32_t MR17               :1;
    uint32_t MR18               :1;
    uint32_t Reserved_19_20     :2;
    uint32_t MR21               :1;
    uint32_t MR22               :1;
    uint32_t Reseved_23_31      :9;
} EXTI_IMR_T;


typedef struct {
    uint32_t TR0                :1;
    uint32_t TR1                :1;
    uint32_t TR2                :1;
    uint32_t TR3                :1;
    uint32_t TR4                :1;
    uint32_t TR5                :1;
    uint32_t TR6                :1;
    uint32_t TR7                :1;
    uint32_t TR8                :1;
    uint32_t TR9                :1;
    uint32_t TR10               :1;
    uint32_t TR11               :1;
    uint32_t TR12               :1;
    uint32_t TR13               :1;
    uint32_t TR14               :1;
    uint32_t TR15               :1;
    uint32_t TR16               :1;
    uint32_t TR17               :1;
    uint32_t TR18               :1;
    uint32_t Reserved_19_20     :2;
    uint32_t TR21               :1;
    uint32_t TR22               :1;
    uint32_t Reseved_23_31      :9;
} EXTI_RTSR_T;

typedef struct {
    uint32_t TR0                :1;
    uint32_t TR1                :1;
    uint32_t TR2                :1;
    uint32_t TR3                :1;
    uint32_t TR4                :1;
    uint32_t TR5                :1;
    uint32_t TR6                :1;
    uint32_t TR7                :1;
    uint32_t TR8                :1;
    uint32_t TR9                :1;
    uint32_t TR10               :1;
    uint32_t TR11               :1;
    uint32_t TR12               :1;
    uint32_t TR13               :1;
    uint32_t TR14               :1;
    uint32_t TR15               :1;
    uint32_t TR16               :1;
    uint32_t TR17               :1;
    uint32_t TR18               :1;
    uint32_t Reserved_19_20     :2;
    uint32_t TR21               :1;
    uint32_t TR22               :1;
    uint32_t Reseved_23_31      :9;
} EXTI_FTSR_T;

typedef struct {
    uint32_t PR0                :1;
    uint32_t PR1                :1;
    uint32_t PR2                :1;
    uint32_t PR3                :1;
    uint32_t PR4                :1;
    uint32_t PR5                :1;
    uint32_t PR6                :1;
    uint32_t PR7                :1;
    uint32_t PR8                :1;
    uint32_t PR9                :1;
    uint32_t PR10               :1;
    uint32_t PR11               :1;
    uint32_t PR12               :1;
    uint32_t PR13               :1;
    uint32_t PR14               :1;
    uint32_t PR15               :1;
    uint32_t PR16               :1;
    uint32_t PR17               :1;
    uint32_t PR18               :1;
    uint32_t Reserved_19_20     :2;
    uint32_t PR21               :1;
    uint32_t PR22               :1;
    uint32_t Reseved_23_31      :9;
} EXTI_PR_T;

typedef struct {
    uint32_t LATENCY            :4;
    uint32_t Reserved_4_7       :4;
    uint32_t PRFTEN             :1;
    uint32_t ICEN               :1;
    uint32_t DCEN               :1;
    uint32_t ICRST              :1;
    uint32_t DCRST              :1;
    uint32_t Reserved_13_31     :19;
} FLASH_ACR_T;

typedef struct {
    uint32_t LPDS               :1;
    uint32_t PDDS               :1;
    uint32_t CWUF               :1;
    uint32_t CSBF               :1;
    uint32_t PVDE               :1;
    uint32_t PLS                :3;
    uint32_t DBP                :1;
    uint32_t FPDS               :1;
    uint32_t LPLVDS             :1;
    uint32_t MRLVDS             :1;
    uint32_t Reserved_12        :1;
    uint32_t ADCDC1             :1;
    uint32_t VOS                :2;
    uint32_t Reserved_16_31     :16; 
} PWR_CR_T;

typedef struct {
    uint32_t WUF                :1;
    uint32_t SBF                :1;
    uint32_t PVDO               :1;
    uint32_t BRR                :1;
    uint32_t Reserved_4_7       :4;
    uint32_t EWUP               :1;
    uint32_t BRE                :1;
    uint32_t Reserved_10_13     :4;
    uint32_t VOSRDY             :1;
    uint32_t Reserved_15_31     :17;
} PWR_CSR_T;

typedef struct {
    uint32_t HSION              :1;
    uint32_t HSIRDY             :1;
    uint32_t Reserved_2         :1;
    uint32_t HSITRIM            :5;
    uint32_t HSICAL             :8;
    uint32_t HSEON              :1;
    uint32_t HSERDY             :1;
    uint32_t HSEBYP             :1;
    uint32_t CSSON              :1;
    uint32_t Reserved_20_23     :4;
    uint32_t PLLON              :1;
    uint32_t PLLRDY             :1;
    uint32_t PLLI2SON           :1;
    uint32_t PLLI2SRDY          :1;
    uint32_t Reserved_28_31     :4;
} RCC_CR_T;

typedef struct {
    uint32_t PLLM               :6;
    uint32_t PLLN               :9;
    uint32_t Reserved_15        :1;
    uint32_t PLLP               :2;
    uint32_t Reserved_18_21     :4;
    uint32_t PLLSRC             :1;
    uint32_t Reserved_23        :1;
    uint32_t PLLQ               :4;
    uint32_t Reserved_28_31     :4;
} RCC_PLLCFGR_T;

typedef struct {
    uint32_t SW                 :2;
    uint32_t SWS                :2;
    uint32_t HPRE               :4;
    uint32_t Reserved_8_9       :2;
    uint32_t PPRE1              :3;
    uint32_t PPRE2              :3;
    uint32_t RTCPRE             :5;
    uint32_t MCO1               :2;
    uint32_t I2SSCR             :1;
    uint32_t MCO1_PRE           :3;
    uint32_t MCO2_PRE           :3;
    uint32_t MCO2               :2;
} RCC_CFGR_T;

typedef struct {
    uint32_t LSEON              :1;
    uint32_t LSERDY             :1;
    uint32_t LSEBYP             :1;
    uint32_t Reserved_3_7       :5;
    uint32_t RTCSEL             :2;
    uint32_t Reserved_10_14     :5;
    uint32_t RTCEN              :1;
    uint32_t BDRST              :1;
    uint32_t Reserverd_17_31    :15;
} RCC_BDCR_T;

typedef struct {
    uint32_t LSION              :1;
    uint32_t LSIRDY             :1;
    uint32_t Reserved_2_23      :21;
    uint32_t RMVF               :1;
    uint32_t BORRSTF            :1;
    uint32_t PINRSTF            :1;
    uint32_t PORRSTF            :1;
    uint32_t SFTRSTF            :1;
    uint32_t IWDGRSTF           :1;
    uint32_t WWDGRSTF           :1;
    uint32_t LPWRRSTF           :1;
} RCC_CSR_T;


/******************************************************************************
 * defination with register value set
*****************************************************************************/

// APB1 register
#define RCC_APB1ENR_R               ((volatile RCC_APB1EN_T*)RCC_APB1ENR)

// power registers
#define PWR_CR_R                    ((volatile PWR_CR_T*)(PWR_CR))

#define PWR_CSR_R                   ((volatile PWR_CSR_T*)(PWR_CSR))

// APB2 register
#define RCC_APB2ENR_R               ((volatile RCC_APB2EN_T*)RCC_APB2ENR)

// 7.2.3 SYSCFG_EXTICR1 register 
#define SYSCFG_EXTICR1_R            ((volatile SYSCFG_EXTCR1_T*)SYSCFG_EXTICR1)

// 10.3.1 interrupt mask register
#define EXTI_IMR_R                  ((volatile EXTI_IMR_T *)EXTI_IMR)

// 10.3.3 Rising trigger selection register
#define EXTI_RTSR_R                 ((volatile EXTI_RTSR_T *)EXTI_RTSR)

// 10.3.4 Falling trigger selection register
#define EXTI_FTSR_R                 ((volatile EXTI_FTSR_T *)EXTI_FTSR)

// 10.3.6 Pending register
#define EXTI_PR_R                   ((volatile EXTI_PR_T *)EXTI_PR)

// AHB1 register
#define RCC_AHB1ENR_R               ((volatile RCC_AHB1EN_T*)(RCC_AHB1ENR))

// Flash register
#define FLASH_ACR_R                 ((volatile FLASH_ACR_T*)(FLASH_ACR))

// RCC register
#define RCC_CR_R                    ((volatile RCC_CR_T*)(RCC_CR))

#define RCC_PLLCFGR_R               ((volatile RCC_PLLCFGR_T*)(RCC_PLLCFGR))

#define RCC_CFGR_R                  ((volatile RCC_CFGR_T*)(RCC_CFGR))

#define RCC_BDCR_R                  ((volatile RCC_BDCR_T*)(RCC_BDCR))

#define RCC_CSR_R                   ((volatile RCC_CSR_T*)(RCC_CSR))

void config_systemclock(void);

__attribute__((always_inline)) static inline void __enable_irq(void) {
    __asm volatile ("cpsie i" : : : "memory");
}

__attribute__((always_inline)) static inline void __disable_irq(void) {
    __asm volatile ("cpsid i" : : : "memory");
}

#ifdef __cplusplus
}
#endif

#endif