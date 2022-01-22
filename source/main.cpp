// STD library includes
#include <iostream>

// Renderer includes
#include "defines.h"
#include "window.h"
#include "renderer.h"
#include "shaderprogram.h"
#include "vertexarray.h"
#include "texture.h"
#include "input/input.h"
#include "input/keys.h"
#include "camera.h"
#include "timer.h"

int main()
{
    std::cout << sizeof(u8) << std::endl;
    std::cout << sizeof(u16) << std::endl;
    std::cout << sizeof(u32) << std::endl;
    std::cout << sizeof(u64) << std::endl;

    std::cout << sizeof(i8) << std::endl;
    std::cout << sizeof(i16) << std::endl;
    std::cout << sizeof(i32) << std::endl;
    std::cout << sizeof(i64) << std::endl;

    std::cout << sizeof(f32) << std::endl;
    std::cout << sizeof(f64) << std::endl;

    std::cout << sizeof(b8) << std::endl;
    std::cout << sizeof(b32) << std::endl;
    
    std::cout << sizeof(size_t) << std::endl;
    std::cout << std::is_signed<size_t>::value << std::endl;

    Window window = Window{ 800, 600, "Window" };
    Renderer renderer;
    Camera camera;
    Timer timer;

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

    auto shaderProgram = ShaderProgramBuilder{}.with(ShaderStage::Vertex, "../resources/shaders/shader.vert")
                                                .with(ShaderStage::Fragment, "../resources/shaders/shader.frag")
                                                .build()
                                                .value();

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
        float_t deltaTime = timer.getDelta();

        timer.start();

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
    	
        Input::getInstance().update();
        window.update();
        camera.update(deltaTime);

        timer.stop();
    }

    return 0;
}
