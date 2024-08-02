/*** 
 * @Author: meteor
 * @Date: 2024-07-30
 * @LastEditTime: 2024-08-02
 * @Description: 
 * @
 * @Copyright (c) 2024
 */
#pragma once

#include <Arduino.h>

#include <LovyanGFX.hpp>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"


namespace lcd {

class LGFX : public lgfx::LGFX_Device {
// Default private
    // TaskHandle_t _lv_hb_task_handle;  // Lvgl heart-beat task

    lgfx::Panel_ILI9341     _panel_instance;
    lgfx::Bus_SPI           _bus_instance;
    lgfx::Light_PWM         _light_instance;
    lgfx::Touch_XPT2046     _touch_instance; // xpt2046 need to calibrate

public:
    SemaphoreHandle_t _lv_mutex_handle;

    LGFX(void);
    ~LGFX(void) = default;
};
extern LGFX gfx;


void Init();
void UpdateGui();

}


/* C funtions */
#ifdef __cplusplus
extern "C" {
#endif

    void ccall_SetBrightness(uint8_t val);

#ifdef __cplusplus
}
#endif
