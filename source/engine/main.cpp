#include "application.h"

#include "utils/log.h"

int main()
{
    OGLR_INFO("Test");

    Application::getInstance().init();

    Application::getInstance().run();

    return 0;
}
