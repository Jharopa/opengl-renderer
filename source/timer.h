#ifndef TIMER_H
#define TIMER_H

// GLFW library includes
#include <GLFW/glfw3.h>

// STD library includes
#include <math.h>

// Renderer includes
#include "defines.h"

class Timer
{
    private:
        f32 m_start, m_end;

    public:
        Timer() : m_start(0.0f), m_end(0.0f) {}
        ~Timer() {}

        void start() { m_start = (f32)glfwGetTime(); }
        void stop() { m_end = (f32)glfwGetTime(); }
        
        f32 getDelta() { return (m_end - m_start); }
        f32 getDeltaMillis() { return getDelta() * 1000.0f; }
};

#endif
