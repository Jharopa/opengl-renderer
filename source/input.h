#ifndef INPUT_H
#define INPUT_H

// GLFW includes
#include <glfw/glfw3.h>

// STD library includes
#include <array>
#include <functional>

// Reference and adapted from 
// https://github.com/htmlboss/OpenGL-Renderer/blob/master/MP-APS/Input.h

class Input
{
    private:
        std::array<bool, GLFW_KEY_LAST> m_pressedKeys{false};
        std::array<bool, GLFW_KEY_LAST> m_prevPressedKeys{false};

        float_t m_xMousePos, m_yMousePos;
        bool m_mouseMoved = false;

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

        [[nodiscard]] bool isKeyPressed(const int32_t key) const noexcept { return m_pressedKeys[key] && !m_prevPressedKeys[key]; }
        [[nodiscard]] bool isKeyHeld(const int32_t key) const noexcept { return m_pressedKeys[key]; }
        
        [[nodiscard]] bool isMouseMoved() const noexcept { return m_mouseMoved; }
        [[nodiscard]] float_t getMousePosX() const noexcept { return m_xMousePos; }
        [[nodiscard]] float_t getMousePosY() const noexcept { return m_yMousePos; }

        std::function<void(int32_t, int32_t, int32_t, int32_t)> keyPressed = [&](int32_t key, int32_t scanCode, int32_t action, int32_t mode)
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

        std::function<void(double_t, double_t)> mouseMoved = [&](double_t xPos, double_t yPos) 
        {
		    this->m_mouseMoved = true;
		    this->m_xMousePos = (float_t)xPos;
		    this->m_yMousePos = (float_t)yPos;
	    };
    
    private:
        Input() {};
	    ~Input() = default;
};

#endif