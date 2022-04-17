#pragma once

// STD library includes
#include <array>
#include <functional>

// Renderer includes
#include "defines.h"
#include "input/keys.h"
#include "utilities/singleton.h"
#include "utilities/utils.h"

// Reference and adapted from 
// https://github.com/htmlboss/OpenGL-Renderer/blob/master/MP-APS/Input.h

class Input : public Singleton<Input>
{
    private:
        std::array<b8, enumCast(KEY_MAX)> m_currKeys{ false };
        std::array<b8, enumCast(KEY_MAX)> m_prevKeys{ false };

        f32 m_xMousePos, m_yMousePos;
        b8 m_mouseMoved = false;

    public:
        void update() 
        {
            m_mouseMoved = false;
            std::copy(m_currKeys.cbegin(), m_currKeys.cend(), m_prevKeys.begin());
        }

        [[nodiscard]] b8 isKeyPressed(const Key key) const noexcept { return (m_currKeys[enumCast(key)] == true); }

        [[nodiscard]] b8 isMouseMoved() const noexcept { return m_mouseMoved; }
        [[nodiscard]] f32 getMousePosX() const noexcept { return m_xMousePos; }
        [[nodiscard]] f32 getMousePosY() const noexcept { return m_yMousePos; }

        void processKeyInput(Key key, b8 pressed) 
        { 
            if (m_currKeys[enumCast(key)] != pressed)
            {
                m_currKeys[enumCast(key)] = pressed; 
            }
        }
};
