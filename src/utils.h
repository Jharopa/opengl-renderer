#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <fstream>

[[nodiscard]] static std::string readFile(const std::string& filepath)
{
    std::string content;
    std::ifstream file(filepath, std::ios::ate | std::ios::binary);

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