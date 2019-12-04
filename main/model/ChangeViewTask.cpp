/****************************************************************************************
 * ChangeViewTask.cpp - A task that runs that toggles the view to be shown
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
#include "model/ChangeViewTask.h"
#include <smooth/core/ipc/Publisher.h>

using namespace std::chrono;
using namespace smooth::core;
using namespace smooth::core::ipc;

namespace redstone
{
    // Constructor
    ChangeViewTask::ChangeViewTask() :
            smooth::core::Task("ChangeViewTask", 3072, 10, milliseconds(2000))

            // The Task Name = "ChangeViewTask"
            // The stack size is 3072 bytes
            // The priority is set to 10
            // The tick interval is 2 sec

    {
    }

    // Initialize the Task
    void ChangeViewTask::init()
    {
    }

    // The task tick event happens every 2 seconds
    void ChangeViewTask::tick()
    {
        if (show_english_greeting)
        {
            show_english_greeting = false;
            show_view_value.set_view_to_show("English Greeting");
            Publisher<ShowViewValue>::publish(show_view_value);
        }
        else
        {
            show_english_greeting = true;
            show_view_value.set_view_to_show("French Greeting");
            Publisher<ShowViewValue>::publish(show_view_value);
        }
    }
}
