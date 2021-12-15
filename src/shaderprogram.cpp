#include "shaderprogram.h"

ShaderProgram::ShaderProgram(const int id) : m_id(id) {}

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

ShaderProgramBuilder& ShaderProgramBuilder::with(ShaderStage stage, std::string shaderPath)
{
    if(m_shadersStage.find(stage) != m_shadersStage.end())
    {
        std::cerr << "Shader Program Builder already has duplicate shader stage type!" << std::endl;
        std::abort(); 
    }

    m_shadersStage.insert({stage, shaderPath});
    
    return *this;
}

std::optional<ShaderProgram> ShaderProgramBuilder::build()
{
    std::vector<uint32_t> shaderIDs;

    for (std::pair<ShaderStage, std::string> stage : m_shadersStage)
    {
        uint32_t id = glCreateShader(stage.first);
        shaderIDs.push_back(id);
        
        std::string source = readFile(stage.second);

        if (!compileStage(id, source))
        {
            for (const auto id : shaderIDs)
            {
                glDeleteShader(id);
            }

            return std::nullopt;
        }
    }

    int programID = glCreateProgram();

    for (const auto shaderID : shaderIDs)
    {
        glAttachShader(programID, shaderID);
    }

    if (!link(programID))
    {
        for (const auto shaderID : shaderIDs)
        {
            glDetachShader(programID, shaderID);
            glDeleteShader(shaderID);
        }

        glDeleteProgram(programID);

        return std::nullopt;
    }

    for (const auto shaderID : shaderIDs)
    {
        glDetachShader(programID, shaderID);
        glDeleteShader(shaderID);
    }

    return std::make_optional<ShaderProgram>(programID);
}

bool ShaderProgramBuilder::compileStage(const int id, const std::string& shaderCode)
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

void ShaderProgramBuilder::compile(const int id, const char* shaderCode)
{
    glShaderSource(id, 1, &shaderCode, nullptr);
    glCompileShader(id);
}

bool ShaderProgramBuilder::link(const int id)
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
