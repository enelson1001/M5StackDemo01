/****************************************************************************************
 * ViewController.h - Controls which view is presented
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
#include <memory>       // for unique_ptr
#include <unordered_map>
#include <smooth/core/Task.h>
#include <smooth/core/ipc/IEventListener.h>
#include <smooth/core/ipc/SubscribingTaskEventQueue.h>
#include "gui/IView.h"
#include "gui/EnglishGreetingView.h"
#include "gui/FrenchGreetingView.h"
#include "model/ChangeViewTask.h"

namespace redstone
{
    class ViewController : public smooth::core::ipc::IEventListener<ShowViewValue>
    {
        public: 
            ViewController(smooth::core::Task &lvglTask);
            
            void init();
            
            void show_view(std::string view_to_show);

            void event(const ShowViewValue& event) override;


        private:
            void create_view_objects();
            void build_views();

            std::unordered_map<std::string, std::unique_ptr<IView>> views;
            bool show_english_greeting {true};
            std::string view_to_show;

            // Subscriber's queue's 
            using SubQShowViewValue = smooth::core::ipc::SubscribingTaskEventQueue<ShowViewValue>;
            std::shared_ptr<SubQShowViewValue> subr_queue_show_view_value;

            
    };
}
