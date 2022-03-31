#include "pch.h"

#include "application.h"

int main()
{
    Application::getInstance().init();

    Application::getInstance().run();

    return 0;
}
