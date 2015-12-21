#include "bluetooth.h"

static void bluetooth_peripheralInit(uint32_t baudrate);
static void USART1_irqEnable(void);
static void USART1_sendData(char* str);
static void USART1_sendByte(uint8_t byte);

void bluetooth_t(void){

    // Init bluetooth peripherals
    bluetooth_peripheralInit(9600);
    // Set baudrate to 115200
    USART1_sendData("AT+BAUD8");
    // // Init bluetooth peripherals with higher baudrate
    bluetooth_peripheralInit(115200);
    // Set MODE2
    USART1_sendData("AT+MODE2");
    // Set name to SmartWatch
    USART1_sendData("AT+NAMESmartwatch");
    // Enable interrupts
    USART1_irqEnable();

}

static void bluetooth_peripheralInit(uint32_t baudrate){

    double usart_div = 0;
    uint32_t mantissa = 0;
    uint8_t fraction = 0;

    // Enable GPIOA peripheral clock
    RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
    // Enable USART1 peripheral clock
    RCC->APB2ENR |= RCC_APB2ENR_USART1EN;

    /* GPIO configuration */

    // Set MODER register
    GPIOA->MODER |= (BT_MODER9_VALUE << BT_MODER9_OFFSET) | (BT_MODER10_VALUE << BT_MODER10_OFFSET);
    // Set OSPEEDR register
    GPIOA->OSPEEDR |= (BT_OSPEEDR9_VALUE << BT_OSPEEDR9_OFFSET) | (BT_OSPEEDR10_VALUE << BT_OSPEEDR10_OFFSET);
    // Set PUPDR register
    GPIOA->PUPDR |= (BT_PUPDR9_VALUE << BT_PUPDR9_OFFSET) | (BT_PUPDR10_VALUE << BT_PUPDR10_OFFSET);
    // Set AF function
    GPIOA->AFR[1] |= (BT_AFRH9_VALUE << BT_AFRH9_OFFSET) | (BT_AFRH10_VALUE << BT_AFRH10_OFFSET);

    /* NVIC configuration */

    // ISER1 register configuration
    NVIC->ISER[1] |= BT_RS5_VALUE << BT_RS5_OFFSET;
    NVIC->IP[BT_IP5_OFFSET] |= BT_IP5_VALUE;

    /* USART configuration */

    // Set CR1 register
    USART1->CR1 |= (BT_OVER8_VALUE << BT_OVER8_OFFSET) | (BT_TE_VALUE << BT_TE_OFFSET) | (BT_RE_VALUE << BT_RE_OFFSET) | (BT_UE_VALUE << BT_UE_OFFSET);
    
    usart_div = APB2_FREQ / (8 * baudrate);
    // Set baudrate
    fraction = round((usart_div - (uint16_t)usart_div) * 8);
    mantissa = usart_div + (fraction / 8);
    USART1->BRR = mantissa << 4 | (fraction & 0b111);

}

static void USART1_irqEnable(void){

    USART1->CR1 |= (BT_RXNEIE_VALUE << BT_RXNEIE_OFFSET);

}

static void USART1_sendByte(uint8_t byte){ 
 
    // Send byte
    USART1->DR = byte;
}

static void USART1_sendData(char* str){

    while(*str){
        while(!(USART1->SR & USART_SR_TXE));
        USART1_sendByte(*str++);
    }

}

void USART1_IRQHandler(void){   

    USART1->SR &= ~USART_SR_RXNE;

}
