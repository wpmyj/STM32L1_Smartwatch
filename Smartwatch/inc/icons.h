#ifndef ICONS_H
#define ICONS_H

#include "stm32l1xx.h"
#include "structures.h"

#define LOGO_ICON_WIDTH 128
#define LOGO_ICON_HEIGHT 128
#define HEADER_BAR_ICON_WIDTH 16
#define HEADER_BAR_ICON_HEIGHT 8
#define SMALL_FONT_ICON_WIDTH 8
#define SMALL_FONT_ICON_HEIGHT 8
#define MEDIUM_FONT_ICON_WIDTH 16
#define MEDIUM_FONT_ICON_HEIGHT 18
#define BIG_FONT_ICON_WIDTH 24
#define BIG_FONT_ICON_HEIGHT 35

Icon getLogoIcon(void);
Icon getBatteryIcon0(void);
Icon getBatteryIcon25(void);
Icon getBatteryIcon50(void);
Icon getBatteryIcon75(void);
Icon getBatteryIcon100(void);
Icon getMissedCallIcon(void);
Icon getNewSmsIcon(void);
Icon getNewMailIcon(void);
Icon removeNotificationIcon(void);
Icon getSmallZeroNumberIcon(void);
Icon getSmallOneNumberIcon(void);
Icon getSmallTwoNumberIcon(void);
Icon getSmallThreeNumberIcon(void);
Icon getSmallFourNumberIcon(void);
Icon getSmallFiveNumberIcon(void);
Icon getSmallSixNumberIcon(void);
Icon getSmallSevenNumberIcon(void);
Icon getSmallEightNumberIcon(void);
Icon getSmallNineNumberIcon(void);
Icon getSmallPercentIcon(void);
Icon getSmallCelsiusIcon(void);
Icon getMediumZeroNumberIcon(void);
Icon getMediumOneNumberIcon(void);
Icon getMediumTwoNumberIcon(void);
Icon getMediumThreeNumberIcon(void);
Icon getMediumFourNumberIcon(void);
Icon getMediumFiveNumberIcon(void);
Icon getMediumSixNumberIcon(void);
Icon getMediumSevenNumberIcon(void);
Icon getMediumEightNumberIcon(void);
Icon getMediumNineNumberIcon(void);
Icon getMediumDotIcon(void);
Icon getBigZeroNumberIcon(void);
Icon getBigOneNumberIcon(void);
Icon getBigTwoNumberIcon(void);
Icon getBigThreeNumberIcon(void);
Icon getBigFourNumberIcon(void);
Icon getBigFiveNumberIcon(void);
Icon getBigSixNumberIcon(void);
Icon getBigSevenNumberIcon(void);
Icon getBigEightNumberIcon(void);
Icon getBigNineNumberIcon(void);
Icon getBigColonIcon(void);

#endif
