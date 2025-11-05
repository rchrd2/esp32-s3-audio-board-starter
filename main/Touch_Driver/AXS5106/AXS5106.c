#include "AXS5106.h"


esp_lcd_touch_handle_t tp = NULL;


void Touch_Init(void)
{
    
    // ESP_ERROR_CHECK(Touch_I2C_Init());
    // ESP_LOGI(TAG, "I2C initialized successfully");
/********************* Touch *********************/

    // esp_lcd_panel_io_handle_t tp_io_handle = NULL;
    // esp_lcd_panel_io_i2c_config_t tp_io_config = ESP_LCD_TOUCH_IO_I2C_AXS5106_CONFIG();
    // ESP_LOGI("Touch", "Initialize touch IO (I2C)");
    // /* Touch IO handle */
    // ESP_ERROR_CHECK(esp_lcd_new_panel_io_i2c(i2c_handle, &tp_io_config, &tp_io_handle));

    
    i2c_master_dev_handle_t dev_handle = NULL;
    i2c_device_config_t dev_cfg = {
        .dev_addr_length = I2C_ADDR_BIT_LEN_7,
        .device_address = ESP_LCD_TOUCH_IO_I2C_AXS5106_ADDRESS,
        .scl_speed_hz = I2C_MASTER_FREQ_HZ,
    };
    ESP_ERROR_CHECK(i2c_master_bus_add_device(i2c_handle, &dev_cfg, &dev_handle));
    esp_lcd_touch_config_t tp_cfg = {
        .x_max = EXAMPLE_LCD_WIDTH,
        .y_max = EXAMPLE_LCD_HEIGHT,
        .rst_gpio_num = I2C_Touch_RST_IO,
        .int_gpio_num = I2C_Touch_INT_IO,
        .flags = {
            .swap_xy = 0,
            .mirror_x = 1,
            .mirror_y = 0,
        },
    };
    
    #ifdef CONFIG_EXAMPLE_DISPLAY_ROTATION_90_DEGREE
        tp_cfg.x_max = EXAMPLE_LCD_HEIGHT,
        tp_cfg.y_max = EXAMPLE_LCD_WIDTH,
        tp_cfg.flags.swap_xy = 1;
        tp_cfg.flags.mirror_x = 0;
        tp_cfg.flags.mirror_y = 0;
    #elif defined(CONFIG_EXAMPLE_DISPLAY_ROTATION_180_DEGREE)
        tp_cfg.flags.swap_xy = 0;
        tp_cfg.flags.mirror_x = 0;
        tp_cfg.flags.mirror_y = 1;
    #elif defined(CONFIG_EXAMPLE_DISPLAY_ROTATION_270_DEGREE)
        tp_cfg.x_max = EXAMPLE_LCD_HEIGHT,
        tp_cfg.y_max = EXAMPLE_LCD_WIDTH,
        tp_cfg.flags.swap_xy = 1;
        tp_cfg.flags.mirror_x = 1;
        tp_cfg.flags.mirror_y = 1;
    #endif
    /* Initialize touch */
    ESP_LOGI("Touch", "Initialize touch controller AXS5106");
    ESP_ERROR_CHECK(esp_lcd_touch_new_i2c_axs5106(dev_handle, &tp_cfg, &tp));
}

