#include "button.h"

static void button_peripheralInit(void);
static void button_enableBtnInterrupt(void);
static void button_disableBtnInterrupt(void);
static void TIM2_enableTimer(void);
static void TIM2_disableTimer(void);

void button_t(void){

    button_peripheralInit();

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

    // Set IMR register
    EXTI->IMR |= CLK_IMR3_VALUE << CLK_IMR3_OFFSET;
    // Set FTSR register
    EXTI->FTSR |= CLK_FTSR3_VALUE << CLK_FTSR3_OFFSET;

    /* SCB configuration */

    // Set AIRCR register
    SCB->AIRCR |= BTN_VECTKEY_VALUE << BTN_VECTKEY_OFFSET;
    SCB->AIRCR |= BTN_PRIGROUP_VALUE << BTN_PRIGROUP_OFFSET;

    /* NVIC configuration */

    // Set ISER0 register 
    NVIC->ISER[0] |= (BTN_RS9_VALUE << BTN_RS9_OFFSET) | (BTN_RS28_VALUE << BTN_RS28_OFFSET);
    NVIC->IP[BTN_IP9_OFFSET] |= BTN_IP9_VALUE << 4;
    NVIC->IP[BTN_IP28_OFFSET] |= BTN_IP28_VALUE << 4;

    /* TIM2 configuration */

    // Set PSC register
    TIM2->PSC = BTN_PSC_VALUE;
    // Set ARR register
    TIM2->ARR = BTN_ARR_VALUE;
    // Set DIER register
    TIM2->DIER |= BTN_UIE_VALUE << BTN_UIE_OFFSET;

}

static void button_enableBtnInterrupt(void){

    EXTI->IMR |= CLK_IMR3_VALUE << CLK_IMR3_OFFSET;

}

static void button_disableBtnInterrupt(void){

    EXTI->IMR &= ~(CLK_IMR3_VALUE << CLK_IMR3_OFFSET);

}

static void TIM2_enableTimer(void){

    TIM2->CR1 |= BTN_CEN_VALUE << BTN_CEN_OFFSET;

}

static void TIM2_disableTimer(void){

    TIM2->CR1 &= ~(BTN_CEN_VALUE << BTN_CEN_OFFSET);

}

void EXTI3_IRQHandler(void){

    // Disable button interrupts
    button_disableBtnInterrupt();
    // Enable timer
    TIM2_enableTimer();
    // Clear interrupt flag
    EXTI->PR |= EXTI_PR_PR3;

}

void TIM2_IRQHandler(void){

    static uint16_t counter;
    static uint8_t lastButtonState, currentButtonState;
    
    // Read current button state
    currentButtonState = (GPIOA->IDR & 0b1000) >> 3;

    if(currentButtonState == lastButtonState)
        counter++;
    else
        // Reset a counter
        counter = 0;

    // Check if a counter value is 100 and return button state
    if(counter == 100){
        // Reset a counter
        counter = 0;
        // Disable timer
        TIM2_disableTimer();
        // Enable button interrupts
        button_enableBtnInterrupt();
    }

    // Save a button state
    lastButtonState = currentButtonState;    
    
    // Clear update event flag
    TIM2->SR &= ~TIM_SR_UIF;

}
