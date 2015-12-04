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

// New email icon
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

/* Small sized icons */

// Small zero number icon
static const uint8_t smallZeroNumberIcon[16] = {0b00111000,
                                                0b01000100,
                                                0b01000100,
                                                0b01000100,
                                                0b01000100,
                                                0b01000100,
                                                0b01000100,
                                                0b00111000
                                               };

// Small one number icon
static const uint8_t smallOneNumberIcon[16] = {0b01110000,
                                               0b00010000,
                                               0b00010000,
                                               0b00010000,
                                               0b00010000,
                                               0b00010000,
                                               0b00010000,
                                               0b01111100
                                              };

// Small two number icon
static const uint8_t smallTwoNumberIcon[16] = {0b01111000,
                                               0b00000100,
                                               0b00000100,
                                               0b00000100,
                                               0b00111000,
                                               0b01000000,
                                               0b01000000,
                                               0b01111100
                                              };

// Small three number icon
static const uint8_t smallThreeNumberIcon[16] = {0b01111000,
                                                 0b00000100,
                                                 0b00000100,
                                                 0b00000100,
                                                 0b00111000,
                                                 0b00000100,
                                                 0b00000100,
                                                 0b01111000
                                                };

// Small four number icon
static const uint8_t smallFourNumberIcon[16] = {0b01000000,
                                                0b01001000,
                                                0b01001000,
                                                0b01001000,
                                                0b01111000,
                                                0b00001000,
                                                0b00001000,
                                                0b00001000
                                               };

// Small five number icon
static const uint8_t smallFiveNumberIcon[16] = {0b00111100,
                                                0b00100000,
                                                0b00100000,
                                                0b00100000,
                                                0b00111000,
                                                0b00000100,
                                                0b00000100,
                                                0b01111000
                                                };

// Small six number icon
static const uint8_t smallSixNumberIcon[16] = {0b01111000,
                                               0b01000000,
                                               0b01000000,
                                               0b01000000,
                                               0b01111100,
                                               0b01000100,
                                               0b01000100,
                                               0b01111100
                                              };

// Small seven number icon
static const uint8_t smallSevenNumberIcon[16] = {0b01111100,
                                                 0b00000100,
                                                 0b00000100,
                                                 0b00001000,
                                                 0b00010000,
                                                 0b00010000,
                                                 0b00010000,
                                                 0b00010000
                                                };

// Small eight number icon
static const uint8_t smallEightNumberIcon[16] = {0b00111000,
                                                0b00101000,
                                                0b00101000,
                                                0b00101000,
                                                0b00111000,
                                                0b01000100,
                                                0b01000100,
                                                0b00111000
                                               };

// Small nine number icon
static const uint8_t smallNineNumberIcon[16] = {0b01111100,
                                                 0b01000100,
                                                 0b01000100,
                                                 0b01111100,
                                                 0b00000100,
                                                 0b00000100,
                                                 0b00000100,
                                                 0b00000100
                                                };

// Small percent icon
static const uint8_t smallPercentIcon[16] = {0b01100000,
                                             0b01100100,
                                             0b00001000,
                                             0b00010000,
                                             0b00010000,
                                             0b00100000,
                                             0b01001100,
                                             0b00001100
                                            };

// Small celsius icon
static const uint8_t smallCelsiusIcon[16] = {0b01110000,
                                             0b01010000,
                                             0b01110000,
                                             0b00000000,
                                             0b00000000,
                                             0b00000000,
                                             0b00000000,
                                             0b00000000
                                            };


/* Medium sized icons */

// Medium zero number icon
static const uint8_t mediumZeroNumberIcon[40] = {0b00011111, 0b11110000,
                                                 0b00111111, 0b11111000,
                                                 0b00110000, 0b00011000,
                                                 0b00110000, 0b00011000,
                                                 0b00110000, 0b00011000,
                                                 0b00110000, 0b00011000,
                                                 0b00110000, 0b00011000,
                                                 0b00110000, 0b00011000,
                                                 0b00110000, 0b00011000,
                                                 0b00110000, 0b00011000,
                                                 0b00110000, 0b00011000,
                                                 0b00110000, 0b00011000,
                                                 0b00110000, 0b00011000,
                                                 0b00110000, 0b00011000,
                                                 0b00110000, 0b00011000,
                                                 0b00110000, 0b00011000,
                                                 0b00111111, 0b11111000,
                                                 0b00011111, 0b11110000
                                                };

