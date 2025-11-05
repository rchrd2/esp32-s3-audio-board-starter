#include "Button_Driver.h"
#include "esp_err.h"
#include "esp_log.h"
#include "driver/gpio.h" 

bool BOOT_State = 0;
bool KEY1_State = 0;
bool KEY2_State = 0;
bool KEY3_State = 0;      
void  ESP32_Button_init(void){
  gpio_reset_pin(Button_PIN1);                        
  gpio_set_direction(Button_PIN1, GPIO_MODE_INPUT);   
  gpio_set_pull_mode(Button_PIN1, GPIO_PULLUP_ONLY);   
}

void Timer_Callback(void *parameter)
{
    while(1)
    {         
      if(Read_EXIO(IO_EXPANDER_PIN_NUM_9) == BUTTON_ACTIVE_LEVEL){
        vTaskDelay(pdMS_TO_TICKS(10));
        if(Read_EXIO(IO_EXPANDER_PIN_NUM_9) == BUTTON_ACTIVE_LEVEL){
          KEY1_State = 1;
          while(Read_EXIO(IO_EXPANDER_PIN_NUM_9) == BUTTON_ACTIVE_LEVEL){
            vTaskDelay(pdMS_TO_TICKS(100));
          }
        }
      }
      if(Read_EXIO(IO_EXPANDER_PIN_NUM_10) == BUTTON_ACTIVE_LEVEL){
        vTaskDelay(pdMS_TO_TICKS(10));
        if(Read_EXIO(IO_EXPANDER_PIN_NUM_10) == BUTTON_ACTIVE_LEVEL){
          KEY2_State = 1; 
          while(Read_EXIO(IO_EXPANDER_PIN_NUM_10) == BUTTON_ACTIVE_LEVEL){
            vTaskDelay(pdMS_TO_TICKS(100));
          }
        }
      }
      if(Read_EXIO(IO_EXPANDER_PIN_NUM_11) == BUTTON_ACTIVE_LEVEL){
        vTaskDelay(pdMS_TO_TICKS(10));
        if(Read_EXIO(IO_EXPANDER_PIN_NUM_11) == BUTTON_ACTIVE_LEVEL){
          KEY3_State = 1; 
          while(Read_EXIO(IO_EXPANDER_PIN_NUM_11) == BUTTON_ACTIVE_LEVEL){
            vTaskDelay(pdMS_TO_TICKS(100));
          }
        }
      }
      if(gpio_get_level(Button_PIN1) == BUTTON_ACTIVE_LEVEL){
        vTaskDelay(pdMS_TO_TICKS(10));
        if(gpio_get_level(Button_PIN1) == BUTTON_ACTIVE_LEVEL){
          BOOT_State = 1; 
          while(gpio_get_level(Button_PIN1) == BUTTON_ACTIVE_LEVEL){
            vTaskDelay(pdMS_TO_TICKS(100));
          }
        }
      }
      vTaskDelay(pdMS_TO_TICKS(100));
    }
    vTaskDelete(NULL);                                              
}
void button_Init(void)
{
  ESP32_Button_init(); 
  xTaskCreatePinnedToCore(
    Timer_Callback, 
    "Timer task",
    4096, 
    NULL, 
    3, 
    NULL, 
    1);      
}

