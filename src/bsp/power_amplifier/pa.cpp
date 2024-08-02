/*** 
 * @Author: meteor
 * @Date: 2024-07-29
 * @LastEditTime: 2024-08-01
 * @Description: 
 * @
 * @Copyright (c) 2024
 */
#include "pa.h"

#include "driver/i2s.h"
#include "bsp/bsp_cfg.h"


static const i2s_pin_config_t i2s_pin = {
    .mck_io_num = -1,
    .bck_io_num = POWER_AMPLIFIER_IIS_SCK_PIN,
    .ws_io_num = POWER_AMPLIFIER_IIS_WS_PIN,
    .data_out_num = POWER_AMPLIFIER_IIS_DOUT_PIN,
    .data_in_num = -1,
};


void PaEnable() {
    digitalWrite(POWER_AMPLIFIER_SHUTDOWN_PIN, 1);
}

void PaDisable() {
    digitalWrite(POWER_AMPLIFIER_SHUTDOWN_PIN, 0);
}

void ccall_PaSetGain(Gain_t gain) {
    if (gain == Normal) {
        digitalWrite(POWER_AMPLIFIER_GAIN_PIN, 1);
    } else if (gain == High) {
        digitalWrite(POWER_AMPLIFIER_GAIN_PIN, 0);
    }
}

void PaInit() {
    // Enable pa
    pinMode(POWER_AMPLIFIER_SHUTDOWN_PIN, OUTPUT);
    PaEnable();

    // Set normal gain
    pinMode(POWER_AMPLIFIER_GAIN_PIN, OUTPUT);
    ccall_PaSetGain(Normal);

    log_i("Init power_amplifier");
}

i2s_pin_config_t PaGetI2sPins() {
    return i2s_pin;
}

