#include "application.h"

void Application::init()
{
    PROFILE_FUNCTION();

    m_window = std::make_unique<Window>(800, 600, "Window");

    m_renderer = std::make_unique<Renderer>();

    m_shaderProgram = Shader::ShaderProgramBuilder{}.with(Shader::ShaderStage::Fragment, "../resources/shaders/shader.frag")
                                                .with(Shader::ShaderStage::Vertex, "../resources/shaders/shader.vert")
                                                .build();

    float vertices[] = 
    {   // Position           // Texture Coordiantes
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
         0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
    };

    m_vertexArray = std::make_unique<VertexArray>();

    m_vertexArray->bind();

    m_vertexArray->attachBuffer(BufferType::VERTEX, sizeof(vertices), DrawMode::STATIC, vertices);

    m_vertexArray->enableAttribute(0, 3, 5 * sizeof(f32), (void*)0);
    m_vertexArray->enableAttribute(1, 2, 5 * sizeof(f32), (void*)(3 * sizeof(f32)));

    m_vertexArray->unbind();

    m_texture = std::make_unique<Texture>("../resources/textures/container.jpg", true);

    m_shaderProgram->bind();

    m_shaderProgram->setUniform("containerTexture", 0);

    m_shaderProgram->unbind();

    m_camera = std::make_unique<Camera>();

    m_timer = std::make_unique<Timer>();
}

void Application::run()
{
    while (!m_window->shouldWindowClose())
    {
        f32 deltaTime = m_timer->getDelta();

        m_timer->start();

        m_renderer->setClearColor(math::vec4(0.2f, 0.3f, 0.3f, 1.0f));
        m_renderer->clear();

        m_texture->bind();
        m_texture->activateTextureUnit(GL_TEXTURE0);

        m_shaderProgram->bind();

        math::mat4 model = math::translate(math::vec3(0.0f, -1.0f, -3.5f));

        m_shaderProgram->setUniform("model", model);

        m_shaderProgram->setUniform("view", m_camera->getVeiwMatrix());

        m_shaderProgram->setUniform("projection", m_camera->getProjMatrix(800.0f, 600.0f));

        m_vertexArray->bind();

        m_renderer->drawArrays(GL_TRIANGLES, 0, 36);

        m_vertexArray->unbind();

        m_shaderProgram->unbind();

        Input::getInstance().update();
        m_window->update();
        m_camera->update(deltaTime);

        m_timer->stop();
    }
}
