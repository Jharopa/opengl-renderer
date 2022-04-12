#pragma once

// Renderer includes
#include "defines.h"
#include "singleton.h"
#include "input/input.h"
#include "events/event.h"
#include "renderer/renderer.h"
#include "renderer/window.h"
#include "renderer/vertexarray.h"
#include "renderer/shaderprogram.h"
#include "renderer/texture.h"


// GLM includes
#include <glm/glm.hpp>

class Application : public Singleton<Application>
{
    private:
        std::shared_ptr<Window> m_window;
        std::unique_ptr<Renderer> m_renderer;

        std::optional<ShaderProgram> m_shaderProgram;
        std::unique_ptr<VertexArray> m_vertexArray;
        std::unique_ptr<Texture> m_texture;

    public:
        void init();
        void run();

        std::shared_ptr<Window> getWindow() { return m_window; }

    private:
        void onEvent(Event& e);
};
