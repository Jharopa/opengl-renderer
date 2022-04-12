#include "renderer.h"

#include "log.h"

void openGLMessageCallback(GLenum source, GLenum type, u32 id, GLenum severity, i32 length, const GLchar* message, const void* userParam)
{
	switch (severity)
	{
		case GL_DEBUG_SEVERITY_HIGH:
            OGLR_FATAL("{} {} - {}","[OPENGL FATAL]", id, message);
            return;
		case GL_DEBUG_SEVERITY_MEDIUM:
            OGLR_ERROR("{} {} - {}","[OPENGL ERROR]", id, message);
            return;
		case GL_DEBUG_SEVERITY_LOW:
            OGLR_WARN("{} {} - {}","[OPENGL WARNING]", id, message);
            return;
		case GL_DEBUG_SEVERITY_NOTIFICATION:
            OGLR_INFO("{} {} - {}","[OPENGL INFO]", id, message);
            return;
	}

    OGLR_ERROR("Unrecognized OpenGL message severity level!");
}

Renderer::Renderer()
{
    glEnable(GL_DEBUG_OUTPUT);
	glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
	glDebugMessageCallback(openGLMessageCallback, nullptr);
		
	glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DEBUG_SEVERITY_NOTIFICATION, 0, NULL, GL_FALSE);
}

Renderer::~Renderer(){}

void Renderer::setClearColor(const glm::vec4& color)
{
    glClearColor(color.r, color.g, color.b, color.a);
}

void Renderer::clear()
{
    glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::drawArrays(GLenum mode, i32 first, i32 count)
{
    glDrawArrays(mode, first, count);
}

void Renderer::drawIndices(GLenum mode, i32 count)
{
    glDrawElements(mode, count, GL_UNSIGNED_INT, 0);
}
