#ifndef REGISTER_H
#define REGISTER_H

#ifdef __cplusplus
extern "C" {
#endif

// Peripheral Base
#define PERIPHERAL_BASE                                 0x40000000U

// APB1 Offset
#define APB1_OFFSET                                     0x0U

// APB2 Offset
#define APB2_OFFSET                                     0x7400U

// AHB1 Offset
#define AHB1_OFFSET                                     0x20000U

// AHB2 Offset
#define AHB2_OFFSET                                     0x10000000U

/******************************* FLASH regiters *************************************/

// 3.8 Flash interface register

// Flash interface register Offset
#define FLASH_INTERFACE_REGISTER_OFFSET                 0x3C00U

// Flash access control register Offset
#define FLASH_ACR_OFFSET                                0x00

// Flash key register Offset
#define FLASH_KEYR_OFFSET                               0x04

// Flash option key register Offset
#define FLASH_OPTKEYR_OFFSET                            0x08

// Flash status register Offset
#define FLASH_SR_OFFSET                                 0x0C

// Flash control register Offset
#define FLASH_CR_OFFSET                                 0x10

// Flash option control register Offset
#define FLASH_OPTCR_OFFSET                              0x14

/******************************* PWR address **********************************/

// 5.4 Power control register

// PWR Offset
#define PWR_OFFSET                                      0x7000U

// PWR power control register Offset
#define PWR_CR_OFFSET                                   0x00U

// PWR power control/status register Offset
#define PWR_CSR_OFFSET                                  0x04U

/******************************* RCC address **********************************/

// 6.3 RCC register

// RCC Offset
#define RCC_OFFSET                                      0x3800U

// RCC clock control register offset
#define RCC_CR_OFFSET                                   0x00U

// RCC PLL configuration register offset
#define RCC_PLLCFGR_OFFSET                              0x04U

// RCC clock configuration register offset
#define RCC_CFGR_OFFSET                                 0x08U

// RCC clock interrput register offset
#define RCC_CIR_OFFSET                                  0x0CU

// RCC AHB1 peripheral reset register offset
#define RCC_AHB1RSTR_OFFSET                             0x10U

// RCC AHB2 peripheral reset register offset
#define RCC_AHB2RSTR_OFFSET                             0x14U

// RCC APB1 peripheral reset register offset
#define RCC_APB1RSTR_OFFSET                             0x20U

// RCC APB2 peripheral reset register offset
#define RCC_APB2RSTR_OFFSET                             0x24U

// RCC AHB1 peripheral clock enable register offset
#define RCC_AHB1ENR_OFFSET                              0x30U

// RCC AHB2 peripheral clock enable register offset
#define RCC_AHB2ENR_OFFSET                              0x34U

// RCC APB1 peripheral clock enable register offset
#define RCC_APB1ENR_OFFSET                              0x40U

// RCC APB2 peripheral clock enable register offset
#define RCC_APB2ENR_OFFSET                              0x44U

// RCC AHB1 peripheral clock enable in low power mode register offset
#define RCC_AHB1LPENR_OFFSET                            0x50U

// RCC AHB2 peripheral clock enable in low power mode register offset
#define RCC_AHB2LPENR_OFFSET                            0x54U

// RCC APB1 peripheral clock enable in low power mode register offset
#define RCC_APB1LPENR_OFFSET                            0x60U

// RCC APB2 peripheral clock enabled in low power mode register offset
#define RCC_APB2LPENR_OFFSET                            0x64U

// RCC Backup domain control register offset
#define RCC_BDCR_OFFSET                                 0x70U

// RCC clock control & status register offset
#define RCC_CSR_OFFSET                                  0x74U

// RCC spread spectrum clock generation register offset
#define RCC_SSCGR_OFFSET                                0x80U

// RCC PLLI2S configuration register offset
#define RCC_PLLI2SCFGR_OFFSET                           0x84U

// RCC Dedicated Clocks Configuration Register offset
#define RCC_DCKCFGR                                     0x8CU

/******************************* SYSCFG address ******************************************/

// SYSCFG external interrupt configuration register 1
#define SYSCFG_OFFSET                                   0xC400

// SYSCFG memory remap offset
#define SYSCFG_MEMRMP_OFFSET                            0x00U

// SYSCFG peripheral mode configuration offset
#define SYSCFG_PMC_OFFSET                               0x04U

// SYSCFG external interrupt configuration register 1 offset
#define SYSCFG_EXTICR1_OFFSET                           0x08U

// SYSCFG external interrupt configuration register 2 offset
#define SYSCFG_EXTICR2_OFFSET                           0x1CU

// SYSCFG external interrupt configuration register 3 offset
#define SYSCFG_EXTICR3_OFFSET                           0x10U

// SYSCFG external interrupt configuration register 4 offset
#define SYSCFG_EXTICR4_OFFSET                           0x14U

// Compensation cell control register offset
#define SYSCFG_CMPCR_OFFSET                             0x20U

/******************************* DMA address ******************************************/

// DMA 1 Offset
#define DMA1_OFFSET                                     0x6000U

// DMA 2 Offset
#define DMA2_OFFSET                                     0x6400U

// CRC Offset
#define CRC_OFFSET                                      0x3000U

/******************************* GPIO address ****************************************/

// 8.4 GPIO register

// GPIO A Offset
#define GPIOA_OFFSET                                    0x00U

// GPIO B Offset
#define GPIOB_OFFSET                                    0x400U

// GPIO C Offset
#define GPIOC_OFFSET                                    0x800U

// GPIO port mode register offset
#define GPIO_MODER_OFFSET                               0x00U

// GPIO port output type register offset
#define GPIO_OTYPER_OFFSET                              0x04U

// GPIO port output speed register offset
#define GPIO_OSPEEDR_OFFSET                             0x08U

// GPIO port pull-up or pull-down register offset
#define GPIO_PUPDR_OFFSET                               0x0CU

// GPIO port input data register offset
#define GPIO_IDR_OFFSET                                 0x10U

// GPIO port output data register offset
#define GPIO_ODR_OFFSET                                 0x14U

// GPIO port bit set/reset register offset
#define GPIO_BSRR_OFFSET                                0x18U

// GPIO port configuration lock register offset
#define GPIO_LCKR_OFFSET                                0x1CU

// GPIO port alternate function low register offset
#define GPIO_AFRL_OFFSET                                0x20U

// GPIO port alternate function high register offset
#define GPIO_AFRH_OFFSET                                0x24U

/******************************* EXTI regiters *************************************/

// 10.3 EXTI register
#define EXTI_OFFSET                                     0xC800

// Interrupt mask register
#define EXTI_IMR_OFFSET                                 0x00

// Event mask register
#define EXTI_EMR_OFFSET                                 0x04

// Rising trigger selection register
#define EXTI_RTSR_OFFSET                                0x08

// Falling trigger selection register
#define EXTI_FTSR_OFFSET                                0x0C

// Software interrupt event register
#define EXTI_SWIER_OFFSET                               0x10

// Pending register
#define EXTI_PR_OFFSET                                  0x14

/******************************* TIM regiters *************************************/

// 13.4 TIM2 to TIM5 register

// TIM2 Offset
#define TIM2_OFFSET                                     0x0U

// TIM3 Offset
#define TIM3_OFFSET                                     0x400U

// TIM4 Offset
#define TIM4_OFFSET                                     0x800U

// TIM5 Offset
#define TIM5_OFFSET                                     0xC00U

// TIMx_CR1 Offset
#define TIMx_CR1_OFFSET                                 0x00U

// TIMx_CR2 Offset
#define TIMx_CR2_OFFSET                                 0x04U

// TIMx_SMCR Offset
#define TIMx_SMCR_OFFSET                                0x08U

// TIMx_DIER Offset
#define TIMx_DIER_OFFSET                                0x0CU

// TIMx_SR Offset
#define TIMx_SR_OFFSET                                  0x10U

// TIMx_EGR Offset
#define TIMx_EGR_OFFSET                                 0x14U

// TIMx_CCMR1 Offset
#define TIMx_CCMR1_OFFSET                               0x18U

// TIMx_CCMR2 Offset
#define TIMx_CCMR2_OFFSET                               0x1CU

// TIMx_CCER Offset
#define TIMx_CCER_OFFSET                                0x20U

// TIMx_CNT Offset
#define TIMx_CNT_OFFSET                                 0x24U

// TIMx_PSC Offset
#define TIMx_PSC_OFFSET                                 0x28U

// TIMx_ARR Offset
#define TIMx_ARR_OFFSET                                 0x2CU

// TIMx_CCR1 Offset
#define TIMx_CCR1_OFFSET                                0x34U

// TIMx_CCR2 Offset
#define TIMx_CCR2_OFFSET                                0x38U

// TIMx_CCR3 Offset
#define TIMx_CCR3_OFFSET                                0x3CU

// TIMx_CCR4 Offset
#define TIMx_CCR4_OFFSET                                0x40U

// TIMx_DCR Offset
#define TIMx_DCR_OFFSET                                 0x48U

// TIMx_DMAR Offset
#define TIMx_DMAR_OFFSET                                0x4CU

// TIM2_OR Offset
#define TIM2_OR_OFFSET                                  0x50U

// TIM5_OR Offset
#define TIM5_OR_OFFSET                                  0x50U

/******************************* RTC regiters *************************************/

// 17.6 RTC registers
#define RTC_OFFSET                                      0x2800U

// RTC timer register
#define RTC_TR_OFFSET                                   0x0U

// RTC data register
#define RTC_DR_OFFSET                                   0x04U

// RTC control register
#define RTC_CR_OFFSET                                   0x08U

// RTC initialization and status register
#define RTC_ISR_OFFSET                                  0x0CU

// RTC prescaler register
#define RTC_PRER_OFFSET                                 0x10U

// RTC wake-up timer register
#define RTC_WUTR_OFFSET                                 0x14U

//RTC calibration register
#define RTC_CALIBR_OFFSET                               0x18U

// RTC alarm A register
#define RTC_ALRMAR_OFFSET                               0x1CU

// RTC alarm B register
#define RTC_ALRMBR_OFFSET                               0x20U

// RTC write proctection register
#define RTC_WPR_OFFSET                                  0x24U

// RTC sub second register
#define RTC_SSR_OFFSET                                  0x28U

// RTC shift control register
#define RTC_SHIFTR_OFFSET                               0x2CU

// RTC time stamp time register
#define RTC_TSTR_OFFSET                                 0x30U

// RTC time stamp data register
#define RTC_TSDR_OFFSET                                 0x34U

// RTC timestamp sub second register
#define RTC_TSSSR_OFFSET                                0x38U

// RTC calibration register
#define RTC_CALR_OFFSET                                 0x3CU

// RTC tamper and alternate function configuration register
#define RTC_TAFCR_OFFSET                                0x40

// RTC alarm A sub second register
#define RTC_ALRMASSR_OFFSET                             0x44

// RTC alarm B sub second register
#define RTC_ALRMBSSR_OFFSET                             0x48

// RTC backup registers
#define RTC_BKPxR_OFFSET                                0x50  // this goes till 0x9C

/******************************* I2C regiters *************************************/

// 18.6 I2C register

// I2C1 Offset
#define I2C1_OFFSET                                     0x5400U

// I2C_CR1 OFFSET
#define I2C_CR1_OFFSET                                  0x00U

// I2C_CR2 OFFSET
#define I2C_CR2_OFFSET                                  0x04U

// I2C_OAR1 OFFSET
#define I2C_OAR1_OFFSET                                 0x08U

// I2C_OAR2 OFFSET
#define I2C_OAR2_OFFSET                                 0x0CU

// I2C_DR OFFSET
#define I2C_DR_OFFSET                                   0x10U

// I2C_SR1 OFFSET
#define I2C_SR1_OFFSET                                  0x14U

// I2C_SR2 OFFSET
#define I2C_SR2_OFFSET                                  0x18U

// I2C_CCR OFFSET
#define I2C_CCR_OFFSET                                  0x1CU

// I2C_TRISE OFFSET
#define I2C_TRISE_OFFSET                                0x20U

// I2C_FLTR OFFSET
#define I2C_FLTR_OFFSET                                 0x24U

/******************************* UART1 regiters *************************************/

// 19.6 USART register

// USART1 Offset
#define USART1_OFFSET                                   0x9C00U

// USART_SR Offset
#define USART_SR_OFFSET                                 0x0U

// USART_DR Offset4

#define USART_DR_OFFSET                                 0x04U

// USART_BRR Offset
#define USART_BRR_OFFSET                                0x08U

// USART_CR1 Offset
#define USART_CR1_OFFSET                                0x0CU

// USART CR2 Offset
#define USART_CR2_OFFSET                                0x010U

//USART_CR3 Offset
#define USART_CR3_OFFSET                                0x014U

// USART_GTPR Offset
#define USART_GTPR_OFFSET                               0x08U

/******************************* Base address ******************************************/

// APB1 Base
#define APB1_BASE                                       ((PERIPHERAL_BASE)+(APB1_OFFSET))

// APB2 Base
#define APB2_BASE                                       ((PERIPHERAL_BASE)+(APB2_OFFSET))

// AHB1 Base
#define AHB1_BASE                                       ((PERIPHERAL_BASE)+(AHB1_OFFSET))

// AHB2 Base
#define AHB2_BASE                                       ((PERIPHERAL_BASE)+(AHB2_OFFSET))

// CRC Base
#define CRC_BASE                                        ((AHB1_BASE)+(CRC_OFFSET))

/******************************* DMA address ******************************************/

// DMA 1 Base
#define DMA1_BASE                                       ((AHB1_BASE)+(DMA1_OFFSET))

// DMA 2 Base
#define DMA2_BASE                                       ((AHB1_BASE)+(DMA2_OFFSET))

/******************************* PWR address **********************************/

// PWR Base
#define PWR_BASE                                        ((APB1_BASE)+(PWR_OFFSET))

// PWR power control register
#define PWR_CR                                          ((PWR_BASE)+(PWR_CR_OFFSET))

// PWR power control/status register 
#define PWR_CSR                                         ((PWR_BASE)+(PWR_CSR_OFFSET))

/******************************* RCC address **********************************/

// RCC Base
#define RCC_BASE                                        ((AHB1_BASE)+(RCC_OFFSET))

// RCC PLL configuration register 
#define RCC_CR                                          ((RCC_BASE)+(RCC_CR_OFFSET))

// RCC PLL configuration register 
#define RCC_PLLCFGR                                     ((RCC_BASE)+(RCC_PLLCFGR_OFFSET))

// RCC clock configuration register 
#define RCC_CFGR                                        ((RCC_BASE)+(RCC_CFGR_OFFSET))

// RCC Backup domain control register 0x40023870
#define RCC_BDCR                                        ((RCC_BASE)+(RCC_BDCR_OFFSET)) 

// RCC clock control & status register
#define RCC_CSR                                         ((RCC_BASE)+(RCC_CSR_OFFSET))

// RCC AHB1 peripheral clock enable register 0x40023830
#define RCC_AHB1ENR                                     ((RCC_BASE)+(RCC_AHB1ENR_OFFSET))

// RCC AHB2 peripheral clock enable register 0x40023834
#define RCC_AHB2ENR                                     ((RCC_BASE)+(RCC_AHB2ENR_OFFSET))

// RCC APB1 peripheral clock enable register  0x40023840
#define RCC_APB1ENR                                     ((RCC_BASE)+(RCC_APB1ENR_OFFSET))

// RCC APB2 peripheral clock enable register  0x40023844
#define RCC_APB2ENR                                     ((RCC_BASE)+(RCC_APB2ENR_OFFSET))

/******************************* SYSCFG address ******************************************/

// SYSCFG Base
#define SYSCFG_BASE                                     ((APB2_BASE)+(SYSCFG_OFFSET))

// SYSCFG memory remap register
#define SYSCFG_MEMRMP                                   ((SYSCFG_BASE)+(SYSCFG_MEMRMP_OFFSET))

// SYSCFG peripheral mode configuration register
#define SYSCFG_PMC                                      ((SYSCFG_BASE)+(SYSCFG_PMC_OFFSET))

// SYSCFG external interrupt configuration register 1 register
#define SYSCFG_EXTICR1                                  ((SYSCFG_BASE)+(SYSCFG_EXTICR1_OFFSET))

// SYSCFG external interrupt configuration register 2 register
#define SYSCFG_EXTICR2                                  ((SYSCFG_BASE)+(SYSCFG_EXTICR2_OFFSET))

// SYSCFG external interrupt configuration register 3 register
#define SYSCFG_EXTICR3                                  ((SYSCFG_BASE)+(SYSCFG_EXTICR3_OFFSET))

// SYSCFG external interrupt configuration register 4 register
#define SYSCFG_EXTICR4                                  ((SYSCFG_BASE)+(SYSCFG_EXTICR4_OFFSET))

// Compensation cell control register register
#define SYSCFG_CMPCR                                    ((SYSCFG_BASE)+(SYSCFG_CMPCR_OFFSET))

/******************************* FLASH address ******************************************/

// FLASH INTERFACE REGISTER Base
#define FLASH_INTERFACE_REGISTER_BASE                   ((AHB1_BASE)+(FLASH_INTERFACE_REGISTER_OFFSET))

// Flash access control register
#define FLASH_ACR                                       ((FLASH_INTERFACE_REGISTER_BASE)+(FLASH_ACR_OFFSET))

// Flash key register
#define FLASH_KEYR                                      ((FLASH_INTERFACE_REGISTER_BASE)+(FLASH_KEYR_OFFSET))

// Flash option key register
#define FLASH_OPTKEYR                                   ((FLASH_INTERFACE_REGISTER_BASE)+(FLASH_OPTKEYR_OFFSET))

// Flash status register
#define FLASH_SR                                        ((FLASH_INTERFACE_REGISTER_BASE)+(FLASH_SR_OFFSET))

// Flash control register
#define FLASH_CR                                        ((FLASH_INTERFACE_REGISTER_BASE)+(FLASH_CR_OFFSET))

// Flash option control register
#define FLASH_OPTCR                                     ((FLASH_INTERFACE_REGISTER_BASE)+(FLASH_OPTCR_OFFSET))

/******************************* GPIO address *****************************************/

//########### GPIO B #############//

// GPIO A Base
#define GPIOA_BASE                                      ((AHB1_BASE)+(GPIOA_OFFSET))

// GPIO A MODER register    0x40020000
#define GPIOA_MODER                                     ((GPIOA_BASE)+(GPIO_MODER_OFFSET))

// GPIO A OTYPER register    0x40020004
#define GPIOA_OTYPER                                     ((GPIOA_BASE)+(GPIO_OTYPER_OFFSET))

// GPIO A OSPEEDR register
#define GPIOA_OSPEEDR                                   ((GPIOA_BASE)+(GPIO_OSPEEDR_OFFSET))

// GPIO A PUPD register
#define GPIOA_PUPDR                                     ((GPIOA_BASE)+(GPIO_PUPDR_OFFSET))

// GPIO A IDR register      0x40020010
#define GPIOA_IDR                                       ((GPIOA_BASE)+(GPIO_IDR_OFFSET))

// GPIO A ODR register      0x40020014
#define GPIOA_ODR                                       ((GPIOA_BASE)+(GPIO_ODR_OFFSET))

// GPIO A AFRL register
#define GPIOA_AFRL                                      ((GPIOA_BASE)+(GPIO_AFRL_OFFSET))

// GPIO A AFRH register
#define GPIOA_AFRH                                      ((GPIOA_BASE)+(GPIO_AFRH_OFFSET))

//########### GPIO B #############//

// GPIO B Base
#define GPIOB_BASE                                      ((AHB1_BASE)+(GPIOB_OFFSET))

// GPIO B MODER register
#define GPIOB_MODER                                     ((GPIOB_BASE)+(GPIO_MODER_OFFSET))

// GPIO B OTYPER register
#define GPIOB_OTYPER                                     ((GPIOB_BASE)+(GPIO_OTYPER_OFFSET))

// GPIO B OSPEEDR register
#define GPIOB_OSPEEDR                                   ((GPIOB_BASE)+(GPIO_OSPEEDR_OFFSET))

// GPIO B PUPDR register
#define GPIOB_PUPDR                                     ((GPIOB_BASE)+(GPIO_PUPDR_OFFSET))

// GPIO A IDR register      
#define GPIOB_IDR                                       ((GPIOB_BASE)+(GPIO_IDR_OFFSET))

// GPIO B ODR register
#define GPIOB_ODR                                       ((GPIOB_BASE)+(GPIO_ODR_OFFSET))

// GPIO B AFRL register
#define GPIOB_AFRL                                      ((GPIOB_BASE)+(GPIO_AFRL_OFFSET))

// GPIO B AFRH register
#define GPIOB_AFRH                                      ((GPIOB_BASE)+(GPIO_AFRH_OFFSET))

//########### GPIO C #############//

// GPIO C Base
#define GPIOC_BASE                                      ((AHB1_BASE)+(GPIOC_OFFSET))

// GPIO C MODER register
#define GPIOC_MODER                                     ((GPIOC_BASE)+(GPIO_MODER_OFFSET))

// GPIO C OTYPER register
#define GPIOC_OTYPER                                     ((GPIOC_BASE)+(GPIO_OTYPER_OFFSET))

// GPIO C OSPEEDR register
#define GPIOC_OSPEEDR                                   ((GPIOC_BASE)+(GPIO_OSPEEDR_OFFSET))

// GPIO C PUPDR register
#define GPIOC_PUPDR                                     ((GPIOC_BASE)+(GPIO_PUPDR_OFFSET))

// GPIO A IDR register
#define GPIOC_IDR                                       ((GPIOC_BASE)+(GPIO_IDR_OFFSET))

// GPIO C ODR register
#define GPIOC_ODR                                       ((GPIOC_BASE)+(GPIO_ODR_OFFSET))

// GPIO C AFRL register
#define GPIOC_AFRL                                      ((GPIOC_BASE)+(GPIO_AFRL_OFFSET))

// GPIO C AFRH register
#define GPIOC_AFRH                                      ((GPIOC_BASE)+(GPIO_AFRH_OFFSET))

/******************************* DMA address ******************************************/


/******************************* EXTI address ******************************************/

// 10.3 EXTI register

// EXTI Base
#define EXTI_BASE                                       ((APB2_BASE)+(EXTI_OFFSET))

// Interrupt mask register
#define EXTI_IMR                                        ((EXTI_BASE)+(EXTI_IMR_OFFSET))

// Event mask register
#define EXTI_EMR                                        ((EXTI_BASE)+(EXTI_EMR_OFFSET))

// Rising trigger selection register
#define EXTI_RTSR                                       ((EXTI_BASE)+(EXTI_RTSR_OFFSET))

// Falling trigger selection register
#define EXTI_FTSR                                       ((EXTI_BASE)+(EXTI_FTSR_OFFSET))

// Software interrupt event register
#define EXTI_SWIER                                      ((EXTI_BASE)+(EXTI_SWIER_OFFSET))

// Pending register
#define EXTI_PR                                         ((EXTI_BASE)+(EXTI_PR_OFFSET))

/******************************* TIM regiters *************************************/

//########### TIMER 2 #############//

// TIM2 Base
#define TIM2_BASE                                       ((APB1_BASE)+(TIM2_OFFSET))

// TIM2_CR1 register 0x40000000
#define TIM2_CR1                                        ((TIM2_BASE)+(TIMx_CR1_OFFSET))

// TIM2_SMCR register 0x40000008
#define TIM2_SMCR                                       ((TIM2_BASE)+(TIMx_SMCR_OFFSET))

// TIM2_CCMR1 register 0x40000018
#define TIM2_CCMR1                                      ((TIM2_BASE)+(TIMx_CCMR1_OFFSET))

// TIM2_CCER register 0x40000020
#define TIM2_CCER                                       ((TIM2_BASE)+(TIMx_CCER_OFFSET))

// TIM2_ARR register 0x4000002C
#define TIM2_ARR                                        ((TIM2_BASE)+(TIMx_ARR_OFFSET))

// TIM2_CNT register 0x40000024
#define TIM2_CNT                                        ((TIM2_BASE)+(TIMx_CNT_OFFSET))

//########### TIMER 3 #############//

// TIM3 Base
#define TIM3_BASE                                       ((APB1_BASE)+(TIM3_OFFSET))

// TIM3_CR1 register
#define TIM3_CR1                                        ((TIM3_BASE)+(TIMx_CR1_OFFSET))

// TIM3_SMCR register
#define TIM3_SMCR                                       ((TIM3_BASE)+(TIMx_SMCR_OFFSET))

// TIM3_CCMR1 register
#define TIM3_CCMR1                                      ((TIM3_BASE)+(TIMx_CCMR1_OFFSET))

// TIM3_CCER register
#define TIM3_CCER                                       ((TIM3_BASE)+(TIMx_CCER_OFFSET))

// TIM3_CNT register
#define TIM3_CNT                                        ((TIM3_BASE)+(TIMx_CNT_OFFSET))

// TIM3_PSC register
#define TIM3_PSC                                        ((TIM3_BASE)+(TIMx_PSC_OFFSET))

// TIM3_ARR register
#define TIM3_ARR                                        ((TIM3_BASE)+(TIMx_ARR_OFFSET))

#define TIM3_CCR1                                       ((TIM3_BASE)+(TIMx_CCR1_OFFSET))

//########### TIMER 4 #############//

// TIM4 Base
#define TIM4_BASE                                       ((APB1_BASE)+(TIM4_OFFSET))

//########### TIMER 5 #############//

// TIM5 Base
#define TIM5_BASE                                       ((APB1_BASE)+(TIM5_OFFSET))

/******************************* RTC regiters *************************************/

// RTC Base
#define RTC_BASE                                        ((APB1_BASE)+(RTC_OFFSET))

// RTC_TR register
#define RTC_TR                                          ((RTC_BASE)+(RTC_TR_OFFSET))

// RTC_DR register
#define RTC_DR                                          ((RTC_BASE)+(RTC_DR_OFFSET))

// RTC_CR register
#define RTC_CR                                          ((RTC_BASE)+(RTC_CR_OFFSET))

// RTC_ISR register
#define RTC_ISR                                         ((RTC_BASE)+(RTC_ISR_OFFSET))

// RTC_PRER register
#define RTC_PRER                                        ((RTC_BASE)+(RTC_PRER_OFFSET))

// RTC_WUTR register
#define RTC_WUTR                                        ((RTC_BASE)+(RTC_WUTR_OFFSET))

// RTC_CALIBR register
#define RTC_CALIBR                                      ((RTC_BASE)+(RTC_CALIBR_OFFSET))

// RTC_ALRMAR register
#define RTC_ALRMAR                                      ((RTC_BASE)+(RTC_ALRMAR_OFFSET))

// RTC_ALRMBR register
#define RTC_ALRMBR                                      ((RTC_BASE)+(RTC_ALRMBR_OFFSET))

// RTC_WPR register
#define RTC_WPR                                         ((RTC_BASE)+(RTC_WPR_OFFSET))

// RTC_SSR register
#define RTC_SSR                                         ((RTC_BASE)+(RTC_SSR_OFFSET))

// RTC_SHIFTR register
#define RTC_SHIFTR                                      ((RTC_BASE)+(RTC_SHIFTR_OFFSET))

// RTC_TSTR register
#define RTC_TSTR                                        ((RTC_BASE)+(RTC_TSTR_OFFSET))

// RTC_TSDR register
#define RTC_TSDR                                        ((RTC_BASE)+(RTC_TSDR_OFFSET))

// RTC_TSSSR register
#define RTC_TSSSR                                       ((RTC_BASE)+(RTC_TSSSR_OFFSET))

// RTC_CALR register
#define RTC_CALR                                        ((RTC_BASE)+(RTC_CALR_OFFSET))

// RTC_TAFCR register
#define RTC_TAFCR                                       ((RTC_BASE)+(RTC_TAFCR_OFFSET))

// RTC_ALRMASSR register
#define RTC_ALRMASSR                                    ((RTC_BASE)+(RTC_ALRMASSR_OFFSET))

// RTC_ALRMBSSR register
#define RTC_ALRMBSSR                                    ((RTC_BASE)+(RTC_ALRMBSSR_OFFSET))

// RTC_BKPxR registers
#define RTC_BKPxR                                       ((RTC_BASE)+(RTC_BKPxR_OFFSET))  // this goes till 0x9C

/******************************* I2C address ****************************************/

// I2C 1 Base
#define I2C_BASE                                        ((APB1_BASE)+(I2C1_OFFSET))

// I2C1_CR1 register
#define I2C1_CR1                                         ((I2C_BASE)+(I2C_CR1_OFFSET))

// I2C1_CR2 register
#define I2C1_CR2                                         ((I2C_BASE)+(I2C_CR2_OFFSET))

// I2C1_OAR2 register
#define I2C1_OAR2                                        ((I2C_BASE)+(I2C_OAR2_OFFSET))

// I2C1_DR register
#define I2C1_DR                                          ((I2C_BASE)+(I2C_DR_OFFSET))

// I2C1_SR1 register
#define I2C1_SR1                                         ((I2C_BASE)+(I2C_SR1_OFFSET))

// I2C1_SR2 register
#define I2C1_SR2                                         ((I2C_BASE)+(I2C_SR2_OFFSET))

// I2C1_CCR register
#define I2C1_CCR                                         ((I2C_BASE)+(I2C_CCR_OFFSET))

// I2C1_TRISE register
#define I2C1_TRISE                                       ((I2C_BASE)+(I2C_TRISE_OFFSET))

// I2C1_FLTR register
#define I2C1_FLTR                                        ((I2C_BASE)+(I2C_FLTR_OFFSET))

/******************************* UART1 address ****************************************/

// UASRT 1 Base
#define UASRT1_BASE                                     ((APB2_BASE)+(USART1_OFFSET)) 

// USART1_SR register    0x40011000
#define USART1_SR                                       ((UASRT1_BASE)+(USART_SR_OFFSET))

// USART1_DR register    0x40011004
#define USART1_DR                                       ((UASRT1_BASE)+(USART_DR_OFFSET))

// USART1_BRR register   0x40011008
#define USART1_BRR                                      ((UASRT1_BASE)+(USART_BRR_OFFSET))

// USART1_CR1 register   0x4001100C
#define USART1_CR1                                      ((UASRT1_BASE)+(USART_CR1_OFFSET))

// USART1 CR2 register   0x40011010
#define USART1_CR2                                      ((UASRT1_BASE)+(USART_CR2_OFFSET))

//USART1_CR3 register    0x40011014
#define USART1_CR3                                      ((UASRT1_BASE)+(USART_CR3_OFFSET))

// USART1_GTPR register  0x40011018
#define USART1_GTPR                                     ((UASRT1_BASE)+(USART_GTPR_OFFSET))



#ifdef __cplusplus
}
#endif
// end of ifndef STM_REGISTER
#endif