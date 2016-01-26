#ifndef PICTURE_H
#define PICTURE_H

#include "stm32l1xx.h"
#include "icons.h"
#include "structures.h"

// picture width and height
#define WIDTH 128
#define HEIGHT 128

// Picture array size divider
#define WIDTH_DIV 8

void getPicture(Picture* picture);
void addLogoFrame(void);
void addBatteryFrame(uint8_t batPercentage);
void addCallFrame(void);
void removeCallFrame(void);
void addSmsFrame(void);
void removeSmsFrame(void);
void addMailFrame(void);
void removeMailFrame(void);
void addHumidityFrame(uint8_t humidity);
void addTemperatureFrame(uint8_t temp);
void addDateFrame(uint8_t day, uint8_t month, uint8_t year);
void addTimeFrame(uint8_t hours, uint8_t minutes);

#endif
