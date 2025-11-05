# 初始化源文件和包含目录
set(SOURCES
    "./main.c"
    "./EXIO/TCA9555PWR.c"
    "./Audio_Driver/Audio_Driver.c"
    "./SD_Card/SD_MMC.c"
    "./RGB/RGB.c"
    "./I2C_Driver/I2C_Driver.c"
    "./I2S_Driver/I2S_Driver.c"
    "./PCF85063/PCF85063.c"
    "./Button_Driver/Button_Driver.c"
)

set(INCLUDE_DIRS
    "./Audio_Driver"
    "./RGB"
    "./EXIO"
    "./SD_Card"
    "./I2C_Driver"
    "./I2S_Driver"
    "./PCF85063"
    "./Button_Driver"
    "."
)

# 注册组件
idf_component_register(
    SRCS ${SOURCES}
    INCLUDE_DIRS ${INCLUDE_DIRS}
)
