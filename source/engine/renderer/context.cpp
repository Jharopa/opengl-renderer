#include "context.h"

#include "log.h"

Context::Context(GLFWwindow* window) 
    : m_window(window) 
{
    glfwMakeContextCurrent(m_window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) 
    {
		OGLR_FATAL("Failed to load GLAD!");
		std::terminate();
	}

    OGLR_INFO("OpenGL version/driver {}", (const char*)(glGetString(GL_VERSION)));
    OGLR_INFO("OpenGL vendor {}", (const char*)(glGetString(GL_VENDOR)));
    OGLR_INFO("OpenGL device {}", (const char*)(glGetString(GL_RENDERER)));
}

Context::~Context() {}

void Context::swapBuffers() const
{
    glfwSwapBuffers(m_window);
}
