/****************************************************************************************
 * App.h - The Application class
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
#pragma once

#include <smooth/core/Application.h>
#include <smooth/core/task_priorities.h>
#include <smooth/application/display/ILI9341.h>

#include "gui/LvglTask.h"
#include "model/ChangeViewTask.h"

namespace redstone
{
    class App : public smooth::core::Application
    {
        public:
            App();

            void init() override;

            void tick() override;

        private:
            LvglTask mLvglTask{};
            ChangeViewTask mChangeViewTask{};
    };
}