// Meduim one number icon
static const uint8_t mediumOneNumberIcon[40] = {0b00111111, 0b00000000,
                                                0b00111111, 0b00000000,
                                                0b00000011, 0b00000000,
                                                0b00000011, 0b00000000,
                                                0b00000011, 0b00000000,
                                                0b00000011, 0b00000000,
                                                0b00000011, 0b00000000,
                                                0b00000011, 0b00000000,
                                                0b00000011, 0b00000000,
                                                0b00000011, 0b00000000,
                                                0b00000011, 0b00000000,
                                                0b00000011, 0b00000000,
                                                0b00000011, 0b00000000,
                                                0b00000011, 0b00000000,
                                                0b00000011, 0b00000000,
                                                0b00000011, 0b00000000,
                                                0b00111111, 0b11111000,
                                                0b00111111, 0b11111000
                                               };

// Medium two number icon
static const uint8_t mediumTwoNumberIcon[40] = {0b00111111, 0b11110000,
                                                0b00111111, 0b11111000,
                                                0b00000000, 0b00011000,
                                                0b00000000, 0b00011000,
                                                0b00000000, 0b00011000,
                                                0b00000000, 0b00011000,
                                                0b00000000, 0b00011000,
                                                0b00000000, 0b00011000,
                                                0b00011111, 0b11111000,
                                                0b00111111, 0b11110000,
                                                0b00110000, 0b00000000,
                                                0b00110000, 0b00000000,
                                                0b00110000, 0b00000000,
                                                0b00110000, 0b00000000,
                                                0b00110000, 0b00000000,
                                                0b00110000, 0b00000000,
                                                0b00111111, 0b11111000,
                                                0b00111111, 0b11111000
                                               };

// Medium Three number icon
static const uint8_t mediumThreeNumberIcon[40] = {0b00111111, 0b11110000,
                                                  0b00111111, 0b11111000,
                                                  0b00000000, 0b00011000,
                                                  0b00000000, 0b00011000,
                                                  0b00000000, 0b00011000,
                                                  0b00000000, 0b00011000,
                                                  0b00000000, 0b00011000,
                                                  0b00000000, 0b00011000,
                                                  0b00001111, 0b11111000,
                                                  0b00001111, 0b11111000,
                                                  0b00000000, 0b00011000,
                                                  0b00000000, 0b00011000,
                                                  0b00000000, 0b00011000,
                                                  0b00000000, 0b00011000,
                                                  0b00000000, 0b00011000,
                                                  0b00000000, 0b00011000,
                                                  0b00111111, 0b11111000,
                                                  0b00111111, 0b11110000
                                                 };

// Medium Four number icon
static const uint8_t mediumFourNumberIcon[40] = {0b00110000, 0b00000000,
                                                 0b00110000, 0b00000000,
                                                 0b00110000, 0b01100000,
                                                 0b00110000, 0b01100000,
                                                 0b00110000, 0b01100000,
                                                 0b00110000, 0b01100000,
                                                 0b00110000, 0b01100000,
                                                 0b00110000, 0b01100000,
                                                 0b00110000, 0b01100000,
                                                 0b00110000, 0b01100000,
                                                 0b00111111, 0b11110000,
                                                 0b00111111, 0b11110000,
                                                 0b00000000, 0b01100000,
                                                 0b00000000, 0b01100000,
                                                 0b00000000, 0b01100000,
                                                 0b00000000, 0b01100000,
                                                 0b00000000, 0b01100000,
                                                 0b00000000, 0b01100000
                                                };

// Medium Five number icon
static const uint8_t mediumFiveNumberIcon[40] = {0b00001111, 0b11111000,
                                                 0b00001111, 0b11111000,
                                                 0b00001100, 0b00000000,
                                                 0b00001100, 0b00000000,
                                                 0b00001100, 0b00000000,
                                                 0b00001100, 0b00000000,
                                                 0b00001100, 0b00000000,
                                                 0b00001100, 0b00000000,
                                                 0b00001111, 0b11110000,
                                                 0b00001111, 0b11111000,
                                                 0b00000000, 0b00011000,
                                                 0b00000000, 0b00011000,
                                                 0b00000000, 0b00011000,
                                                 0b00000000, 0b00011000,
                                                 0b00000000, 0b00011000,
                                                 0b00110000, 0b00011000,
                                                 0b00111111, 0b11111000,
                                                 0b00001111, 0b11110000
                                                };

