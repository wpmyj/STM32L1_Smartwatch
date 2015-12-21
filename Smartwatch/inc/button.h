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
#define BTN_RS9_OFFSET EXTI3_IRQn;
#define BTN_RS9_VALUE 0x1
// NVIC IP register offsets and values
#define BTN_IP9_OFFSET EXTI3_IRQn // Priority
#define BTN_IP9_VALUE 0x0 // Priority


void button_t(void);
void EXTI3_IRQHandler(void);

#endif
