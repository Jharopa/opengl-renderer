#pragma once

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
        u64 fileSize = (u64) file.tellg();
        content.resize(fileSize);
        file.seekg(0);
        file.read(&content[0], fileSize);
    }

    return content;
}
