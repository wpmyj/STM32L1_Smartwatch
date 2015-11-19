#include "battery.h"

static void battery_Init(void);
static void startBattery_ADC_Conversion(void);
static uint8_t getBatteryCapacity(short dr);
static uint8_t ADC1_FlagStatus(uint16_t flag);
static void ADC1_ClearFlag(uint16_t flag);

volatile uint8_t batteryCapacity;

static void battery_Init(void){
    
    // Enable GPIOA peripheral clock
    RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
    // Enable ADC1 peripheral clock
    RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;

    /* GPIO configuration */
    
    // MODER register configuration
    GPIOA->MODER |= MODER2_VALUE << MODER2_OFFSET;
    // OSPEEDR register configuration
    GPIOA->OSPEEDR |= OSPEEDR2_VALUE << OSPEEDR2_OFFSET;

    /* NVIC configuration */

    // ISER0 register configuration
    NVIC->ISER[0] |= RS17_VALUE << RS17_OFFSET;
    NVIC->IP[IP17_OFFSET] |= IP17_VALUE;

    /* ADC1 configuration */

    // CR1 register configuration
    ADC1->CR1 |= (PDI_VALUE << PDI_OFFSET) | (EOCIE_VALUE << EOCIE_OFFSET);
    // SMPR3 register configuration
    ADC1->SMPR3 |= SMP2_VALUE << SMP2_OFFSET;
    // SQR5 register configuration
    ADC1->SQR5 |= SQ1_VALUE << SQ1_OFFSET;
    // CR2 register configuration
    ADC1->CR2 |= (EOCS_VALUE << EOCS_OFFSET) | (ADON_VALUE << ADON_OFFSET);
    // Wait until ADC is ready to convert
    while(!ADC1_FlagStatus(ADC_SR_ADONS));

    for(;;)
        startBattery_ADC_Conversion();

}

static void startBattery_ADC_Conversion(void){

    while(!ADC1_FlagStatus(ADC_SR_EOC))
    // Start conversion
    ADC1->CR2 |= ADC_CR2_SWSTART;

}

static uint8_t ADC1_FlagStatus(uint16_t flag){

    if(!(ADC1->SR & flag))
        return 0;
    return 1;
}

static void ADC1_ClearFlag(uint16_t flag){

    ADC1->SR = ~(uint32_t)flag;

}

static uint8_t getBatteryCapacity(short dr){

    float voltage = (float)dr / pow(2, 12) * VDDA;

    if(voltage > MAX_V)
        return 100;
    else if(voltage < MIN_V)
        return 0;
    else
        return (voltage / MAX_V) * 100;


}

void ADC1_IRQHandler(void){   

    batteryCapacity = getBatteryCapacity(ADC1->DR);
    ADC1_ClearFlag(ADC_SR_EOC);

}
