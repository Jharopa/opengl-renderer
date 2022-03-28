#pragma once

// STD library includes
#include <string>
#include <iostream>
#include <memory>

// Renderer includes
#include "../defines.h"
#include "../context.h"

class Window
{    
    private:
        GLFWwindow* m_window = nullptr;

        u32 m_width, m_height;
        std::string m_title;

        b8 m_shouldClose = false;

        std::unique_ptr<Context> m_context;

    public:
        Window(const u32& width, const u32& height, const std::string& title);
        ~Window();

        void update();

        [[nodiscard]] GLFWwindow* getWindow() const noexcept { return m_window; }
        [[nodiscard]] u32 getWidth() const noexcept { return m_width; }
        [[nodiscard]] u32 getHeight() const noexcept { return m_height; }

        [[nodiscard]] b8 shouldClose() const noexcept { return m_shouldClose; }
};
