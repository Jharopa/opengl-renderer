#include "application.h"
#include "vec.h"

int main()
{
    vec2 v = vec2();

    std::cout << v.x << " " << v.y << std::endl;

    Application::getInstance().init();

    Application::getInstance().run();
    
    return 0;
}
