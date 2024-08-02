/*** 
 * @Author: meteor
 * @Date: 2024-07-29
 * @LastEditTime: 2024-07-29
 * @Description: 
 * @
 * @Copyright (c) 2024
 */
#pragma once

#include <Arduino.h>

#include "hal/gpio_types.h"


// The config of power amplifier
#define POWER_AMPLIFIER_IIS_SCK_PIN     GPIO_NUM_16
#define POWER_AMPLIFIER_IIS_WS_PIN      GPIO_NUM_4
#define POWER_AMPLIFIER_IIS_DOUT_PIN    GPIO_NUM_17
#define POWER_AMPLIFIER_GAIN_PIN        GPIO_NUM_27 /* 0: 12dB gain --- 1: 6dB gain */
#define POWER_AMPLIFIER_SHUTDOWN_PIN    GPIO_NUM_22 /* 0: shutdown --- 1: startup */

// The config of lcd
#define LCD_SCK_PIN                     GPIO_NUM_14
#define LCD_DC_PIN                      GPIO_NUM_2  /* Data/Command select */
#define LCD_CS_PIN                      GPIO_NUM_15 /* Low is valid */
#define LCD_SDI_PIN                     GPIO_NUM_13 /* i.e. MCU's sda */
#define LCD_SDO_PIN                     GPIO_NUM_12 /* Not used */
#define LCD_BLK_PIN                     GPIO_NUM_21 /* Backlight control, 1 is on */
#define LCD_WIDTH                       (240)
#define LCD_HEIGHT                      (320)

// The config of touchpad
#define TOUCHPAD_CLK_PIN                GPIO_NUM_25
#define TOUCHPAD_CS_PIN                 GPIO_NUM_33
#define TOUCHPAD_SDI_PIN                GPIO_NUM_32 /* i.e. MCU's MOSI */
#define TOUCHPAD_SDO_PIN                GPIO_NUM_39 /* i.e. MCU's MISO */
#define TOUCHPAD_IRQ_PIN                GPIO_NUM_36 /* Low is valid */

// The config of TF-Card
#define TFCARD_CLK_PIN                  GPIO_NUM_18
#define TFCARD_CMD_PIN                  GPIO_NUM_23 /* i.e. MCU's MOSI */
#define TFCARD_DAT0_PIN                 GPIO_NUM_19 /* i.e. MCU's MISO */
#define TFCARD_CS_PIN                   GPIO_NUM_5  /* Low is valid */

// The config of bluetooth
#define BLUETOOTH_DEVICE_NAME           ((const char*)"Bluetooth_Audio_Box_V1.0")
