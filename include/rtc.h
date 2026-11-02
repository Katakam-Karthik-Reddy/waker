#ifndef RTC_H
#define RTC_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "register.h"

/*****************************************************************************
* typedef for differnt resigters
*****************************************************************************/

typedef struct {
    uint32_t SU                 :4;
    uint32_t ST                 :3;
    uint32_t Reserved_7         :1;
    uint32_t MNU                :4;
    uint32_t MNT                :3;
    uint32_t Reserved_15        :1;
    uint32_t HU                 :4;
    uint32_t HT                 :2;
    uint32_t PM                 :1;
    uint32_t Reserved_23_31     :9;
} RTC_TR_T;

typedef struct {
    uint32_t DU                 :4;
    uint32_t DT                 :2;
    uint32_t Reserved_6_7       :2;
    uint32_t MU                 :4;
    uint32_t MT                 :1;
    uint32_t WDU                :3;
    uint32_t YU                 :4;
    uint32_t YT                 :4;
    uint32_t Reserved_24_31     :8;
} RTC_DR_T;

typedef struct {
    uint32_t WUCKSEL            :3;
    uint32_t TSEDGE             :1;
    uint32_t REFCKON            :1;
    uint32_t BYPSHAD            :1;
    uint32_t FMT                :1;
    uint32_t DCE                :1;
    uint32_t ALRAE              :1;
    uint32_t ALRBE              :1;
    uint32_t WUTE               :1;
    uint32_t TSE                :1;
    uint32_t ALRAIE             :1;
    uint32_t ALRBIE             :1;
    uint32_t WUTIE              :1;
    uint32_t TSIE               :1;
    uint32_t ADD1H              :1;
    uint32_t SUB1H              :1;
    uint32_t BKP                :1;
    uint32_t COSEL              :1;
    uint32_t POL                :1;
    uint32_t OSEL               :1;
    uint32_t COE                :1;
    uint32_t Reserved_24_31     :8;
} RTC_CR_T;

typedef struct {
    uint32_t ALRAWF             :1;
    uint32_t AlRBWF             :1;
    uint32_t WUTWF              :1;
    uint32_t SHPF               :1;
    uint32_t INITS              :1;
    uint32_t RSF                :1;
    uint32_t INITF              :1;
    uint32_t INIT               :1;
    uint32_t ALRAF              :1;
    uint32_t ALRBF              :1;
    uint32_t WUTF               :1;
    uint32_t TSF                :1;
    uint32_t TSOVF              :1;
    uint32_t TAMP1F             :1;
    uint32_t Reserved_14        :1;
    uint32_t Reserverd_15       :1;
    uint32_t RECALPF            :1;
    uint32_t Reserved_17_31     :15;
} RTC_ISR_T;

typedef struct {
    uint32_t PREDIV_S           :15;
    uint32_t Reserved_15        :1;
    uint32_t PREDIV_A           :7;
    uint32_t Reserved_23_31     :9;
} RTC_PRER_T;

typedef struct{
    uint32_t SU                 :4;
    uint32_t ST                 :3;
    uint32_t MSK1               :1;
    uint32_t MNU                :4;
    uint32_t MNT                :3;
    uint32_t MSK2               :1;
    uint32_t HU                 :4;
    uint32_t HT                 :2;
    uint32_t PM                 :1;
    uint32_t MSK3               :1;
    uint32_t DU                 :4;
    uint32_t DT                 :2;
    uint32_t WDSEL              :1;
    uint32_t MSK4               :1;
} RTC_ALRMAR_T;

typedef struct {
    uint32_t KEY                :8;
    uint32_t Reserved_8_31      :22;
} RTC_WPR_T;


typedef enum {
    AM      = 0x0U,
    PM      = 0x1U,
} AM_PM_T;


/*****************************************************************************
* defination with register value set
*****************************************************************************/

#define RTC_TR_R                ((volatile RTC_TR_T*)(RTC_TR))

#define RTC_DR_R                ((volatile RTC_DR_T*)(RTC_DR))

#define RTC_CR_R                ((volatile RTC_CR_T*)(RTC_CR))

#define RTC_ISR_R               ((volatile RTC_ISR_T*)(RTC_ISR))

#define RTC_PRER_R              ((volatile RTC_PRER_T*)(RTC_PRER))

#define RTC_ALRMAR_R            ((volatile RTC_ALRMAR_T*)(RTC_ALRMAR))

#define RTC_WPR_R               ((volatile RTC_WPR_T*)(RTC_WPR))

/******************************************************************************
* functions
*****************************************************************************/

uint32_t RTC_ByteToBcd(uint8_t number);

// function to set the time

void setup_rtc(void);

void enter_rtc_init_mode(void);

void exit_rtc_init_mode(void);

void sethour(uint8_t hour);

void setminutes(uint8_t minutes);

void setseconds(uint8_t seconds); 

void setAMPM(AM_PM_T AM_PM);

void setday(uint8_t day);

void setmonth(uint8_t month);

void setweekday(uint8_t weekday);

void setyear(uint32_t year);

uint8_t gethour(void);

uint8_t getminutes(void);

uint8_t getseconds(void);

AM_PM_T getampm(void);

uint8_t getday(void);

uint8_t getweekday(void);

uint8_t getmonth(void);

uint8_t getyear(void);

// ALARM function to set

void settime(uint8_t hour, uint32_t minute, uint32_t second, uint8_t ampm, uint8_t day, uint8_t month, uint8_t year, uint8_t weekday);

void setalarmA(uint32_t hour, uint32_t minute, uint32_t second, AM_PM_T ampm, uint32_t day);

// interrupt to be triggerd when alaram up
void Alarm_Handler(void); 

#ifdef __cplusplus
}
#endif

#endif //RTC_H