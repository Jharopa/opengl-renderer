#ifndef CONTEXT_H
#define CONTEXT_H

// GLAD + GLFW includes
#include <glad/glad.h>
#include <glfw/glfw3.h>

// STD library includes
#include <iostream>

class Context
{
    private:
        GLFWwindow* m_window;

    public:
        Context(GLFWwindow* m_window);

        void init();
        void swapBuffers() const;
};

#endif