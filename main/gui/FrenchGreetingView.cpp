/****************************************************************************************
 * FrenchGreetingView.cpp - A view that displays an French Greeting
 * Created on Dec. 03, 2019
 * Copyright (c) 2019 Ed Nelson (https://github.com/enelson1001)
 * Licensed under MIT License (see LICENSE file)
 *
 * Derivative Works
 * Smooth - A C++ framework for embedded programming on top of Espressif's ESP-IDF
 * Copyright 2019 Per Malmberg (https://gitbub.com/PerMalmberg)
 * Licensed under the Apache License, Version 2.0 (the "License");
 *
 * LittlevGL - A powerful and easy-to-use embedded GUI
 * Copyright (c) 2016 Gábor Kiss-Vámosi (https://github.com/littlevgl/lvgl)
 * Licensed under MIT License
 ***************************************************************************************/
#include "gui/FrenchGreetingView.h"
#include <smooth/core/logging/log.h>

using namespace smooth::core::logging;

namespace redstone
{
    // Class constatnts
    static const char* TAG = "FrenchGreetingView";

    // Constructor
    FrenchGreetingView::FrenchGreetingView()
    {
    }

    // Build the French Greeting View
    void FrenchGreetingView::build_view()
    {
        Log::info(TAG, "Building French Greeting View");

        // create screen handle
        french_greeting_screen = lv_obj_create(NULL, NULL);

        // create a roboto font, color yellow, size 28
        static lv_style_t style28yel;
        lv_style_copy(&style28yel, &lv_style_pretty);
        style28yel.text.font = &lv_font_roboto_28;
        style28yel.text.color = LV_COLOR_YELLOW;

        // create a roboto font, color white, size 28
        static lv_style_t style28wht;
        lv_style_copy(&style28wht, &lv_style_pretty);
        style28wht.text.font = &lv_font_roboto_28;
        style28wht.text.color = LV_COLOR_WHITE;

        // create a roboto font, color yellow, size 22
        static lv_style_t style22yel;
        lv_style_copy(&style22yel, &lv_style_pretty);
        style22yel.text.font = &lv_font_roboto_22;
        style22yel.text.color = LV_COLOR_YELLOW;

        // create a roboto font, color white, size 22
        static lv_style_t style22wht;
        lv_style_copy(&style22wht, &lv_style_pretty);
        style22wht.text.font = &lv_font_roboto_22;
        style22wht.text.color = LV_COLOR_WHITE;

        // create a roboto font, color black, size 22
        static lv_style_t style22blk;
        lv_style_copy(&style22blk, &lv_style_pretty);
        style22blk.text.font = &lv_font_roboto_22;
        style22blk.text.color = LV_COLOR_BLACK;

        // create a roboto font, color red, size 16
        static lv_style_t style16red;
        lv_style_copy(&style16red, &lv_style_pretty);
        style16red.text.font = &lv_font_roboto_16;
        style16red.text.color = LV_COLOR_RED;

        // create a roboto font, color blue, size 16
        static lv_style_t style16blu;
        lv_style_copy(&style16blu, &lv_style_pretty);
        style16blu.text.font = &lv_font_roboto_16;
        style16blu.text.color = LV_COLOR_BLUE;

        // create a style for our base container
        static lv_style_t styleBase;
        lv_style_copy(&styleBase, &lv_style_plain);
        styleBase.body.border.width = 0;
        styleBase.body.padding.inner = 20;
        styleBase.body.padding.top = 20;
        styleBase.body.padding.bottom = 20;
        styleBase.body.main_color = LV_COLOR_NAVY;
        styleBase.body.grad_color = LV_COLOR_NAVY;

        // create a style for our greeting container
        static lv_style_t stylecont_greeting;
        lv_style_copy(&stylecont_greeting, &lv_style_pretty);
        stylecont_greeting.body.border.width = 0;
        stylecont_greeting.body.main_color = LV_COLOR_GRAY;
        stylecont_greeting.body.grad_color = LV_COLOR_GRAY;
        stylecont_greeting.body.radius = 10;

        // create the base container; container size is size of the screen
        // layout children in centerd column; align container in center
        // of screen; set container style to use styleBase
        lv_obj_t* cont_base = lv_cont_create(french_greeting_screen, NULL);
        lv_obj_set_size(cont_base, LV_HOR_RES, LV_VER_RES);
        lv_cont_set_layout(cont_base, LV_LAYOUT_COL_M);
        lv_obj_align(cont_base, NULL, LV_ALIGN_CENTER, 0, 0);
        lv_cont_set_style(cont_base, LV_CONT_STYLE_MAIN, &styleBase);

        // place 1st item in base container - this is our title
        lv_obj_t* title = lv_label_create(cont_base, NULL);
        lv_obj_set_style(title, &style22wht);
        lv_label_set_text(title, "M5Stack Demo #1");
        lv_obj_align(title, cont_base, LV_ALIGN_CENTER, 0, 20);

        // place 2nd item in base container which is another contatiner;
        // create contatiner cont_greeting; set cont_greeting style
        // to stylecont_greeting; set width and height of container;
        // align container in center of cont_base
        lv_obj_t* cont_greeting = lv_cont_create(cont_base, NULL);
        lv_cont_set_style(cont_greeting, LV_CONT_STYLE_MAIN, &stylecont_greeting);
        lv_obj_set_width(cont_greeting, (lv_obj_get_width(cont_base) - 20));
        lv_obj_set_height(cont_greeting, (lv_obj_get_height(cont_base) - lv_obj_get_height(title) - 50));
        lv_obj_align(cont_greeting, NULL, LV_ALIGN_CENTER, 0, 0);

        // create a title for our contatiner cont_greeting
        lv_obj_t* title_greeting = lv_label_create(cont_greeting, NULL);
        lv_obj_set_style(title_greeting, &style22blk);
        lv_label_set_text(title_greeting, "Salutations");
        lv_obj_align(title_greeting, NULL, LV_ALIGN_IN_TOP_LEFT, 10, 5);

        // Create a large size greeting label
        lv_obj_t* label_greeting_lrg = lv_label_create(cont_greeting, NULL);
        lv_obj_set_style(label_greeting_lrg, &style28yel);
        lv_label_set_text(label_greeting_lrg, "BONJOUR");
        lv_obj_align(label_greeting_lrg, NULL, LV_ALIGN_IN_TOP_MID, 0, 60);

        // create medium size greeting label
        lv_obj_t* label_greeting_med = lv_label_create(cont_greeting, NULL);
        lv_obj_set_style(label_greeting_med, &style22wht);
        lv_label_set_text(label_greeting_med, "BONSOIR");
        lv_obj_align(label_greeting_med, NULL, LV_ALIGN_IN_TOP_MID, 0, 120);

        // create small size greeting label
        lv_obj_t* label_greeting_small = lv_label_create(cont_greeting, NULL);
        lv_obj_set_style(label_greeting_small, &style16red);
        lv_label_set_text(label_greeting_small, "BONNE NUIT");
        lv_obj_align(label_greeting_small, NULL, LV_ALIGN_IN_TOP_MID, 0, 180);
    }

    // Show the view
    void FrenchGreetingView::show()
    {
        lv_scr_load(french_greeting_screen);
    }
}
