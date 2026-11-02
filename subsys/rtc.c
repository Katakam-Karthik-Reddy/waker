#include <stdbool.h>
#include <stdint.h>

#include "rtc.h"
#include "types.h"
#include "system.h"
#include "uart.h"
#include "utils.h"
#include "timer.h"
#include "core.h"
#include "systick.h"



uint32_t RTC_ByteToBcd(uint8_t number){
    return (uint32_t)((((number/10)/10)%10 << 8U) | (((number/10)%10) << 4U) | (number%10));
}

void setup_rtc(void){
    
    // Disable backup domain write protection
    PWR_CR_R->DBP           = 0x01U;
    volatile PWR_CR_T dummy __attribute__((unused));
    dummy = *(PWR_CR_R);
    while(PWR_CR_R->DBP != 0x01U){};

    // reset the backup domain software reset registers
    RCC_BDCR_R->BDRST       = 0x1U;
    RCC_BDCR_R->BDRST       = 0x0U;
    
    // Enable internal low-speed oscillator and wait for it get ready.
    RCC_CSR_R->LSION        = 0x01U;
    while(RCC_CSR_R->LSIRDY == 0x0U){};

    // select the LSI as the RTC clock and enable it.
    RCC_BDCR_R->RTCSEL      = 0x02U;
    RCC_BDCR_R->RTCEN       = 0x01U;

    // enter_rtc_init_mode();
    
    settime(12, 24, 55, 1, 20, 26, 10, 2);

    // // set the time and date
    // sethour(12);
    // setminutes(24);
    // setseconds(55);
    // setAMPM(PM);

    // setday(20);
    // setyear(26);
    // setmonth(10);
    // setweekday(2);

    // exit_rtc_init_mode();

    RTC_CR_R->BKP           = 0x00U;
}

void enter_rtc_init_mode(void){
    // Disable the write protection.
    RTC_WPR_R->KEY          = 0xCAU;
    RTC_WPR_R->KEY          = 0x53U;
    
    // enable the bypass the shadow register, so that we will not read the shadow register.
    RTC_CR_R->BYPSHAD       = 0x01U;
    
    // enter init mode and need to wait for initf to be set
    RTC_ISR_R->INIT         = 0x01U;
    while(RTC_ISR_R->INITF == 0x0U){};

    // select the am/pm format
    RTC_CR_R->FMT           = AM_PM_FORMAT;
    // setting the prescaler
    RTC_PRER_R->PREDIV_A    = 127;
    // setting the prescaler
    RTC_PRER_R->PREDIV_S    = 255;
    // disable the output for now
    RTC_CR_R->OSEL          = 0x00U;
}

void exit_rtc_init_mode(void){
    //exit init mode and wait for that 
    RTC_ISR_R->INIT         = 0x00U; 
    while(RTC_ISR_R->INITF != 0U){};

    // enable the write protection 
    RTC_WPR_R->KEY          = 0xFF;

    RTC_CR_R->ADD1H         = 0x00U;
}


void sethour(uint8_t hour){
    uint32_t temphour       = RTC_ByteToBcd(hour);
    RTC_TR_R->HT            = (temphour & 0x30U) >> 4U;
    RTC_TR_R->HU            = temphour & 0x0FU;
}

void setminutes(uint8_t minutes){
    uint32_t tempminutes    = RTC_ByteToBcd(minutes);
    RTC_TR_R->MNT           = (tempminutes & 0x70U) >> 4U;
    RTC_TR_R->MNU           = tempminutes & 0x0FU;
}

void setseconds(uint8_t seconds){
    uint32_t tempseconds    = RTC_ByteToBcd(seconds);
    RTC_TR_R->ST            = (tempseconds & 0x70U) >> 4U;
    RTC_TR_R->SU            = tempseconds & 0x0FU;
}

void setAMPM(AM_PM_T AM_PM){
    RTC_TR_R->PM            = AM_PM;
}

void setday(uint8_t day){
    uint32_t tempday        = RTC_ByteToBcd(day);
    RTC_DR_R->DT            = (tempday & 0xF0U) >> 4U;
    RTC_DR_R->DU            = (tempday & 0xFU);
}

void setmonth(uint8_t month){
    uint32_t tempmonth      = RTC_ByteToBcd(month);
    RTC_DR_R->MT            = (tempmonth & 0x10U) >> 4U;
    RTC_DR_R->MU            = (tempmonth & 0xFU);
}

void setweekday(uint8_t weekday){
    RTC_DR_R->WDU           = weekday;
}


void setyear(uint32_t year){
    uint32_t tempyear       = RTC_ByteToBcd(year);
    RTC_DR_R->YT            = (tempyear & 0xF0U) >> 4U;
    RTC_DR_R->YU            = (tempyear & 0x0FU);
}



uint8_t gethour(void){
    uint32_t tr = *(volatile uint32_t *)RTC_TR;
    return (uint8_t)((((tr& 0x300000U) >> 20 ) * 10) + ((tr & 0xF0000U) >> 16));
}

uint8_t getminutes(void){
    uint32_t tr = *(volatile uint32_t *)RTC_TR;
    return (uint8_t)(((tr & 0x7000U) >> 12) * 10) + (((tr& 0xF00U) >> 8) );
}

