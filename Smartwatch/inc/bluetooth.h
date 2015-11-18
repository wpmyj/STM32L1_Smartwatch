#ifndef BLUETOOTH_H
#define BLUETOOTH_H

#include "math.h"
#include "stm32l1xx.h"

#define APB2_FREQ 32000000.0

// GPIO MODER register offsets and values
#define MODER9_OFFSET 0x12
#define MODER9_VALUE 0x2
#define MODER10_OFFSET 0x14
#define MODER10_VALUE 0x2
// GPIO OSPEEDR register offsets and values
#define OSPEEDR9_OFFSET 0x12
#define OSPEEDR9_VALUE 0x2
#define OSPEEDR10_OFFSET 0x14
#define OSPEEDR10_VALUE 0x2
// GPIO PUPDR register offsets and values
#define PUPDR9_OFFSET 0x12
#define PUPDR9_VALUE 0x1
#define PUPDR10_OFFSET 0x14
#define PUPDR10_VALUE 0x1
// GPIO AFRH register offsets and values
#define AFRH9_OFFSET 0x4
#define AFRH9_VALUE 0x7
#define AFRH10_OFFSET 0x8
#define AFRH10_VALUE 0x7
// NVIC ISER1 register offsets and values
#define RS5_OFFSET (USART1_IRQn % 31)
#define RS5_VALUE 0x1
// NVIC IP register offsets and values
#define IP5_OFFSET USART1_IRQn // Priority
#define IP5_VALUE 0x0 // Priority
// USART CR1 register offsets and values
#define OVER8_OFFSET 0xF
#define OVER8_VALUE 0x1
#define TE_OFFSET 0x3
#define TE_VALUE 0x1
#define RE_OFFSET 0x2
#define RE_VALUE 0x1
#define UE_OFFSET 0xD
#define UE_VALUE 0x1
#define RXNEIE_OFFSET 0x5
#define RXNEIE_VALUE 0x1

void USART1_IRQHandler(void);

#endif
