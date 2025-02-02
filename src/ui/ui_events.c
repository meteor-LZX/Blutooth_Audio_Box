// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.0
// LVGL version: 8.3.11
// Project name: SquareLine_Project

#include "ui.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"

#include "bsp/bluetooth/bt.h"
#include "bsp/power_amplifier/pa.h"

extern EventGroupHandle_t cur_status_evt;


void PlayOrPauseCallback(lv_event_t * e)
{
	// Your code here
    EventBits_t bits;

    bits = xEventGroupWaitBits(
        cur_status_evt,
        IS_PLAYING_EVT | IS_PAUSED_EVT,
        pdTRUE,     // Clear specific bit
        pdFALSE,    // Wait only one
        0
    );
    if (bits & IS_PLAYING_EVT) {
        ccall_BtPauseSong();
    } else if (bits & IS_PAUSED_EVT) {
        ccall_BtPlaySong();
    }
}

void PrevSongCallback(lv_event_t * e)
{
	// Your code here
    ccall_BtPreviousSong();
}

void NextSongCallback(lv_event_t * e)
{
	// Your code here
    ccall_BtNextSong();
}

void VolumeChangeCallback(lv_event_t * e)
{
	// Your code here
    uint8_t volume = 0;
    lv_obj_t *slider = lv_event_get_target(e);

    volume = (uint8_t)lv_slider_get_value(slider);  // Current set volume
    ccall_BtSetVolume(volume);
}

void ModeChangeCallback(lv_event_t * e)
{
	// Your code here
    static Gain_t cur_mode = Normal;
    
    if (cur_mode == Normal) {
        cur_mode = High;
        lv_label_set_text(ui_ModeLabel, "H");
    } else {
        cur_mode = Normal;
        lv_label_set_text(ui_ModeLabel, "N");
    }
    ccall_PaSetGain(cur_mode);
}

// Time: August 1, 2024, 21:15 in my home.