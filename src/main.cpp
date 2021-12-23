// Renderer includes
#include "window.h"
#include "shaderprogram.h"
#include "vertexarray.h"

// STD library includes
#include <iostream>

int main()
{
    Window window = Window{ 800, 600, "Window" };

    auto shaderProgram = ShaderProgramBuilder{}.with(ShaderStage::FRAGMENT, "../src/shader.frag")
                                                .with(ShaderStage::VERETX, "../src/shader.vert")
                                                .build();

    // ----------------------------- //
    // Sets up vertex and index data //
    // ----------------------------- //
    float vertices[] = 
    {
         0.5f,  0.5f, 0.0f,  // top right
         0.5f, -0.5f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f,  // bottom left
        -0.5f,  0.5f, 0.0f   // top left 
    };
    
    unsigned int indices[] = 
    {  // note that we start from 0!
        0, 1, 2,   // first triangle
        0, 3, 2    // second triangle
    }; 

    // --------------------------------------------------- //
    // Sets up and binds vertex and indices buffer objects //
    // --------------------------------------------------- //
    VertexArray vertexArray;

    vertexArray.bind();

    vertexArray.attachBuffer(BufferType::VERTEX, sizeof(vertices), DrawMode::STATIC, vertices);
    vertexArray.attachBuffer(BufferType::INDEX, sizeof(indices), DrawMode::STATIC, indices);

    vertexArray.enableAttribute(0, 3, 3 * sizeof(float), (void*)0);

    vertexArray.unbind();
    
    // ---------------------------------------- //
    // Optional: Sets OpenGL to draw wireframes //
    // ---------------------------------------- //
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    // ----------- //
    // Render loop //
    // ----------- //

    while(!window.shouldClose())
    {
        // ------ //
        // Render //
        // ------ //
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        float change = ((float)sin(glfwGetTime() * 0.5f) + 1.5f);

        shaderProgram->bind();
        shaderProgram->setUniform("w", change);

        vertexArray.bind();

        //glDrawArrays(GL_TRIANGLES, 0, 3);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        vertexArray.unbind();

        shaderProgram->unbind();

        window.update();
    }

    return 0;
}
