#include "shaderprogram.h"

// SHADER PROGRAM //

ShaderProgram::ShaderProgram(const uint32_t id) : m_id(id) 
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

void ShaderProgram::setUniform(const std::string& name, const int value)
{
    uint32_t location = getUniformLocation(name);
    glUniform1i(location, value);
}

void ShaderProgram::setUniform(const std::string& name, const float value)
{
    uint32_t location = getUniformLocation(name);
    glUniform1f(location, value);
}

void ShaderProgram::setUniform(const std::string& name, const glm::vec2& vector)
{
    uint32_t location = getUniformLocation(name);
    glUniform2f(location, vector.x, vector.y);
}

void ShaderProgram::setUniform(const std::string& name, const glm::vec3& vector)
{
    uint32_t location = getUniformLocation(name);
    glUniform3f(location, vector.x, vector.y, vector.z);
}

void ShaderProgram::setUniform(const std::string& name, const glm::vec4& vector)
{
    uint32_t location = getUniformLocation(name);
    glUniform4f(location, vector.x, vector.y, vector.z, vector.w);
}

void ShaderProgram::setUniform(const std::string& name, const glm::mat4x4& matrix)
{
    uint32_t location = getUniformLocation(name);
    glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
}

void ShaderProgram::cacheUniforms()
{
    int total;
	glGetProgramiv(m_id, GL_ACTIVE_UNIFORMS, &total);

	for (int i = 0; i < total; ++i) {
		int length, size;
		GLenum type;
		char name[128];

		glGetActiveUniform(m_id, static_cast<GLuint>(i), sizeof(name) - 1, &length, &size, &type, name);

		std::string nameStr = std::string(name);

		m_uniformCache.emplace(nameStr, glGetUniformLocation(m_id, name));
	}
}

int ShaderProgram::getUniformLocation(const std::string& name)
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
    std::vector<uint32_t> shaderIDs;

    for (std::pair<ShaderStage, std::string> shaderStage : m_shaderStages)
    {
        uint32_t shaderID = glCreateShader(shaderStage.first);
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

    int programID = glCreateProgram();

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

bool ShaderProgramBuilder::compileStage(const uint32_t id, const std::string& shaderCode)
{
    int success;
    char infoLog[512];
    
    compile(id, shaderCode.c_str());

    glGetShaderiv(id, GL_COMPILE_STATUS, &success);
    glGetShaderInfoLog(id, 512, NULL, infoLog);
    
    if (!success)
    {
        std::cout << infoLog << std::endl;
    }

    return success;
}

void ShaderProgramBuilder::compile(const uint32_t id, const char* shaderCode)
{
    glShaderSource(id, 1, &shaderCode, nullptr);
    glCompileShader(id);
}

bool ShaderProgramBuilder::link(const uint32_t id)
{
    int success;
    char infoLog[512];
    
    glLinkProgram(id);
    glGetProgramiv(id, GL_LINK_STATUS, &success);
    glGetProgramInfoLog(id, 512, NULL, infoLog);
    
    if (!success)
    {
        std::cout << infoLog << std::endl;
    }

    return success;
}

bool ShaderProgramBuilder::validate(const uint32_t id)
{
    int success;
    char infoLog[512];
    
    glValidateProgram(id);
    glGetProgramiv(id, GL_VALIDATE_STATUS, &success);
    glGetProgramInfoLog(id, 512, NULL, infoLog);

    if (!success)
    {
        std::cout << infoLog << std::endl;
    }

    return success;
}
