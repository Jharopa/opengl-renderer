#include "application.h"

void Application::init()
{
    m_window = std::make_shared<Window>(800, 600, "Window");

    m_renderer = std::make_shared<Renderer>();

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

    m_vertexArray = std::make_shared<VertexArray>();

    m_vertexArray->bind();

    m_vertexArray->attachBuffer(BufferType::VERTEX, sizeof(vertices), DrawMode::STATIC, vertices);

    m_vertexArray->enableAttribute(0, 3, 5 * sizeof(f32), (void*)0);
    m_vertexArray->enableAttribute(1, 2, 5 * sizeof(f32), (void*)(3 * sizeof(f32)));

    m_vertexArray->unbind();

    m_texture = std::make_shared<Texture>("../resources/textures/container.jpg", true);

    m_shaderProgram->bind();

    m_shaderProgram->setUniform("containerTexture", 0);

    m_shaderProgram->unbind();
}

void Application::run()
{
    while (!m_window->shouldClose())
    {
        m_renderer->setClearColor(glm::vec4(0.2f, 0.3f, 0.3f, 1.0f));
        m_renderer->clear();

        m_texture->bind();
        m_texture->activateTextureUnit(GL_TEXTURE0);

        m_shaderProgram->bind();

        m_vertexArray->bind();

        m_renderer->drawArrays(GL_TRIANGLES, 0, 36);

        m_vertexArray->unbind();

        m_shaderProgram->unbind();

        m_window->update();
    }
}

void Application::onEvent(Event& e)
{
    if (e.getEventType() == KeyPressedEvent::getStaticType())
    {
        KeyPressedEvent kpe = static_cast<KeyPressedEvent&>(e);
        
        if(!kpe.isRepeat())
        {
            std::cout << kpe.getKey() << " key pressed" << std::endl;
        }
        else
        {
            std::cout << kpe.getKey() << " key repeated" << std::endl;
        }   
    }
    else if (e.getEventType() == KeyReleasedEvent::getStaticType())
    {
        KeyReleasedEvent kre = static_cast<KeyReleasedEvent&>(e);
        std::cout << kre.getKey() << " key released" << std::endl;
    }
}
