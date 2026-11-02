#ifndef APP_H
#define APP_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

enum {
    NONE                = 0x00,
    SHOW_TIME           = 0x01,
    SET_TIME            = 0x02,
    SET_ALARM           = 0x04, 
    TOGGLE_ONBOARD_LED  = 0x08,
};

// states for SET_TIME
enum {
    SET_HOUR        = 0x01U,
    SET_MINUTE      = 0x02U,
    SET_SECOND      = 0x03U,
    SET_AM_PM       = 0x04U,
    SET_DAY         = 0x05U,
    SET_MONTH       = 0x06U,
    SET_YEAR        = 0x07U,
    SET_WEEKDAY     = 0x08U,
};


extern volatile uint32_t previous_state;
extern volatile uint32_t current_mode;
extern volatile uint32_t time_state;
extern volatile uint32_t state_before_selecting;
extern volatile uint32_t selecting_state;
extern volatile uint8_t frames;

// temp time variables
extern volatile uint8_t hour;
extern volatile uint8_t minute;
extern volatile uint8_t second;
extern volatile uint8_t ampm;

extern volatile uint8_t day;
extern volatile uint8_t weekday;
extern volatile uint8_t month;
extern volatile uint8_t year;

extern char temp;

void mainSV_Handler(void);

void main_Handler(void);

void show_time(void);

void update_set_time_state(void);

void update_set_alarm_state(void);

void rotary_change_Handler(void);

void rotary_button_press_Handler(void);

#ifdef __cplusplus
}
#endif
#endif // APP_H