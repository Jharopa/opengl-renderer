#ifndef TEXTURE_H
#define TEXTURE_H

// GLAD includes
#include <glad/glad.h>

// STB_IMAGE includes
#include "../external/stb_image/stb_image.h"

// STD library includes
#include <cstdint>
#include <string>
#include <iostream>

// Only represents a 2D texture at the moment, could be generalized 
// and will refactor if neccessary later on

class Texture
{
    private:
        uint32_t m_id;
        int32_t m_width, m_height, m_channels;

    public:
        Texture(const std::string& path, const bool enableMipmaps);
        ~Texture();

        void bind() const;
        void activateTextureUnit(const int32_t unit) const;

        [[nodiscard]] int32_t getWidth() const noexcept { return m_width; }
        [[nodiscard]] int32_t getHeight() const noexcept { return m_height; }
        [[nodiscard]] int32_t getChannels() const noexcept { return m_channels; }
};

#endif