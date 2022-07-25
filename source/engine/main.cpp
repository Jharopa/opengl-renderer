#include "application.h"
#include "local.h"

int main()
{
    local();
    
    Application::getInstance().init();

    Application::getInstance().run();
    
    return 0;
}
