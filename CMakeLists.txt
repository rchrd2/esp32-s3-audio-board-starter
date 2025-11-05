cmake_minimum_required(VERSION 3.16)

include($ENV{IDF_PATH}/tools/cmake/project.cmake)

project(ESP32-S3-AUDIO-Board-Test)

# Create SPIFFS partition image for audio files
spiffs_create_partition_image(audio ${CMAKE_CURRENT_SOURCE_DIR}/spiffs_image FLASH_IN_PROJECT)