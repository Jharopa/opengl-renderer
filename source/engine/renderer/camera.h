#pragma once

// GLFW includes
#include <glfw/glfw3.h>

// STD library includes
#include <algorithm>

// Renderer includes
#include "math/oglr_math.h"
#include "input/input.h"

// Referenced and adapted from
// https://learnopengl.com/Getting-started/Camera
// https://github.com/htmlboss/OpenGL-Renderer/blob/master/MP-APS/Camera.h

enum class MovementDirection
{
    Forward,
    Backward,
    Left,
    Right
};

class Camera
{
    public:
        Camera();

        void update(const f32 deltaTime);

        [[nodiscard]] math::mat4 getProjMatrix(const f32 width, const f32 height) const { return math::perspective(math::radians(m_FOV), width / height, m_nearPlane, m_farPlane); }
        [[nodiscard]] math::mat4 getVeiwMatrix() const { return math::look_at(m_position, m_position + m_front, m_up); };

    private:
        void processKeyboard(MovementDirection direction, f32 deltaTime);

        void updateMouse();
        void updateVectors();
    
    private:
        math::vec3 m_position {0.0f, 0.0f, 3.0f};
        math::vec3 m_front = math::froward();
        math::vec3 m_up = math::up();
        math::vec3 m_right;
        math::vec3 m_worldUp = math::up();
        
        const f32 m_FOV = 60.0f, m_nearPlane = 0.1f, m_farPlane = 1000.0f;

        f32 m_pitch = 0.0f, m_yaw = -90.0f;

        f32 m_speed = 2.5f;

        f32 m_sensitivity = 0.1f;
        b8 m_firstMouse = true;
        f32 m_prevX = 0.0f, m_prevY = 0.0f;
};
