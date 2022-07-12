#include "camera.h"

Camera::Camera()
{
    updateVectors();
}

void Camera::update(const f32 deltaTime)
{
    updateMouse();

    if (Input::getInstance().isKeyPressed(KEY_W)) processKeyboard(MovementDirection::Forward, deltaTime);
    if (Input::getInstance().isKeyPressed(KEY_A)) processKeyboard(MovementDirection::Left, deltaTime);
    if (Input::getInstance().isKeyPressed(KEY_S)) processKeyboard(MovementDirection::Backward, deltaTime);
    if (Input::getInstance().isKeyPressed(KEY_D)) processKeyboard(MovementDirection::Right, deltaTime);
}

void Camera::processKeyboard(MovementDirection direction, f32 deltaTime)
{
    float velocity = m_speed * deltaTime;
    if (direction == MovementDirection::Forward)
        m_position = m_position + m_front * velocity;
    if (direction == MovementDirection::Backward)
        m_position = m_position - m_front * velocity;
    if (direction == MovementDirection::Left)
        m_position = m_position - m_right * velocity;
    if (direction == MovementDirection::Right)
        m_position = m_position + m_right * velocity;
}

void Camera::updateMouse()
{
    if (Input::getInstance().isMouseMoved())
    {
        const f32 xPos = Input::getInstance().getMousePosX();
        const f32 yPos = Input::getInstance().getMousePosY();

        if (m_firstMouse) 
        {
			m_prevX = xPos;
			m_prevY = yPos;
			m_firstMouse = false;
		}

        f32 xOffset = (xPos - m_prevX) * m_sensitivity;
		f32 yOffset = (m_prevY - yPos) * m_sensitivity;

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
    math::vec3 front(
        cos(math::radians(m_yaw) * cos(math::radians(m_pitch))),
        sin(math::radians(m_pitch)),
        sin(math::radians(m_yaw))  * cos(math::radians(m_pitch))
    );

    m_front = math::normalize(front);
    m_right = math::normalize(math::cross(m_front, m_worldUp));
    m_up = math::normalize(math::cross(m_right, m_front));
}
