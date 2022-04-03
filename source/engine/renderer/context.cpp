#include "context.h"

#include "log.h"

Context::Context(GLFWwindow* window) 
    : m_window(window) 
{
    glfwMakeContextCurrent(m_window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) 
    {
		OGLR_FATAL("Failed to load GLAD!");
		std::abort();
	}

    std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;
}

Context::~Context() {}

void Context::swapBuffers() const
{
    glfwSwapBuffers(m_window);
}
