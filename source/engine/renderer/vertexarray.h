#pragma once

// GLAD includes
#include <glad/glad.h>

// Renderer includes
#include "defines.h"

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
        u32 m_id;

    public:
        VertexArray();
        ~VertexArray();

        void attachBuffer(const BufferType type, const u64 size, const DrawMode mode, const void* data) noexcept;
        void enableAttribute(const u32 index, const u64 size, const u32 offset, const void* data) noexcept;

        void bind() const noexcept;
        void unbind() const noexcept;
};
