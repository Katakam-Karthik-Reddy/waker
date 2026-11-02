/**
 * @brief implimentation of USART
 * 
 * @author Katakam Karthik Reddy
 */

#include "uart.h"
#include "gpio.h"
#include "types.h"
#include "utils.h"
#include "stdlib.h"
#include "system.h"
#include "uart.h"


int USART1_enable_clock(void){
    RCC_APB2ENR_R->USART1_EN = 0x01U;
    return !(RCC_APB2ENR_R->USART1_EN);
}

int USART1_disable_clock(void){
    RCC_APB2ENR_R->USART1_EN = 0x00U;
    return !(RCC_APB2ENR_R->USART1_EN);
}

int USART1_Setup_TX_RX_Pins(void){
    // enable the GPIO A
    enable_GPIO_ports('A');
    
    GPIO_A_MODER_R->MODER9          = ALTERNATE_FUNCTION; //TX      
    GPIO_A_MODER_R->MODER10         = ALTERNATE_FUNCTION; //RX
    
    GPIO_A_OSPEEDR_R->OSPEEDR9      = VERY_HIGH_SPEED;
    GPIO_A_OSPEEDR_R->OSPEEDR10     = VERY_HIGH_SPEED;

    GPIO_A_AFRH_R->AFRH9            = AF7;
    GPIO_A_AFRH_R->AFRH10           = AF7;

    return 1;
}

int USART1_INIT(void){
    USART1_enable_clock();
    USART1_Setup_TX_RX_Pins();
    USART1_BRR_R->DIV_MANTISSA   = 0x2D; // for (45)2D part of the value
    USART1_BRR_R->DIV_FRACTION   = 0x9;  // for (0.56)9 part of the value after decimal point

    USART1_CR1_R->M      = 0x0; // 8 bit word
    USART1_CR2_R->STOP   = 0x0; // 1 bit stop bit

    USART1_CR1_R->TE     = 0x1; // enabling the transmitter
    USART1_CR1_R->RE     = 0x1; // enabling the recevier

    USART1_CR1_R->UE     = 0x1; // enabling the USART

    return 0;
}

void USART1_send_byte(uint8_t byte){

    // wait for the TXE flag is set(transmit buffer is empty)
    while(!(USART1_SR_R->TXE)){} //wait
    
    // send the data
    USART1_DR_R->DR = byte;
}

void USART1_send_string(const char *string){
    while(*string){
        USART1_send_byte(*string++);
    }
}


void USART1_send_number(int32_t value){

    if(value==0){
        USART1_send_byte('0');
        return ;
    }

    uint8_t *buff = convert_number_to_string(value);

    size_t i = 0;
    while(i<22 && buff[i] != '\0'){
        USART1_send_byte(buff[i++]);
    }
}