#ifndef DISPLAY_H
#define DISPLAY_H

#include "stm32l1xx.h"

// GPIO(C) MODER register offsets and values
#define MODER4C_OFFSET 0x8
#define MODER4C_VALUE 0x1
// GPIO(C) OSPEEDR register offsets and values
#define OSPEEDR4C_OFFSET 0x8
#define OSPEEDR4C_VALUE 0x2
// GPIO(A) MODER register offsets and values
#define MODER4A_OFFSET 0x8
#define MODER4A_VALUE 0x2
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
#define AFRL4_OFFSET 0x10
#define AFRL4_VALUE 0x5
#define AFRL5_OFFSET 0x14
#define AFRL5_VALUE 0x5
#define AFRL6_OFFSET 0x18
#define AFRL6_VALUE 0x2
#define AFRL7_OFFSET 0x1C
#define AFRL7_VALUE 0x5

#endif
