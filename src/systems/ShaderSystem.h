//
// Created by Viktor Hundahl Strate on 2019-03-03.
//


#pragma once

#include "graphics/Shader.h"

#include <unordered_map>
#include <vector>

class CameraComponent;
class Entity;

class ShaderSystem
{
public:

    ShaderSystem();

    void updateShaders(std::vector<Entity>* entities, CameraComponent* activeCamera);

    int loadShader(const std::string& path);

    Shader* getShader(int id);
    std::unordered_map<int, Shader>* getShaders();

private:
    std::unordered_map<int, Shader> loadedShaders;
    int nextShaderId;

    struct ShaderBlocks {
        UniformBlock cameraBlock;
        UniformBlock directionalLightsBlock;

        ShaderBlocks();
    };

    ShaderBlocks shaderBlocks;
};


