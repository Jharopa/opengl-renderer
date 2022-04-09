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
        template <typename... Args>
        void log(Level level, const std::string& message, Args... args)
        {
            std::time_t t = std::time(nullptr);

            std::string finalFormat = m_prefixTimestampFormat + message + "\n";

            if(level == Level::Fatal)
            {
                fmt::print(stderr, fg(m_levelTextColor[enumCast(level)]), finalFormat, m_levelPrefix[enumCast(level)], fmt::localtime(t), args...);
            }
            else
            {
                fmt::print(fg(m_levelTextColor[enumCast(level)]), finalFormat, m_levelPrefix[enumCast(level)], fmt::localtime(t), args...);
            }
        }

    private:
        const std::string m_levelPrefix[enumCast(Level::Max)] = {"[DEBUG] ", "[INFO] ", "[WARN] ", "[ERROR] ", "[FATAL] "};
        const fmt::color m_levelTextColor[enumCast(Level::Max)] = {fmt::color::beige, fmt::color::dodger_blue, fmt::color::yellow, fmt::color::orange, fmt::color::red};
        const std::string m_prefixTimestampFormat = "{}{:%Y-%m-%d %H:%M:%S}: ";
};

#define OGLR_DEBUG(msg, ...) Logger::getInstance().log(Level::Debug, msg, __VA_ARGS__)
#define OGLR_INFO(msg, ...) Logger::getInstance().log(Level::Info, msg, __VA_ARGS__)
#define OGLR_WARN(msg, ...) Logger::getInstance().log(Level::Warning, msg, __VA_ARGS__)
#define OGLR_ERROR(msg, ...) Logger::getInstance().log(Level::Error, msg, __VA_ARGS__)
#define OGLR_FATAL(msg, ...) Logger::getInstance().log(Level::Fatal, msg, __VA_ARGS__)
