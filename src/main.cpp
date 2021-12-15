// Renderer includes
#include "window.h"
#include "shaderprogram.h"

// STD library includes
#include <iostream>

int main()
{
    Window window = Window{ 800, 600, "Window" };

    std::optional<ShaderProgram> test = ShaderProgramBuilder{}.with(ShaderStage::FRAGMENT, "../src/shader.frag")
                                                                .with(ShaderStage::VERETX, "../src/shader.vert")
                                                                .build();

    while(!window.shouldClose())
    {
        window.update();
    }

    return 0;
}
