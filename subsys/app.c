#include "app.h"
#include "utils.h"
#include "rtc.h"
#include "systick.h"
#include "core.h"
#include "general.h"
#include "system.h"
#include "timer.h"
#include "oled.h"

static uint32_t last_show_time = 0;
static uint32_t last_update_time = 0;
volatile uint32_t selecting_state = 0;

void mainSV_Handler(void){
    __disable_irq(); // disable before entering critical space

    // every second(1000ms) toggle the onboard led
    if((MS_TICKS % 500) == 0){
        irq_event_mask |= (TOGGLE_ONBOARD_LED);
    }
    if((current_mode == SHOW_TIME) && (MS_TICKS - last_show_time) >= (1000/(int)frames)){
        last_show_time = MS_TICKS;
        irq_event_mask |= (SHOW_TIME);
    }
    if((current_mode == SET_TIME)  && (MS_TICKS - last_update_time) >= (1000/(int)(frames*4))){
        last_update_time = MS_TICKS;
        irq_event_mask |= (SET_TIME);
    }
    if((current_mode == SET_ALARM) && (MS_TICKS - last_show_time) >= (1000/(int)(frames*4))){
        last_show_time = MS_TICKS;
        irq_event_mask |= (SET_ALARM);
    }

    __enable_irq(); // enable after exiting critical space
    ICSR_R->PENDSVSET = 0x01U; // set the flag to indicate there are pending interrupts to server
}


void main_Handler(void){
    __disable_irq(); // disable before reading the shared variable
    uint32_t active_IRQ = irq_event_mask;
    irq_event_mask      = 0x0U; // set the shared variable which indicated the interrupt event back to none
    __enable_irq(); // enable after reading the share variable
    
    // server if it is onboard led toggle
    if(((active_IRQ & TOGGLE_ONBOARD_LED) >> 0x03U) == 0x01U){
        toggle_onboard_led();
    }
    if(((active_IRQ & SHOW_TIME) == 0x01U) && (((active_IRQ & SET_TIME) >> 0x01U) != 0x01U) ){
        show_time();
    }
    if(((active_IRQ & SET_TIME) >> 0x01U) == 0x01U){
        writef("set time to : %d:%d:%d %s %d-%d-%d %d", hour, minute, second, ampm == 1 ? "AM" : "PM", day, month, year, weekday);
        update_set_time_state();
    }
    if(((active_IRQ & SET_ALARM) >> 0x02U) == 0x01U){
        writef("set time to : %d:%d:%d %s %d", hour, minute, second, ampm == 1 ? "AM" : "PM", day);
        update_set_alarm_state();
    }
}


void show_time(void){
    if(selecting_state == 0){
        state_before_selecting  = SHOW_TIME;
        writef("current time : %d:%d:%d %s, %d-%d-%d %d", gethour(), getminutes(), getseconds(), getampm() == 1 ? "PM" : "AM", getday(), getmonth(), getyear(), getweekday());
        send_char_oled(gethour(), getminutes(), getseconds(), getampm(), getday(), getmonth(), getyear(), getweekday());
    }
    else{
        selecting_state--;
    }
}

void update_set_time_state(void){
    send_char_oled(hour, minute, second, ampm, day, month, year, weekday);
}

void update_set_alarm_state(void){
    send_char_oled_alarm(hour, minute, second, ampm, day);
}

void rotary_change_Handler(void){
    if((current_mode & SHOW_TIME) == 0x01U | current_mode == 0x00U){
        uint32_t temp_value = (get_counter_value()%3);
        if(temp_value == 0){ temp_value = 2; };
        state_before_selecting = (0x01U << temp_value);
        switch (state_before_selecting){
        case SET_TIME:
            writef("Selected state is SET_TIME");
            send_state_oled(SET_TIME);
            state_before_selecting = SET_TIME;
            selecting_state = 5;
            break;     
        case SET_ALARM:
            writef("Selected state is SET_ALARM");
            send_state_oled(SET_ALARM);
            state_before_selecting = SET_ALARM;
            selecting_state = 5;
            break;              
        default:
            selecting_state = 0;
        }
    }
    else if(((current_mode & SET_TIME) >> 0x01U) == 0x01U){
        if(time_state == SET_HOUR){
            hour = (get_counter_value()%13);
            if(hour == 0) hour++;
        }
        else if(time_state == SET_MINUTE){
            minute = (get_counter_value()%60);
        }
        else if(time_state == SET_SECOND){
            second = (get_counter_value()%60);  
        }
        else if(time_state == SET_AM_PM){
            ampm = (get_counter_value()%2);
        }
        else if(time_state == SET_DAY){
            day = (get_counter_value()%31);
            if(day==0){day++;}
        }
        else if(time_state == SET_MONTH){
            month = (get_counter_value()%13);
            if(month == 0){month++;}
        }
        else if(time_state == SET_YEAR){
            year = (get_counter_value()%99);
            if(year==0){year++;}
        }
    }
    else if(((current_mode & SET_ALARM) >> 0x02U) == 0x01U){
        if(time_state == SET_HOUR){
            hour = (get_counter_value()%13);
            if(hour == 0) hour++;
        }
        else if(time_state == SET_MINUTE){
            minute = (get_counter_value()%60);
        }
        else if(time_state == SET_SECOND){
            second = (get_counter_value()%60);  
        }
        else if(time_state == SET_AM_PM){
            ampm = (get_counter_value()%2);
        }
        else if(time_state == SET_DAY){
            day = (get_counter_value()%31);
            if(day==0){day++;}
        }
    }
}

void rotary_button_press_Handler(void){
    writef("inside button press");
    writef("current mode : %d", current_mode);
    if((current_mode & SHOW_TIME) == 0x01U){
        current_mode = state_before_selecting;
        time_state = SET_HOUR;
        hour = gethour();
        minute = getminutes();
        second = getseconds();
        ampm = getampm();
        day  = getday();
        weekday = getweekday();
        month = getmonth();
        year = getyear();
    }
    else if(((current_mode & SET_TIME) >> 0x01U) == 0x01U){
        if(time_state == SET_HOUR){
            time_state = SET_MINUTE;
        }
        else if(time_state == SET_MINUTE){
            time_state = SET_SECOND;
        }
        else if(time_state == SET_SECOND){
            time_state = SET_AM_PM;
        }
        else if(time_state == SET_AM_PM){
            time_state = SET_DAY;
        }
        else if(time_state == SET_DAY){
            time_state = SET_MONTH;
        }
        else if(time_state == SET_MONTH){
            time_state = SET_YEAR;
        }
        else if(time_state == SET_YEAR){
            settime(hour, minute, second, ampm, day, month, year, weekday);
            print_string_to_oled("time set!", 9);
            selecting_state = 0;
            current_mode = SHOW_TIME;
        }
    }
    else if(((current_mode & SET_ALARM) >> 0x02U) == 0x01U){
        if(time_state == SET_HOUR){
            time_state = SET_MINUTE;
        }
        else if(time_state == SET_MINUTE){
            time_state = SET_SECOND;
        }
        else if(time_state == SET_SECOND){
            time_state = SET_AM_PM;
        }
        else if(time_state == SET_AM_PM){
            time_state = SET_DAY;
        }
        else if(time_state == SET_DAY){
            setalarmA(hour, minute, second, ampm, day);
            print_string_to_oled("alarm set!", 10);
            selecting_state = 0;
            current_mode = SHOW_TIME;

        }
    }
    for(volatile size_t i=0; i<10000; i++){};
}