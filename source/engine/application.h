#pragma once

// Renderer includes
#include "defines.h"
#include "singleton.h"
#include "input/input.h"
#include "events/event.h"
#include "renderer/renderer.h"
#include "renderer/window.h"

// GLM includes
#include <glm/glm.hpp>

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
