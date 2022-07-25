#pragma once

// STD library includes
#include <string>
#include <functional>

// Renderer includes
#include "defines.h"
#include "renderer/context.h"

// GLFW includes
#include <glfw/glfw3.h>

class Window
{
    public:
        Window(u32 width, u32 height, const std::string title);
        ~Window();
        
        void update();

        [[nodiscard]] u32 getWidth() const noexcept { return m_width; }
        [[nodiscard]] u32 getHeight() const noexcept { return m_height; };

        [[nodiscard]] b8 shouldWindowClose() const noexcept { return m_close; };

        [[nodiscard]] GLFWwindow* getWindow() const noexcept { return m_window; }

        void setWidth(u32 width) { m_width = width; }
        void setHeight(u32 height) { m_height = height; }

        void closeWindow() { m_close = true; }
    
    private:
        std::string m_title;
        u32 m_width, m_height;

        b8 m_close = false;

        GLFWwindow* m_window;

        std::shared_ptr<Context> m_context;
};
