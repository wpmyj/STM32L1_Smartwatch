#ifndef SENSORS_H
#define SENSORS_H

#include "stm32l1xx.h"

// I2C1 speed in Hz
#define I2C1_SPEED 100000

// GPIOB MODER register offsets and values
#define MODER6_OFFSET 0xC
#define MODER6_VALUE 0x2
#define MODER7_OFFSET 0xE
#define MODER7_VALUE 0x2

// GPIOB OTYPER register offsets and values
#define OTYPER6_OFFSET 0x6
#define OTYPER7_VALUE 0x1
#define OTYPER7_OFFSET 0x7
#define OTYPER7_VALUE 0x1

// GPIOB OSPEEDR register offsets and values
#define OSPEEDR6_OFFSET 0xC
#define OSPEEDR6_VALUE 0x1
#define OSPEEDR7_OFFSET 0xE
#define OSPEEDR7_VALUE 0x1

//GPIOB AFRL register offsets and values
#define AFRL6_OFFSET 0x18
#define AFRL6_VALUE 0x4
#define AFRL7_OFFSET 0x1C
#define AFRL7_VALUE 0x4

//I2C1 CR1 register offsets and values
#define PE_OFFSET 0x0
#define PE_VALUE 0x1

//I2C1 CR2 register offsets and values
#define FREQ_OFFSET 0x0
#define FREQ_VALUE 0x20

//I2C1 CCR register offsets and values

#endif
