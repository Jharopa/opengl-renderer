// Renderer includes
#include "window.h"
#include "shaderprogram.h"

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
    uint32_t VAO, VBO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0); 
    glBindVertexArray(0);
    
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

        glBindVertexArray(VAO);
        //glDrawArrays(GL_TRIANGLES, 0, 3);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        shaderProgram->unbind();

        window.update();
    }

    return 0;
}
