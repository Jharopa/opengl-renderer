
// STD library includes
#include <iostream>

// Renderer includes
#include "window.h"
#include "renderer.h"
#include "shaderprogram.h"
#include "vertexarray.h"
#include "texture.h"
#include "input.h"
#include "camera.h"

float_t deltaTime = 0.0f;
float_t lastFrame = 0.0f;

int main()
{
    Window window = Window{ 800, 600, "Window" };
    Renderer renderer;
    Camera camera;

    const auto keyCallback = [](GLFWwindow* window, auto key, auto scancode, auto action, auto mode) 
    {
		Input::getInstance().keyPressed(key, scancode, action, mode);
	};

    glfwSetKeyCallback(window.getWindow(), keyCallback);

    const auto cursorPosCallback = [](GLFWwindow* window, auto xPos, auto yPos) 
    {
		Input::getInstance().mouseMoved(xPos, yPos);
	};

	glfwSetCursorPosCallback(window.getWindow(), cursorPosCallback); 

    glfwSetInputMode(window.getWindow(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    renderer.setClearColor(glm::vec4(0.2f, 0.3f, 0.3f, 1.0f));

    auto shaderProgram = ShaderProgramBuilder{}.with(ShaderStage::FRAGMENT, "../resources/shaders/shader.frag")
                                                .with(ShaderStage::VERETX, "../resources/shaders/shader.vert")
                                                .build()
                                                .value();
    
    std::cout << typeid(GL_TEXTURE0).name() << std::endl;

    float vertices[] = 
    {           
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

    VertexArray vertexArray;

    vertexArray.bind();

    vertexArray.attachBuffer(BufferType::VERTEX, sizeof(vertices), DrawMode::STATIC, vertices);

    vertexArray.enableAttribute(0, 3, 5 * sizeof(float), (void*)0);
    vertexArray.enableAttribute(1, 2, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    
    Texture texture{"../resources/textures/container.jpg", true};

    shaderProgram.bind();
    shaderProgram.setUniform("texture1", 0);
    shaderProgram.unbind();

    while(!window.shouldClose())
    {
        float_t currentFrame = (float_t)glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        renderer.clear();

        texture.activateTextureUnit(GL_TEXTURE0);
        texture.bind();

        shaderProgram.bind();

        shaderProgram.setUniform("projection", camera.getProjMatrix((float_t)window.getWidth(), (float_t)window.getHeight()));
        shaderProgram.setUniform("view", camera.getVeiwMatrix());

        vertexArray.bind();

        renderer.drawArrays(GL_TRIANGLES, 0, 36);

        vertexArray.unbind();

        shaderProgram.unbind();

        camera.update(deltaTime);
        Input::getInstance().update();
        window.update();
    }

    return 0;
}
