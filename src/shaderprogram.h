#ifndef SHADER_PROGRAM_H
#define SHADER_PROGRAM_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>
#include <string>
#include <optional>
#include <unordered_map>

#include "utils.h"

// Referenced and Adapted from:
// https://github.com/htmlboss/OpenGL-Renderer/tree/master/MP-APS/Graphics
// https://github.com/TheCherno/Hazel/tree/master/Hazel/src/Platform/OpenGL

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
        uint32_t m_id;
        std::unordered_map<std::string, uint32_t> m_uniformCache;

    public:
        ShaderProgram(const uint32_t id);
        ~ShaderProgram();

        void bind() const;
        void unbind() const;

        void setUniform(const std::string& name, const int32_t value);
        void setUniform(const std::string& name, const float value);
        void setUniform(const std::string& name, const glm::vec2& vector);
        void setUniform(const std::string& name, const glm::vec3& vector);
        void setUniform(const std::string& name, const glm::vec4& vector);
        void setUniform(const std::string& name, const glm::mat4x4& matrix);

    private:
        void cacheUniforms();
        int32_t getUniformLocation(const std::string& name);
};

// TODO: Is a builder going to be appropriate down the line when loading from config files?

class ShaderProgramBuilder
{
    private:
        std::unordered_map<ShaderStage, std::string> m_shaderStages;

    public:
        ShaderProgramBuilder& with(ShaderStage stage, std::string shaderCode);
        std::optional<ShaderProgram> build();

    private:
        bool compileStage(const uint32_t id, const std::string& shaderCode);
        void compile(const uint32_t id, const char* shaderCode);

        bool link(const uint32_t id);
        bool validate(const uint32_t id);
};

#endif