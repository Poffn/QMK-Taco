// Copyright 2023 ZiTe (@ZiTe)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once


#define SPI_SCK_PIN GP18
#define SPI_MOSI_PIN GP19
#define SPI_MISO_PIN GP16
#define PMW33XX_CS_PIN GP17 // SPI CS pin.

/* Optional. */
#define PMW33XX_CPI 2000      // The CPI range is 100-12000, in increments of 100. Defaults to 1600 CPI.
#define PMW33XX_CLOCK_SPEED 2000000 // Sets the clock speed that the sensor runs at. Defaults to 2000000
// Use -32767 to 32767, instead of just -127 to 127.
// #define POINTING_DEVICE_TASK_THROTTLE_MS 10

/* RP2040 Reset. */
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET

// #define OLED_DISPLAY_128X32  // Use this if your display is 128x32
// // #define OLED_DISPLAY_128X64  // Uncomment if your display is 128x64

#define I2C1_SDA_PIN GP14  // Change if using a different I²C bus
#define I2C1_SCL_PIN GP15

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
// #define NO_DEBUG

/* disable print */
// #define NO_PRINT

/* disable action features */
// #define NO_ACTION_LAYER
// #define NO_ACTION_TAPPING
// #define NO_ACTION_ONESHOT