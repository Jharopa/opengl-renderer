#pragma once

// Renderer includes
#include "defines.h"
#include "singleton.h"
#include "window.h"
#include "input/input.h"
#include "events/event.h"
#include "renderer/renderer.h"

class Application : public Singleton<Application>
{
    private:
        std::shared_ptr<Window> m_window;

    public:
        void init();
        void run();

        std::shared_ptr<Window> getWindow() { return m_window; }

    private:
        void onEvent(Event& e);
};
