#include "application.h"
#include "asserts.h"
#include "allocator.h"

#include <chrono>

int main()
{
    Application::getInstance().init();

    Application::getInstance().run();
    
    return 0;
}
