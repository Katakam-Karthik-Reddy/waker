#include "system.h"
#include "types.h"

void enable_GPIO_ports(char port){
    switch(port){
        case 'A':
            if(RCC_AHB1ENR_R->GPIOA_EN == 0x00U){
                RCC_AHB1ENR_R->GPIOA_EN = 0x01U;
            }
            break;
        case 'B':
            if(RCC_AHB1ENR_R->GPIOB_EN == 0x00U){
                RCC_AHB1ENR_R->GPIOB_EN = 0x01U;
            }
            break;
        case 'C':
            if(RCC_AHB1ENR_R->GPIOC_EN == 0x00U){
                RCC_AHB1ENR_R->GPIOC_EN = 0x01U;
            }
            break;
    }
    
    // dummy reads for errata
    volatile RCC_AHB1EN_T dummy __attribute__((unused));
    dummy = *(RCC_AHB1ENR_R);
    dummy = *(RCC_AHB1ENR_R);
}


