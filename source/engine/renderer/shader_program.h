#pragma once

// GLAD includes
#include <glad/glad.h>

// STD library includes
#include <iostream>
#include <string>
#include <optional>
#include <unordered_map>

// Renderer includes
#include "core/utils.h"
#include "math/oglr_math.h"

// Referenced and Adapted from:
// https://github.com/htmlboss/OpenGL-Renderer/tree/master/MP-APS/Graphics
// https://github.com/TheCherno/Hazel/tree/master/Hazel/src/Platform/OpenGL
namespace Shader
{
    enum class ShaderStage
    {
        Vertex = GL_VERTEX_SHADER,
        Fragment = GL_FRAGMENT_SHADER,
        Geometry = GL_GEOMETRY_SHADER
    };

    class ShaderProgram
    {
        public:
            ShaderProgram(const u32 id);
            ~ShaderProgram();

            ShaderProgram(ShaderProgram&& other) 
            {
    		    m_uniformCache = other.m_uniformCache;
    		    m_id = other.m_id;

    		    other.m_id = 0;
    		    other.m_uniformCache.clear();
    	    }

            ShaderProgram& operator=(ShaderProgram other) {
    		    std::swap(m_uniformCache, other.m_uniformCache);
    		    std::swap(m_id, other.m_id);

    		    return *this;
    	    }

            void bind() const;
            void unbind() const;

            void setUniform(const std::string& name, const i32 value);
            void setUniform(const std::string& name, const f32 value);
            void setUniform(const std::string& name, const math::vec2& vector);
            void setUniform(const std::string& name, const math::vec3& vector);
            void setUniform(const std::string& name, const math::vec4& vector);
            void setUniform(const std::string& name, const math::mat4& matrix);

        private:
            void cacheUniforms();
            i32 getUniformLocation(const std::string& name);

        private:
            u32 m_id;
            std::unordered_map<std::string, u32> m_uniformCache;
    };

    // TODO: Is a builder going to be appropriate down the line when loading from config files?

    class ShaderProgramBuilder
    {
        public:
            ShaderProgramBuilder& with(ShaderStage stage, std::string shaderPath);
            std::optional<ShaderProgram> build();

        private:
            b8 compileStage(const u32 id, const std::string& shaderCode);
            void compile(const u32 id, const i8* shaderCode);

            b8 link(const u32 id);
            b8 validate(const u32 id);

        private:
            std::unordered_map<ShaderStage, std::string> m_shaderStages;
    };
};
