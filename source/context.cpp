#include "context.h"

Context::Context(GLFWwindow* window) : m_window(window) {}

void Context::init()
{
    glfwMakeContextCurrent(m_window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cerr << "Failed to start GLAD!";
		std::abort();
	}

    std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;
}

void Context::swapBuffers() const
{
    glfwSwapBuffers(m_window);
}
