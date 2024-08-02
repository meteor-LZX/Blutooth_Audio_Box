/*** 
 * @Author: meteor
 * @Date: 2024-07-30
 * @LastEditTime: 2024-08-02
 * @Description: 
 * @
 * @Copyright (c) 2024
 */
#include <cstring>
#include "lcd.h"

#include "ui/ui.h"
#include <lvgl.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "esp_log.h"

#include "bsp/flash/flash.hpp"
#include "bsp/bsp_cfg.h"


namespace lcd {

LGFX gfx;

static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf[2][ LCD_HEIGHT * 20 ];

static NvsFlash flash;


// gfx flushing
static void DispFlush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p) {
    if (gfx.getStartCount() == 0)
    {   // Processing if not yet started
        gfx.startWrite();
    }
    gfx.pushImageDMA( area->x1
                    , area->y1
                    , area->x2 - area->x1 + 1
                    , area->y2 - area->y1 + 1
                    , ( lgfx::swap565_t* )&color_p->full);
    lv_disp_flush_ready( disp );
}

// Read the touchpad
static void TpRead(lv_indev_drv_t * indev_driver, lv_indev_data_t * data) {
    uint16_t touchX, touchY;

    data->state = LV_INDEV_STATE_REL;

    if( gfx.getTouch( &touchX, &touchY ) )
    {
        data->state = LV_INDEV_STATE_PR;

        // Set the coordinates
        data->point.x = touchX;
        data->point.y = touchY;
    }
}


// Init lcd
void Init() {
    flash.Init();

    // Init gfx
    gfx.begin();

    /* Get calibration data at first and then store it to nvs flash */

    /*
    uint16_t calibrate_data[8];
    std::memset(calibrate_data, 0, sizeof(calibrate_data));

    if (gfx.touch())
    {
        if (gfx.width() < gfx.height()) gfx.setRotation(gfx.getRotation() ^ 1);

        // 画面に案内文章を描画します。
        gfx.setTextDatum(textdatum_t::middle_center);
        gfx.drawString("touch the arrow marker.", gfx.width()>>1, gfx.height() >> 1);
        gfx.setTextDatum(textdatum_t::top_left);

        // タッチを使用する場合、キャリブレーションを行います。画面の四隅に表示される矢印の先端を順にタッチしてください。
        std::uint16_t fg = TFT_WHITE;
        std::uint16_t bg = TFT_BLACK;
        if (gfx.isEPD()) std::swap(fg, bg);
        gfx.calibrateTouch(&calibrate_data[0], fg, bg, std::max(gfx.width(), gfx.height()) >> 3);
    }

    log_i("now callibrate data is: %u, %u, %u, %u, %u, %u, %u, %u\n\r", calibrate_data[0], \
            calibrate_data[1], calibrate_data[2], calibrate_data[3], calibrate_data[4], \
            calibrate_data[5], calibrate_data[6], calibrate_data[7]);
    
    // Write calibrate_data to flash
    flash.WriteLcdCalibrateData(calibrate_data, GET_ARRAY_LEN(calibrate_data));
    */
    uint16_t *p = nullptr;
    p = flash.ReadLcdCalibrateData(8); // Need to delete p
    if (p) {
        // log_i("Read callibrate data is: %u, %u, %u, %u, %u, %u, %u, %u\n\r", \
        //                         p[0], p[1], p[2], p[3], p[4], p[5], p[6], p[7]);
        gfx.setTouchCalibrate(p);
        delete[] p;
    } else {
        log_e("Read callibrate data error!\n\r");
    }
    
    // Init lvgl
    lv_init();
    lv_disp_draw_buf_init( &draw_buf, buf[0], buf[1], LCD_HEIGHT * 20 );

    /*Initialize the display device*/
    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init( &disp_drv );
    disp_drv.hor_res = LCD_HEIGHT;
    disp_drv.ver_res = LCD_WIDTH;
    disp_drv.flush_cb = DispFlush;
    disp_drv.draw_buf = &draw_buf;
    lv_disp_drv_register( &disp_drv );

    /*Initialize the input device driver*/
    static lv_indev_drv_t indev_drv;
    lv_indev_drv_init( &indev_drv );
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = TpRead;
    lv_indev_drv_register( &indev_drv );

    ui_init();
}

// Update gui, need be called in loop()
void UpdateGui() {
    if (pdTRUE == xSemaphoreTake(gfx._lv_mutex_handle, portMAX_DELAY)) {
        lv_task_handler();  // Lvgl heartbeat
        xSemaphoreGive(gfx._lv_mutex_handle);
    }
    vTaskDelay(pdMS_TO_TICKS(5));
}

