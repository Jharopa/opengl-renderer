#include "window.h"

#include <iostream>

Window::Window(u32 width, u32 height, const std::string title) 
    : m_width(width), m_height(height), m_title(title)
{
    if(!glfwInit())
    {
        std::cout << "Failed to initialize GLFW!" << std::endl;
        std::abort();
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    m_window = glfwCreateWindow(m_width, m_height, m_title.c_str(), NULL, NULL);

    if (m_window == NULL)
    {
        std::cout << "Failed to create GLFW window!" << std::endl;
        glfwTerminate();
        std::abort();
    }

    m_context = std::make_shared<Context>(m_window);
}

Window::~Window()
{
    glfwDestroyWindow(m_window);
    glfwTerminate();
}

void Window::update()
{
    m_context->swapBuffers();
    glfwPollEvents();
}
