#include "bluetooth.h"

static void bluetooth_peripheralInit(uint32_t baudrate);
static void bluetooth_sendData(char* str);
static void bluetooth_readResponse(char* buffer, uint8_t len);
static void USART1_irqEnable(void);
static void USART1_sendByte(uint8_t byte);
static uint8_t USART1_receiveByte(void);
static void TIM4_enableTimer(void);
static void TIM4_disableTimer(void);
char response[30];
void bluetooth_t(void){

    

    // Init bluetooth peripherals
    bluetooth_peripheralInit(115200);
    // Set name to Smartwatch(Check first if the name has already been set)
    bluetooth_sendData("AT+NAME?");
    bluetooth_readResponse(response, sizeof(response));
    if(!strstr(response, "Smartwatch")){
        // Name has not been set. Set it!
        bluetooth_sendData("AT+NAMESmartwatch");
        bluetooth_readResponse(response, sizeof(response));
        if(!strstr(response, "OK"))
            for(;;); // BT returned error!
    }
    // Set pass to 123456(Check first if the pass has already been set)
    bluetooth_sendData("AT+PASS?");
    bluetooth_readResponse(response, sizeof(response));
    if(!strstr(response, "123456")){
        // Name has not been set. Set it!
        bluetooth_sendData("AT+PASS123456");
        bluetooth_readResponse(response, sizeof(response));
        if(!strstr(response, "OK"))
            for(;;); // BT returned error!
    }
    // Reset BT
    bluetooth_sendData("AT+RESET");
    bluetooth_readResponse(response, sizeof(response));
    if(!strstr(response, "OK"))
            for(;;); // BT returned error!
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
    // Enable TIM4 peripheral clock
    RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;

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
    NVIC->ISER[1] |= BT_RS4_VALUE << BT_RS4_OFFSET;
    // IPR register configuration
    NVIC->IP[BT_IP4_OFFSET] |= BT_IP4_VALUE;

    /* USART configuration */

    // Set CR1 register
    USART1->CR1 |= (BT_OVER8_VALUE << BT_OVER8_OFFSET) | (BT_TE_VALUE << BT_TE_OFFSET) | (BT_RE_VALUE << BT_RE_OFFSET) | (BT_UE_VALUE << BT_UE_OFFSET);
    
    usart_div = APB2_FREQ / (8 * baudrate);
    // Set baudrate
    fraction = round((usart_div - (uint16_t)usart_div) * 8);
    mantissa = usart_div + (fraction / 8);
    USART1->BRR = mantissa << 4 | (fraction & 0b111);

    /* TIM4 configuration */

    // Set CR1 register
    TIM4->CR1 |= BT_URS_VALUE << BT_URS_OFFSET;
    // Set PSC register
    TIM4->PSC = BT_PSC_VALUE;
    // Set ARR register
    TIM4->ARR = BT_ARR_VALUE;

}

static void bluetooth_sendData(char* str){

    while(*str){
        while(!(USART1->SR & USART_SR_TXE));
        USART1_sendByte(*str++);
    }

}

static void bluetooth_readResponse(char* buffer, uint8_t len){

    uint8_t i = 0;

    // Enable timer
    TIM4_enableTimer();
    // Clear update event flag
    TIM4->SR &= ~TIM_SR_UIF;
    // Reset counter
    TIM4->EGR |= BT_UG_VALUE << BT_UG_OFFSET;
    while(!(TIM4->SR & TIM_SR_UIF) && i < len - 1){
        // Check for new byte
        if((USART1->SR & USART_SR_RXNE)){
            // Reset counter
            TIM4->EGR |= BT_UG_VALUE << BT_UG_OFFSET;
            // Read byte
            buffer[i++] = USART1_receiveByte();
        }
    }
    // Add string termination character
    buffer[i] = '\0';
    // Disable timer
    TIM4_disableTimer();

}

static void USART1_irqEnable(void){

    USART1->CR1 |= (BT_RXNEIE_VALUE << BT_RXNEIE_OFFSET);

}

static void USART1_sendByte(uint8_t byte){ 
 
    // Send byte
    USART1->DR = byte;
}

static uint8_t USART1_receiveByte(void){

    // Return byte
    return USART1->DR;

}

static void TIM4_enableTimer(void){

    TIM4->CR1 |= BT_CEN_VALUE << BT_CEN_OFFSET;

}

static void TIM4_disableTimer(void){

    TIM4->CR1 &= ~(BT_CEN_VALUE << BT_CEN_OFFSET);

}

void USART1_IRQHandler(void){   

    USART1->SR &= ~USART_SR_RXNE;

}
