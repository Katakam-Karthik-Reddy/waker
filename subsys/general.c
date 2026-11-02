#include "types.h"
#include "gpio.h"


void config_onboard_led(void){
    enable_GPIO_ports('C');
    // set the PC13 as output pin
    GPIO_C_MODER_R->MODER13     = GENERAL_PURPOSE_OUTPUT_MODE;
}

void toggle_onboard_led(void){
    GPIO_C_ODR_R->ODR13         ^= 0x01U;
}