#pragma once

// STD library includes
#include <string>

// Renderer includes
#include "defines.h"
#include "events/event.h"

class Window
{       
    protected:
        u32 m_width, m_height;
        std::string m_title;

        b8 m_shouldClose = false;

        std::function<void(Event&)> fn_eventCallback;

    public:
        Window(const u32& width, const u32& height, const std::string& title) : m_width(width), m_height(height), m_title(title) {}
        virtual ~Window() = default;

        static std::shared_ptr<Window> init(const u32& width, const u32& height, const std::string& title);

        virtual void update() = 0;
        
        [[nodiscard]] virtual void* getWindow() const noexcept = 0;

        [[nodiscard]] u32 getWidth() const noexcept { return m_width; }
        [[nodiscard]] u32 getHeight() const noexcept { return m_height; };
        
        [[nodiscard]] b8 shouldClose() const noexcept { return m_shouldClose; };

        void setEventCallback(const std::function<void(Event&)>& callback) { fn_eventCallback = callback; }
        std::function<void(Event&)>& getEventCallback() { return fn_eventCallback; }

    private:
        virtual void processInput() = 0;
};
