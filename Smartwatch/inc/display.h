#ifndef DISPLAY_H
#define DISPLAY_H

#include "stm32l1xx.h"
#include "picture.h"

// Commands
#define CLEAR_DISPLAY 0b00100000
#define SET_PICTURE 0b10000000

// GPIO pins
#define DISPLAY_ENABLE 0x4
#define SPI_CS 0x4

// GPIO(C) MODER register offsets and values
#define MODER4C_OFFSET 0x8
#define MODER4C_VALUE 0x1
// GPIO(C) OSPEEDR register offsets and values
#define OSPEEDR4C_OFFSET 0x8
#define OSPEEDR4C_VALUE 0x2
// GPIO(A) MODER register offsets and values
#define MODER4A_OFFSET 0x8
#define MODER4A_VALUE 0x1
#define MODER5A_OFFSET 0xA
#define MODER5A_VALUE 0x2
#define MODER6A_OFFSET 0xC
#define MODER6A_VALUE 0x2
#define MODER7A_OFFSET 0xE
#define MODER7A_VALUE 0x2
// GPIO(A) OSPEEDR register offsets and values
#define OSPEEDR4A_OFFSET 0x8
#define OSPEEDR4A_VALUE 0x2
#define OSPEEDR5A_OFFSET 0xA
#define OSPEEDR5A_VALUE 0x2
#define OSPEEDR6A_OFFSET 0xC
#define OSPEEDR6A_VALUE 0x2
#define OSPEEDR7A_OFFSET 0xE
#define OSPEEDR7A_VALUE 0x2
// GPIO(A) AFR register offsets and values
#define AFRL5_OFFSET 0x14
#define AFRL5_VALUE 0x5
#define AFRL6_OFFSET 0x18
#define AFRL6_VALUE 0x2
#define AFRL7_OFFSET 0x1C
#define AFRL7_VALUE 0x5
// TIM3 CR1 register offsets and values
#define CEN_OFFSET 0x0
#define CEN_VALUE 0x1
// TIM3 PSC register value
#define PSC_VALUE 128
// TIM3 ARR register value
#define ARR_VALUE 2070
// TIM3 EGR register offsets and values
#define UG_OFFSET 0x0
#define UG_VALUE 0x1
// TIM3 CCMR1 register offsets and values
#define OC1M_OFFSET 0x4
#define OC1M_VALUE 0x3
// TIM3 CCER register offsets and values
#define CC1E_OFFSET 0x0
#define CC1E_VALUE 0x1
// TIM3 CCR1 value
#define CCR1_VALUE 2070
// SPI1 CR1 register offsets and values
#define BIDIMODE_OFFSET 0xF
#define BIDIMODE_VALUE 0x1
#define BIDIOE_OFFSET 0xE
#define BIDIOE_VALUE 0x1
#define SSI_OFFSET 0x8
#define SSI_VALUE 0x1
#define SSM_OFFSET 0x9
#define SSM_VALUE 0x1
#define SPE_OFFSET 0x6
#define SPE_VALUE 0x1
#define BR_OFFSET 0x3
#define BR_VALUE 0x6
#define MSTR_OFFSET 0x2
#define MSTR_VALUE 0x1

void display_t(void);

#endif
