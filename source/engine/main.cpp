#include "application.h"

#include "oglr_math.h"
#include <type_traits>

int main()
{
    math::vec3 v1 = math::vec3(2, 3, 4);
    math::vec3 v2 = math::vec3(5, 6, 7);
    math::vec3 av = v2 + 3.0f ;

    std::cout << "(" << av.x << ", " << av.y << ", " << av.z << ")" << std::endl;

    f32 d = math::dot(v1, v2);
    math::vec3 cv = math::cross(v1, v2);

    std::cout << d << std::endl;
    std::cout << "(" << cv.x << ", " << cv.y << ", " << cv.z << ")" << std::endl;

    std::cout << std::is_trivial<math::vec2>() << std::endl;
    std::cout << std::is_standard_layout<math::vec2>() << std::endl;

    std::cout << OGLR_PI << std::endl; 

    std::cout << math::magnitude(v1) << std::endl;

    math::vec3 nv = math::normalize(v1);
    std::cout << "(" << nv.x << ", " << nv.y << ", " << nv.z << ")" << std::endl;

    Application::getInstance().init();

    Application::getInstance().run();
    
    return 0;
}
