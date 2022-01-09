#include "camera.h"

#include "input.h"

Camera::Camera()
{
    updateVectors();
}

void Camera::update(const float_t deltaTime)
{
    updateMouse();

    if (Input::getInstance().isKeyPressed(GLFW_KEY_W) || Input::getInstance().isKeyHeld(GLFW_KEY_W)) processKeyboard(MovementDirection::FORWARD, deltaTime);
    if (Input::getInstance().isKeyPressed(GLFW_KEY_D) || Input::getInstance().isKeyHeld(GLFW_KEY_D)) processKeyboard(MovementDirection::RIGHT, deltaTime);
    if (Input::getInstance().isKeyPressed(GLFW_KEY_S) || Input::getInstance().isKeyHeld(GLFW_KEY_S)) processKeyboard(MovementDirection::BACKWARD, deltaTime);
    if (Input::getInstance().isKeyPressed(GLFW_KEY_A) || Input::getInstance().isKeyHeld(GLFW_KEY_A)) processKeyboard(MovementDirection::LEFT, deltaTime);
}

void Camera::processKeyboard(MovementDirection direction, float_t deltaTime)
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

void Camera::updateMouse()
{
    if (Input::getInstance().isMouseMoved())
    {
        const float_t xPos = Input::getInstance().getMousePosX();
        const float_t yPos = Input::getInstance().getMousePosY();

        if (m_firstMouse) 
        {
			m_prevX = xPos;
			m_prevY = yPos;
			m_firstMouse = false;
		}

        float_t xOffset = (xPos - m_prevX) * m_sensitivity;
		float_t yOffset = (m_prevY - yPos) * m_sensitivity;

        m_prevX = xPos;
		m_prevY = yPos;

		m_yaw += xOffset;
		m_pitch += yOffset;

        m_pitch = std::clamp(m_pitch, -89.0f, 89.0f);

        updateVectors();
    }
}

void Camera::updateVectors()
{
    glm::vec3 front
    {
        cos(glm::radians(m_yaw) * cos(glm::radians(m_pitch))),
        sin(glm::radians(m_pitch)),
        sin(glm::radians(m_yaw))  * cos(glm::radians(m_pitch))
    };

    m_front = glm::normalize(front);
    m_right = glm::normalize(glm::cross(m_front, m_worldUp));
    m_up = glm::normalize(glm::cross(m_right, m_front));
}
