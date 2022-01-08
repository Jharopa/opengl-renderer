#ifndef TEXTURE_H
#define TEXTURE_H

#include <glad/glad.h>

#include "../external/stb_image/stb_image.h"

#include <cstdint>
#include <string>
#include <iostream>

class Texture
{
    private:
        uint32_t m_id;
        int32_t m_width, m_height, m_channels;

    public:
        Texture(const std::string& path, const bool enableMipmaps);
        ~Texture();

        void bind() const;
};

#endif