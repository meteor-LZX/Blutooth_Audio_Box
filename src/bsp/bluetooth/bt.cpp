/*** 
 * @Author: meteor
 * @Date: 2024-07-29
 * @LastEditTime: 2024-08-02
 * @Description: 
 * @
 * @Copyright (c) 2024
 */
#include <cstring>
#include "bt.h"

#include "ui/ui.h"
#include <lvgl.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "freertos/queue.h"
#include "BluetoothA2DPSink.h"
#include "esp_log.h"

#include "bsp/lcd/lcd.h"
#include "bsp/power_amplifier/pa.h"
#include "bsp/bsp_cfg.h"


typedef struct {
    uint8_t id;
    char text[50];
} AvrcMetadataQueElem_t;


EventGroupHandle_t cur_status_evt;   // Used to sync current status and lvgl event

static TaskHandle_t avrc_mdata_task_handle;
static QueueHandle_t avrc_metadata_que;
static TaskHandle_t avrc_volume_task_handle;
static QueueHandle_t avrc_volume_que;

static BluetoothA2DPSink a2dp_sink;


static void MetadataTaskApp(void *argp);    // Used to change metadata labels to avoid blocking the audio thread
static void VolumeTaskApp(void *argp);      // Used to change volume slider
/* AVRCP event callback custom funtions */

static void AvrcMetadataCallback(uint8_t id, const uint8_t *text) {
    AvrcMetadataQueElem_t avrc_metadata_elem; // Used to store metadata and corresponding id

    // log_i("==> AVRC metadata rsp: attribute id 0x%x, %s\n", id, text);
    avrc_metadata_elem.id = id;
    std::snprintf(avrc_metadata_elem.text, sizeof(avrc_metadata_elem.text), "%s", (char*)text);
    xQueueSend(avrc_metadata_que, (void*)&avrc_metadata_elem, 0);
}

static void AvrcPlayStatusCallback(esp_avrc_playback_stat_t playback) {
    switch (playback) {
        case esp_avrc_playback_stat_t::ESP_AVRC_PLAYBACK_STOPPED:
            log_i("Stopped.");
        break;
        case esp_avrc_playback_stat_t::ESP_AVRC_PLAYBACK_PLAYING:
            xEventGroupSetBits(cur_status_evt, IS_PLAYING_EVT);
            log_i("Playing.");
        break;
        case esp_avrc_playback_stat_t::ESP_AVRC_PLAYBACK_PAUSED:
            xEventGroupSetBits(cur_status_evt, IS_PAUSED_EVT);
            log_i("Paused.");
        break;
        case esp_avrc_playback_stat_t::ESP_AVRC_PLAYBACK_FWD_SEEK:
            log_i("Forward seek.");
        break;
        case esp_avrc_playback_stat_t::ESP_AVRC_PLAYBACK_REV_SEEK:
            log_i("Reverse seek.");
        break;
        case esp_avrc_playback_stat_t::ESP_AVRC_PLAYBACK_ERROR:
            log_i("Error.");
        break;
        default:
            log_i("Got unknown playback status %d\n", playback);
        break;
    }
}

// static void AvrcPlayPosCallback(uint32_t play_pos) {
//     log_i("Play position is %d (%d seconds)\n", play_pos, \
//                                 (int)round(play_pos/1000.0));
// }

static void AvrcVolumeChangedCallback(int volume_127) {
    uint8_t volume_100 = volume_127 * 100 / 0x7f;
    xQueueSend(avrc_volume_que, (void*)&volume_100, 0);
}


// Init bluetooth
void BtInit() {
    // Init os variables
    cur_status_evt = xEventGroupCreate();
    avrc_metadata_que = xQueueCreate(4, sizeof(AvrcMetadataQueElem_t));
    avrc_volume_que = xQueueCreate(1, sizeof(uint8_t));
    xTaskCreatePinnedToCore(MetadataTaskApp, "MetadataTaskApp",
                    3072, nullptr, 7, &avrc_mdata_task_handle, 1);
    xTaskCreatePinnedToCore(VolumeTaskApp, "VolumeTaskApp",
                    2048, nullptr, 8, &avrc_volume_task_handle, 1);
    
    // Set audio output
    a2dp_sink.set_pin_config(PaGetI2sPins());
    a2dp_sink.set_bits_per_sample(32);

    // Set AVRCP metadata & play statu & play position & volume
    a2dp_sink.set_avrc_metadata_attribute_mask(
        ESP_AVRC_MD_ATTR_TITLE |
        ESP_AVRC_MD_ATTR_ARTIST |
        ESP_AVRC_MD_ATTR_ALBUM |
        ESP_AVRC_MD_ATTR_PLAYING_TIME
    );
    a2dp_sink.set_avrc_metadata_callback(AvrcMetadataCallback);
    a2dp_sink.set_avrc_rn_playstatus_callback(AvrcPlayStatusCallback);
    // a2dp_sink.set_avrc_rn_play_pos_callback(AvrcPlayPosCallback, 1); // 1s interval, 10s default
    a2dp_sink.set_avrc_rn_volumechange(AvrcVolumeChangedCallback);

    a2dp_sink.set_auto_reconnect(true);
    a2dp_sink.start(BLUETOOTH_DEVICE_NAME);
    log_i("Init bluetooth_a2dp");
}

