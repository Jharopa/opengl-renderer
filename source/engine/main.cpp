#include "application.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/string_cast.hpp>

int main()
{
    Application::getInstance().init();

    Application::getInstance().run();
    
    return 0;
}
