/*** 
 * @Author: meteor
 * @Date: 2024-08-01
 * @LastEditTime: 2024-08-01
 * @Description: 
 * @
 * @Copyright (c) 2024
 */
#pragma once

#include <cstring>
#include <Arduino.h>

#include "nvs_flash.h"
#include "nvs.h"
#include "esp_err.h"
#include "esp_log.h"

#define GET_ARRAY_LEN(array)    (sizeof(array) / sizeof(array[0]))


class NvsFlash {
    // Specific name in flash, note that key name can not over 15 char(include '\0')
    const char *_calibrate_data_space_name = "tp_cal_namesp";
    const char *_calibrate_data_blob_name = "tp_cal_data";

public:
    // Init nvs flash to store data of calibration
    void Init() {
        esp_err_t ret = nvs_flash_init();
        if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
            ESP_ERROR_CHECK(nvs_flash_erase());
            ret = nvs_flash_init();
        }
        ESP_ERROR_CHECK(ret);
    }

    // Write touchpad calibrate data to flash
    void WriteLcdCalibrateData(uint16_t calibrate_data[], uint8_t len) {
        esp_err_t err;
        nvs_handle_t cur_handle;

        err = nvs_open(_calibrate_data_space_name, NVS_READWRITE, &cur_handle); // R/W
        if (err != ESP_OK) {
            log_e("Error (%s) opening NVS handle!\n", esp_err_to_name(err));
        } else {
            // Set data blob(Binary large object), note that use char as units.
            err = nvs_set_blob(cur_handle, _calibrate_data_blob_name, calibrate_data, \
                                                                len * sizeof(uint16_t));
            if (err != ESP_OK) {
                log_e("===> Failed to write calibrate data!");
            } else {
                log_i("===> Calibrate data written successfully!");
            }
            // Commit data
            err = nvs_commit(cur_handle);
            if (err != ESP_OK) {
                log_e("===> Failed to commit calibrate data!");
            } else {
                log_i("===> Calibrate data committed successfully!");
            }

            nvs_close(cur_handle);
        }
    }

    /* Read touchpad calibrate data from flash
     * Return pointer which point to the data array and the pointer need to delete */ 
    uint16_t *ReadLcdCalibrateData(uint8_t len) {
        esp_err_t err;
        nvs_handle_t cur_handle;

        // A buffer to store data from reading
        uint16_t *data_read = new uint16_t[len];
        std::memset(data_read, 0, len);

        err = nvs_open(_calibrate_data_space_name, NVS_READONLY, &cur_handle); // R only
        if (err != ESP_OK) {
            log_e("Error (%s) opening NVS handle!\n", esp_err_to_name(err));
        } else {
            size_t required_size = 0;
            
            // Get blob, and then ensure blob data is specific length(8 in there)
            err = nvs_get_blob(cur_handle, _calibrate_data_blob_name, nullptr, \
                                                                    &required_size);
            if (err == ESP_OK && required_size == len * sizeof(uint16_t)) {
                err = nvs_get_blob(cur_handle, _calibrate_data_blob_name, \
                                                    data_read, &required_size);
                if (err != ESP_OK) {
                    log_e("===> Calibrate data read failed!");
                } else {
                    log_i("===> Calibrate data read successfully!");
                }
            } else {
                log_e("===> Failed to get nvs blob calibrate data!");
            }
        }
        nvs_close(cur_handle);
        
        return data_read;
    }
};
