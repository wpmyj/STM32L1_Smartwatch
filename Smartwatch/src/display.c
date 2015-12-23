#include "display.h"

static void display_peripheralInit(void);
static void display_enable(void);
static void display_disable(void);
static void display_setPicture(Picture* picture);
static void display_clearPicture(void);
static uint8_t display_reverseByte(uint8_t byte);
static void SPI1_CSEnable(void);
static void SPI1_CSDisable(void);
static void SPI1_sendByte(uint8_t byte);

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
    GPIOC->MODER |= DISP_MODER4C_VALUE << DISP_MODER4C_OFFSET;
    // Set OSPEEDR(C) register
    GPIOC->OSPEEDR |= DISP_OSPEEDR4C_VALUE << DISP_OSPEEDR4C_OFFSET;

    // Set MODER(A) register
    GPIOA->MODER |= (DISP_MODER4A_VALUE << DISP_MODER4A_OFFSET) | (DISP_MODER5A_VALUE << DISP_MODER5A_OFFSET) | (DISP_MODER6A_VALUE << DISP_MODER6A_OFFSET) | (DISP_MODER7A_VALUE << DISP_MODER7A_OFFSET);
    // Set OSPEEDR(A) register
    GPIOA->OSPEEDR |= (DISP_OSPEEDR4A_VALUE << DISP_OSPEEDR4A_OFFSET) | (DISP_OSPEEDR5A_VALUE << DISP_OSPEEDR5A_OFFSET) | (DISP_OSPEEDR6A_VALUE << DISP_OSPEEDR6A_OFFSET) | (DISP_OSPEEDR7A_VALUE << DISP_OSPEEDR7A_OFFSET);
    // Set AFR(A) register
    GPIOA->AFR[0] |= (DISP_AFRL5_VALUE << DISP_AFRL5_OFFSET) | (DISP_AFRL6_VALUE << DISP_AFRL6_OFFSET) | (DISP_AFRL7_VALUE << DISP_AFRL7_OFFSET);

    /* TIM configuration */

    // Set PSC register
    TIM3->PSC = DISP_PSC_VALUE;
    // Set ARR register
    TIM3->ARR = DISP_ARR_VALUE;
    // Set EGR register
    TIM3->EGR |= DISP_UG_VALUE << DISP_UG_OFFSET;
    // Set CCMR1 register
    TIM3->CCMR1 |= DISP_OC1M_VALUE << DISP_OC1M_OFFSET;
    // Set CCER register
    TIM3->CCER |= DISP_CC1E_VALUE << DISP_CC1E_OFFSET;
    // Set CCR1 register
    TIM3->CCR1 = DISP_CCR1_VALUE;

    /* SPI configuration */

    // Set CR1 register
    SPI1->CR1 |= (DISP_BIDIMODE_VALUE << DISP_BIDIMODE_OFFSET) | (DISP_BIDIOE_VALUE << DISP_BIDIOE_OFFSET) | (DISP_SSM_VALUE << DISP_SSM_OFFSET) | (DISP_SSI_VALUE << DISP_SSI_OFFSET) | (DISP_BR_VALUE << DISP_BR_OFFSET) | (DISP_MSTR_VALUE << DISP_MSTR_OFFSET);
    SPI1->CR1 |= DISP_SPE_VALUE << DISP_SPE_OFFSET;

}

static void display_enable(void){

    // Set ENABLE pin high
    GPIOC->ODR |= 1 << DISPLAY_ENABLE;
    // Enable TIM3
    TIM3->CR1 |= DISP_CEN_VALUE << DISP_CEN_OFFSET;

}

static void display_disable(void){

    // Set ENABLE pin to low
    GPIOC->ODR = ~(1 << DISPLAY_ENABLE);
    // Disable TIM3
    TIM3->CR1 = ~(DISP_CEN_VALUE << DISP_CEN_OFFSET);

}

static void display_setPicture(Picture* picture){

    short lineNum;
    uint8_t byteNum;

    // Enable CS
    SPI1_CSEnable();
    SPI1_sendByte(SET_PICTURE);
    for(lineNum = 1; lineNum <= picture->rows; lineNum++){
        while(!(SPI1->SR & SPI_SR_TXE));
        SPI1_sendByte(display_reverseByte(lineNum));
        for(byteNum = 0; byteNum < picture->cols; byteNum++){
            while(!(SPI1->SR & SPI_SR_TXE));
            SPI1_sendByte(~picture->pixels[(lineNum - 1) * picture->cols + byteNum]);
        }
        // Send dummy byte
        while(!(SPI1->SR & SPI_SR_TXE));
        SPI1_sendByte(0);
    }
    // Send dummy byte
    while(!(SPI1->SR & SPI_SR_TXE));
    SPI1_sendByte(0);
    while(SPI1->SR & SPI_SR_BSY);
    // Disable CS
    SPI1_CSDisable();

}

static void display_clearPicture(void){

    // Enable CS
    SPI1_CSEnable();
    // Send data
    while(!(SPI1->SR & SPI_SR_TXE));
    SPI1_sendByte(CLEAR_DISPLAY);
    // Send dummy bytes
    while(!(SPI1->SR & SPI_SR_TXE));
    SPI1_sendByte(0);
    while(!(SPI1->SR & SPI_SR_TXE));
    SPI1_sendByte(0);
    while(SPI1->SR & SPI_SR_BSY);
    // Disable CS
    SPI1_CSDisable();

}

static uint8_t display_reverseByte(uint8_t byte){

    return ((byte * 0x0802LU & 0x22110LU) | (byte * 0x8020LU & 0x88440LU)) * 0x10101LU >> 16;;
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

    // Send byte
    SPI1->DR = byte;

}

