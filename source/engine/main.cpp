#include "application.h"

#include "utils/log.h"

int main()
{
    Application::getInstance().init();

    Application::getInstance().run();

    return 0;
}
