#ifndef CAMERA_H
#define CAMERA_H

#include <glfw/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <algorithm>

// Referenced and adapted from
// https://learnopengl.com/Getting-started/Camera
// https://github.com/htmlboss/OpenGL-Renderer/blob/master/MP-APS/Camera.h

class Camera
{
    private:
        enum class MovementDirection
        {
            FORWARD,
            BACKWARD,
            LEFT,
            RIGHT
        };

        glm::vec3 m_position {0.0f, 0.0f, 3.0f};
        glm::vec3 m_front {0.0f, 0.0f, -1.0f};
        glm::vec3 m_up {0.0f, 1.0f, 0.0f};
        glm::vec3 m_right;
        glm::vec3 m_worldUp {0.0f, 1.0f, 0.0f};
        
        const float_t m_near = 0.1f, m_far = 1000.0f;
        const float_t m_FOV = 60.0f;

        float_t m_yaw = -90.0f;
        float_t m_pitch = 0.0f;

        float_t m_speed = 2.5f;

        float_t m_sensitivity = 0.1f;
        bool m_firstMouse = true;
        float_t m_prevX = 0.0, m_prevY = 0.0;

    public:
        Camera();

        void update(const float_t deltaTime);

        [[nodiscard]] glm::mat4 getProjMatrix(const float_t width, const float_t height) const { return glm::perspective(glm::radians(m_FOV), width / height, m_near, m_far); }
        [[nodiscard]] glm::mat4 getVeiwMatrix() const { return glm::lookAt(m_position, m_position + m_front, m_up); };

    private:
        void processKeyboard(MovementDirection direction, float_t deltaTime);

        void updateMouse();
        void updateVectors();
};

#endif
