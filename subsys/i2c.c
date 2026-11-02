#include "i2c.h"
#include "gpio.h"
#include "system.h"
#include "utils.h"
#include "systick.h"

void setup_OLED_pins(void){
    // enable clock for GPIO B 
    enable_GPIO_ports('B');
    // enable the clock for I2C
    RCC_APB1ENR_R->I2C1_EN      = 0x01U;

    // setup GPIO pin PB8(SCK) and PB9(SDA)
    GPIO_B_MODER_R->MODER8      = 0x02U;
    GPIO_B_OTYPER_R->OT8        = 0x01U;
    GPIO_B_OSPEEDR_R->OSPEEDR8  = 0x03U;
    GPIO_B_PUPDR_R->PUPDR8      = 0x01U;
    GPIO_B_AFRH_R->AFRH8        = 0x04U;

    GPIO_B_MODER_R->MODER9      = 0x02U;
    GPIO_B_OTYPER_R->OT9        = 0x01U;
    GPIO_B_OSPEEDR_R->OSPEEDR9  = 0x03U;
    GPIO_B_PUPDR_R->PUPDR9      = 0x01U;
    GPIO_B_AFRH_R->AFRH9        = 0x04U;
    
    // set the clock for I2C
    I2C1_CR2_R->FREQ            = 42U;
    // config the clock for I2C
    I2C1_CCR_R->CCR             = 210U;
    //config the rise time rgister
    I2C1_TRISE_R->TRISE         = 43U;
    // enable the I2C peripheral
    I2C1_CR1_R->PE              = 0x01U;
}

bool isI2C1readytosend(void){
    while(!I2C1_SR1_R->TxE){};      // wait for I2C1 to be read to send
    return true;
}

void start_I2C1_transmit(void){
    I2C1_CR1_R->ACK             = 0x01U;    // enable ack to be returned from send byte
    I2C1_CR1_R->START           = 0x01U;    // set the start bit

    while(I2C1_SR1_R->SB != 0x01U){};       // wait for signal for start bit
    I2C1_DR_R->DR = 0x3CU << 1;             // send the address of the OLED to select the device
    
    while((I2C1_SR1_R->ADDR != 0x01U)){};   // wait for addr bit to get set.
    uint16_t __attribute__((unused)) sr1 = *(volatile uint16_t *)I2C1_SR1_R;    // dummy read
    uint16_t __attribute__((unused)) sr2 = *(volatile uint16_t *)I2C1_SR2_R;    // dummy read
}

void send_I2C1_data(uint8_t data){
    isI2C1readytosend();                    // wait for send byte to be sent
    I2C1_DR_R->DR       = data;             // set the data
}

void stop_I2C1_transmit(void){
    while(I2C1_SR1_R->BTF != 0x01U){};      // wait for send byte to be sent
    I2C1_CR1_R->STOP        = 0x01U;        // set the stop byte
}

