// GLAD includes
#include <glad/glad.h>

// STD library includes
#include <iostream>

// My includes
#include "window.h"

int main()
{
    Window window = Window(800, 600, "Window");

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cerr << "Failed to start GLAD!";
		std::abort();
	}

    while(!window.shouldClose())
    {
        window.update();
    }

    return 0;
}
