/****************************************************************************************
 * App.cpp - The Application class
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

//*****************************************************************************************************************
// Typical output on M5Stack 
//
//  MemStat: Mem type |  8-bit free | Smallest block | Minimum free | 32-bit free | Smallest block | Minimum free
//  MemStat: INTERNAL |      130552 |         113804 |       129928 |      187448 |         113804 |       186816
//  MemStat:      DMA |      130552 |         113804 |       129928 |      130552 |         113804 |       129928
//  MemStat:   SPIRAM |           0 |              0 |            0 |           0 |              0 |            0
//  MemStat:
//  MemStat:             Name |      Stack |  Min free stack |  Max used stack
//  MemStat:         LvglTask |       4096 |             944 |            3152
//  MemStat:   ChangeViewTask |       3072 |             996 |            2076
//  MemStat: SocketDispatcher |      20480 |           18404 |            2076
//  MemStat:         MainTask |      16384 |           12948 |            3436
//******************************************************************************************************************
#include "App.h"
#include <smooth/core/logging/log.h>
#include <smooth/core/SystemStatistics.h>

using namespace smooth::core;
using namespace std::chrono;
using namespace smooth::core::io::spi;
using namespace smooth::application::display;

namespace redstone
{
    // Class Constants
    static const char* TAG = "APP";
    

    // Constructor
    App::App() : Application(APPLICATION_BASE_PRIO, seconds(5))
    {
    }

    // Initialize the application
    void App::init()
    {
        Log::warning(TAG, "============ Starting APP  ===========");
        Application::init();

        mLvglTask.start();

        mChangeViewTask.start();
    }

    // Tick event happens every 5 seconds
    void App::tick()
    {
        Log::warning(TAG, "============ Main TICK TICK TICK  =============");

        if ( !heap_caps_check_integrity_all(true) )
        {
            Log::error(TAG, "========= Heap Corrupted  ===========");
        }

        SystemStatistics::instance().dump();
    }
}
