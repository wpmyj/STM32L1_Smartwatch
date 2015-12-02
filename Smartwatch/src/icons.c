#include "icons.h"

/* Battery icons */

// Empty battery icon
static const uint8_t batteryIcon_0[16] = {0b00111111, 0b11111111,
                                          0b00100000, 0b00000001,
                                          0b11100000, 0b00000001,
                                          0b11100000, 0b00000001,
                                          0b11100000, 0b00000001,
                                          0b11100000, 0b00000001,
                                          0b00100000, 0b00000001,
                                          0b00111111, 0b11111111
                                          };

// 25% battery icon
static const uint8_t batteryIcon_25[16] = {0b00111111, 0b11111111,
                                           0b00100000, 0b00001111,
                                           0b11100000, 0b00001111,
                                           0b11100000, 0b00001111,
                                           0b11100000, 0b00001111,
                                           0b11100000, 0b00001111,
                                           0b00100000, 0b00001111,
                                           0b00111111, 0b11111111
                                           };

// 50% battery icon
static const uint8_t batteryIcon_50[16] = {0b00111111, 0b11111111,
                                           0b00100000, 0b01111111,
                                           0b11100000, 0b01111111,
                                           0b11100000, 0b01111111,
                                           0b11100000, 0b01111111,
                                           0b11100000, 0b01111111,
                                           0b00100000, 0b01111111,
                                           0b00111111, 0b11111111
                                           };

// 75% battery icon
static const uint8_t batteryIcon_75[16] = {0b00111111, 0b11111111,
                                           0b00100011, 0b11111111,
                                           0b11100011, 0b11111111,
                                           0b11100011, 0b11111111,
                                           0b11100011, 0b11111111,
                                           0b11100011, 0b11111111,
                                           0b00100011, 0b11111111,
                                           0b00111111, 0b11111111
                                           };

// 100% battery icon
static const uint8_t batteryIcon_100[16] = {0b00111111, 0b11111111,
                                            0b00111111, 0b11111111,
                                            0b11111111, 0b11111111,
                                            0b11111111, 0b11111111,
                                            0b11111111, 0b11111111,
                                            0b11111111, 0b11111111,
                                            0b00111111, 0b11111111,
                                            0b00111111, 0b11111111
                                            };


/* Notification icons */

// Missed call icon
static const uint8_t missedCallIcon[16] = {0b00111111, 0b11111100,
                                           0b01000000, 0b00000010,
                                           0b10000000, 0b00000001,
                                           0b10001111, 0b11110001,
                                           0b10010000, 0b00001001,
                                           0b10010000, 0b00001001,
                                           0b10010000, 0b00001001,
                                           0b11110000, 0b00001111
                                          };

// New SMS icon
static const uint8_t newSmsIcon[16] = {0b11111111, 0b11111111,
                                   0b11000000, 0b00000011,
                                   0b10110000, 0b00001101,
                                   0b10001100, 0b00110001,
                                   0b10000011, 0b11000001,
                                   0b10000000, 0b00000001,
                                   0b10000000, 0b00000001,
                                   0b11111111, 0b11111111
                                  };

// New email
static const uint8_t newMailIcon[16] = {0b11111111, 0b11111111,
                                   0b10000000, 0b00000001,
                                   0b10001100, 0b00110001,
                                   0b10001010, 0b01010001,
                                   0b10001001, 0b10010001,
                                   0b10001000, 0b00010001,
                                   0b10000000, 0b00000001,
                                   0b11111111, 0b11111111
                                  };

// Notification icon remove mask
static const uint8_t noNotificationIcon[16] = {0};

/* Functions which are used to get Icon struct */

Icon getBatteryIcon0(void){
    
    Icon icon = {HEADER_BAR_ICON_WIDTH, HEADER_BAR_ICON_HEIGHT, batteryIcon_0};
    return icon;

}

Icon getBatteryIcon25(void){
    
    Icon icon = {HEADER_BAR_ICON_WIDTH, HEADER_BAR_ICON_HEIGHT, batteryIcon_25};
    return icon;

}

Icon getBatteryIcon50(void){
    
    Icon icon = {HEADER_BAR_ICON_WIDTH, HEADER_BAR_ICON_HEIGHT, batteryIcon_50};
    return icon;

}

Icon getBatteryIcon75(void){
    
    Icon icon = {HEADER_BAR_ICON_WIDTH, HEADER_BAR_ICON_HEIGHT, batteryIcon_75};
    return icon;

}

Icon getBatteryIcon100(void){
    
    Icon icon = {HEADER_BAR_ICON_WIDTH, HEADER_BAR_ICON_HEIGHT, batteryIcon_100};
    return icon;

}

Icon getMissedCallIcon(void){
    
    Icon icon = {HEADER_BAR_ICON_WIDTH, HEADER_BAR_ICON_HEIGHT, missedCallIcon};
    return icon;

}

Icon getNewSmsIcon(void){
    
    Icon icon = {HEADER_BAR_ICON_WIDTH, HEADER_BAR_ICON_HEIGHT, newSmsIcon};
    return icon;

}

Icon getNewMailIcon(void){
    
    Icon icon = {HEADER_BAR_ICON_WIDTH, HEADER_BAR_ICON_HEIGHT, newMailIcon};
    return icon;

}

/* Function to remove notification icons */

Icon removeNotificationIcon(void){

    Icon icon = {HEADER_BAR_ICON_WIDTH, HEADER_BAR_ICON_HEIGHT, noNotificationIcon};
    return icon;

}
