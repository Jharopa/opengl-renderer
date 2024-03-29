#include "window.h"

#include "log.h"
#include "input/input.h"

Window::Window(u32 width, u32 height, const std::string title) 
    : m_width(width), m_height(height), m_title(title)
{
    if(!glfwInit())
    {
        OGLR_FATAL("Failed to initialize GLFW window!");
        std::terminate();
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    m_window = glfwCreateWindow(m_width, m_height, m_title.c_str(), NULL, NULL);

    if (m_window == NULL)
    {
        OGLR_FATAL("Failed to create GLFW window!");
        glfwTerminate();
        std::terminate();
    }

    m_context = std::make_shared<Context>(m_window);

    glfwSetWindowUserPointer(m_window, this);

    glfwSetWindowCloseCallback(m_window, [](GLFWwindow* window)
    {
        Window& handle = *static_cast<Window*>((glfwGetWindowUserPointer(window)));
        handle.closeWindow();
    });

    glfwSetWindowSizeCallback(m_window, [](GLFWwindow* window, i32 width, i32 height)
    {
        Window& handle = *static_cast<Window*>((glfwGetWindowUserPointer(window)));

        i32 w, h;
        glfwGetFramebufferSize(window, &w, &h);

        handle.setWidth((u32)w);
        handle.setHeight((u32)h);

        OGLR_DEBUG("Window resize: ({}, {})", w, h);
    });

    glfwSetFramebufferSizeCallback(m_window, [](GLFWwindow* window, i32 width, i32 height)
    {
        glViewport(0, 0, width, height);
    });

    glfwSetKeyCallback(m_window, [](GLFWwindow* window, auto key, auto scancode, auto action, auto mode)
    {
        Input::getInstance().keyPressed(key, scancode, action, mode);
    });

    glfwSetCursorPosCallback(m_window, [](GLFWwindow* window, auto xPos, auto yPos)
    {
        Input::getInstance().mouseMoved(xPos, yPos);
    });

    glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
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
