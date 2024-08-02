/*** 
 * @Author: meteor
 * @Date: 2024-07-29
 * @LastEditTime: 2024-08-01
 * @Description: 
 * @
 * @Copyright (c) 2024
 */
#include <Arduino.h>

#include "bsp/lcd/lcd.h"
#include "bsp/bluetooth/bt.h"
#include "bsp/power_amplifier/pa.h"


void setup() {
    Serial.begin(115200);

    PaInit();
    BtInit();
    lcd::Init();
}

void loop() {
    lcd::UpdateGui();
}
