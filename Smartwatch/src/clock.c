#include "clock.h"

static void clock_peripheralInit(void);
static void clock_setTime(Time time);
static Time clock_getTime(void);

Time time2;
Time tim;
uint32_t lol;

void clock_t(void){

    tim.year = 14;
    tim.month = 12;
    tim.day = 29;
    tim.hours = 14;
    tim.minutes = 37;
    tim.seconds = 29;

    clock_peripheralInit();
    clock_setTime(tim);
    for(;;)
        time2 = clock_getTime();

}

static void clock_peripheralInit(void){

    // Enable power interface
    RCC->APB1ENR |= RCC_APB1ENR_PWREN;

    /* RTC configuration */

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
    while(!(RTC->ISR & RTC_ISR_INITF));
    // Set PRER register
    RTC->PRER |= CLK_PREDIV_S_VALUE << CLK_PREDIV_S_OFFSET;
    RTC->PRER |= CLK_PREDIV_A_VALUE << CLK_PREDIV_A_OFFSET;
    // Wait for ALRAWF flag
    while(!(RTC->ISR & RTC_ISR_ALRAWF));
    // Set ALRMAR register
    RTC->ALRMAR |= (CLK_MSK2_VALUE << CLK_MSK2_OFFSET) | (CLK_MSK3_VALUE << CLK_MSK3_OFFSET) | (CLK_MSK4_VALUE << CLK_MSK4_OFFSET);
    // Enable ALARM A and interrupts
    RTC->CR |= (CLK_ALRAE_VALUE << CLK_ALRAE_OFFSET) | (CLK_ALRAIE_VALUE << CLK_ALRAIE_OFFSET);
    // Set ALARMA mask
    // Set ISR register(exit initialization)
    RTC->ISR &= ~(CLK_INIT_VALUE << CLK_INIT_OFFSET);
    // Enable RTC write protection
    RTC->WPR = 0xFF;

    /* EXTI configuration */

    // IMR register configuration
    EXTI->IMR |= CLK_IMR17_VALUE << CLK_IMR17_OFFSET;
    // EMR register configuration
    EXTI->EMR |= CLK_EMR17_VALUE << CLK_EMR17_OFFSET;
    // RTSR register configuration
    EXTI->RTSR |= CLK_RTSR17_VALUE << CLK_RTSR17_OFFSET;

    /* NVIC configuration */

    // ISER1 register configuration
    NVIC->ISER[1] |= CLK_RS8_VALUE << CLK_RS8_OFFSET;
    NVIC->IP[CLK_IP8_OFFSET] |= CLK_IP8_VALUE;

}

static void clock_setTime(Time time){

    // Disable the RTC write protection
    RTC->WPR |= CLK_WPR1;
    RTC->WPR |= CLK_WPR2;
    // Set ISR register(enter initialization)
    RTC->ISR |= CLK_INIT_VALUE << CLK_INIT_OFFSET;
    // Wait for the INITF flag
    while(!(RTC->ISR & RTC_ISR_INITF));
    // Set time
    RTC->TR = ((time.hours / 10) << CLK_HT_OFFSET) | ((time.hours % 10) << CLK_HU_OFFSET) | ((time.minutes / 10) << CLK_MNT_OFFSET) | ((time.minutes % 10) << CLK_MNU_OFFSET) | 
               ((time.seconds / 10) << CLK_ST_OFFSET) | ((time.seconds % 10) << CLK_SU_OFFSET); 
    // Set date
    RTC->DR = ((time.year / 10) << CLK_YT_OFFSET) | ((time.year % 10) << CLK_YU_OFFSET) | ((time.month / 10) << CLK_MT_OFFSET) | ((time.month % 10) << CLK_MU_OFFSET) | 
               ((time.day / 10) << CLK_DT_OFFSET) | ((time.day % 10) << CLK_DU_OFFSET);      
    // Set ISR register(exit initialization)
    RTC->ISR &= ~(CLK_INIT_VALUE << CLK_INIT_OFFSET);
    // Enable RTC write protection
    RTC->WPR = 0xFF;

}

static Time clock_getTime(void){

    Time time;
    uint32_t reg;

    // Clear WSR flag
    RTC->ISR &= ~RTC_ISR_RSF;
    // Wait for the WSR flag
    while(!(RTC->ISR & RTC_ISR_RSF));

    reg = RTC->TR;
    // Get time
    time.hours = (((reg & (0b11 << CLK_HT_OFFSET)) >> CLK_HT_OFFSET) * 10) + ((reg & (0b1111 << CLK_HU_OFFSET)) >> CLK_HU_OFFSET);
    time.minutes = (((reg & (0b111 << CLK_MNT_OFFSET)) >> CLK_MNT_OFFSET) * 10) + ((reg & (0b1111 << CLK_MNU_OFFSET)) >> CLK_MNU_OFFSET);
    time.seconds = (((reg & (0b111 << CLK_ST_OFFSET)) >> CLK_ST_OFFSET) * 10) + ((reg & (0b1111 << CLK_SU_OFFSET)) >> CLK_SU_OFFSET);

    // Get date
    reg = RTC->DR;
    time.year = (((reg & (0b1111 << CLK_YT_OFFSET)) >> CLK_YT_OFFSET) * 10) + ((reg & (0b1111 << CLK_YU_OFFSET)) >> CLK_YU_OFFSET);
    time.month = (((reg & (0b1 << CLK_MT_OFFSET)) >> CLK_MT_OFFSET) * 10) + ((reg & (0b1111 << CLK_MU_OFFSET)) >> CLK_MU_OFFSET);
    time.day = (((reg & (0b11 << CLK_DT_OFFSET)) >> CLK_DT_OFFSET) * 10) + ((reg & (0b1111 << CLK_DU_OFFSET)) >> CLK_DU_OFFSET);

    return time;

}

void RTC_Alarm_IRQHandler(void){

    lol++;
    RTC->ISR &= ~RTC_ISR_ALRAF;
    EXTI->PR |= EXTI_PR_PR17;

}
