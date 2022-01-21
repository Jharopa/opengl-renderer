#ifndef UTILS_H
#define UTILS_H

// STD library includes
#include <string>
#include <fstream>

// Renderer includes
#include "defines.h"

[[nodiscard]] static std::string readFile(const std::string& path)
{
    std::string content;
    std::ifstream file(path, std::ios::ate | std::ios::binary);

    if (file)
	{
        size_t fileSize = (size_t) file.tellg();
        content.resize(fileSize);
        file.seekg(0);
        file.read(&content[0], fileSize);
    }

    return content;
}

#endif