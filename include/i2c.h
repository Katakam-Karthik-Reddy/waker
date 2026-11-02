#ifndef I2C_H
#define I2C_H

#ifdef __cplusplus
extern "C" {
#endif

#include "register.h"
#include <stdint.h>
#include <stdbool.h>

// I2C types

typedef struct {
    uint16_t PE                 :1;
    uint16_t SMBUS              :1;
    uint16_t Reserved_2         :1;
    uint16_t SMBTYPE            :1;
    uint16_t ENARP              :1;
    uint16_t ENPEC              :1;
    uint16_t ENGC               :1;
    uint16_t NOSTRETCH          :1;
    uint16_t START              :1;
    uint16_t STOP               :1;
    uint16_t ACK                :1;
    uint16_t POS                :1;
    uint16_t PEC                :1;
    uint16_t ALERT              :1;
    uint16_t Reserved_14        :1;
    uint16_t SWRST              :1;
} I2C_CR1_T;

typedef struct {
    uint16_t FREQ               :6;
    uint16_t Reserved_6_7       :2;
    uint16_t ITERREN            :1;
    uint16_t ITEVTEN            :1;
    uint16_t ITBUFEN            :1;
    uint16_t DMAEN              :1;
    uint16_t LAST               :1;
    uint16_t Reserved_13_15     :3;
} I2C_CR2_T;


typedef struct {
    uint16_t DR                 :8;
    uint16_t Reserved_8_15      :8;
} I2C_DR_T;

typedef struct {
    uint16_t SB                 :1;
    uint16_t ADDR               :1;
    uint16_t BTF                :1;
    uint16_t ADD10              :1;
    uint16_t STOPF              :1;
    uint16_t Reserved_5         :1;
    uint16_t RxNE               :1;
    uint16_t TxE                :1;
    uint16_t BERR               :1;
    uint16_t ARLO               :1;
    uint16_t AF                 :1;
    uint16_t OVR                :1;
    uint16_t PECERR             :1;
    uint16_t Reserved_13        :1;
    uint16_t TIMEOUT            :1;
    uint16_t SMBALERT           :1;
} I2C_SR1_T;

typedef struct {
    uint16_t MSL                :1;
    uint16_t BUSY               :1;
    uint16_t TRA                :1;
    uint16_t Reserved           :1;
    uint16_t GENCALL            :1;
    uint16_t SMBDEFAULT         :1;
    uint16_t SMBHOST            :1;
    uint16_t DUALF              :1;
    uint16_t PEC                :1;
} I2C_SR2_T;

typedef struct {
    uint16_t CCR                :12;
    uint16_t Reserved_12_13     :2;
    uint16_t DUTY               :1;
    uint16_t F_S                :1;
} I2C_CCR_T;

typedef struct {
    uint16_t TRISE              :6;
    uint16_t Reserved_7_15      :10;
} I2C_TRISE_T;

/*****************************************************************************
* defination with register value set
*****************************************************************************/

// I2C 1

#define I2C1_CR1_R              ((volatile I2C_CR1_T *)(I2C1_CR1))

#define I2C1_CR2_R              ((volatile I2C_CR2_T *)(I2C1_CR2))

#define I2C1_DR_R               ((volatile I2C_DR_T *)(I2C1_DR))

#define I2C1_SR1_R              ((volatile I2C_SR1_T *)(I2C1_SR1))

#define I2C1_SR2_R              ((volatile I2C_SR2_T *)(I2C1_SR2))

#define I2C1_CCR_R              ((volatile I2C_CCR_T *)(I2C1_CCR))

#define I2C1_TRISE_R            ((volatile I2C_TRISE_T *)(I2C1_TRISE))

// functions
void setup_OLED_pins(void);

bool isI2C1readytosend(void);

void start_I2C1_transmit(void);

void send_I2C1_data(uint8_t data);

void stop_I2C1_transmit(void);



#ifdef __cplusplus
}
#endif
#endif