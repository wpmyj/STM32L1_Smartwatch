#include "button.h"

static void button_peripheralInit(void);

uint32_t cnt;

void button_t(void){

    button_peripheralInit();
    for(;;);

}

static void button_peripheralInit(void){

    // Enable SYSCFG peripheral clock
    RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;
    // Enable GPIOA peripheral clock
    RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
    // Enable TIM2 peripheral clock
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;

    /* GPIO configuration */

    GPIOA->PUPDR |= BTN_PUPDR3_VALUE << BTN_PUPDR3_OFFSET;

    /* EXTI configuration */

    // IMR register configuration
    EXTI->IMR |= CLK_IMR3_VALUE << CLK_IMR3_OFFSET;
    // FTSR register configuration
    EXTI->FTSR |= CLK_FTSR3_VALUE << CLK_FTSR3_OFFSET;

    /* NVIC configuration */

    // ISER0 register configuration
    NVIC->ISER[0] |= BTN_RS9_VALUE << BTN_RS9_OFFSET;
    NVIC->IP[BTN_IP9_OFFSET] |= BTN_IP9_VALUE;

}


void EXTI3_IRQHandler(void){

    cnt++;
    EXTI->PR |= EXTI_PR_PR3;

}
