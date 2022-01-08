#ifndef VERTEX_ARRAY_H
#define VERTEX_ARRAY_H

#include <glad/glad.h>

#include <cstdint>

enum BufferType 
{
    VERTEX = GL_ARRAY_BUFFER,
    INDEX = GL_ELEMENT_ARRAY_BUFFER
};

enum DrawMode
{
    STATIC = GL_STATIC_DRAW
};

class VertexArray
{
    private:
        uint32_t m_id;

    public:
        VertexArray();
        ~VertexArray();

        void attachBuffer(const BufferType type, const size_t size, const DrawMode mode, const void* data) noexcept;
        void enableAttribute(const uint32_t index, const int32_t size, const uint32_t offset, const void* data) noexcept;

        void bind() const noexcept;
        void unbind() const noexcept;
};

#endif
