#include "display.h"

void display_init(void);

void display_init(void){

    // Enable GPIOA and GPIOC peripheral clock
    RCC->AHBENR |= RCC_AHBENR_GPIOAEN | RCC_AHBENR_GPIOCEN;

    /* GPIO configuration*/

    // Set MODER(C) register
    GPIOC->MODER |= MODER4C_VALUE << MODER4C_OFFSET;
    // Set OSPEEDR(C) register
    GPIOC->OSPEEDR |= OSPEEDR4C_VALUE << OSPEEDR4C_OFFSET;

    // Set MODER(A) register
    GPIOA->MODER |= (MODER4A_VALUE << MODER4A_OFFSET) | (MODER5A_VALUE << MODER5A_OFFSET) | (MODER6A_VALUE << MODER6A_OFFSET) | (MODER7A_VALUE << MODER7A_OFFSET);
    // Set OSPEEDR(A) register
    GPIOA->OSPEEDR |= (OSPEEDR4A_VALUE << OSPEEDR4A_OFFSET) | (OSPEEDR5A_VALUE << OSPEEDR5A_OFFSET) | (OSPEEDR6A_VALUE << OSPEEDR6A_OFFSET) | (OSPEEDR7A_VALUE << OSPEEDR7A_OFFSET);
    // Set AFR(A) register
    GPIOA->AFR[0] |= (AFRL4_VALUE << AFRL4_OFFSET) | (AFRL5_VALUE << AFRL5_OFFSET) | (AFRL6_VALUE << AFRL6_OFFSET) | (AFRL7_VALUE << AFRL7_OFFSET);

    /* TIM configuration */

    /* SPI configuration */

}
