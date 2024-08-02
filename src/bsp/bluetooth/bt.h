/*** 
 * @Author: meteor
 * @Date: 2024-07-29
 * @LastEditTime: 2024-08-02
 * @Description: 
 * @
 * @Copyright (c) 2024
 */
#pragma once

#include <Arduino.h>

#define IS_PLAYING_EVT  (1 << 0)
#define IS_PAUSED_EVT   (1 << 1)    // Used for current status


void BtInit();


/* C funtions */
#ifdef __cplusplus
extern "C" {
#endif

    void ccall_BtPlaySong();
    void ccall_BtPauseSong();
    void ccall_BtStopSong();
    void ccall_BtNextSong();
    void ccall_BtPreviousSong();
    void ccall_BtFastForward();
    void ccall_BtRewind();
    void ccall_BtSetVolume(uint8_t volume_100);

#ifdef __cplusplus
}
#endif

