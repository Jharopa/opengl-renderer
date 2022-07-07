#include "application.h"
#include "vec.h"
#include <type_traits>

int main()
{
    math::vec3 v1 = math::vec3(2, 3, 4);
    math::vec3 v2 = math::vec3(5, 6, 7);

    f32 d = math::dot(v1, v2);
    math::vec3 cv = math::cross(v1, v2);

    std::cout << d << std::endl;
    std::cout << "(" << cv.x << ", " << cv.y << ", " << cv.z << ")" << std::endl;

    std::cout << std::is_trivial<math::vec2>() << std::endl;
    std::cout << std::is_standard_layout<math::vec2>() << std::endl;

    Application::getInstance().init();

    Application::getInstance().run();
    
    return 0;
}
