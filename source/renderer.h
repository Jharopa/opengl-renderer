#ifndef RENDERER_H
#define RENDERER_H

// GLAD includes
#include <glad/glad.h>

// GLM includes
#include <glm/glm.hpp>

// STD library includes
#include <iostream>

// Renderer includes
#include "defines.h"

class Renderer
{
    public:
        Renderer();
        ~Renderer();

        void setClearColor(const glm::vec4& color);
        void clear();

        void drawArrays(GLenum mode, i32 first, i32 count);
};

#endif
