#include "display.h"

static void display_peripheralInit(void);
static void display_enable(void);
static void display_disable(void);
static void display_setPicture(Picture picture);
static void display_clearPicture(void);
static void SPI1_CSEnable(void);
static void SPI1_CSDisable(void);
static void SPI1_sendByte(uint8_t byte);
static uint8_t SPI1_flagStatus(uint16_t flag);

void display_t(void){

    // Init display peripheral
    display_peripheralInit();
    // Enable display
    display_enable();
    // Clear display
    display_clearPicture();

}

static void display_peripheralInit(void){

    // Enable GPIOA and GPIOC peripheral clock
    RCC->AHBENR |= RCC_AHBENR_GPIOAEN | RCC_AHBENR_GPIOCEN;
    // Enable TIM3 peripheral clock
    RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
    // Enable SPI1 peripheral clock
    RCC->APB2ENR |= RCC_APB2ENR_SPI1EN;

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
    GPIOA->AFR[0] |= (AFRL5_VALUE << AFRL5_OFFSET) | (AFRL6_VALUE << AFRL6_OFFSET) | (AFRL7_VALUE << AFRL7_OFFSET);

    /* TIM configuration */

    // Set PSC register
    TIM3->PSC = PSC_VALUE;
    // Set ARR register
    TIM3->ARR = ARR_VALUE;
    // Set EGR register
    TIM3->EGR |= UG_VALUE << UG_OFFSET;
    // Set CCMR1 register
    TIM3->CCMR1 |= OC1M_VALUE << OC1M_OFFSET;
    // Set CCER register
    TIM3->CCER |= CC1E_VALUE << CC1E_OFFSET;
    // Set CCR1 register
    TIM3->CCR1 = CCR1_VALUE;

    /* SPI configuration */

    SPI1->CR1 |= (BIDIMODE_VALUE << BIDIMODE_OFFSET) | (BIDIOE_VALUE << BIDIOE_OFFSET) | (SSM_VALUE << SSM_OFFSET) | (SSI_VALUE << SSI_OFFSET) | (BR_VALUE << BR_OFFSET) | (MSTR_VALUE << MSTR_OFFSET);
    SPI1->CR1 |= SPE_VALUE << SPE_OFFSET;

}

static void display_enable(void){

    // Set ENABLE pin high
    GPIOC->ODR |= 1 << DISPLAY_ENABLE;
    // Enable TIM3
    TIM3->CR1 |= CEN_VALUE << CEN_OFFSET;

}

static void display_disable(void){

    // Set ENABLE pin to low
    GPIOC->ODR = ~(1 << DISPLAY_ENABLE);
    // Disable TIM3
    TIM3->CR1 = ~(CEN_VALUE << CEN_OFFSET);

}

static void display_setPicture(Picture picture){

    /*uint8_t lineNum;
    uint8_t byteNum;

    // Enable CS
    SPI1_CSEnable();
    // Send data
    for(lineNum = 0; lineNum < picture.height; lineNum++){
        SPI1_sendByte(lineNum);
        for(byteNum = 0; byteNum < picture.width; byteNum++){
            SPI1_sendByte(0);
        }
    }
    // Send dummy bytes
    SPI1_sendByte(0);
    SPI1_sendByte(0);
    while(SPI1_flagStatus(SPI_SR_BSY));
    // Disable CS
    SPI1_CSDisable();*/

}

static void display_clearPicture(void){

    // Enable CS
    SPI1_CSEnable();
    // Send data
    SPI1_sendByte(CLEAR_DISPLAY);
    // Send dummy bytes
    SPI1_sendByte(0);
    SPI1_sendByte(0);
    while(SPI1_flagStatus(SPI_SR_BSY));
    // Disable CS
    SPI1_CSDisable();

}

static void SPI1_CSEnable(void){
    
    // Set CS to high
    GPIOA->ODR |= 1 << SPI_CS;

}

static void SPI1_CSDisable(void){

    // Set CS to low
    GPIOA->ODR = ~(1 << SPI_CS);

}

static void SPI1_sendByte(uint8_t byte){

    SPI1->DR = byte;
    while(!SPI1_flagStatus(SPI_SR_TXE));

}

uint8_t SPI1_flagStatus(uint16_t flag){

    if(!(SPI1->SR & flag))
        return 0;
    return 1;

}
