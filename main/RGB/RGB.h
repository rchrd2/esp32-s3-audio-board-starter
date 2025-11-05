#pragma once

#include "driver/gpio.h"
#include "led_strip.h"

#define BLINK_GPIO      38
#define BLINK_MAX_leds  7

void RGB_Init(void);
void Set_RGB(uint8_t ledx, uint8_t red_val, uint8_t green_val, uint8_t blue_val);
void RGB_Example(void);