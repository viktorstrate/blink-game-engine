//
// Created by Viktor Hundahl Strate on 2019-02-19.
//


#pragma once

#include <vector>
#include <unordered_map>
#include <string>

#include "graphics/Model.h"
#include "Entity.h"
#include "ShaderSystem.h"

class Shader;

class ModelSystem
{
public:
    ModelSystem();

    void drawModels(World* world, ShaderSystem* shaderSystem);

    int loadModel(const std::string& path);

private:
    std::unordered_map<int, Model> loadedModels;
    int nextModelId;

};


