/**
 * @file
 * @brief ESP LCD touch: CST820
 */

#pragma once

#include "I2C_Driver.h"
#include "TCA9555PWR.h"
#include "LCD_Driver.h"

#include "esp_lcd_touch_axs5106.h"

// I2C settings
// #define I2C_Touch_SDA_IO            11               /*!< GPIO number used for I2C master data  */
// #define I2C_Touch_SCL_IO            10               /*!< GPIO number used for I2C master clock */
#define I2C_Touch_INT_IO            -1               /*!< GPIO number used for I2C master data  */
#define I2C_Touch_RST_IO            -1              /*!< GPIO number used for I2C master clock */
// #define I2C_Touch_MASTER_NUM        0               /*!< I2C master i2c port number, the number of i2c peripheral interfaces available will depend on the chip */
// #define I2C_Touch_MASTER_FREQ_HZ    400000          /*!< I2C master clock frequency */

extern esp_lcd_touch_handle_t tp;

void Touch_Init(void);
