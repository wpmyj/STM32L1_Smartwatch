#include "sensors.h"

static void sensors_peripheralInit(void);

static void sensors_peripheralInit(void){

    // Enable GPIOB peripheral clock
    RCC->AHBENR |= RCC_AHBENR_GPIOBEN;
    // Enable I2C1 peripheral clock
    RCC->APB1ENR |= RCC_APB1ENR_I2C1EN;

    /* GPIO configuration */

    // Set MODER register
    GPIOB->MODER |= (MODER6_VALUE << MODER6_OFFSET) | (MODER7_VALUE << MODER7_OFFSET);
    // Set OSPEEDR register
    GPIOB->OSPEEDR |= (OSPEEDR6_VALUE << OSPEEDR6_OFFSET) | (OSPEEDR7_VALUE << OSPEEDR7_OFFSET);
    // Set AF function
    GPIOA->AFR[0] |= (AFRL6_VALUE << AFRL6_OFFSET) | (AFRL7_VALUE << AFRL7_OFFSET);

    /* I2C1 */


    //I2C1->CR1 |= 

}
