/****************************************************************************************
 * ViewController.cpp - Controls which view is presented
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
#include "gui/ViewController.h"
#include <smooth/core/logging/log.h>

using namespace smooth::core::logging;

namespace redstone
{
    // Class constants
    static const char* TAG = "ViewController";

    // Constructor
    ViewController::ViewController(smooth::core::Task& lvglTask) :
            subr_queue_show_view_value(SubQShowViewValue::create(8, lvglTask, *this))

            // Create Subscriber Queue (SubQ) so this view can listen for
            // ShowViewValue events
            // the queue will hold up to 2 items
            // the "lvglTask" is this task which to signal when an event is available.
            // the "*this" is the class instance that will receive the events
    {
    }

    // Initialize view controller
    void ViewController::init()
    {
        Log::info(TAG, "====== initializing ViewController ======");
        create_view_objects();
        build_views();
        show_view("English Greeting");
    }

    // Create view instance
    void ViewController::create_view_objects()
    {
        views.insert(std::make_pair("English Greeting", std::make_unique<EnglishGreetingView>()));
        views.insert(std::make_pair("French Greeting", std::make_unique<FrenchGreetingView>()));
    }

    // Build the views
    void ViewController::build_views()
    {
        views.at("English Greeting")->build_view();
        views.at("French Greeting")->build_view();
    }

    // Show a particular view
    void ViewController::show_view(std::string view_to_show)
    {
        views.at(view_to_show)->show();
    }

    // The published event from ShowViewValue
    void ViewController::event(const ShowViewValue& event)
    {
        view_to_show = event.get_view_to_show();
        show_view(view_to_show);
    }
}
