#ifndef WINDOW_H
#define WINDOW_H

// Renderer includes
#include "context.h"

// STD library includes
#include <string>
#include <iostream>
#include <memory>

class Window
{    
    private:
        GLFWwindow* m_window = nullptr;

        uint32_t m_width, m_height;
        std::string m_title;

        bool m_shouldClose = false;

        std::unique_ptr<Context> m_context;

    public:
        Window(const uint32_t& width, const uint32_t& height, const std::string& title);
        ~Window();

        void update();

        [[nodiscard]] GLFWwindow* getWindow() const noexcept { return m_window; }
        [[nodiscard]] uint32_t getWidth() const noexcept { return m_width; }
        [[nodiscard]] uint32_t getHeight() const noexcept { return m_height; }

        [[nodiscard]] bool shouldClose() const noexcept { return m_shouldClose; }

    private:
        void init();
        void shutdown() const;
};

#endif