#ifndef TYPES_H
#define TYPES_H

#ifdef __cplusplus
extern "C" {
#endif


enum MODER_TYPES {
    INPUT                           = 0,
    GENERAL_PURPOSE_OUTPUT_MODE     = 1,
    ALTERNATE_FUNCTION              = 2,
    ANALOG_MODE                     = 3,
};

enum OSPEEDR_TYPES {
    LOW_SPEED                       = 0,
    MEDIUM_SPEED                    = 1,
    HIGH_SPEED                      = 2,
    VERY_HIGH_SPEED                 = 3,
};

enum AFR_TYPES {
    AF0                             = 0,
    AF1                             = 1,
    AF2                             = 2,
    AF3                             = 3,
    AF4                             = 4,
    AF5                             = 5,
    AF6                             = 6,
    AF7                             = 7,
    AF8                             = 8,
    AF9                             = 9,
    AF10                            = 10,
    AF11                            = 11,
    AF12                            = 12,
    AF13                            = 13,
    AF14                            = 14,
    AF15                            = 15,
};

enum OTYPES_TYPES {
    PUSH_PULL                       = 0,
    OPEN_DRAIN                      = 1,
};

enum PUPD_TYPES {
    NO_PULLUP_NO_PULLDOWN           = 0,
    PULL_UP                         = 1,
    PULL_DOWN                       = 2,
};

enum SMS_TYPES {
    Slave_mode_disabled             = 0x00,
    Encoder_mode_1                  = 0x01,
    Encoder_mode_2                  = 0x02,
    Encoder_mode_3                  = 0x03,
    Reset_mode                      = 0x04, 
    Gated_mode                      = 0x05,
    Trigger_mode                    = 0x06,
    External_Clock_mode_1           = 0x07,
};

enum CC1S_TYPE {
    IC1_OUTPUT                  = 0x00,
    IC1_TI1                     = 0x01,
    IC1_TI2                     = 0x02,
    IC1_TRC                     = 0x03,
};

enum CC2S_TYPE {
    IC2_OUTPUT                  = 0x00,
    IC2_TI2                     = 0x01,
    IC2_TI1                     = 0x02,
    IC2_TRC                     = 0x03,
};

enum CC1P_TYPE {
    NON_INVERTED_RISING_EDGE    = 0x00,
    INVERTED_FALLING_EDGE       = 0x01,
    RESERVED                    = 0x02,
    NON_INVERTED_EDGE           = 0x03,
};

// RTC types

enum FMT_TYPE {
    HOUR_24_FORMAT              = 0x00,
    AM_PM_FORMAT                = 0x01,
};


#ifdef __cplusplus
}
#endif

#endif