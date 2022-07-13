#pragma once

// Renderer includes
#include "defines.h"
#include "utilities/singleton.h"
#include "input/input.h"
#include "events/event.h"
#include "renderer/renderer.h"
#include "renderer/window.h"
#include "renderer/vertex_array.h"
#include "renderer/shader_program.h"
#include "renderer/texture.h"
#include "renderer/camera.h"
#include "utilities/profiler.h"

class Application : public Singleton<Application>
{
    public:
        void init();
        void run();

    private:
        void onEvent(Event& e);
    
    private:
        std::unique_ptr<Window> m_window;
        std::unique_ptr<Renderer> m_renderer;

        std::optional<Shader::ShaderProgram> m_shaderProgram;

        std::unique_ptr<VertexArray> m_vertexArray;
        std::unique_ptr<Texture> m_texture;

        std::unique_ptr<Camera> m_camera;
};