// Constructor
LGFX::LGFX(void) {
    {   // Config spi bus of panel
        auto cfg = _bus_instance.config();    // バス設定用の構造体を取得します。

        cfg.spi_host = SPI2_HOST;     // 使用するSPIを選択  ESP32-S2,C3 : SPI2_HOST or SPI3_HOST / ESP32 : VSPI_HOST or HSPI_HOST
        // ※ ESP-IDFバージョンアップに伴い、VSPI_HOST , HSPI_HOSTの記述は非推奨になるため、エラーが出る場合は代わりにSPI2_HOST , SPI3_HOSTを使用してください。
        cfg.spi_mode = 2;             // SPI通信モードを設定 (0 ~ 3)
        cfg.freq_write = 80000000;    // 送信時のSPIクロック (最大80MHz, 80MHzを整数で割った値に丸められます)
        cfg.freq_read  = 16000000;    // 受信時のSPIクロック
        cfg.spi_3wire  = true;        // 受信をMOSIピンで行う場合はtrueを設定
        cfg.use_lock   = true;        // トランザクションロックを使用する場合はtrueを設定
        cfg.dma_channel = SPI_DMA_CH_AUTO; // 使用するDMAチャンネルを設定 (0=DMA不使用 / 1=1ch / 2=ch / SPI_DMA_CH_AUTO=自動設定)
        // ※ ESP-IDFバージョンアップに伴い、DMAチャンネルはSPI_DMA_CH_AUTO(自動設定)が推奨になりました。1ch,2chの指定は非推奨になります。
        cfg.pin_sclk = LCD_SCK_PIN;            // SPIのSCLKピン番号を設定
        cfg.pin_mosi = LCD_SDI_PIN;            // SPIのMOSIピン番号を設定
        cfg.pin_miso = -1;            // SPIのMISOピン番号を設定 (-1 = disable)
        cfg.pin_dc   = LCD_DC_PIN;            // SPIのD/Cピン番号を設定  (-1 = disable)

        _bus_instance.config(cfg);    // 設定値をバスに反映します。
        _panel_instance.setBus(&_bus_instance);      // バスをパネルにセットします。
    }
    {   // Config others of panel
        auto cfg = _panel_instance.config();    // 表示パネル設定用の構造体を取得します。

        cfg.pin_cs           =    LCD_CS_PIN;  // CSが接続されているピン番号   (-1 = disable)
        cfg.pin_rst          =    -1;  // RSTが接続されているピン番号  (-1 = disable)
        cfg.pin_busy         =    -1;  // BUSYが接続されているピン番号 (-1 = disable)

        cfg.panel_width      =   LCD_WIDTH;  // 実際に表示可能な幅
        cfg.panel_height     =   LCD_HEIGHT;  // 実際に表示可能な高さ
        cfg.offset_x         =     0;  // パネルのX方向オフセット量
        cfg.offset_y         =     0;  // パネルのY方向オフセット量
        cfg.offset_rotation  =     1;  // 回転方向の値のオフセット 0~7 (4~7は上下反転)
        cfg.dummy_read_pixel =     8;  // ピクセル読出し前のダミーリードのビット数
        cfg.dummy_read_bits  =     1;  // ピクセル以外のデータ読出し前のダミーリードのビット数
        cfg.readable         =  true;  // データ読出しが可能な場合 trueに設定
        cfg.invert           = false;  // パネルの明暗が反転してしまう場合 trueに設定
        cfg.rgb_order        = false;  // パネルの赤と青が入れ替わってしまう場合 trueに設定
        cfg.dlen_16bit       = false;  // 16bitパラレルやSPIでデータ長を16bit単位で送信するパネルの場合 trueに設定
        cfg.bus_shared       = false;  // SDカードとバスを共有している場合 trueに設定(drawJpgFile等でバス制御を行います)

        _panel_instance.config(cfg);
    }
    {   // Config backlight
        auto cfg = _light_instance.config();    // バックライト設定用の構造体を取得します。

        cfg.pin_bl = LCD_BLK_PIN;              // バックライトが接続されているピン番号
        cfg.invert = false;           // バックライトの輝度を反転させる場合 true
        cfg.freq   = 44100;           // バックライトのPWM周波数
        cfg.pwm_channel = 7;          // 使用するPWMのチャンネル番号

        _light_instance.config(cfg);
        _panel_instance.setLight(&_light_instance);  // バックライトをパネルにセットします。
    }
    {   // Config touchpad
        auto cfg = _touch_instance.config();

        cfg.x_min      = 0;    // タッチスクリーンから得られる最小のX値(生の値)
        cfg.x_max      = LCD_WIDTH-1;  // タッチスクリーンから得られる最大のX値(生の値)
        cfg.y_min      = 0;    // タッチスクリーンから得られる最小のY値(生の値)
        cfg.y_max      = LCD_HEIGHT-1;  // タッチスクリーンから得られる最大のY値(生の値)
        cfg.pin_int    = TOUCHPAD_IRQ_PIN;   // INTが接続されているピン番号
        cfg.bus_shared = false; // 画面と共通のバスを使用している場合 trueを設定
        cfg.offset_rotation = 0;// 表示とタッチの向きのが一致しない場合の調整 0~7の値で設定

    // SPI接続の場合
        cfg.spi_host = SPI3_HOST;// 使用するSPIを選択 (HSPI_HOST or VSPI_HOST)
        cfg.freq = 1000000;     // SPIクロックを設定
        cfg.pin_sclk = TOUCHPAD_CLK_PIN;     // SCLKが接続されているピン番号
        cfg.pin_mosi = TOUCHPAD_SDI_PIN;     // MOSIが接続されているピン番号
        cfg.pin_miso = TOUCHPAD_SDO_PIN;     // MISOが接続されているピン番号
        cfg.pin_cs   = TOUCHPAD_CS_PIN;     //   CSが接続されているピン番号

        _touch_instance.config(cfg);
        _panel_instance.setTouch(&_touch_instance);  // タッチスクリーンをパネルにセットします。
    }

    setPanel(&_panel_instance); // 使用するパネルをセットします。

    // Create mutex
    _lv_mutex_handle = xSemaphoreCreateMutex();
}

}

// C function

// Setting brightness of screen
void ccall_SetBrightness(uint8_t val) {
    lcd::gfx.setBrightness(val);
}
