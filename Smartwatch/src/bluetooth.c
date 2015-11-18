#include "bluetooth.h"

static void bluetooth_UART_Init(uint16_t baudrate);
static void sendByte(uint8_t data);
static uint8_t USART1_flagStatus(uint16_t flag);
static void USART1_ClearFlag(uint16_t flag);

void bluetooth_UART_Init(uint16_t baudrate){

    double usart_div = 0;
    uint32_t mantissa = 0;
    uint8_t fraction = 0;

    // Enable GPIOA peripheral clock
    RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
    // Enable USART1 peripheral clock
    RCC->APB2ENR |= RCC_APB2ENR_USART1EN;

    /* GPIO configuration */

    // Set MODER register
    GPIOA->MODER |= (MODER9_VALUE << MODER9_OFFSET) | (MODER10_VALUE << MODER9_OFFSET);
    // Set OSPEEDR register
    GPIOA->OSPEEDR |= (OSPEEDR9_VALUE << OSPEEDR9_OFFSET) | (OSPEEDR10_VALUE << OSPEEDR10_OFFSET);
    // Set PUPDR register
    GPIOA->PUPDR |= (PUPDR9_VALUE << PUPDR9_OFFSET) | (PUPDR10_VALUE << PUPDR10_OFFSET);
    // Set AF function
    GPIOA->AFR[1] |= (AFRH9_VALUE << AFRH9_OFFSET) | (AFRH10_VALUE << AFRH10_OFFSET);

    /* NVIC configuration */

    // ISER1 register configuration
    NVIC->ISER[1] |= RS5_VALUE << RS5_OFFSET;
    NVIC->IP[IP5_OFFSET] |= IP5_VALUE;

    /* USART configuration */

    // Set CR1 register
    USART1->CR1 |= (OVER8_VALUE << OVER8_OFFSET) | (TE_VALUE << TE_OFFSET) | (RE_VALUE << RE_OFFSET) | (UE_VALUE << UE_OFFSET) | (RXNEIE_VALUE << RXNEIE_OFFSET);
    
    usart_div = APB2_FREQ / (8 * baudrate);
    // Set baudrate
    fraction = round((usart_div - (uint16_t)usart_div) * 8);
    mantissa = usart_div + (fraction / 8);
    USART1->BRR = mantissa << 4 | (fraction & 0b111);

}

static void sendByte(uint8_t data){ 
 
    USART1->DR = data;
}

static uint8_t USART1_flagStatus(uint16_t flag){

    if(!(USART1->SR & flag))
        return 0;
    return 1;

}

static void USART1_ClearFlag(uint16_t flag){

    USART1->SR = ~(uint32_t)flag;

}

void USART1_IRQHandler(void){   

    USART1_ClearFlag(USART_SR_RXNE);

}
