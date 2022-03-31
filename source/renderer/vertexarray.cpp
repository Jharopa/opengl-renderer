#include "vertexarray.h"

#include "pch.h"

VertexArray::VertexArray()
{
    glGenVertexArrays(1, &m_id);
}

VertexArray::~VertexArray()
{
    glDeleteVertexArrays(1, &m_id);
}

void VertexArray::attachBuffer(const BufferType type, const u64 size, const DrawMode mode, const void* data) noexcept
{
    u32 buffer;
    glGenBuffers(1, &buffer);

    glBindBuffer(type, buffer);
    glBufferData(type, size, data, mode);
}

void VertexArray::enableAttribute(const u32 index, const u64 size, const u32 offset, const void* data) noexcept
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
