# ESP32-S3-AUDIO-Board Screen-less Application

> **Note**: This README and the code modifications were created with assistance from [Cursor](https://cursor.sh), an AI-powered code editor.

This is a reduced version of the [Waveshare ESP32-S3-AUDIO-Board](https://www.waveshare.com/wiki/ESP32-S3-AUDIO-Board) demo project, optimized for screen-less applications.

## Overview

This project is based on the Waveshare ESP32-S3-AUDIO-Board development board, but with all display-related functionality removed to create a streamlined, audio-focused application. The board features an ESP32-S3 microcontroller with dual-core processing, Wi-Fi, Bluetooth, and integrated audio capabilities.

For complete documentation, hardware specifications, and the full-featured demo, please refer to the [official Waveshare wiki](https://www.waveshare.com/wiki/ESP32-S3-AUDIO-Board).

## What's Included

This screen-less version includes:

- **Audio Playback**

  - WAV file playback from SPIFFS
  - Synthesized beep tones with configurable frequency
  - Volume control (default: 60%)
  - ES8311 audio codec support

- **Button Input**

  - KEY1, KEY2, KEY3 buttons (via IO expander)
  - BOOT button (GPIO 0)
  - Button press detection with beep feedback

- **RTC Clock**

  - PCF85063 real-time clock support
  - Time management and scheduling

- **I2C Communication**

  - IO expander (TCA9555PWR) for additional GPIO
  - I2C device communication

- **Storage**
  - SPIFFS for audio file storage
  - Flash memory management

## What's Removed

The following features have been removed for screen-less operation:

- ❌ LCD/LVGL display support
- ❌ Touch screen functionality
- ❌ Camera interface
- ❌ Microphone and speech recognition
- ❌ RGB LED ring effects
- ❌ SD card support (TF card)
- ❌ Music player functionality

## Hardware

- **Board**: Waveshare ESP32-S3-AUDIO-Board
- **MCU**: ESP32-S3R8 (dual-core, 240MHz)
- **Audio Codec**: ES8311
- **IO Expander**: TCA9555PWR
- **RTC**: PCF85063

## Features

### Audio Controls

- **BOOT Button**: Plays WAV file from `/spiffs/sample.wav`
- **KEY1**: Plays beep at 440 Hz
- **KEY2**: Plays beep at 660 Hz
- **KEY3**: Plays beep at 880 Hz

### Volume Control

- Default volume: 60%
- Volume range: 0-100%
- Volume adjustment functions available (currently disabled in code)

## Building and Flashing

### Prerequisites

- ESP-IDF v5.4.1 or compatible
- Python 3.11+
- USB Type-C cable

### Build Commands

```bash
idf.py build
idf.py flash
idf.py monitor
```

### Entering Download Mode

If flashing fails, enter download mode:

1. Hold the **BOOT** button
2. Press and release the **RESET** button (while holding BOOT)
3. Release the **BOOT** button
4. Flash immediately after entering download mode

## Project Structure

```
main/
├── Audio_Driver/     # Audio playback and beep generation
├── Button_Driver/    # Button input handling
├── EXIO/            # IO expander (TCA9555PWR) interface
├── I2S_Driver/      # I2S audio interface
├── PCF85063/        # RTC clock management
└── main.c           # Application entry point
```

## Configuration

- Default volume can be changed in `main/Audio_Driver/Audio_Driver.c`:

  ```c
  uint8_t Volume = 60;  // Change default volume here
  ```

- Beep frequencies are defined in `main/Audio_Driver/Audio_Driver.c`:
  - KEY1: 440 Hz (A4 note)
  - KEY2: 660 Hz
  - KEY3: 880 Hz (A5 note)

## Audio Files

Place WAV files in the `spiffs_image/` directory before building. The demo uses `sample.wav` which is played when the BOOT button is pressed.

## Troubleshooting

### No Serial Output

- Check USB connection
- Try pressing RESET button
- Verify correct COM port in monitor settings
- Ensure USB CDC is properly configured

### Audio Not Playing

- Verify audio files are in SPIFFS partition
- Check volume level (default: 60%)
- Ensure I2S and codec are properly initialized

### Button Not Responding

- Verify IO expander is initialized
- Check button pin definitions in `Button_Driver.h`
- Ensure button task is running

## Resources

- [Waveshare ESP32-S3-AUDIO-Board Wiki](https://www.waveshare.com/wiki/ESP32-S3-AUDIO-Board)
- [ESP-IDF Documentation](https://docs.espressif.com/projects/esp-idf/en/latest/)
- [Waveshare Product Page](https://www.waveshare.com/esp32-S3-audio-board.htm)

## License

This project is based on the Waveshare ESP32-S3-AUDIO-Board demo code. Refer to the original project for licensing information.

## Notes

This is a simplified version optimized for applications that don't require display functionality. For full-featured demos with LCD, camera, and microphone support, please use the original Waveshare demo project.
