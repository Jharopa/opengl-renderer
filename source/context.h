#ifndef CONTEXT_H
#define CONTEXT_H

// GLAD includes
#include <glad/glad.h>

// GLFW includes
#include <glfw/glfw3.h>

// STD library includes
#include <iostream>

class Context
{
    private:
        GLFWwindow* m_window;

    public:
        Context(GLFWwindow* m_window);
        ~Context();
        
        void swapBuffers() const;
};

#endif