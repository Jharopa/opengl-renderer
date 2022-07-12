#include "application.h"

#include "oglr_math.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/string_cast.hpp>

int main()
{
    //math::mat4 m = math::identity();

    //std::cout << "(" << m[0].x << ", " << m[0].y << ", " << m[0].z << ", " << m[0].w << ")\n";
    //std::cout << "(" << m[1].x << ", " << m[1].y << ", " << m[1].z << ", " << m[1].w << ")\n";
    //std::cout << "(" << m[2].x << ", " << m[2].y << ", " << m[2].z << ", " << m[2].w << ")\n";
    //std::cout << "(" << m[3].x << ", " << m[3].y << ", " << m[3].z << ", " << m[3].w << ")\n";

    //std::cout << "\n";

    math::mat4 mm = math::mat4(math::vec4(1, 2, 3, 4), math::vec4(4, 3, 2, 1), math::vec4(5, 6, 7, 8), math::vec4(8, 7, 6, 5));
    std::cout << "(" << mm[0].x << ", " << mm[0].y << ", " << mm[0].z << ", " << mm[0].w << ")\n";
    std::cout << "(" << mm[1].x << ", " << mm[1].y << ", " << mm[1].z << ", " << mm[1].w << ")\n";
    std::cout << "(" << mm[2].x << ", " << mm[2].y << ", " << mm[2].z << ", " << mm[2].w << ")\n";
    std::cout << "(" << mm[3].x << ", " << mm[3].y << ", " << mm[3].z << ", " << mm[3].w << ")\n";

    std::cout << "\n";

    math::vec4 mv = math::vec4(4, 6, 9, 2);

    std::cout << "(" << mv.x << ", " << mv.y << ", " << mv.z << ", " << mv.w << ")\n";

    std::cout << "\n";

    math::vec4 rv = mm * mv;

    std::cout << "(" << rv.x << ", " << rv.y << ", " << rv.z << ", " << rv.w << ")\n";

    std::cout << "\n";

    math::mat4 mmm = mm * mm;

    std::cout << "(" << mmm[0].x << ", " << mmm[0].y << ", " << mmm[0].z << ", " << mmm[0].w << ")\n";
    std::cout << "(" << mmm[1].x << ", " << mmm[1].y << ", " << mmm[1].z << ", " << mmm[1].w << ")\n";
    std::cout << "(" << mmm[2].x << ", " << mmm[2].y << ", " << mmm[2].z << ", " << mmm[2].w << ")\n";
    std::cout << "(" << mmm[3].x << ", " << mmm[3].y << ", " << mmm[3].z << ", " << mmm[3].w << ")\n";

    math::mat4 pm = math::perspective(math::radians(70.0f), 16.0f / 9.0f, 0.1f, 1000.0f);
    glm::mat4 gm = glm::perspective(glm::radians(70.0f), 16.0f / 9.0f, 0.1f, 1000.0f);
    std::cout << glm::to_string(gm) << "\n";

    std::cout << "(" << pm[0].x << ", " << pm[0].y << ", " << pm[0].z << ", " << pm[0].w << ")\n";
    std::cout << "(" << pm[1].x << ", " << pm[1].y << ", " << pm[1].z << ", " << pm[1].w << ")\n";
    std::cout << "(" << pm[2].x << ", " << pm[2].y << ", " << pm[2].z << ", " << pm[2].w << ")\n";
    std::cout << "(" << pm[3].x << ", " << pm[3].y << ", " << pm[3].z << ", " << pm[3].w << ")\n";

    Application::getInstance().init();

    Application::getInstance().run();
    
    return 0;
}
