#pragma once

// STD library includes
#include <array>
#include <functional>

// Renderer includes
#include "defines.h"
#include "input/keys.h"
#include "core/singleton.h"
#include "core/utils.h"

// Reference and adapted from 
// https://github.com/htmlboss/OpenGL-Renderer/blob/master/MP-APS/Input.h

class Input : public Singleton<Input>
{
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

        std::function<void(int32_t, int32_t, int32_t, int32_t)> keyPressed = [&](int32_t key, int32_t scanCode, int32_t action, int32_t mode)
        {
            if (key > 0)
            {
                switch (action) 
                {
				    case 0:
				    	this->m_currKeys[key] = false;
				    	break;
				    case 1:
				    	this->m_currKeys[key] = true;
				    	break;
			    }
            }
        };

        std::function<void(double_t, double_t)> mouseMoved = [&](double_t xPos, double_t yPos) 
        {
		    this->m_mouseMoved = true;
		    this->m_xMousePos = (float_t)xPos;
		    this->m_yMousePos = (float_t)yPos;
	    };

    private:
        std::array<b8, enumCast(KEY_MAX)> m_currKeys{ false };
        std::array<b8, enumCast(KEY_MAX)> m_prevKeys{ false };

        f32 m_xMousePos, m_yMousePos;
        b8 m_mouseMoved = false;
};
