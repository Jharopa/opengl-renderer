#include "renderer.h"

void openGLMessageCallback(GLenum source, GLenum type, u32 id, GLenum severity, i32 length, const GLchar* message, const void* userParam)
{
	switch (severity)
	{
		case GL_DEBUG_SEVERITY_HIGH:
            std::cout << "[OPENGL CRITICAL] " << id << " " << message << std::endl; return;
		case GL_DEBUG_SEVERITY_MEDIUM:
            std::cout << "[OPENGL ERROR] " << id << " " << message << std::endl; return;
		case GL_DEBUG_SEVERITY_LOW:
            std::cout << "[OPENGL WARNING] " << id << " " << message << std::endl; return;
		case GL_DEBUG_SEVERITY_NOTIFICATION:
            std::cout << "[OPENGL INFO] " << id << " " << message << std::endl; return;
	}

    std::cout << "[ERROR] Unrecognized OpenGL message severity level!" << std::endl;
}

Renderer::Renderer()
{
    glEnable(GL_DEBUG_OUTPUT);
	glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
	glDebugMessageCallback(openGLMessageCallback, nullptr);
		
	glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DEBUG_SEVERITY_NOTIFICATION, 0, NULL, GL_FALSE);

    glEnable(GL_DEPTH_TEST);
}

Renderer::~Renderer(){}

void Renderer::setClearColor(const glm::vec4& color)
{
    glClearColor(color.r, color.g, color.b, color.a);
}

void Renderer::clear()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::drawArrays(GLenum mode, i32 first, i32 count)
{
    glDrawArrays(mode, first, count);
}
