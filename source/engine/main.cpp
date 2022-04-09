#include "application.h"

#include "utils/log.h"

#include <chrono>
#include <thread>

int main()
{
    i32 duration = 2000;

    OGLR_DEBUG("Debug test");
    std::this_thread::sleep_for(std::chrono::milliseconds(duration));
    OGLR_INFO("Info test");
    std::this_thread::sleep_for(std::chrono::milliseconds(duration));
    OGLR_WARN("Warn test");
    std::this_thread::sleep_for(std::chrono::milliseconds(duration));
    OGLR_ERROR("Error test");
    std::this_thread::sleep_for(std::chrono::milliseconds(duration));
    OGLR_FATAL("Fatal test");

    Application::getInstance().init();

    Application::getInstance().run();

    return 0;
}