// Medium Six number icon
static const uint8_t mediumSixNumberIcon[40] = {0b00111111, 0b11000000,
                                                0b00111111, 0b11000000,
                                                0b00110000, 0b00000000,
                                                0b00110000, 0b00000000,
                                                0b00110000, 0b00000000,
                                                0b00110000, 0b00000000,
                                                0b00110000, 0b00000000,
                                                0b00110000, 0b00000000,
                                                0b00110000, 0b00000000,
                                                0b00110000, 0b00000000,
                                                0b00111111, 0b11111000,
                                                0b00111111, 0b11111000,
                                                0b00110000, 0b00011000,
                                                0b00110000, 0b00011000,
                                                0b00110000, 0b00011000,
                                                0b00110000, 0b00011000,
                                                0b00111111, 0b11111000,
                                                0b00111111, 0b11111000
                                               };

// Medium Seven number icon
static const uint8_t mediumSevenNumberIcon[40] = {0b00111111, 0b11111000,
                                                  0b00111111, 0b11111000,
                                                  0b00110000, 0b00011000,
                                                  0b00000000, 0b00011000,
                                                  0b00000000, 0b00011000,
                                                  0b00000000, 0b00011000,
                                                  0b00000000, 0b00011000,
                                                  0b00000000, 0b01111000,
                                                  0b00000000, 0b11110000,
                                                  0b00000001, 0b11100000,
                                                  0b00000011, 0b10000000,
                                                  0b00000011, 0b00000000,
                                                  0b00000011, 0b00000000,
                                                  0b00000011, 0b00000000,
                                                  0b00000011, 0b00000000,
                                                  0b00000011, 0b00000000,
                                                  0b00000011, 0b00000000,
                                                  0b00000011, 0b00000000
                                                 };

// Medium Eight number icon
static const uint8_t mediumEightNumberIcon[40] = {0b00001111, 0b11100000,
                                                  0b00001111, 0b11100000,
                                                  0b00001100, 0b01100000,
                                                  0b00001100, 0b01100000,
                                                  0b00001100, 0b01100000,
                                                  0b00001100, 0b01100000,
                                                  0b00001100, 0b01100000,
                                                  0b00001100, 0b01100000,
                                                  0b00011111, 0b11110000,
                                                  0b00111111, 0b11111000,
                                                  0b00110000, 0b00011000,
                                                  0b00110000, 0b00011000,
                                                  0b00110000, 0b00011000,
                                                  0b00110000, 0b00011000,
                                                  0b00110000, 0b00011000,
                                                  0b00110000, 0b00011000,
                                                  0b00111111, 0b11111000,
                                                  0b00011111, 0b11110000
                                                 };

// Medium Nine number icon
static const uint8_t mediumNineNumberIcon[40] = {0b00111111, 0b11111000,
                                                 0b00111111, 0b11111000,
                                                 0b00110000, 0b00011000,
                                                 0b00110000, 0b00011000,
                                                 0b00110000, 0b00011000,
                                                 0b00110000, 0b00011000,
                                                 0b00111111, 0b11111000,
                                                 0b00111111, 0b11111000,
                                                 0b00000000, 0b00011000,
                                                 0b00000000, 0b00011000,
                                                 0b00000000, 0b00011000,
                                                 0b00000000, 0b00011000,
                                                 0b00000000, 0b00011000,
                                                 0b00000000, 0b00011000,
                                                 0b00000000, 0b00011000,
                                                 0b00000000, 0b00011000,
                                                 0b00000000, 0b00011000,
                                                 0b00000000, 0b00011000
                                                };

// Medium Dot icon
static const uint8_t mediumDotIcon[40] = {0b00000000, 0b00000000,
                                          0b00000000, 0b00000000,
                                          0b00000000, 0b00000000,
                                          0b00000000, 0b00000000,
                                          0b00000000, 0b00000000,
                                          0b00000000, 0b00000000,
                                          0b00000000, 0b00000000,
                                          0b00000000, 0b00000000,
                                          0b00000000, 0b00000000,
                                          0b00000000, 0b00000000,
                                          0b00000000, 0b00000000,
                                          0b00000000, 0b00000000,
                                          0b00000000, 0b00000000,
                                          0b00000000, 0b00000000,
                                          0b00111110, 0b00000000,
                                          0b00111110, 0b00000000,
                                          0b00111110, 0b00000000,
                                          0b00111110, 0b00000000
                                         };


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

/* Functions for small sized numbers */

Icon getSmallZeroNumberIcon(void){

    Icon icon = {SMALL_FONT_ICON_WIDTH, SMALL_FONT_ICON_HEIGHT, smallZeroNumberIcon};
    return icon;

}

Icon getSmallOneNumberIcon(void){

    Icon icon = {SMALL_FONT_ICON_WIDTH, SMALL_FONT_ICON_HEIGHT, smallOneNumberIcon};
    return icon;

}

Icon getSmallTwoNumberIcon(void){

    Icon icon = {SMALL_FONT_ICON_WIDTH, SMALL_FONT_ICON_HEIGHT, smallTwoNumberIcon};
    return icon;

}

