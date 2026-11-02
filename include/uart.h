#ifndef UART_H
#define UART_H

#ifdef __cplusplus
extern "C" {
#endif

#include "gpio.h"


/******************************************************************************
 * typedef differnt resigters
 *****************************************************************************/

typedef struct {
    uint32_t PE                 :1;
    uint32_t FE                 :1;
    uint32_t NF                 :1;
    uint32_t ORE                :1;
    uint32_t IDLE               :1;
    uint32_t RXNE               :1;
    uint32_t TC                 :1;
    uint32_t TXE                :1;
    uint32_t LBD                :1;
    uint32_t CTS                :1;
    uint32_t Reserved_10_31     :22;
} USART_SR_T;

typedef struct {
    uint32_t DR                 :8;
    uint32_t Reserved_8_31      :16;
} USART_DR_T;

typedef struct {
    uint32_t DIV_FRACTION       :4;
    uint32_t DIV_MANTISSA       :12;
    uint32_t Reserved_16_31     :16;
} USART_BRR_T; 

typedef struct {
    uint32_t SBK                :1;
    uint32_t RWU                :1;
    uint32_t RE                 :1;
    uint32_t TE                 :1;
    uint32_t IDLEIE             :1;
    uint32_t RXNEIE             :1;
    uint32_t TCIE               :1;
    uint32_t TXEIE              :1;
    uint32_t PEIE               :1;
    uint32_t PS                 :1;
    uint32_t PCE                :1;
    uint32_t WAKE               :1;
    uint32_t M                  :1;
    uint32_t UE                 :1;
    uint32_t Reserved_14        :1;
    uint32_t OVER8              :1;
    uint32_t Reserved_16_31     :16;
} USART_CR1_T;

typedef struct {
    uint32_t ADD                :4;
    uint32_t Res_1              :1;
    uint32_t LBDL               :1;
    uint32_t LBDIE              :1;
    uint32_t Res_2              :1;
    uint32_t LBCL               :1;
    uint32_t CPHA               :1;
    uint32_t CPOL               :1;
    uint32_t CLKEN              :1;
    uint32_t STOP               :2;
    uint32_t LINEN              :1;
    uint32_t Res_3              :1;
    uint32_t Reserved_16_31     :16;
} USART_CR2_T;

typedef struct {
    uint32_t EIE                :1;
    uint32_t IREN               :1;
    uint32_t IRLP               :1;
    uint32_t HDSEL              :1;
    uint32_t NACK               :1;
    uint32_t SCEN               :1;
    uint32_t DMAR               :1;
    uint32_t DMAT               :1;
    uint32_t RTSE               :1;
    uint32_t CTSE               :1;
    uint32_t CTSIE              :1;
    uint32_t ONEBIT             :1;
    uint32_t Reserved_12_31     :20;
} USART_CR3_T;

typedef struct {
    uint32_t PSC                :8;
    uint32_t GT                 :8;
    uint32_t Reserved_16_31     :16;
} USART_GTPR_T;

/******************************************************************************
 * defination with register value set
 *****************************************************************************/

// USART1_SR register
#define USART1_SR_R ((volatile USART_SR_T*)USART1_SR)

// USART1_DR register
#define USART1_DR_R ((volatile USART_DR_T*)USART1_DR)

// USART1_BRR register
#define USART1_BRR_R ((volatile USART_BRR_T*)USART1_BRR)

// USART1_CR1 register
#define USART1_CR1_R ((volatile USART_CR1_T*)USART1_CR1)

// USART1_CR2 register
#define USART1_CR2_R ((volatile USART_CR2_T*)USART1_CR2)

// USART1_CR3 register
#define USART1_CR3_R ((volatile USART_CR2_T*)USART1_CR3)

// USART1_DTPR register
#define USART1_GTPR_R ((volatile USART_GTPR_T*)USART1_GTPR)


/******************************************************************************
 * functions
 *****************************************************************************/

/**
 * @brief enable clock for USART 1
 * @param none
 * @return status 
 *         0->succes
 *         1->error
 */
int USART1_enable_clock(void);

/**
 * @brief disable clock for USART 1
 * @param none
 * @return status 
 *         0->succes
 *         1->error
 */
int USART1_disable_clock(void);

/**
 * @brief Setup TX and RX pins for USART 1
 * @param  none
 * @return status
 */
int USART1_Setup_TX_RX_Pins(void);

/**
 * @brief setup the USART 1 
 * @param none
 * @return status
 */
int USART1_INIT(void);

/**
 * @brief send one byte 
 * @param uint8_t byte
 * @return none
 */
void USART1_send_byte(uint8_t byte);

/**
 * @brief send full string
 * @param string 
 * @return none
 */
void USART1_send_string(const char *string);

/**
 * @brief send value
 * @param int
 * @return none
 */
void USART1_send_number(int32_t value);



#ifdef __cplusplus
}
#endif

#endif /* UART_H */