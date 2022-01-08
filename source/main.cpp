
// STD library includes
#include <iostream>

// Renderer includes
#include "window.h"
#include "shaderprogram.h"
#include "vertexarray.h"
#include "texture.h"
#include "camera.h"
#include "input.h"

int main()
{
    Window window = Window{ 800, 600, "Window" };

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

    auto shaderProgram = ShaderProgramBuilder{}.with(ShaderStage::FRAGMENT, "../resources/shaders/shader.frag")
                                                .with(ShaderStage::VERETX, "../resources/shaders/shader.vert")
                                                .build()
                                                .value();

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

    VertexArray vertexArray;

    vertexArray.bind();

    vertexArray.attachBuffer(BufferType::VERTEX, sizeof(vertices), DrawMode::STATIC, vertices);
    vertexArray.attachBuffer(BufferType::INDEX, sizeof(indices), DrawMode::STATIC, indices);

    vertexArray.enableAttribute(0, 3, 8 * sizeof(float), (void*)0);
    vertexArray.enableAttribute(1, 3, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    vertexArray.enableAttribute(2, 2, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    
    Texture texture{"../resources/textures/container.jpg", true};

    shaderProgram.bind();
    shaderProgram.setUniform("texture1", 0);
    shaderProgram.unbind();

    while(!window.shouldClose())
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glActiveTexture(GL_TEXTURE0);
        texture.bind();

        shaderProgram.bind();
        
        vertexArray.bind();

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        vertexArray.unbind();

        shaderProgram.unbind();

        Input::getInstance().update();
        window.update();
    }

    return 0;
}
