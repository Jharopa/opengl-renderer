#include "application.h"

void Application::init()
{
    m_window = std::make_shared<Window>(800, 600, "Window");

    m_renderer = std::make_unique<Renderer>();

    m_shaderProgram = ShaderProgramBuilder{}.with(ShaderStage::Fragment, "../resources/shaders/shader.frag")
                                                .with(ShaderStage::Vertex, "../resources/shaders/shader.vert")
                                                .build();

    float vertices[] = 
    {   // Positions           // Colors            // Texture coords
         0.5f,  0.5f, 0.0f,    1.0f, 0.0f, 0.0f,    1.0f, 1.0f, // top right
         0.5f, -0.5f, 0.0f,    0.0f, 1.0f, 0.0f,    1.0f, 0.0f, // bottom right
        -0.5f, -0.5f, 0.0f,    0.0f, 0.0f, 1.0f,    0.0f, 0.0f, // bottom left
        -0.5f,  0.5f, 0.0f,    1.0f, 1.0f, 0.0f,    0.0f, 1.0f  // top left
    };
    
    uint32_t indices[] = 
    {
        0, 1, 2,   // first triangle
        0, 3, 2    // second triangle
    }; 

    m_vertexArray = std::make_unique<VertexArray>();

    m_vertexArray->bind();

    m_vertexArray->attachBuffer(BufferType::VERTEX, sizeof(vertices), DrawMode::STATIC, vertices);
    m_vertexArray->attachBuffer(BufferType::INDEX, sizeof(indices), DrawMode::STATIC, indices);

    m_vertexArray->enableAttribute(0, 3, 8 * sizeof(float), (void*)0);
    m_vertexArray->enableAttribute(1, 3, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    m_vertexArray->enableAttribute(2, 2, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    
    m_texture = std::make_unique<Texture>("../resources/textures/container.jpg", true);

    m_shaderProgram->bind();
    m_shaderProgram->setUniform("texture1", 0);
    m_shaderProgram->unbind();
}

void Application::run()
{
    while (!m_window->shouldClose())
    {
        m_renderer->setClearColor(glm::vec4(0.2f, 0.3f, 0.3f, 1.0f));
        m_renderer->clear();

        glActiveTexture(GL_TEXTURE0);
        m_texture->bind();

        m_shaderProgram->bind();
        
        m_vertexArray->bind();

        m_renderer->drawIndices(GL_TRIANGLES, 6);

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
