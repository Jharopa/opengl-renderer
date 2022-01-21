#ifndef INPUT_H
#define INPUT_H

// GLFW includes
#include <glfw/glfw3.h>

// STD library includes
#include <array>
#include <functional>

// Renderer includes
#include "defines.h"

// Reference and adapted from 
// https://github.com/htmlboss/OpenGL-Renderer/blob/master/MP-APS/Input.h

class Input
{
    private:
        std::array<b8, GLFW_KEY_LAST> m_pressedKeys{false};
        std::array<b8, GLFW_KEY_LAST> m_prevPressedKeys{false};

        f32 m_xMousePos, m_yMousePos;
        b8 m_mouseMoved = false;

    public:
        static Input& getInstance() 
        {
		    static Input instance;
		    return instance;
	    }

        void update() 
        {
            m_mouseMoved = false; 
            std::copy(m_pressedKeys.cbegin(), m_pressedKeys.cend(), m_prevPressedKeys.begin());
        }

        [[nodiscard]] b8 isKeyPressed(const i32 key) const noexcept { return m_pressedKeys[key] && !m_prevPressedKeys[key]; }
        [[nodiscard]] b8 isKeyHeld(const i32 key) const noexcept { return m_pressedKeys[key]; }
        
        [[nodiscard]] b8 isMouseMoved() const noexcept { return m_mouseMoved; }
        [[nodiscard]] f32 getMousePosX() const noexcept { return m_xMousePos; }
        [[nodiscard]] f32 getMousePosY() const noexcept { return m_yMousePos; }

        std::function<void(i32, i32, i32, i32)> keyPressed = [&](i32 key, i32 scanCode, i32 action, i32 mode)
        {
            if (key > 0)
            {
                switch (action) 
                {
				    case 0:
				    	this->m_pressedKeys[key] = false;
				    	break;
				    case 1:
				    	this->m_pressedKeys[key] = true;
				    	break;
			    }
            }
        };

        std::function<void(f64, f64)> mouseMoved = [&](f64 xPos, f64 yPos) 
        {
		    this->m_mouseMoved = true;
		    this->m_xMousePos = (f32)xPos;
		    this->m_yMousePos = (f32)yPos;
	    };
    
    private:
        Input() {};
	    ~Input() = default;
};

#endif