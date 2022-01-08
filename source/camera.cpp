#include "camera.h"

Camera::Camera()
{
    updateVectors();
}

void Camera::processKeyboard(MovementDirection direction, float deltaTime)
{
    float velocity = m_speed * deltaTime;
    if (direction == MovementDirection::FORWARD)
        m_position += m_front * velocity;
    if (direction == MovementDirection::BACKWARD)
        m_position -= m_front * velocity;
    if (direction == MovementDirection::LEFT)
        m_position -= m_right * velocity;
    if (direction == MovementDirection::RIGHT)
        m_position += m_right * velocity;
}

void Camera::processMouseMovement(float xOffset, float yOffset, GLboolean constrainPitch)
{
    xOffset *= m_sensitivity;
    yOffset *= m_sensitivity;

    m_yaw += xOffset;
    m_pitch += yOffset;

    if(constrainPitch){ m_pitch = std::clamp(m_pitch, -89.0f, 89.0f); }

    updateVectors();
}

void Camera::updateVectors()
{
    glm::vec3 front{
        cos(glm::radians(m_yaw) * cos(glm::radians(m_pitch))),
        sin(glm::radians(m_pitch)),
        sin(glm::radians(m_yaw))  * cos(glm::radians(m_pitch))
    };

    m_front = glm::normalize(front);
    m_right = glm::normalize(glm::cross(m_front, m_worldUp));
    m_up = glm::normalize(glm::cross(m_right, m_front));
}
