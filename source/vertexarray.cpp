#include "vertexarray.h"

VertexArray::VertexArray()
{
    glGenVertexArrays(1, &m_id);
}

VertexArray::~VertexArray()
{
    glDeleteVertexArrays(1, &m_id);
}

void VertexArray::attachBuffer(const BufferType type, const size_t size, const DrawMode mode, const void* data) noexcept
{
    uint32_t buffer;
    glGenBuffers(1, &buffer);

    glBindBuffer(type, buffer);
    glBufferData(type, size, data, mode);
}

void VertexArray::enableAttribute(const uint32_t index, const int32_t size, const uint32_t offset, const void* data) noexcept
{
    glEnableVertexAttribArray(index);
    glVertexAttribPointer(index, size, GL_FLOAT, GL_FALSE, offset, data);
}

void VertexArray::bind() const noexcept
{
    glBindVertexArray(m_id);
}

void VertexArray::unbind() const noexcept
{
    glBindVertexArray(0);
}
