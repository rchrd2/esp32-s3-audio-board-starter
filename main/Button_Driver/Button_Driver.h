#ifndef BUTTON_BSP_H
#define BUTTON_BSP_H
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <stdio.h>
#include <stdbool.h>  
#include "TCA9555PWR.h"

#define BOOT_KEY_PIN            GPIO_NUM_0
#define Button_PIN1             BOOT_KEY_PIN
#define BUTTON_ACTIVE_LEVEL     0

extern bool BOOT_State;    
extern bool KEY1_State;   
extern bool KEY2_State;   
extern bool KEY3_State;   

void button_Init(void);

#endif