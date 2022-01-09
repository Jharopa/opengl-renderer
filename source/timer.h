#ifndef TIMER_H
#define TIMER_H

// GLFW library includes
#include <GLFW/glfw3.h>

#include <math.h>

class Timer
{
    private:
        float_t m_start, m_end;

    public:
        Timer() : m_start(0.0f), m_end(0.0f) {}
        ~Timer() {}

        void start() { m_start = (float_t)glfwGetTime(); }
        void stop() { m_end = (float_t)glfwGetTime(); }
        
        float_t getDelta() { return (m_end - m_start); }
        float_t getDeltaMillis() { return getDelta() * 1000.0f; }
};

#endif
