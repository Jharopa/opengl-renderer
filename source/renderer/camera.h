#pragma once

// GLFW includes
#include <glfw/glfw3.h>

// GLM includes
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

// STD library includes
#include <algorithm>

// Renderer includes
#include "input/input.h"

// Referenced and adapted from
// https://learnopengl.com/Getting-started/Camera
// https://github.com/htmlboss/OpenGL-Renderer/blob/master/MP-APS/Camera.h

class Camera
{
    private:
        enum class MovementDirection
        {
            Forward,
            Backward,
            Left,
            Right
        };

        glm::vec3 m_position {0.0f, 0.0f, 3.0f};
        glm::vec3 m_front {0.0f, 0.0f, -1.0f};
        glm::vec3 m_up {0.0f, 1.0f, 0.0f};
        glm::vec3 m_right;
        glm::vec3 m_worldUp {0.0f, 1.0f, 0.0f};
        
        const f32 m_near = 0.1f, m_far = 1000.0f;
        const f32 m_FOV = 60.0f;

        f32 m_yaw = -90.0f;
        f32 m_pitch = 0.0f;

        f32 m_speed = 2.5f;

        f32 m_sensitivity = 0.1f;
        b8 m_firstMouse = true;
        f32 m_prevX = 0.0f, m_prevY = 0.0f;

    public:
        Camera();

        void update(const f32 deltaTime);

        [[nodiscard]] glm::mat4 getProjMatrix(const f32 width, const f32 height) const { return glm::perspective(glm::radians(m_FOV), width / height, m_near, m_far); }
        [[nodiscard]] glm::mat4 getVeiwMatrix() const { return glm::lookAt(m_position, m_position + m_front, m_up); };

    private:
        void processKeyboard(MovementDirection direction, f32 deltaTime);

        void updateMouse();
        void updateVectors();
};
