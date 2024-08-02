// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.0
// LVGL version: 8.3.11
// Project name: SquareLine_Project

#include "../ui.h"

extern lv_font_t lv_font_chinese_blod;

void ui_Screen1_screen_init(void)
{
    ui_Screen1 = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Screen1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Screen1, lv_color_hex(0x10EDE9), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Screen1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui_Screen1, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Desktop = lv_img_create(ui_Screen1);
    lv_img_set_src(ui_Desktop, &ui_img_desktop_png);
    lv_obj_set_width(ui_Desktop, LV_SIZE_CONTENT);   /// 320
    lv_obj_set_height(ui_Desktop, LV_SIZE_CONTENT);    /// 180
    lv_obj_set_x(ui_Desktop, 0);
    lv_obj_set_y(ui_Desktop, -30);
    lv_obj_set_align(ui_Desktop, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Desktop, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Desktop, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_DevNameLabel = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_DevNameLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_DevNameLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_DevNameLabel, 0);
    lv_obj_set_y(ui_DevNameLabel, 75);
    lv_obj_set_align(ui_DevNameLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_DevNameLabel, ">>Device Name<<");
    lv_obj_set_style_text_color(ui_DevNameLabel, lv_color_hex(0x0081FB), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_DevNameLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_DevNameLabel, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_DevNameLabel, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_DevNameLabel, lv_color_hex(0xC4FF01), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_DevNameLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_DevNameLabel, lv_color_hex(0xE99898), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_main_stop(ui_DevNameLabel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_stop(ui_DevNameLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui_DevNameLabel, LV_GRAD_DIR_HOR, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_TrueDevName = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_TrueDevName, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_TrueDevName, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_TrueDevName, 0);
    lv_obj_set_y(ui_TrueDevName, 100);
    lv_obj_set_align(ui_TrueDevName, LV_ALIGN_CENTER);
    lv_label_set_text(ui_TrueDevName, "Bluetooth_Audio_Box_V1.0");
    lv_obj_set_style_text_color(ui_TrueDevName, lv_color_hex(0xC410EF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_TrueDevName, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_TrueDevName, LV_TEXT_ALIGN_AUTO, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_TrueDevName, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_TrueDevName, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_TitleLabel = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_TitleLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_TitleLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_TitleLabel, 0);
    lv_obj_set_y(ui_TitleLabel, -100);
    lv_obj_set_align(ui_TitleLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_TitleLabel, "Title:");
    lv_obj_set_style_text_color(ui_TitleLabel, lv_color_hex(0x04E3FF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_TitleLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_TitleLabel, LV_TEXT_ALIGN_AUTO, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_TitleLabel, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_TrueTitleLabel = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_TrueTitleLabel, 60);
    lv_obj_set_height(ui_TrueTitleLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_TrueTitleLabel, 60);
    lv_obj_set_y(ui_TrueTitleLabel, -100);
    lv_obj_set_align(ui_TrueTitleLabel, LV_ALIGN_CENTER);
    lv_label_set_long_mode(ui_TrueTitleLabel, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_TrueTitleLabel, "Title--Title--");
    lv_obj_set_style_text_color(ui_TrueTitleLabel, lv_color_hex(0x04E3FF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_TrueTitleLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_TrueTitleLabel, LV_TEXT_ALIGN_AUTO, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_TrueTitleLabel, &lv_font_chinese_blod, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ArtistLabel = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_ArtistLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ArtistLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_ArtistLabel, 5);
    lv_obj_set_y(ui_ArtistLabel, -70);
    lv_obj_set_align(ui_ArtistLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_ArtistLabel, "Artist:");
    lv_obj_set_style_text_color(ui_ArtistLabel, lv_color_hex(0xFF0008), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ArtistLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_ArtistLabel, LV_TEXT_ALIGN_AUTO, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ArtistLabel, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_TrueArtistLabel = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_TrueArtistLabel, 60);
    lv_obj_set_height(ui_TrueArtistLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_TrueArtistLabel, 70);
    lv_obj_set_y(ui_TrueArtistLabel, -70);
    lv_obj_set_align(ui_TrueArtistLabel, LV_ALIGN_CENTER);
    lv_label_set_long_mode(ui_TrueArtistLabel, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_TrueArtistLabel, "Artist--Artist--");
    lv_obj_set_style_text_color(ui_TrueArtistLabel, lv_color_hex(0xFF0008), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_TrueArtistLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_TrueArtistLabel, LV_TEXT_ALIGN_AUTO, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_TrueArtistLabel, &lv_font_chinese_blod, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_AlbumLabel = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_AlbumLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_AlbumLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_AlbumLabel, 10);
    lv_obj_set_y(ui_AlbumLabel, -40);
    lv_obj_set_align(ui_AlbumLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_AlbumLabel, "Album:");
    lv_obj_set_style_text_color(ui_AlbumLabel, lv_color_hex(0x00FF16), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_AlbumLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_AlbumLabel, LV_TEXT_ALIGN_AUTO, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_AlbumLabel, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_TrueAlbumLabel = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_TrueAlbumLabel, 60);
    lv_obj_set_height(ui_TrueAlbumLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_TrueAlbumLabel, 80);
    lv_obj_set_y(ui_TrueAlbumLabel, -40);
    lv_obj_set_align(ui_TrueAlbumLabel, LV_ALIGN_CENTER);
    lv_label_set_long_mode(ui_TrueAlbumLabel, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_TrueAlbumLabel, "Album--Album--");
    lv_obj_set_style_text_color(ui_TrueAlbumLabel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_TrueAlbumLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_TrueAlbumLabel, LV_TEXT_ALIGN_AUTO, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_TrueAlbumLabel, &lv_font_chinese_blod, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_TimeLabel1 = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_TimeLabel1, 60);
    lv_obj_set_height(ui_TimeLabel1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_TimeLabel1, 10);
    lv_obj_set_y(ui_TimeLabel1, -10);
    lv_obj_set_align(ui_TimeLabel1, LV_ALIGN_CENTER);
    lv_label_set_long_mode(ui_TimeLabel1, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_TimeLabel1, "Total Time");
    lv_obj_set_style_text_color(ui_TimeLabel1, lv_color_hex(0x86FF00), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_TimeLabel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_TimeLabel1, LV_TEXT_ALIGN_AUTO, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_TimeLabel1, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_TimeLabel2 = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_TimeLabel2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_TimeLabel2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_TimeLabel2, 45);
    lv_obj_set_y(ui_TimeLabel2, -10);
    lv_obj_set_align(ui_TimeLabel2, LV_ALIGN_CENTER);
    lv_label_set_long_mode(ui_TimeLabel2, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_TimeLabel2, ":");
    lv_obj_set_style_text_color(ui_TimeLabel2, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_TimeLabel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_TimeLabel2, LV_TEXT_ALIGN_AUTO, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_TimeLabel2, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_TrueTimeLabel = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_TrueTimeLabel, 60);
    lv_obj_set_height(ui_TrueTimeLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_TrueTimeLabel, 85);
    lv_obj_set_y(ui_TrueTimeLabel, -10);
    lv_obj_set_align(ui_TrueTimeLabel, LV_ALIGN_CENTER);
    lv_label_set_long_mode(ui_TrueTimeLabel, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_TrueTimeLabel, "Time--Time--");
    lv_obj_set_style_text_color(ui_TrueTimeLabel, lv_color_hex(0x86FF00), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_TrueTimeLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_TrueTimeLabel, LV_TEXT_ALIGN_AUTO, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_TrueTimeLabel, &lv_font_chinese_blod, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Spinner1 = lv_spinner_create(ui_Screen1, 1000, 90);
    lv_obj_set_width(ui_Spinner1, 50);
    lv_obj_set_height(ui_Spinner1, 50);
    lv_obj_clear_flag(ui_Spinner1, LV_OBJ_FLAG_CLICKABLE);      /// Flags
    lv_obj_set_style_arc_width(ui_Spinner1, 7, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_arc_color(ui_Spinner1, lv_color_hex(0xC3A16D), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui_Spinner1, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui_Spinner1, 7, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    ui_PlayOrPauseBtn = lv_btn_create(ui_Screen1);
    lv_obj_set_width(ui_PlayOrPauseBtn, 45);
    lv_obj_set_height(ui_PlayOrPauseBtn, 45);
    lv_obj_set_x(ui_PlayOrPauseBtn, 0);
    lv_obj_set_y(ui_PlayOrPauseBtn, 40);
    lv_obj_set_align(ui_PlayOrPauseBtn, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_PlayOrPauseBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_PlayOrPauseBtn, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PlayOrPauseBtn, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PlayOrPauseBtn, lv_color_hex(0xCAD7C2), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PlayOrPauseBtn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PrevSongBtn = lv_btn_create(ui_Screen1);
    lv_obj_set_width(ui_PrevSongBtn, 45);
    lv_obj_set_height(ui_PrevSongBtn, 45);
    lv_obj_set_x(ui_PrevSongBtn, -50);
    lv_obj_set_y(ui_PrevSongBtn, 40);
    lv_obj_set_align(ui_PrevSongBtn, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_PrevSongBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_PrevSongBtn, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PrevSongBtn, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PrevSongBtn, lv_color_hex(0xCAD7C2), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PrevSongBtn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_NextSongBtn = lv_btn_create(ui_Screen1);
    lv_obj_set_width(ui_NextSongBtn, 45);
    lv_obj_set_height(ui_NextSongBtn, 45);
    lv_obj_set_x(ui_NextSongBtn, 50);
    lv_obj_set_y(ui_NextSongBtn, 40);
    lv_obj_set_align(ui_NextSongBtn, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_NextSongBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_NextSongBtn, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_NextSongBtn, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_NextSongBtn, lv_color_hex(0xCAD7C2), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_NextSongBtn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_VolumeSlider = lv_slider_create(ui_Screen1);
    lv_slider_set_value(ui_VolumeSlider, 0, LV_ANIM_OFF);
    if(lv_slider_get_mode(ui_VolumeSlider) == LV_SLIDER_MODE_RANGE) lv_slider_set_left_value(ui_VolumeSlider, 50,
                                                                                                 LV_ANIM_OFF);
    lv_obj_set_width(ui_VolumeSlider, 10);
    lv_obj_set_height(ui_VolumeSlider, 100);
    lv_obj_set_x(ui_VolumeSlider, 145);
    lv_obj_set_y(ui_VolumeSlider, -10);
    lv_obj_set_align(ui_VolumeSlider, LV_ALIGN_CENTER);
    lv_obj_set_style_bg_color(ui_VolumeSlider, lv_color_hex(0xFFF8EB), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_VolumeSlider, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_VolumeSlider, lv_color_hex(0x00FFFA), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_VolumeSlider, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_VolumeSlider, lv_color_hex(0x00FFFA), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_VolumeSlider, 255, LV_PART_KNOB | LV_STATE_DEFAULT);

    ui_VolumeLabel = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_VolumeLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_VolumeLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_VolumeLabel, 110);
    lv_obj_set_y(ui_VolumeLabel, 25);
    lv_obj_set_align(ui_VolumeLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_VolumeLabel, "Volume");
    lv_obj_set_style_text_color(ui_VolumeLabel, lv_color_hex(0x510BE2), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_VolumeLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_NextImage = lv_img_create(ui_Screen1);
    lv_img_set_src(ui_NextImage, &ui_img_next_png);
    lv_obj_set_width(ui_NextImage, LV_SIZE_CONTENT);   /// 32
    lv_obj_set_height(ui_NextImage, LV_SIZE_CONTENT);    /// 32
    lv_obj_set_x(ui_NextImage, 50);
    lv_obj_set_y(ui_NextImage, 40);
    lv_obj_set_align(ui_NextImage, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_NextImage, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_NextImage, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_PrevImage = lv_img_create(ui_Screen1);
    lv_img_set_src(ui_PrevImage, &ui_img_previous_png);
    lv_obj_set_width(ui_PrevImage, LV_SIZE_CONTENT);   /// 32
    lv_obj_set_height(ui_PrevImage, LV_SIZE_CONTENT);    /// 32
    lv_obj_set_x(ui_PrevImage, -50);
    lv_obj_set_y(ui_PrevImage, 40);
    lv_obj_set_align(ui_PrevImage, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_PrevImage, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_PrevImage, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_PlayOrPauseImage = lv_img_create(ui_Screen1);
    lv_img_set_src(ui_PlayOrPauseImage, &ui_img_play_and_pause_png);
    lv_obj_set_width(ui_PlayOrPauseImage, LV_SIZE_CONTENT);   /// 32
    lv_obj_set_height(ui_PlayOrPauseImage, LV_SIZE_CONTENT);    /// 32
    lv_obj_set_x(ui_PlayOrPauseImage, 0);
    lv_obj_set_y(ui_PlayOrPauseImage, 40);
    lv_obj_set_align(ui_PlayOrPauseImage, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_PlayOrPauseImage, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_PlayOrPauseImage, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_BluetoothImage = lv_img_create(ui_Screen1);
    lv_img_set_src(ui_BluetoothImage, &ui_img_bluetooth_png);
    lv_obj_set_width(ui_BluetoothImage, LV_SIZE_CONTENT);   /// 32
    lv_obj_set_height(ui_BluetoothImage, LV_SIZE_CONTENT);    /// 32
    lv_obj_set_x(ui_BluetoothImage, 145);
    lv_obj_set_y(ui_BluetoothImage, -100);
    lv_obj_set_align(ui_BluetoothImage, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_BluetoothImage, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_BluetoothImage, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_ModeButton = lv_btn_create(ui_Screen1);
    lv_obj_set_width(ui_ModeButton, 35);
    lv_obj_set_height(ui_ModeButton, 35);
    lv_obj_set_x(ui_ModeButton, -140);
    lv_obj_set_y(ui_ModeButton, 80);
    lv_obj_set_align(ui_ModeButton, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ModeButton, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ModeButton, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ModeButton, lv_color_hex(0x00F6CA), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ModeButton, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ModeLabel = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_ModeLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ModeLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_ModeLabel, -140);
    lv_obj_set_y(ui_ModeLabel, 80);
    lv_obj_set_align(ui_ModeLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_ModeLabel, "N");
    lv_label_set_recolor(ui_ModeLabel, "true");
    lv_obj_set_style_text_font(ui_ModeLabel, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_PlayOrPauseBtn, ui_event_PlayOrPauseBtn, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_PrevSongBtn, ui_event_PrevSongBtn, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_NextSongBtn, ui_event_NextSongBtn, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_VolumeSlider, ui_event_VolumeSlider, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ModeButton, ui_event_ModeButton, LV_EVENT_ALL, NULL);

}
