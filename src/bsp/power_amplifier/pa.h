/*** 
 * @Author: meteor
 * @Date: 2024-07-29
 * @LastEditTime: 2024-08-01
 * @Description: 
 * @
 * @Copyright (c) 2024
 */
#pragma once

#include <Arduino.h>

#include "driver/i2s.h"


typedef enum {
    Normal,  // 6 dB
    High     // 12 dB
} Gain_t;


void PaInit();
i2s_pin_config_t PaGetI2sPins();
void PaEnable();
void PaDisable();


/* C funtions */
#ifdef __cplusplus
extern "C" {
#endif

    void ccall_PaSetGain(Gain_t gain);

#ifdef __cplusplus
}
#endif

