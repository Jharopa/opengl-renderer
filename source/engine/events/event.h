#pragma once

#include "defines.h"
#include "input/keys.h"
#include "input/mousebuttons.h"

enum class EventType
{
    WindowClosed, WindowResized,
    KeyPressed, KeyReleased,
    MousePressed, MouseReleased, MouseMoved
};

#define BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { \
    return this->fn(std::forward<decltype(args)>(args)...);          \
}

class Event
{
    public:
        virtual ~Event() = default;
        
        virtual EventType getEventType() = 0;
};

class WindowClosedEvent : public Event
{
    public:
        WindowClosedEvent() = default;

        static EventType getStaticType() { return EventType::WindowClosed; }
        virtual EventType getEventType() override { return getStaticType(); }
};

class WindowResizedEvent : public Event
{
    public:
        WindowResizedEvent(u32 width, u32 height) : m_width(width), m_height(height) {}

        [[nodiscard]] u32 getWidth() const noexcept { return m_width; }
        [[nodiscard]] u32 getHeight() const noexcept { return m_height; }

        static EventType getStaticType() { return EventType::WindowResized; }
        virtual EventType getEventType() override { return getStaticType(); }
    
    private:
        u32 m_width, m_height;
};

class KeyPressedEvent : public Event
{
    public:
        KeyPressedEvent(Key key, b8 repeat) : m_key(key), m_repeat(repeat) {}

        [[nodiscard]] Key getKey() const noexcept { return m_key; }
        [[nodiscard]] b8 isRepeat() const noexcept { return m_repeat; }

        static EventType getStaticType() { return EventType::KeyPressed; }
        virtual EventType getEventType() override { return getStaticType(); }
    
    private:
        Key m_key;
        b8 m_repeat;
};

class KeyReleasedEvent : public Event
{
    public:
        KeyReleasedEvent(Key key) : m_key(key) {}

        [[nodiscard]] Key getKey() const noexcept { return m_key; }
        
        static EventType getStaticType() { return EventType::KeyReleased; }
        virtual EventType getEventType() override { return getStaticType(); }
    
    private:
        Key m_key;
};

class MousePressedEvent : public Event
{
    public:
        MousePressedEvent(MouseButton button, b8 repeat) : m_button(button), m_repeat(repeat) {}

        [[nodiscard]] MouseButton getKey() const noexcept { return m_button; }
        [[nodiscard]] b8 isRepeat() const noexcept { return m_repeat; }
        
        static EventType getStaticType() { return EventType::MousePressed; }
        virtual EventType getEventType() override { return getStaticType(); }

    private:
        MouseButton m_button;
        b8 m_repeat;
};

class MouseReleasedEvent : public Event
{
    public:
        MouseReleasedEvent(MouseButton button) : m_button(button) {}

        [[nodiscard]] MouseButton getKey() const noexcept { return m_button; }

        static EventType getStaticType() { return EventType::MouseReleased; }
        virtual EventType getEventType() override { return getStaticType(); }
    
    private:
        MouseButton m_button;
};

class MouseMovedEvent : public Event
{
    public:
        MouseMovedEvent(f32 x, f32 y) : m_x(x), m_y(y) {}

        [[nodiscard]] f32 getX() const noexcept { return m_x; }
        [[nodiscard]] f32 getY() const noexcept { return m_y; }

        static EventType getStaticType() { return EventType::MouseMoved; }
        virtual EventType getEventType() override { return getStaticType(); }

    private:
        f32 m_x, m_y;
};
