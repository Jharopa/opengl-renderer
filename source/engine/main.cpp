#include "application.h"

#include "utils/log.h"

#include <chrono>
#include <thread>

int main()
{
    i32 duration = 2000;

    OGLR_DEBUG("Debug test");
    OGLR_INFO("Info test");
    OGLR_WARN("Warn test");
    OGLR_ERROR("Error test");
    OGLR_FATAL("Fatal test");

    OGLR_INFO("Test {}", 3.14);

    Application::getInstance().init();

    Application::getInstance().run();

    return 0;
}
