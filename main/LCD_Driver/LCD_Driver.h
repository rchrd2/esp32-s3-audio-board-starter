#pragma once
#include "sdkconfig.h"
#ifdef CONFIG_WAVESHARE_1_47INCH_TOUCH_LCD
#include "JD9853.h"
#elif defined(CONFIG_WAVESHARE_1_85INCH_TOUCH_LCD)
#include "ST77916.h"
#elif defined(CONFIG_WAVESHARE_2INCH_TOUCH_LCD)
#include "ST7789.h"
#elif defined(CONFIG_WAVESHARE_2_8INCH_TOUCH_LCD)
#include "ST7789.h"
#else
#warning "LCD Configuration is not properly defined"
#error "No valid touch screen configuration is defined"
#endif


#include "Touch_Driver.h"
#include "driver/ledc.h"

#define LEDC_HS_TIMER          LEDC_TIMER_0
#define LEDC_LS_MODE           LEDC_LOW_SPEED_MODE
#define LEDC_HS_CH0_GPIO       EXAMPLE_LCD_PIN_NUM_BK_LIGHT
#define LEDC_HS_CH0_CHANNEL    LEDC_CHANNEL_0
#define LEDC_TEST_DUTY         (4000)
#define LEDC_ResolutionRatio   LEDC_TIMER_13_BIT
#define LEDC_MAX_Duty          ((1 << LEDC_ResolutionRatio) - 1)
#define Backlight_MAX           100    

extern uint8_t LCD_Backlight;
void LCD_INIT();


void Backlight_Init(void);                             // Initialize the LCD backlight, which has been called in the LCD_Init function, ignore it                                                         
void Set_Backlight(uint8_t Light);                   // Call this function to adjust the brightness of the backlight. The value of the parameter Light ranges from 0 to 100
