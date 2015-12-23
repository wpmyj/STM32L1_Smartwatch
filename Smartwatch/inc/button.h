#ifndef BUTTON_H
#define BUTTON_H

#include "stm32l1xx.h"

// GPIO PUPDR register offsets and values
#define BTN_PUPDR3_OFFSET 0x6
#define BTN_PUPDR3_VALUE 0x1

// EXTI IMR register offsets and values
#define CLK_IMR3_OFFSET 0x3
#define CLK_IMR3_VALUE 0x1
// EXTI FTSR register offsets and values
#define CLK_FTSR3_OFFSET 0x3
#define CLK_FTSR3_VALUE 0x1

// NVIC ISER0 register offsets and values
#define BTN_RS9_OFFSET EXTI3_IRQn
#define BTN_RS9_VALUE 0x1
#define BTN_RS28_OFFSET TIM2_IRQn
#define BTN_RS28_VALUE 0x1
// NVIC IP register offsets and values
#define BTN_IP9_OFFSET EXTI3_IRQn // Priority
#define BTN_IP9_VALUE 0x0
#define BTN_IP28_OFFSET TIM2_IRQn
#define BTN_IP28_VALUE 0x0

// TIM2 CR1 register offsets and values
#define BTN_CEN_OFFSET 0x0
#define BTN_CEN_VALUE 0x1
// TIM2 PSC register value
#define BTN_PSC_VALUE 0x80
// TIM2 ARR register value
#define BTN_ARR_VALUE 0xFA
// Set ERG register offsets and values
#define BTN_UG_OFFSET 0x0
#define BTN_UG_VALUE 0x1
// TIM2 DIER register offsets and values
#define BTN_UIE_OFFSET 0x0
#define BTN_UIE_VALUE 0x1


void button_t(void);
void EXTI3_IRQHandler(void);

#endif
