#pragma once

#include <fmt/core.h>
#include <fmt/color.h>
#include <fmt/chrono.h>

#include "defines.h"
#include "singleton.h"
#include "utils.h"

enum class Level : u8
{
    Debug = 0,
    Info = 1,
    Warning = 2,
    Error = 3,
    Fatal = 4,
    Max
};

class Logger : public Singleton<Logger>
{
    public:
        void log(Level level, std::string message)
        {
            std::time_t t = std::time(nullptr);

            std::string level_prefix[enumCast(Level::Max)] = {"[DEBUG] ", "[INFO] ", "[WARN] ", "[ERROR] ", "[FATAL] "};
            fmt::color level_text_color[enumCast(Level::Max)] = {fmt::color::beige, fmt::color::blue, fmt::color::yellow, fmt::color::orange_red, fmt::color::red}; 

            fmt::print(fg(level_text_color[enumCast(level)]), "{} {:%Y-%m-%d %H:%M:%S}: {}\n", level_prefix[enumCast(level)], fmt::localtime(t), message);
        }
};

#define OGLR_DEBUG(msg) Logger::getInstance().log(Level::Debug, msg)
#define OGLR_INFO(msg) Logger::getInstance().log(Level::Info, msg)
#define OGLR_WARN(msg) Logger::getInstance().log(Level::Warning, msg)
#define OGLR_ERROR(msg) Logger::getInstance().log(Level::Error, msg)
#define OGLR_FATAL(msg) Logger::getInstance().log(Level::Fatal, msg)
