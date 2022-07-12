#pragma once

// GLAD includes
#include <glad/glad.h>

// STD library includes
#include <iostream>

// Renderer includes
#include "defines.h"
#include "math/oglr_math.h"

class Renderer
{
    public:
        Renderer();
        ~Renderer();

        void setClearColor(const math::vec4& color);
        void clear();

        void drawArrays(GLenum mode, i32 first, i32 count);
        void drawIndices(GLenum mode, i32 count);
};
