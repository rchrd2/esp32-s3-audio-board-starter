
#include "SD_MMC.h"
#include "TCA9555PWR.h"
// #include "LVGL_Example.h"  // Disabled - no LCD
#include "Audio_Driver.h"
#include "PCF85063.h"
// #include "MIC_Speech.h"  // Disabled - no microphone
// #include "LCD_Driver.h"  // Disabled - no LCD
#include "RGB.h"
#include "I2S_Driver.h"
#include "Button_Driver.h"


void Driver_Loop(void *parameter)
{
    while(1)
    {
        PCF85063_Loop();
        vTaskDelay(pdMS_TO_TICKS(100));
    }
    vTaskDelete(NULL);
}
void Driver_Init(void)
{
    Flash_Searching();
    I2C_Init();
    EXIO_Init();                    // Example Initialize EXIO
    PCF85063_Init();
    I2S_Init();
    RGB_Init();
    RGB_Example();
    SD_Init();
    SPIFFS_Init();                  // Initialize SPIFFS for audio files
    button_Init();
    xTaskCreatePinnedToCore(
        Driver_Loop,
        "Other Driver task",
        4096,
        NULL,
        3,
        NULL,
        0);
}
void app_main(void)
{
    Driver_Init();

    // LCD_INIT();  // Disabled - no LCD
    Audio_Init();
    // MIC_init();  // Disabled - no microphone
    // LVGL_Init();   // Disabled - no LCD
    // Lvgl_Example1();  // Disabled - no LCD
    // Camera_Init();  // Disabled - no camera
    // lv_demo_widgets();
    // lv_demo_keypad_encoder();
    // lv_demo_benchmark();
    // lv_demo_stress();
    // lv_demo_music();

    while (1) {
        // raise the task priority of LVGL and/or reduce the handler period can improve the performance
        vTaskDelay(pdMS_TO_TICKS(100));
        // The task running lv_timer_handler should have lower priority than that running `lv_tick_inc`
        // lv_timer_handler();  // Disabled - no LCD
    }
}



