#include "context.h"

Context::Context(GLFWwindow* window) 
    : m_window(window) 
{
    glfwMakeContextCurrent(m_window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cerr << "Failed to start GLAD!";
		std::abort();
	}

    std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;
}

Context::~Context() {}

void Context::swapBuffers() const
{
    glfwSwapBuffers(m_window);
}
