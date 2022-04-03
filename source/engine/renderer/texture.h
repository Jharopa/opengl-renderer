#pragma once

// GLAD includes
#include <glad/glad.h>

// STB_IMAGE includes
#include <stb_image.h>

// STD library includes
#include <string>

// Renderer includes
#include "defines.h"

// Only represents a 2D texture at the moment, could be generalized 
// and will refactor if neccessary later on

class Texture
{
    private:
        u32 m_id;
        i32 m_width, m_height, m_channels;

    public:
        Texture(const std::string& path, const b8 enableMipmaps);
        ~Texture();

        void bind() const;
        void activateTextureUnit(const i32 unit) const;

        [[nodiscard]] i32 getWidth() const noexcept { return m_width; }
        [[nodiscard]] i32 getHeight() const noexcept { return m_height; }
        [[nodiscard]] i32 getChannels() const noexcept { return m_channels; }
};
