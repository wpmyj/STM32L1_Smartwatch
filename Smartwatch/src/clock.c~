#include "clock.h"

static void clock_peripheralInit(void);
static void RTC_setTime(Time time);
static Time RTC_getTime(void);
static uint8_t RTC_flagStatus(uint16_t flag);
static void RTC_clearFlag(uint16_t flag);

Time time;
Time tim;

void clock_t(void){

    tim.year = 14;
    tim.month = 12;
    tim.day = 29;
    tim.hours = 14;
    tim.minutes = 37;
    tim.seconds = 29;

    clock_peripheralInit();
    RTC_setTime(tim);
    for(;;)
        time = RTC_getTime();

}

static void clock_peripheralInit(void){

    // Enable power interface
    RCC->APB1ENR |= RCC_APB1ENR_PWREN;
    // Access to RTC, RTC Backup and RCC CSR registers enabled
    PWR->CR |= CLK_DBP_VALUE << CLK_DBP_OFFSET;
    // Reset rtc interface
    RCC->CSR |= CLK_RTCRST_VALUE << CLK_RTCRST_OFFSET;
    RCC->CSR &= ~(CLK_RTCRST_VALUE << CLK_RTCRST_OFFSET);
    // Set LSI clock source
    RCC->CSR |= RCC_CSR_LSEON;
    // Wait for the LSERDY flag
    while(!(RCC->CSR & RCC_CSR_LSERDY));
    // Select clock source and enable RTC
    RCC->CSR |= RCC_CSR_RTCEN | (CLK_RTCSEL_VALUE << CLK_RTCSEL_OFFSET);
    // Disable the RTC write protection
    RTC->WPR |= CLK_WPR1;
    RTC->WPR |= CLK_WPR2;
    // Set ISR register(enter initialization)
    RTC->ISR |= CLK_INIT_VALUE << CLK_INIT_OFFSET;
    // Wait for the INITF flag
    while(!RTC_flagStatus(RTC_ISR_INITF));
    // Set PRER register
    RTC->PRER |= CLK_PREDIV_S_VALUE << CLK_PREDIV_S_OFFSET;
    RTC->PRER |= CLK_PREDIV_A_VALUE << CLK_PREDIV_A_OFFSET;
    // Set ALARMA to one minute
    // Set ISR register(exit initialization)
    RTC->ISR &= ~(CLK_INIT_VALUE << CLK_INIT_OFFSET);
    // Enable RTC write protection
    RTC->WPR = 0xFF;

}

static void RTC_setTime(Time time){

    // Disable the RTC write protection
    RTC->WPR |= CLK_WPR1;
    RTC->WPR |= CLK_WPR2;
    // Set ISR register(enter initialization)
    RTC->ISR |= CLK_INIT_VALUE << CLK_INIT_OFFSET;
    // Wait for the INITF flag
    while(!RTC_flagStatus(RTC_ISR_INITF));
    // Set time
    RTC->TR |= ((time.hours / 10) << RTC_HT_OFFSET) | ((time.hours % 10) << RTC_HU_OFFSET) | ((time.minutes / 10) << RTC_MNT_OFFSET) | ((time.minutes % 10) << RTC_MNU_OFFSET) | 
               ((time.seconds / 10) << RTC_ST_OFFSET) | ((time.seconds % 10) << RTC_SU_OFFSET); 
    // Set date
    RTC->DR |= ((time.year / 10) << RTC_YT_OFFSET) | ((time.year % 10) << RTC_YU_OFFSET) | ((time.month / 10) << RTC_MT_OFFSET) | ((time.month % 10) << RTC_MU_OFFSET) | 
               ((time.day / 10) << RTC_DT_OFFSET) | ((time.day % 10) << RTC_DU_OFFSET);      
    // Set ISR register(exit initialization)
    RTC->ISR &= ~(CLK_INIT_VALUE << CLK_INIT_OFFSET);
    // Enable RTC write protection
    RTC->WPR = 0xFF;

}

static Time RTC_getTime(void){

    Time time;
    uint32_t reg;

    // Clear WSR flag
    RTC_clearFlag(RTC_ISR_RSF);
    // Wait for the WSR flag
    while(!RTC_flagStatus(RTC_ISR_RSF));

    // get time
    reg = RTC->TR;
    time.hours = (((reg & (0b11 << RTC_HT_OFFSET)) >> RTC_HT_OFFSET) * 10) + ((reg & (0b1111 << RTC_HU_OFFSET)) >> RTC_HU_OFFSET);
    time.minutes = (((reg & (0b111 << RTC_MNT_OFFSET)) >> RTC_MNT_OFFSET) * 10) + ((reg & (0b1111 << RTC_MNU_OFFSET)) >> RTC_MNU_OFFSET);
    time.seconds = (((reg & (0b111 << RTC_ST_OFFSET)) >> RTC_ST_OFFSET) * 10) + ((reg & (0b1111 << RTC_SU_OFFSET)) >> RTC_SU_OFFSET);

    // Get date
    reg = RTC->DR;
    time.year = (((reg & (0b1111 << RTC_YT_OFFSET)) >> RTC_YT_OFFSET) * 10) + ((reg & (0b1111 << RTC_YU_OFFSET)) >> RTC_YU_OFFSET);
    time.month = (((reg & (0b1 << RTC_MT_OFFSET)) >> RTC_MT_OFFSET) * 10) + ((reg & (0b1111 << RTC_MU_OFFSET)) >> RTC_MU_OFFSET);
    time.day = (((reg & (0b11 << RTC_DT_OFFSET)) >> RTC_DT_OFFSET) * 10) + ((reg & (0b1111 << RTC_DU_OFFSET)) >> RTC_DU_OFFSET);

    return time;

}

static uint8_t RTC_flagStatus(uint16_t flag){

    if(!(RTC->ISR & flag))
        return 0;
    return 1;

}

static void RTC_clearFlag(uint16_t flag){

    RTC->ISR &= ~(uint32_t)flag;

}
