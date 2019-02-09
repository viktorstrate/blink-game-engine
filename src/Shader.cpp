//
// Created by Viktor Hundahl Strate on 06/02/2019.
//

#include "Shader.h"

#include <iostream>
#include <fstream>
#include <sstream>

Shader::ShaderSource Shader::parseShader(const char* shaderPath) {

    std::ifstream fileStream;
    fileStream.open(shaderPath);

    enum ShaderType {
        NONE = -1, VERTEX = 0, FRAGMENT = 1
    };

    std::string line;
    std::stringstream ss[2];
    ShaderType type = ShaderType::NONE;

    while (getline(fileStream, line)) {
        if (line.find("#shader") != std::string::npos) {

            if (line.find("vertex") != std::string::npos) {
                type = ShaderType::VERTEX;

            } else if (line.find("fragment") != std::string::npos) {
                type = ShaderType::FRAGMENT;

            }
        } else {
            ss[(int) type] << line << '\n';
        }
    }

    return { ss[0].str(), ss[1].str() };
}

static void validateShader(unsigned int shader, const std::string& name) {
    int  success;
    char infoLog[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

    glGetShaderInfoLog(shader, 512, NULL, infoLog);

    if (!success) {
        std::cout << "Shader compile error: " << name << " - " << infoLog;
    }
}

Shader::Shader(const char* shaderPath) {
    ShaderSource shaders = parseShader(shaderPath);

    unsigned int vertex, fragment;

    // Vertex shader
    vertex = glCreateShader(GL_VERTEX_SHADER);
    const char* vertexSource = shaders.vertex.c_str();
    glShaderSource(vertex, 1, &vertexSource, nullptr);
    glCompileShader(vertex);
    validateShader(vertex, "Vertex Shader");

    // Fragment shader
    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    const char* fragmentSource = shaders.fragment.c_str();
    glShaderSource(fragment, 1, &fragmentSource, nullptr);
    glCompileShader(fragment);
    validateShader(fragment, "Fragment shader");

    // Shader program
    ID = glCreateProgram();
    glAttachShader(ID, vertex);
    glAttachShader(ID, fragment);
    glLinkProgram(ID);

    // Validate program lining
    {
        int success;
        char infoLog[512];

        glGetProgramiv(ID, GL_LINK_STATUS, &success);
        if(!success)
        {
            glGetProgramInfoLog(ID, 512, NULL, infoLog);
            std::cout << "Shader linking failed: " << infoLog << std::endl;
        }
    }

    // delete the shaders as they're linked into our program now and no longer necessery
    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

void Shader::use() {
    glUseProgram(ID);
}

void Shader::setBool(const std::string &name, bool value) const {
    glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
}

void Shader::setInt(const std::string &name, int value) const {
    glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}

void Shader::setFloat(const std::string &name, float value) const {
    glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
}
