#ifndef INPUT_H
#define INPUT_H

#include <array>
#include <functional>

// Reference and adapted from https://github.com/htmlboss/OpenGL-Renderer/blob/master/MP-APS/Input.h

class Input
{
    private:
        std::array<bool, 512> m_pressedKeys;
        std::array<bool, 512> m_heldKeys;

        double_t m_xMousePos, m_yMousePos;
        bool m_mouseMoved = false;

    public:
        static Input& getInstance() 
        {
		    static Input instance;
		    return instance;
	    }

        void update() { m_mouseMoved = false; }

        bool isKeyPressed(const int32_t key) const noexcept { return m_pressedKeys[key]; }
        bool isKeyHeld(const int32_t key) const noexcept { return m_heldKeys[key]; }
        
        bool isMouseMoved() const noexcept { return m_mouseMoved; }
        double_t getMousePosX() const noexcept { return m_xMousePos; }
        double_t getMousePosY() const noexcept { return m_yMousePos; }

        std::function<void(int32_t, int32_t, int32_t, int32_t)> keyPressed = [&](int32_t key, int32_t scanCode, int32_t action, int32_t mode)
        {
            if (key > 0)
            {
                switch (action) 
                {
				    case 0:
				    	this->m_pressedKeys[key] = false;
                        this->m_pressedKeys[key] = false;
				    	break;
				    case 1:
				    	this->m_pressedKeys[key] = true;
                        std::cout << "Key Pressed" << std::endl;
				    	break;
                    case 2:
				    	this->m_heldKeys[key] = true;
                        std::cout << "Key Held" << std::endl;
				    	break;
			    }
            }
        };

        std::function<void(double_t, double_t)> mouseMoved = [&](double_t xPos, double_t yPos) 
        {
		    this->m_mouseMoved = true;
		    this->m_xMousePos = xPos;
		    this->m_yMousePos = yPos;
	    };
    
    private:
        Input() 
        {
            std::fill(m_pressedKeys.begin(), m_pressedKeys.end(), false); 
            std::fill(m_heldKeys.begin(), m_heldKeys.end(), false);
        };

	    ~Input() = default;
};

#endif