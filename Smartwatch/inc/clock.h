#ifndef CLOCK_H
#define CLOCK_H

#include "stm32l1xx.h"

// PWR CR register offsets and values
#define CLK_DBP_OFFSET 0x8
#define CLK_DBP_VALUE 0x1

// RCC CSR register offsets and values
#define CLK_RTCSEL_OFFSET 0x10
#define CLK_RTCSEL_VALUE 0x2

// RTC WPR register values
#define CLK_WPR1 0xCA
#define CLK_WPR2 0x53

// RTC ISR register offsets and values
#define CLK_INIT_OFFSET 0x7
#define CLK_INIT_VALUE 0x1

// RTC PRER register offsets and values
#define CLK_PREDIV_S_OFFSET 0x0
#define CLK_PREDIV_S_VALUE 0x128
#define CLK_PREDIV_A_OFFSET 0x10
#define CLK_PREDIV_A_VALUE 0x7D

// RTC DR register offsets
#define RTC_YT_OFFSET 0x14
#define RTC_YU_OFFSET 0x10
#define RTC_MT_OFFSET 0xC
#define RTC_MU_OFFSET 0x8
#define RTC_DT_OFFSET 0x4
#define RTC_DU_OFFSET 0x0

// RTC TR register offsets
#define RTC_HT_OFFSET 0x14
#define RTC_HU_OFFSET 0x10
#define RTC_MNT_OFFSET 0xC
#define RTC_MNU_OFFSET 0x8
#define RTC_ST_OFFSET 0x4
#define RTC_SU_OFFSET 0x0

typedef struct Time{

    // Calendar
    uint8_t day;
    uint8_t month;
    uint8_t year;

    // Time
    uint8_t hours;
    uint8_t minutes;
    uint8_t seconds;

} Time;

void clock_t(void);

#endif
