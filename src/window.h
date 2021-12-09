#ifndef WINDOW_H
#define WINDOW_H

// GLFW includes
#include <glfw/glfw3.h>

// STD library includes
#include <string>
#include <iostream>

class Window
{
    public:
        Window(const uint32_t& width, const uint32_t& height, const std::string& title);
        ~Window();

        void update();

        uint32_t getWidth() const noexcept { return m_width; }
        uint32_t getHeight() const noexcept { return m_height; }

        bool shouldClose() const noexcept { return m_shouldClose; }

    private:
        void init();
        void shutdown();

    private:
        GLFWwindow* m_window{ nullptr };

        uint32_t m_width, m_height;
        std::string m_title;

        bool m_shouldClose{ false };
};

#endif