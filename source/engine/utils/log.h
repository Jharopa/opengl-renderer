#pragma once

#include <iostream>

#include "defines.h"
#include "singleton.h"
#include "utils.h"

enum class Level : u8
{
    Debug = 0,
    Info = 1,
    Warning = 2,
    Error = 3,
    Fatal = 4
};

class Logger : public Singleton<Logger>
{
    public:
        void log(Level level, std::string message)
        {
            std::string level_string[5] = {"[DEBUG]: ", "[INFO]: ", "[WARN]: ", "[ERROR]: ", "[FATAL]: "};

            std::cout << level_string[enumCast(level)] << message << std::endl;
        }
};

#define OGLR_DEBUG(msg) Logger::getInstance().log(Level::Debug, msg)
#define OGLR_INFO(msg) Logger::getInstance().log(Level::Info, msg)
#define OGLR_WARN(msg) Logger::getInstance().log(Level::Warning, msg)
#define OGLR_ERROR(msg) Logger::getInstance().log(Level::Error, msg)
#define OGLR_FATAL(msg) Logger::getInstance().log(Level::Fatal, msg)
