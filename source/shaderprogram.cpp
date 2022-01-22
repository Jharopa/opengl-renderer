#include "shaderprogram.h"

// SHADER PROGRAM //

ShaderProgram::ShaderProgram(const u32 id) : m_id(id) 
{
    cacheUniforms();
}

ShaderProgram::~ShaderProgram()
{
    glDeleteProgram(m_id);
}

void ShaderProgram::bind() const
{
    glUseProgram(m_id);
}

void ShaderProgram::unbind() const
{
    glUseProgram(0);
}

void ShaderProgram::setUniform(const std::string& name, const i32 value)
{
    u32 location = getUniformLocation(name);
    glUniform1i(location, value);
}

void ShaderProgram::setUniform(const std::string& name, const f32 value)
{
    u32 location = getUniformLocation(name);
    glUniform1f(location, value);
}

void ShaderProgram::setUniform(const std::string& name, const glm::vec2& vector)
{
    u32 location = getUniformLocation(name);
    glUniform2f(location, vector.x, vector.y);
}

void ShaderProgram::setUniform(const std::string& name, const glm::vec3& vector)
{
    u32 location = getUniformLocation(name);
    glUniform3f(location, vector.x, vector.y, vector.z);
}

void ShaderProgram::setUniform(const std::string& name, const glm::vec4& vector)
{
    u32 location = getUniformLocation(name);
    glUniform4f(location, vector.x, vector.y, vector.z, vector.w);
}

void ShaderProgram::setUniform(const std::string& name, const glm::mat4x4& matrix)
{
    u32 location = getUniformLocation(name);
    glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
}

void ShaderProgram::cacheUniforms()
{
    i32 total;
	glGetProgramiv(m_id, GL_ACTIVE_UNIFORMS, &total);

	for (i32 i = 0; i < total; ++i) {
		i32 length, size;
		GLenum type;
		i8 name[128];

		glGetActiveUniform(m_id, static_cast<GLuint>(i), sizeof(name) - 1, &length, &size, &type, name);

		std::string nameStr = std::string(name);

		m_uniformCache.emplace(nameStr, glGetUniformLocation(m_id, name));
	}
}

i32 ShaderProgram::getUniformLocation(const std::string& name)
{
    assert(m_uniformCache.find(name) != m_uniformCache.end());

    return m_uniformCache[name];
}

// SHADER PROGRAM BUILDER //

ShaderProgramBuilder& ShaderProgramBuilder::with(ShaderStage stage, std::string shaderPath)
{
    if(m_shaderStages.find(stage) != m_shaderStages.end())
    {
        std::cerr << "Shader Program Builder doesn't support duplicate shader stage types!" << std::endl;
        std::abort();
    }

    m_shaderStages.insert({stage, shaderPath});
    
    return *this;
}

std::optional<ShaderProgram> ShaderProgramBuilder::build()
{
    std::vector<u32> shaderIDs;

    for (std::pair<ShaderStage, std::string> shaderStage : m_shaderStages)
    {
        u32 shaderID = glCreateShader(shaderStage.first);
        shaderIDs.push_back(shaderID);
        
        std::string source = readFile(shaderStage.second);

        if (!compileStage(shaderID, source))
        {
            for (const auto& id : shaderIDs)
            {
                glDeleteShader(id);
            }

            return std::nullopt;
        }
    }

    i32 programID = glCreateProgram();

    for (const auto& shaderID : shaderIDs)
    {
        glAttachShader(programID, shaderID);
    }

    if (!link(programID) || !validate(programID))
    {
        for (const auto& shaderID : shaderIDs)
        {
            glDetachShader(programID, shaderID);
            glDeleteShader(shaderID);
        }

        glDeleteProgram(programID);

        return std::nullopt;
    }
    
    for (const auto& shaderID : shaderIDs)
    {
        glDetachShader(programID, shaderID);
        glDeleteShader(shaderID);
    }

    return std::make_optional<ShaderProgram>(programID);
}

b8 ShaderProgramBuilder::compileStage(const u32 id, const std::string& shaderCode)
{
    i32 success;
    i8 infoLog[512];
    
    compile(id, shaderCode.c_str());

    glGetShaderiv(id, GL_COMPILE_STATUS, &success);
    glGetShaderInfoLog(id, 512, NULL, infoLog);
    
    if (!success)
    {
        std::cout << infoLog << std::endl;
    }

    return success;
}

void ShaderProgramBuilder::compile(const u32 id, const i8* shaderCode)
{
    glShaderSource(id, 1, &shaderCode, nullptr);
    glCompileShader(id);
}

b8 ShaderProgramBuilder::link(const u32 id)
{
    i32 success;
    i8 infoLog[512];
    
    glLinkProgram(id);
    glGetProgramiv(id, GL_LINK_STATUS, &success);
    glGetProgramInfoLog(id, 512, NULL, infoLog);
    
    if (!success)
    {
        std::cout << infoLog << std::endl;
    }

    return success;
}

b8 ShaderProgramBuilder::validate(const u32 id)
{
    i32 success;
    i8 infoLog[512];
    
    glValidateProgram(id);
    glGetProgramiv(id, GL_VALIDATE_STATUS, &success);
    glGetProgramInfoLog(id, 512, NULL, infoLog);

    if (!success)
    {
        std::cout << infoLog << std::endl;
    }

    return success;
}
