/****************************************************************************************
 * IView.h - An abstract class that Views implement
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

namespace redstone
{
    class IView
    {
        public:
            virtual ~IView() {}

            virtual void show() = 0;

            virtual void build_view() = 0;

        private:
    };
}
