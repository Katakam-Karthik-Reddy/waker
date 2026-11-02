#include <stdint.h>
#include <stdio.h>
#include "types.h"
#include "gpio.h"
#include "uart.h"
#include "system.h"
#include "timer.h"
#include "rtc.h"
#include "utils.h"
#include "general.h"
#include "systick.h"
#include "core.h"
#include "oled.h"
#include "app.h"

volatile uint32_t irq_event_mask    = 0;
volatile uint32_t current_mode = SHOW_TIME;
volatile uint32_t time_state = SET_HOUR;
volatile uint8_t frames = 10;
volatile uint32_t state_before_selecting = 0;

volatile uint8_t hour = 0;
volatile uint8_t minute = 0;
volatile uint8_t second = 0;
volatile uint8_t ampm = 0;
volatile uint8_t day = 0;
volatile uint8_t weekday = 1;
volatile uint8_t month = 0;
volatile uint8_t year = 0;

void init(void){
    current_mode = SHOW_TIME;
    frames = 2;
    selecting_state = 0;
    config_systemclock();
    USART1_INIT();
    config_systick();
    setup_encoder();
    setup_rtc();
    setup_servo();
    setup_oled_display();
    config_onboard_led();
}

int main(void){
    init();
    while(1){};
}
