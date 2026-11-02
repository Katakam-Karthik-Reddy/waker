#ifndef GPIO_H
#define GPIO_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "register.h"

/*****************************************************************************
* typedef for differnt resigters
*****************************************************************************/

typedef struct {
    uint32_t MODER0             :2;
    uint32_t MODER1             :2;
    uint32_t MODER2             :2;
    uint32_t MODER3             :2;
    uint32_t MODER4             :2;
    uint32_t MODER5             :2;
    uint32_t MODER6             :2;
    uint32_t MODER7             :2;
    uint32_t MODER8             :2;
    uint32_t MODER9             :2;
    uint32_t MODER10            :2;
    uint32_t MODER11            :2;
    uint32_t MODER12            :2;
    uint32_t MODER13            :2;
    uint32_t MODER14            :2;
    uint32_t MODER15            :2;
} MODER_T;

typedef struct {
    uint32_t OT0                :1;
    uint32_t OT1                :1;
    uint32_t OT2                :1;
    uint32_t OT3                :1;
    uint32_t OT4                :1;
    uint32_t OT5                :1;
    uint32_t OT6                :1;
    uint32_t OT7                :1;
    uint32_t OT8                :1;
    uint32_t OT9                :1;
    uint32_t OT10               :1;
    uint32_t OT11               :1;
    uint32_t OT12               :1;
    uint32_t OT13               :1;
    uint32_t OT14               :1;
    uint32_t OT15               :1;
    uint32_t Reserved_16_31     :16;
} OTYPER_T;

typedef struct {
    uint32_t OSPEEDR0          :2;
    uint32_t OSPEEDR1          :2;
    uint32_t OSPEEDR2          :2;
    uint32_t OSPEEDR3          :2;
    uint32_t OSPEEDR4          :2;
    uint32_t OSPEEDR5          :2;
    uint32_t OSPEEDR6          :2;
    uint32_t OSPEEDR7          :2;
    uint32_t OSPEEDR8          :2;
    uint32_t OSPEEDR9          :2;
    uint32_t OSPEEDR10         :2;
    uint32_t OSPEEDR11         :2;
    uint32_t OSPEEDR12         :2;
    uint32_t OSPEEDR13         :2;
    uint32_t OSPEEDR14         :2;
    uint32_t OSPEEDR15         :2;
    uint32_t OSPEEDR16         :2;
} OSPEEDR_T;

typedef struct {
    uint32_t PUPDR0             :2;
    uint32_t PUPDR1             :2;
    uint32_t PUPDR2             :2;
    uint32_t PUPDR3             :2;
    uint32_t PUPDR4             :2;
    uint32_t PUPDR5             :2;
    uint32_t PUPDR6             :2;
    uint32_t PUPDR7             :2;
    uint32_t PUPDR8             :2;
    uint32_t PUPDR9             :2;
    uint32_t PUPDR10            :2;
    uint32_t PUPDR11            :2;
    uint32_t PUPDR12            :2;
    uint32_t PUPDR13            :2;
    uint32_t PUPDR14            :2;
    uint32_t PUPDR15            :2;    
} PUPD_T;

typedef struct {
    uint32_t IDR0               :1;
    uint32_t IDR1               :1;
    uint32_t IDR2               :1;
    uint32_t IDR3               :1;
    uint32_t IDR4               :1;
    uint32_t IDR5               :1;
    uint32_t IDR6               :1;
    uint32_t IDR7               :1;
    uint32_t IDR8               :1;
    uint32_t IDR9               :1;
    uint32_t IDR10              :1;
    uint32_t IDR11              :1;
    uint32_t IDR12              :1;
    uint32_t IDR13              :1;
    uint32_t IDR14              :1;
    uint32_t IDR15              :1;
    uint32_t Reserved_16_31     :16;
} IDR_T;

