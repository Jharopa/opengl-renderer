#pragma once

// STD library includes
#include <string>
#include <fstream>
#include <type_traits>

// Renderer includes
#include "defines.h"

// Returns value of enums underlying type
// https://stackoverflow.com/questions/11421432/how-can-i-output-the-value-of-an-enum-class-in-c11
template <typename E>
constexpr typename std::underlying_type<E>::type enumCast(E const value)
{
    return static_cast<typename std::underlying_type<E>::type>(value);
}

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
