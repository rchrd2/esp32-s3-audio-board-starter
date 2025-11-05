#pragma once
#include "sdkconfig.h"
#ifdef CONFIG_WAVESHARE_1_47INCH_TOUCH_LCD
#include "AXS5106.h"
#elif defined(CONFIG_WAVESHARE_1_85INCH_TOUCH_LCD)
#include "CST816.h"
#elif defined(CONFIG_WAVESHARE_2INCH_TOUCH_LCD)
#include "CST816.h"
#elif defined(CONFIG_WAVESHARE_2_8INCH_TOUCH_LCD)
#include "CST328.h"
#else
#warning "LCD Configuration is not properly defined"
#error "No valid touch screen configuration is defined"
#endif

void TOUCH_INIT(void);