typedef struct {
    uint32_t ODR0               :1;
    uint32_t ODR1               :1;
    uint32_t ODR2               :1;
    uint32_t ODR3               :1;
    uint32_t ODR4               :1;
    uint32_t ODR5               :1;
    uint32_t ODR6               :1;
    uint32_t ODR7               :1;
    uint32_t ODR8               :1;
    uint32_t ODR9               :1;
    uint32_t ODR10              :1;
    uint32_t ODR11              :1;
    uint32_t ODR12              :1;
    uint32_t ODR13              :1;
    uint32_t ODR14              :1;
    uint32_t ODR15              :1;
    uint32_t Reserved_16_31     :16;
} ODR_T;



typedef struct {
    uint32_t AFRL0              :4;
    uint32_t AFRL1              :4;
    uint32_t AFRL2              :4;
    uint32_t AFRL3              :4;
    uint32_t AFRL4              :4;
    uint32_t AFRL5              :4;
    uint32_t AFRL6              :4;
    uint32_t AFRL7              :4;
} AFRL_T;

typedef struct {
    uint32_t AFRH8              :4;
    uint32_t AFRH9              :4;
    uint32_t AFRH10             :4;
    uint32_t AFRH11             :4;
    uint32_t AFRH12             :4;
    uint32_t AFRH13             :4;
    uint32_t AFRH14             :4;
    uint32_t AFRH15             :4;
} AFRH_T;

/*****************************************************************************
* defination with register value set
*****************************************************************************/


// GPIO A registers 

#define GPIO_A_MODER_R          ((volatile MODER_T*)(GPIOA_MODER))

#define GPIO_A_OTYPER_R         ((volatile OTYPER_T*)(GPIOA_OTYPER))

#define GPIO_A_OSPEEDR_R        ((volatile OSPEEDR_T*)GPIOA_OSPEEDR)

#define GPIO_A_PUPDR_R          ((volatile PUPD_T*)GPIOA_PUPDR)

#define GPIO_A_IDR_R            ((volatile IDR_T*)(GPIOA_IDR))

#define GPIO_A_ODR_R            ((volatile ODR_T*)GPIOA_ODR)

#define GPIO_A_AFRL_R           ((volatile AFRL_T*)GPIOA_AFRL)

#define GPIO_A_AFRH_R           ((volatile AFRH_T*)GPIOA_AFRH)


// GPIO B registers 

#define GPIO_B_MODER_R          ((volatile MODER_T*)GPIOB_MODER)

#define GPIO_B_OTYPER_R         ((volatile OTYPER_T*)GPIOB_OTYPER)

#define GPIO_B_OSPEEDR_R        ((volatile OSPEEDR_T*)GPIOB_OSPEEDR)

#define GPIO_B_PUPDR_R          ((volatile PUPD_T*)GPIOB_PUPDR)

#define GPIO_B_IDR_R            ((volatile IDR_T*)(GPIOB_IDR))

#define GPIO_B_ODR_R            ((volatile ODR_T*)GPIOB_ODR)

#define GPIO_B_AFRL_R           ((volatile AFRL_T*)GPIOB_AFRL)

#define GPIO_B_AFRH_R           ((volatile AFRH_T*)GPIOB_AFRH)

// GPIO C registers

#define GPIO_C_MODER_R          ((volatile MODER_T*)GPIOC_MODER)

#define GPIO_C_OTYPER_R         ((volatile OTYPER_T*)GPIOC_OTYPER)

#define GPIO_C_OSPEEDR_R        ((volatile OSPEEDR_T*)GPIOC_OSPEEDR)

#define GPIO_C_PUPDR_R          ((volatile PUPD_T*)GPIOC_PUPDR)

#define GPIO_C_IDR_R            ((volatile IDR_T*)(GPIOC_IDR))

#define GPIO_C_ODR_R            ((volatile ODR_T*)GPIOC_ODR)

#define GPIO_C_AFRL_R           ((volatile AFRL_T*)GPIOC_AFRL)

#define GPIO_C_AFRH_R           ((volatile AFRH_T*)GPIOC_AFRH)


/*****************************************************************************
* function declaration
*****************************************************************************/

void enable_GPIO_ports(char port);


#ifdef __cplusplus
}
#endif

#endif /* GPIO_H */