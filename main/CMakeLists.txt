# 初始化源文件和包含目录
set(SOURCES
    "./main.c"
    "./LCD_Driver/LCD_Driver.c"
    "./Touch_Driver/Touch_Driver.c"
    "./EXIO/TCA9555PWR.c"
    "./Audio_Driver/Audio_Driver.c" 
    "./MIC_Driver/MIC_Speech.c" 
    "./LVGL_Driver/LVGL_Driver.c"
    "./LVGL_UI/LVGL_Example.c"
    "./LVGL_UI/LVGL_Music.c"
    "./SD_Card/SD_MMC.c" 
    "./RGB/RGB.c"
    "./I2C_Driver/I2C_Driver.c"
    "./I2S_Driver/I2S_Driver.c"
    "./PCF85063/PCF85063.c"
    "./Camera_Driver/Camera_Driver.c"
    "./Button_Driver/Button_Driver.c"
)

set(INCLUDE_DIRS 
    "./LCD_Driver"   
    "./Touch_Driver"
    "./Audio_Driver" 
    "./MIC_Driver" 
    "./LVGL_Driver" 
    "./LVGL_UI" 
    "./RGB" 
    "./EXIO"
    "./SD_Card" 
    "./I2C_Driver"
    "./I2S_Driver"
    "./PCF85063"
    "./Camera_Driver"
    "./Button_Driver"
    "."
)
 
# 根据配置添加源文件和包含目录,在 LCD_Driver.h 和 Touch_Driver.h 要同步修改

if(CONFIG_WAVESHARE_1_47INCH_TOUCH_LCD)
    list(APPEND SOURCES 
        "./LCD_Driver/JD9853/JD9853.c"
        "./Touch_Driver/AXS5106/AXS5106.c"
    )
    list(APPEND INCLUDE_DIRS
        "./LCD_Driver/JD9853"
        "./Touch_Driver/AXS5106"
    )
endif()

if(CONFIG_WAVESHARE_1_85INCH_TOUCH_LCD)
    list(APPEND SOURCES 
        "./LCD_Driver/ST77916/ST77916.c"
        "./Touch_Driver/CST816/CST816.c"
    )
    list(APPEND INCLUDE_DIRS
        "./LCD_Driver/ST77916"
        "./Touch_Driver/CST816"
    )
endif()

if(CONFIG_WAVESHARE_2INCH_TOUCH_LCD)
    list(APPEND SOURCES 
        "./LCD_Driver/ST7789/ST7789.c"
        "./Touch_Driver/CST816/CST816.c"
    )
    list(APPEND INCLUDE_DIRS
        "./LCD_Driver/ST7789"
        "./Touch_Driver/CST816"
    )
endif()

if(CONFIG_WAVESHARE_2_8INCH_TOUCH_LCD)
    list(APPEND SOURCES 
        "./LCD_Driver/ST7789/ST7789.c"
        "./Touch_Driver/CST328/CST328.c"
    )
    list(APPEND INCLUDE_DIRS
        "./LCD_Driver/ST7789"
        "./Touch_Driver/CST328"
    )
endif()

# 注册组件
idf_component_register(
    SRCS ${SOURCES}
    INCLUDE_DIRS ${INCLUDE_DIRS}
)
