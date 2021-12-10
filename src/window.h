#ifndef WINDOW_H
#define WINDOW_H

// STD library includes
#include <string>
#include <iostream>

// Renderer includes
#include "context.h"

class Window
{    
    private:
        GLFWwindow* m_window = nullptr;

        uint32_t m_width, m_height;
        std::string m_title;

        bool m_shouldClose = false;

        Context m_context = NULL;

    public:
        Window(const uint32_t& width, const uint32_t& height, const std::string& title);
        ~Window();

        void update();

        [[nodiscard]] uint32_t getWidth() const noexcept { return m_width; }
        [[nodiscard]] uint32_t getHeight() const noexcept { return m_height; }

        bool shouldClose() const noexcept { return m_shouldClose; }

    private:
        void init();
        void shutdown();
};

#endif