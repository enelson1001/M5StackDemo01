/****************************************************************************************
 * ChangeViewTask.h - A task that runs that toggles the view to be shown
 * Created by Ed Nelson on Nov. 06, 2019
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
#pragma once

#include <smooth/core/Task.h>
#include <smooth/core/ipc/IEventListener.h>
#include <smooth/core/ipc/SubscribingTaskEventQueue.h>
#include "model/ShowViewValue.h"

namespace redstone
{
    class ChangeViewTask : public smooth::core::Task

    {
        public:
            ChangeViewTask();

            void init() override;

            void tick() override;

        private:
            bool show_english_greeting{ true };
            ShowViewValue show_view_value{};
    };
}
