#include "window.h"

Window::Window(const uint32_t& width, const uint32_t& height, const std::string& title)
    : m_width(width), m_height(height), m_title(title)
{
    if(!glfwInit())
    {
        std::cerr << "Failed to initialize GLFW!";
        std::abort();
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    m_window = glfwCreateWindow(m_width, m_height, m_title.c_str(), nullptr, nullptr);

    if(!m_window)
    {
        std::cerr << "Failed to create GLFW window!";
        std::abort();
    }

    m_context = std::make_unique<Context>(m_window);
}

Window::~Window()
{
    glfwDestroyWindow(m_window);
    glfwTerminate();
}

void Window::update()
{
    glfwPollEvents();

    if (glfwGetKey(m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS || glfwWindowShouldClose(m_window))
    {
        m_shouldClose = true;
        glfwSetWindowShouldClose(m_window, true);
    }

    m_context->swapBuffers();
}
