#ifndef ICONS_H
#define ICONS_H

#include "stm32l1xx.h"

typedef struct Icon{

    short width;
    short height;
    const uint8_t *pixels;

} Icon;

#define HEADER_BAR_ICON_WIDTH 16
#define HEADER_BAR_ICON_HEIGHT 8

Icon getBatteryIcon0(void);
Icon getBatteryIcon25(void);
Icon getBatteryIcon50(void);
Icon getBatteryIcon75(void);
Icon getBatteryIcon100(void);
Icon getMissedCallIcon(void);
Icon getNewSmsIcon(void);
Icon getNewMailIcon(void);
Icon removeNotificationIcon(void);

#endif
