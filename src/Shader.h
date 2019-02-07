//
// Created by Viktor Hundahl Strate on 06/02/2019.
//


#pragma once

#include <glad/glad.h>
#include <string>

class Shader {
public:

    struct ShaderSource {
        std::string vertex, fragment;
    };

    // the program ID
    unsigned int ID;

    // constructor reads and builds the shader
    explicit Shader(const char* shaderPath);

    // use/activate the shader
    void use();

    // utility uniform functions
    void setBool(const std::string &name, bool value) const;

    void setInt(const std::string &name, int value) const;

    void setFloat(const std::string &name, float value) const;

private:
    ShaderSource parseShader(const char* shaderPath);

};

