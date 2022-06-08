#pragma once

#include "log.h"

#include <chrono>
#include <thread>
#include <sstream>

// Referenced and Adapted from:
// https://gist.github.com/TheCherno/31f135eea6ee729ab5f26a6908eb3a5e
// Game Engine Architecture, Third Edition ISBN-13 - 978-1138035454

struct ProfileResults
{
    std::string name;
    std::chrono::microseconds elapsedTime;
    std::thread::id threadID;
};

static void printProfile(const ProfileResults& results)
{
    std::stringstream ss;
    ss << results.threadID;
    
    OGLR_DEBUG("Function name: {} - Duration: {} \xE6s - Thread ID: #{} ", results.name, results.elapsedTime.count(), ss.str());
}

class Profiler
{
    public:
        Profiler(const char* name) 
            : m_name(name)
        {
            m_startTimePoint = std::chrono::high_resolution_clock::now();
        }

        ~Profiler()
        {
            std::chrono::steady_clock::time_point endTimePoint = std::chrono::high_resolution_clock::now();

            auto elapsedTime = std::chrono::time_point_cast<std::chrono::microseconds>(endTimePoint).time_since_epoch() - std::chrono::time_point_cast<std::chrono::microseconds>(m_startTimePoint).time_since_epoch();

            printProfile({ m_name, elapsedTime, std::this_thread::get_id() });
        }
    
    private:
        const char* m_name;
        std::chrono::time_point<std::chrono::high_resolution_clock> m_startTimePoint;
};
#ifdef PROFILER_ENABLED
    #define PROFILE_SCOPE(name) Profiler OGLR_CONCAT(timer, __LINE__)(name)
    #define PROFILE_FUNCTION() PROFILE_SCOPE(__FUNCTION__)
#else
    #define PROFILE_SCOPE(name)
    #define PROFILE_FUNCTION()
#endif