Icon getSmallThreeNumberIcon(void){

    Icon icon = {SMALL_FONT_ICON_WIDTH, SMALL_FONT_ICON_HEIGHT, smallThreeNumberIcon};
    return icon;

}

Icon getSmallFourNumberIcon(void){

    Icon icon = {SMALL_FONT_ICON_WIDTH, SMALL_FONT_ICON_HEIGHT, smallFourNumberIcon};
    return icon;

}

Icon getSmallFiveNumberIcon(void){

    Icon icon = {SMALL_FONT_ICON_WIDTH, SMALL_FONT_ICON_HEIGHT, smallFiveNumberIcon};
    return icon;

}

Icon getSmallSixNumberIcon(void){

    Icon icon = {SMALL_FONT_ICON_WIDTH, SMALL_FONT_ICON_HEIGHT, smallSixNumberIcon};
    return icon;

}

Icon getSmallSevenNumberIcon(void){

    Icon icon = {SMALL_FONT_ICON_WIDTH, SMALL_FONT_ICON_HEIGHT, smallSevenNumberIcon};
    return icon;

}

Icon getSmallEightNumberIcon(void){

    Icon icon = {SMALL_FONT_ICON_WIDTH, SMALL_FONT_ICON_HEIGHT, smallEightNumberIcon};
    return icon;

}

Icon getSmallNineNumberIcon(void){

    Icon icon = {SMALL_FONT_ICON_WIDTH, SMALL_FONT_ICON_HEIGHT, smallNineNumberIcon};
    return icon;

}

/* Funtions for medium sized numbers */

Icon getMediumZeroNumberIcon(void){

    Icon icon = {MEDIUM_FONT_ICON_WIDTH, MEDIUM_FONT_ICON_HEIGHT, mediumZeroNumberIcon};
    return icon;

}

Icon getSmallPercentIcon(void){

    Icon icon = {SMALL_FONT_ICON_WIDTH, SMALL_FONT_ICON_HEIGHT, smallPercentIcon};
    return icon;

}

Icon getMediumOneNumberIcon(void){

    Icon icon = {MEDIUM_FONT_ICON_WIDTH, MEDIUM_FONT_ICON_HEIGHT, mediumOneNumberIcon};
    return icon;

}

Icon getSmallCelsiusIcon(void){

    Icon icon = {SMALL_FONT_ICON_WIDTH, SMALL_FONT_ICON_HEIGHT, smallCelsiusIcon};
    return icon;

}

Icon getMediumTwoNumberIcon(void){

    Icon icon = {MEDIUM_FONT_ICON_WIDTH, MEDIUM_FONT_ICON_HEIGHT, mediumTwoNumberIcon};
    return icon;
}

Icon getMediumThreeNumberIcon(void){

    Icon icon = {MEDIUM_FONT_ICON_WIDTH, MEDIUM_FONT_ICON_HEIGHT, mediumThreeNumberIcon};
    return icon;

}

Icon getMediumFourNumberIcon(void){

    Icon icon = {MEDIUM_FONT_ICON_WIDTH, MEDIUM_FONT_ICON_HEIGHT, mediumFourNumberIcon};
    return icon;

}

Icon getMediumFiveNumberIcon(void){

    Icon icon = {MEDIUM_FONT_ICON_WIDTH, MEDIUM_FONT_ICON_HEIGHT, mediumFiveNumberIcon};
    return icon;

}

Icon getMediumSixNumberIcon(void){

    Icon icon = {MEDIUM_FONT_ICON_WIDTH, MEDIUM_FONT_ICON_HEIGHT, mediumSixNumberIcon};
    return icon;

}

Icon getMediumSevenNumberIcon(void){

    Icon icon = {MEDIUM_FONT_ICON_WIDTH, MEDIUM_FONT_ICON_HEIGHT, mediumSevenNumberIcon};
    return icon;

}

Icon getMediumEightNumberIcon(void){

    Icon icon = {MEDIUM_FONT_ICON_WIDTH, MEDIUM_FONT_ICON_HEIGHT, mediumEightNumberIcon};
    return icon;

}

Icon getMediumNineNumberIcon(void){

    Icon icon = {MEDIUM_FONT_ICON_WIDTH, MEDIUM_FONT_ICON_HEIGHT, mediumNineNumberIcon};
    return icon;

}

Icon getMediumDotIcon(void){

    Icon icon = {MEDIUM_FONT_ICON_WIDTH, MEDIUM_FONT_ICON_HEIGHT, mediumDotIcon};
    return icon;

}
