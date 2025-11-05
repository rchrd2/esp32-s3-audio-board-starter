#pragma once
#include <stdio.h>
#include "esp_timer.h"
#include "driver/gpio.h"
#include "esp_camera.h"
#include "lvgl.h"
#include "demos/lv_demos.h"

#include "LCD_Driver.h"
#include "TCA9555PWR.h"
#include "Button_Driver.h"
#include "LVGL_Example.h"
#include "LVGL_Music.h"

extern bool camera_Show_Flag;
void Camera_Init(void);
void camera_task(void *param);