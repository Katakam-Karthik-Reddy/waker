#ifndef CORE_H
#define CORE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

/******************************************************************************
 * defination with register value set
*****************************************************************************/

// Base address of System Control Space
#define SCS_BASE                        0xE000E000U

// System Control Block Offset
#define SCB_OFFSET                      0xD00U

// Interrupt Control and State Register Offset
#define ICSR_OFFSET                     0x4U

// Application Interrupt and Reset Control Register Offset
#define AIRCR_OFFSET                    0xCU


// SysTick Offset
#define SYSTICK_OFFSET                  0x10U

// Systick Control and Status Register Offset
#define SYST_CSR_OFFSET                 0x0U

// Systick Reload Value Register Offset
#define SYST_RVR_OFFSET                 0x4U

// Systick Current Value Register Offset
#define SYST_CVR_OFFSET                 0x8U

// Systick Calibration Value Register Offset
#define SYST_CALB_OFFSET                0xCU


// NVIC Offset
#define NVIC_OFFSET                     0x100U

// Interrupt Set Enable Register Offset
#define NVIC_ISER_OFFSET                0x0U

// Interrupt Clear Enable Register Offset
#define NVIC_ICER_OFFSET                0x80U

// Interrupt Set Pending Register Offset
#define NVIC_ISPR_OFFSET                0x100U

// Interrupt Clear Pending Register Offset
#define NVIC_ICPR_OFFSET                0x180U

// Interrupt Active Bit Register Offset
#define NVIC_IABR_OFFSET                0x200U

// Interrupt Priority Register Offset
#define NVIC_IPR_OFFSET                 0x300U

/******************************* SCB address ******************************************/

// SCB base address
#define SCB_BASE                        ((SCS_BASE)+(SCB_OFFSET))

// Interrupt Control and State Register
#define ICSR                            ((SCB_BASE)+(ICSR_OFFSET))

// Application Interrupt and Reset Control Register
#define AIRCR                           ((SCB_BASE)+(AIRCR_OFFSET))

/******************************* SYSTICK address ******************************************/

// Systick Base address
#define SYSTICK_BASE                    ((SCS_BASE)+(SYSTICK_OFFSET))

// Systick Control and Status Register
#define SYST_CSR                        ((SYSTICK_BASE)+(SYST_CSR_OFFSET))

// Systick Reload Value Register
#define SYST_RVR                        ((SYSTICK_BASE)+(SYST_RVR_OFFSET))

// Systick Current Value Register 
#define SYST_CVR                        ((SYSTICK_BASE)+(SYST_CVR_OFFSET))

// Systick Calibration Value Register
#define SYST_CALB                       ((SYSTICK_BASE)+(SYST_CALB_OFFSET))

/******************************* NVIC address ******************************************/

// NVIC BASE
#define NVIC_BASE                       ((SCS_BASE)+(NVIC_OFFSET))

// Interrupt Set Enable Register
#define NVIC_ISER                       ((NVIC_BASE)+(NVIC_ISER_OFFSET))

// Interrupt Clear Enable Register
#define NVIC_ICER                       ((NVIC_BASE)+(NVIC_ICER_OFFSET))

// Interrupt Set Pending Register
#define NVIC_ISPR                       ((NVIC_BASE)+(NVIC_ISPR_OFFSET))

// Interrupt Clear Pending Register
#define NVIC_ICPR                       ((NVIC_BASE)+(NVIC_ICPR_OFFSET))

// Interrupt Active Bit Register
#define NVIC_IABR                       ((NVIC_BASE)+(NVIC_IABR_OFFSET))

// Interrupt Priority Register
#define NVIC_IPR                         ((NVIC_BASE)+(NVIC_IPR_OFFSET))

/******************************* Types address ******************************************/

typedef struct {
    uint32_t VECTACTIVE                 :9;
    uint32_t Reserved_9_10              :2;
    uint32_t RETTOBASE                  :1;
    uint32_t VECTPENDING                :9;
    uint32_t Reserved_21                :1;
    uint32_t ISRPENDING                 :1;
    uint32_t ISRPPREEMPT                :1;
    uint32_t Reserved_24                :1;
    uint32_t PENDSTCLR                  :1;
    uint32_t PENDSTSET                  :1;
    uint32_t PENDSVCLR                  :1;
    uint32_t PENDSVSET                  :1;
    uint32_t Reserved_29_30             :2;
    uint32_t NMIPENDSET                 :1;
} ICSR_T;

typedef struct {
    uint32_t VECTRESET                  :1;
    uint32_t VECTCLRACTIVE              :1;
    uint32_t SYSRESETREQ                :1;
    uint32_t Reserved_3_7               :5;
    uint32_t PRIGROUP                   :3;
    uint32_t Reserved_11_14             :4;
    uint32_t ENDIANNESS                 :1;
    uint32_t VECTKEY                    :16;
} AIRCR_T;

typedef struct {
    uint32_t ENABLE                     :1;
    uint32_t TICKINT                    :1;
    uint32_t CLOCKSOURCE                :1;
    uint32_t Reserved_3_15              :13;
    uint32_t COUNTFLAG                  :1;
    uint32_t Reserved_17_31             :15;
} SYST_CSR_T;

typedef struct {
    uint32_t RELOAD                     :24;
    uint32_t Reserved_24_31             :8;
} SYST_RVR_T;

typedef struct {
    uint32_t CURRENT                    :32;
} SYST_CVR_T;

typedef struct {
    uint32_t TENMS                      :24;
    uint32_t Reserved_24_29             :6;
    uint32_t SKEW                       :1;
    uint32_t NOREF                      :1;
} SYST_CALB_T;

/******************************************************************************
 * defination with register value set
*****************************************************************************/

// Application Interrupt and Reset Control Register
#define AIRCR_R                         ((volatile AIRCR_T*)(AIRCR))

#define ICSR_R                         ((volatile ICSR_T*)(ICSR))

#define SYST_CSR_R                      ((volatile SYST_CSR_T*)(SYST_CSR))

#define SYST_RVR_R                      ((volatile SYST_RVR_T*)(SYST_RVR))

#define SYST_CVR_R                      ((volatile SYST_CVR_T*)(SYST_CVR))

#define SYST_CALB_R                     ((volatile SYST_CALB_T*)(SYST_CALB))

#define NVIC_ISER_R                     ((volatile uint32_t*)NVIC_ISER)

#define NVIC_IPR_R                      ((volatile uint8_t *)(NVIC_IPR))


extern volatile uint32_t irq_event_mask;

void PendSV_Handler(void);


#ifdef __cplusplus
}
#endif
#endif //CORE_H