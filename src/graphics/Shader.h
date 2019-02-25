//
// Created by Viktor Hundahl Strate on 06/02/2019.
//


#pragma once

#include <glm/matrix.hpp>
#include <string>

class Shader
{
public:

    struct ShaderSource
    {
        std::string vertex, fragment;
    };

    // the program ID
    unsigned int ID;

    Shader() = default;

    // constructor reads and builds the shader
    explicit Shader(const std::string &shaderPath);

    // use/activate the shader
    void use();

    // utility uniform functions
    void setBool(const std::string &name, bool value) const;

    void setInt(const std::string &name, int value) const;

    void setFloat(const std::string &name, float value) const;

    void setMat4(const std::string &name, glm::mat4 &matrix);

    void setVec2(const std::string &name, float x, float y);

    void setVec2(const std::string &name, glm::vec2 vector);

    void setVec3(const std::string &name, float x, float y, float z);

    void setVec3(const std::string &name, glm::vec3 vector);

private:
    ShaderSource parseShader(const std::string &shaderPath);

};

