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

    OGLR_INFO("OpenGL version {}", (const char*)(glGetString(GL_VERSION)));
}

Context::~Context() {}

void Context::swapBuffers() const
{
    glfwSwapBuffers(m_window);
}
