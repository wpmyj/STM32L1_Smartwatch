#include "uart.h"

void initUart(GPIO_TypeDef * GPIOx, USART_TypeDef * USARTx, uint8_t pin_rx, uint8_t pin_tx, uint32_t baudrate){

    double usart_div;
    uint32_t mantissa;
    uint8_t fraction;

    // Enable GPIO interface
    if(GPIOx == GPIOA)
        RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
    else if(GPIOx == GPIOB)
        RCC->AHBENR |= RCC_AHBENR_GPIOBEN;
    else if(GPIOx == GPIOC)
        RCC->AHBENR |= RCC_AHBENR_GPIOCEN;
    else if(GPIOx == GPIOD)
        RCC->AHBENR |= RCC_AHBENR_GPIODEN;
    else if(GPIOx == GPIOE)
        RCC->AHBENR |= RCC_AHBENR_GPIOEEN;

    // Set MODER register
    GPIOx->MODER |= (GPIO_Mode_AF << pin_rx * 2) | (GPIO_Mode_AF << pin_tx * 2);
    // Set OSPEEDR register
    GPIOx->OSPEEDR |= (GPIO_Speed_400KHz << pin_rx * 2) | (GPIO_Speed_400KHz << pin_tx * 2);
    // Set PUPDR register
    GPIOx->PUPDR |= (GPIO_PuPd_UP << pin_rx * 2) | (GPIO_PuPd_UP << pin_tx * 2);
    // Set AFRL/AFRH register
    if(USARTx == USART1 || USARTx == USART2 || USARTx == USART3){
        GPIOx->AFR[pin_rx >> 3] |= GPIO_AF_USART123 << (pin_rx % 8) * 4;
        GPIOx->AFR[pin_tx >> 3] |= GPIO_AF_USART123 << (pin_tx % 8) * 4;
    }
    else if(USARTx == UART4 || USARTx == UART5){
        GPIOx->AFR[pin_rx >> 3] |= GPIO_AF_UART45 << (pin_rx % 8) * 4;
        GPIOx->AFR[pin_tx >> 3] |= GPIO_AF_UART45 << (pin_tx % 8) * 4;
    }

    // Enable USART interface
    if(USARTx == USART1)
        RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
    else if(USARTx == USART2)
        RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
    else if(USARTx == USART3)
        RCC->APB1ENR |= RCC_APB1ENR_USART3EN;
    else if(USARTx == UART4)
        RCC->APB1ENR |= RCC_APB1ENR_UART4EN;
    else if(USARTx == UART5)
        RCC->APB1ENR |= RCC_APB1ENR_UART5EN;

    // Enable uart, set tx mode, rx mode and oversampling(8 -> faster speeds)
    USARTx->CR1 |= USART_CR1_UE | USART_CR1_RE | USART_CR1_TE | USART_CR1_OVER8;
    // Calculate USART_DIV
    if(USARTx == USART1)
        usart_div = APB2_FREQ / (8 * baudrate);
    else
        usart_div = APB1_FREQ / (8 * baudrate);
    // Set baudrate
    fraction = round((usart_div - (uint16_t)usart_div) * 8);
    mantissa = usart_div + (fraction / 8);
    USARTx->BRR = mantissa << 4 | (fraction & 0b111);
}

void sendByte(USART_TypeDef * USARTx, uint8_t data){  
    USARTx->DR = data;
}

uint8_t readByte(USART_TypeDef * USARTx){
    return USARTx->DR;

}

uint8_t flagStatus(USART_TypeDef * USARTx, uint16_t flag){
    if(!(USARTx->SR & flag))
        return 0;
    return 1;

}
