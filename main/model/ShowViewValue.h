/****************************************************************************************
 * ShowViewValue.h - This class instance is published and received by subscribers
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

#include <string>

namespace redstone
{
    class ShowViewValue
    {
        public:
            ShowViewValue() {}

            std::string get_view_to_show() const { return view_to_show; }

            void set_view_to_show(std::string value) { view_to_show = value; }
        private:
            std::string view_to_show;
    };
}