/* Tasks */

void MetadataTaskApp(void *argp) {
    (void)argp;
    AvrcMetadataQueElem_t label_metadata_element;

    uint32_t playtime;
    uint8_t min, sec;
    char show_time[10];

    for(;;) {
        // Wait for medadata
        if (pdTRUE == xQueueReceive(avrc_metadata_que, &label_metadata_element, \
                                                                    portMAX_DELAY)) {
            // Wait for mutex of lvgl
            if (pdTRUE == xSemaphoreTake(lcd::gfx._lv_mutex_handle, portMAX_DELAY)) {
                switch (label_metadata_element.id) {
                    case ESP_AVRC_MD_ATTR_TITLE:
                        // Change title label
                        lv_label_set_text(ui_TrueTitleLabel, label_metadata_element.text);
                    break;
                    case ESP_AVRC_MD_ATTR_ARTIST:
                        // Change artist label
                        lv_label_set_text(ui_TrueArtistLabel, label_metadata_element.text);
                    break;
                    case ESP_AVRC_MD_ATTR_ALBUM:
                        // Change album label
                        lv_label_set_text(ui_TrueAlbumLabel, label_metadata_element.text);
                    break;
                    case ESP_AVRC_MD_ATTR_PLAYING_TIME:
                        // Change playtime label
                        playtime = String(label_metadata_element.text).toInt();

                        min = (playtime / 1000) / 60;
                        sec = (playtime / 1000) % 60;
                        std::snprintf(show_time, sizeof(show_time), \
                                (sec < 10) ? "%d : 0%d" : "%d : %d", min, sec);
                        lv_label_set_text(ui_TrueTimeLabel, show_time);
                    break;
                    default:
                        log_e("Unused AVRC ATTR!");
                }
                xSemaphoreGive(lcd::gfx._lv_mutex_handle);
            }
            // UBaseType_t stack_space = uxTaskGetStackHighWaterMark(NULL);
            // log_i("current stack space is: %u", stack_space);
        }
    }
}

void VolumeTaskApp(void *argp) {
    (void)argp;
    uint8_t volume_100; 

    for(;;) {
        // Wait for volume changed
        if (pdTRUE == xQueueReceive(avrc_volume_que, &volume_100, portMAX_DELAY)) {
            // Wait for mutex of lvgl
            if (pdTRUE == xSemaphoreTake(lcd::gfx._lv_mutex_handle, portMAX_DELAY)) {
                // Change volume display
                lv_slider_set_value(ui_VolumeSlider, volume_100, LV_ANIM_OFF);
                xSemaphoreGive(lcd::gfx._lv_mutex_handle);
            }
            // UBaseType_t stack_space = uxTaskGetStackHighWaterMark(NULL);
            // log_i("current stack space is: %u", stack_space);
        }
    }
}


/* AVRCP control functions set */

void ccall_BtPlaySong() {
    if (a2dp_sink.is_connected()) {
        a2dp_sink.play();
    }
}

void ccall_BtPauseSong() {
    if (a2dp_sink.is_connected()) {
        a2dp_sink.pause();
    }
}

void ccall_BtStopSong() {
    if (a2dp_sink.is_connected()) {
        a2dp_sink.stop();   // Returns the progress bar to zero
    }
}

void ccall_BtNextSong() {
    if (a2dp_sink.is_connected()) {
        a2dp_sink.next();
    }
}

void ccall_BtPreviousSong() {
    if (a2dp_sink.is_connected()) {
        a2dp_sink.previous();
    }
}

void ccall_BtFastForward() {
    if (a2dp_sink.is_connected()) {
        a2dp_sink.fast_forward();
    }
}

void ccall_BtRewind() {
    if (a2dp_sink.is_connected()) {
        a2dp_sink.rewind();
    }
}

void ccall_BtSetVolume(uint8_t volume_100) {
    if (a2dp_sink.is_connected()) {
        volume_100 *= 1.27; // Volume need in 0~127
        a2dp_sink.set_volume(volume_100);
        log_i("Setting volume to: %d%%", volume_100);
    }
}
