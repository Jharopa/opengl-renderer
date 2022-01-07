#ifndef TEXTURE_H
#define TEXTURE_H

#include <glad/glad.h>


#define STB_IMAGE_IMPLEMENTATION
#include "../external/stb_image/stb_image.h"

#include <cstdint>
#include <string>

class Texture
{
    private:
        uint32_t m_id;
        uint32_t m_width, m_height;

    public:
        Texture(const std::string& path);
        ~Texture();

        void bind() const;
        void unbind() const;
};

#endif