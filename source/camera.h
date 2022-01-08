#ifndef CAMERA_H
#define CAMERA_H

#include <glad/glad.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <algorithm>

class Camera
{
    public:
        enum class MovementDirection
        {
            FORWARD,
            BACKWARD,
            LEFT,
            RIGHT
        };

    private:
        glm::vec3 m_position {0.0f, 0.0f, 3.0f};
        glm::vec3 m_front {0.0f, 0.0f, -1.0f};
        glm::vec3 m_up {0.0f, 1.0f, 0.0f};
        glm::vec3 m_right;
        glm::vec3 m_worldUp {0.0f, 1.0f, 0.0f};

        float m_yaw = -90.0f;
        float m_pitch = 0.0f;

        float m_speed = 2.5f;
        float m_sensitivity = 0.1f;

    public:
        Camera();

        [[nodiscard]] glm::mat4 getVeiwMatrix() const noexcept { return glm::lookAt(m_position, m_position + m_front, m_up); };

        void processMouseMovement(float xOffset, float yOffset, GLboolean constrainPitch);
        void processKeyboard(MovementDirection direction, float deltaTime);

    private:
        void updateVectors();
};

#endif
