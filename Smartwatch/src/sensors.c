#include "sensors.h"

static void sensors_peripheralInit(void);
static void sensors_startSHT21(uint8_t cmd);
static uint16_t sensors_getSHT21Value(void);
static void I2C1_startBit(void);
static void I2C1_stopBit(void);
static void I2C1_address(uint8_t address, uint8_t direction);
static void I2C1_sendByte(uint8_t byte);
static uint8_t I2C1_SR1flagStatus(uint16_t flag);
static uint8_t I2C1_SR2flagStatus(uint16_t flag);

void sensors_t(void){

    sensors_peripheralInit();

}

static void sensors_peripheralInit(void){

    // Enable GPIOB peripheral clock
    RCC->AHBENR |= RCC_AHBENR_GPIOBEN;
    // Enable I2C1 peripheral clock
    RCC->APB1ENR |= RCC_APB1ENR_I2C1EN;

    /* GPIO configuration */

    // Set MODER register
    GPIOB->MODER |= (SENS_MODER6_VALUE << SENS_MODER6_OFFSET) | (SENS_MODER7_VALUE << SENS_MODER7_OFFSET);
    // Set OTYPER register
    GPIOB->OTYPER |= (SENS_OTYPER6_VALUE << SENS_OTYPER6_OFFSET) | (SENS_OTYPER7_VALUE << SENS_OTYPER7_OFFSET);
    // Set OSPEEDR register
    GPIOB->OSPEEDR |= (SENS_OSPEEDR6_VALUE << SENS_OSPEEDR6_OFFSET) | (SENS_OSPEEDR7_VALUE << SENS_OSPEEDR7_OFFSET);
    // Set PUPDR register... Remove this code when tests are finished
    GPIOB->PUPDR |= (SENS_PUPDR6_VALUE << SENS_PUPDR6_OFFSET) | (SENS_PUPDR7_VALUE << SENS_PUPDR6_OFFSET);
    // Set AF function
    GPIOB->AFR[0] |= (SENS_AFRL6_VALUE << SENS_AFRL6_OFFSET) | (SENS_AFRL7_VALUE << SENS_AFRL7_OFFSET);

    /* I2C1 configuration */

    // Set CCR register
    I2C1->CCR |= SENS_CCR_VALUE << SENS_CCR_OFFSET; 
    // Set TRISE register
    I2C1->TRISE |= SENS_TRISE_VALUE << SENS_TRISE_OFFSET;
    // Set CR2 register
    I2C1->CR2 |= SENS_FREQ_VALUE << SENS_FREQ_OFFSET;
    // Set CR1 register
    I2C1->CR1 |= SENS_PE_VALUE << SENS_PE_OFFSET;

}

static void sensors_startSHT21(uint8_t cmd){

    while(I2C1_SR2flagStatus(I2C_SR2_BUSY));
    // Set start bit
    I2C1_startBit();
    while(!I2C1_SR1flagStatus(I2C_SR1_SB));
    // Send address
    I2C1_address(SHT21_ADDR, I2C1_WRITE);
    while(!I2C1_SR1flagStatus(I2C_SR1_ADDR));
    while(!I2C1_SR2flagStatus(I2C_SR2_TRA));
    // Send command
    while(!I2C1_SR1flagStatus(I2C_SR1_TXE));
    I2C1_sendByte(cmd);
    // Set stop bit
    while(!I2C1_SR1flagStatus(I2C_SR1_BTF));
    I2C1_stopBit();
    while(I2C1_SR1flagStatus(I2C_SR1_STOPF));

}

static uint16_t sensors_getSHT21Value(void){

    uint8_t msb, lsb;

    // Set ACK bit
    I2C1->CR1 |= SENS_ACK_VALUE << SENS_ACK_OFFSET;
    while(I2C1_SR2flagStatus(I2C_SR2_BUSY));
    // Set start bit
    I2C1_startBit();
    while(!I2C1_SR1flagStatus(I2C_SR1_SB));
    // Send address
    I2C1_address(SHT21_ADDR, I2C1_READ);
    while(!I2C1_SR1flagStatus(I2C_SR1_ADDR));
    while(I2C1_SR2flagStatus(I2C_SR2_TRA));
    // Read two bytes
    while(!I2C1_SR1flagStatus(I2C_SR1_RXNE));
    msb = I2C1->DR;
    while(!I2C1_SR1flagStatus(I2C_SR1_RXNE));
    lsb = I2C1->DR;
    // Reset ACK bit
    I2C1->CR1 &= ~(SENS_ACK_VALUE << SENS_ACK_OFFSET);
    // Set stop bit
    I2C1_stopBit();
    while(I2C1_SR1flagStatus(I2C_SR1_STOPF));

    return ((msb << 8) | lsb) & ~0x0003;

}


static void I2C1_startBit(void){

    // Send start bit
    I2C1->CR1 |= SENS_START_VALUE << SENS_START_OFFSET;

}

static void I2C1_stopBit(void){

    // Send stop bit
    I2C1->CR1 |= SENS_STOP_VALUE << SENS_STOP_OFFSET;

}

static void I2C1_address(uint8_t address, uint8_t direction){

    // Shift address to the left
    address = address << 1;

    if(direction == I2C1_READ)
        address |= I2C1_READ;

    // Send address
    I2C1->DR = address;

}

static void I2C1_sendByte(uint8_t byte){

    // Send byte
    I2C1->DR = byte;    

}

static uint8_t I2C1_SR1flagStatus(uint16_t flag){

    if(!(I2C1->SR1 & flag))
        return 0;
    return 1;

}

static uint8_t I2C1_SR2flagStatus(uint16_t flag){

    if(!(I2C1->SR2 & flag))
        return 0;
    return 1;

}


