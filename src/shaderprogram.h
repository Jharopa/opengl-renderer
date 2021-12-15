#ifndef SHADER_PROGRAM_H
#define SHADER_PROGRAM_H

#include <glad/glad.h>

#include <iostream>
#include <string>
#include <optional>
#include <unordered_map>

#include "utils.h"

enum ShaderStage
{
    VERETX = GL_VERTEX_SHADER,
    FRAGMENT = GL_FRAGMENT_SHADER,
    GEOMETRY = GL_GEOMETRY_SHADER,
    COMPUTE = GL_COMPUTE_SHADER,
};

class ShaderProgram
{
    private:
        int m_id;
        std::unordered_map<std::string, int> m_uniformsCache;

    public:
        ShaderProgram(const int id);
        ~ShaderProgram();

        void bind() const;
        void unbind() const;
};

class ShaderProgramBuilder
{
    private:
        std::unordered_map<ShaderStage, std::string> m_shaderStages;

    public:
        ShaderProgramBuilder& with(ShaderStage stage, std::string shaderCode);
        std::optional<ShaderProgram> build();

    private:
        bool compileStage(const int id, const std::string& shaderCode);
        void compile(const int id, const char* shaderCode);

        bool link(const int id);
};

#endif