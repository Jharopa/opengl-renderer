#pragma once

// GLAD includes
#include <glad/glad.h>

// GLFW includes
#include <glfw/glfw3.h>

// STD library includes
#include <iostream>

class Context
{
    public:
        Context(GLFWwindow* m_window);
        ~Context();
        
        void swapBuffers() const;

    private:
        GLFWwindow* m_window;
};