uint8_t getseconds(void){
    uint32_t tr = *(volatile uint32_t *)RTC_TR;
    return (uint8_t)((((tr & 0x70U) >> 4) * 10) + ((tr & 0xFU) >> 0));
}

AM_PM_T getampm(){
    return RTC_TR_R->PM ? PM : AM;
}

uint8_t getday(void){
    uint32_t dr = *(volatile uint32_t *)RTC_DR;
    return (uint8_t)((((dr & 0x30U) >> 4) * 10) + ((dr & 0xFU) >> 0U));
}

uint8_t getmonth(void){
    uint32_t mr = *(volatile uint32_t *)RTC_DR;
    return (uint32_t)((((mr & 0x1000U) >> 12U) * 10) + ((mr & 0xF00U) >> 8U));
}

uint8_t getweekday(void){
    uint32_t wd = *(volatile uint32_t *)RTC_DR;
    return (uint8_t)((wd & 0xE000U) >> 13U);
}

uint8_t getyear(void){
    uint32_t yr = *(volatile uint32_t *)RTC_DR;
    return (uint32_t)((((yr & 0xF00000U) >> 20U) * 10) + ((yr & 0xF0000U) >> 16U));
}


void settime(uint8_t hour, uint32_t minute, uint32_t second, uint8_t ampm, uint8_t day, uint8_t month, uint8_t year, uint8_t weekday){
    enter_rtc_init_mode();
    sethour(hour);
    setminutes(minute);
    setseconds(second);
    setAMPM(ampm);
    setday(day);
    setmonth(month);
    setyear(year);
    setweekday(weekday);
    exit_rtc_init_mode();
}


//TODO  need to add am pm
void setalarmA(uint32_t hour, uint32_t minute, uint32_t second, AM_PM_T ampm, uint32_t day){
    // Disable the write protection.
    RTC_WPR_R->KEY          = 0xCAU;
    RTC_WPR_R->KEY          = 0x53U;

    RTC_CR_R->ALRAE         = 0x00U; // disable the alarm
    while(RTC_ISR_R->ALRAWF == 0x00U){}; // wait for this become set
    RTC_ISR_R->ALRAF        = 0x00U; // reset the alarm trigger value

    if(hour == 0){
        RTC_ALRMAR_R->MSK3 = 0x01U; // hours does not matter for set alarm
    }
    else{
        uint32_t temphour   = RTC_ByteToBcd(hour);
        RTC_ALRMAR_R->HT    = (temphour & 0x30U) >> 0x04U;
        RTC_ALRMAR_R->HU    = (temphour & 0x0FU) >> 0x00U;
    }
    if(minute == 0){
        RTC_ALRMAR_R->MSK2 = 0x01U;
    }
    else{
        uint32_t tempmintue = RTC_ByteToBcd(minute);
        RTC_ALRMAR_R->MNT   = (tempmintue & 0x70U) >> 0x04U;
        RTC_ALRMAR_R->MNU   = (tempmintue & 0x0FU) >> 0x00U;
    }
    if(second == 0){
        RTC_ALRMAR_R->MSK1  = 0x01U;
    }
    else{
        uint32_t tempsecond = RTC_ByteToBcd(second);
        RTC_ALRMAR_R->ST    = (tempsecond & 0x70U) >> 0x04U;
        RTC_ALRMAR_R->SU    = (tempsecond & 0x0FU) >> 0x00U;
    }
    RTC_ALRMAR_R->PM        = ampm;
    if(day == 0){
        RTC_ALRMAR_R->MSK4  = 0x01U;
    }
    else{
        uint32_t tempday    = RTC_ByteToBcd(day);
        RTC_ALRMAR_R->DT    = (tempday & 0x30U) >> 0x04U;
        RTC_ALRMAR_R->DU    = (tempday & 0x0FU) >> 0x00U;
    }
    
    RTC_CR_R->ALRAIE            = 0x01U; // enable the interrupt for the alarm A
    RTC_CR_R->ALRAE             = 0x01U; // enable the Alarm A

    // enable the write protection 
    RTC_WPR_R->KEY          = 0xFF;

    // enable interrupt for PA1
    EXTI_IMR_R->MR17            = 0x01U;
    EXTI_RTSR_R->TR17           = 0x01U;
    EXTI_FTSR_R->TR17            = 0x01U;
    NVIC_IPR_R[41]               = 0x2U;
    NVIC_ISER_R[1]              = 0x1U << 9U;

}

void Alarm_Handler(void){
    if(EXTI_PR_R->PR17 != 0x0U){
        EXTI_PR_R->PR17     = 0x01U;
        // for(uint8_t i=0; i< 100; i++){
            writef("alarm is up!");
            TIM3_CCR1_R->CCR1 = 1700;
            writef("light is up");
            for(uint32_t i=0; i<10000000; i++){}
            // delay_ms(1000);
            TIM3_CCR1_R->CCR1 = 900;
            writef("light is up 2");
            for(uint32_t i=0; i<10000000; i++){}
        // }
    }
}