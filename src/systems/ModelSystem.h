//
// Created by Viktor Hundahl Strate on 2019-02-19.
//


#pragma once

#include <vector>
#include <unordered_map>
#include <string>

#include "graphics/Model.h"
#include "Entity.h"

class Shader;

class ModelSystem
{
public:
    ModelSystem();

    void drawModels(World* world);

    int loadModel(const std::string& path);

    int loadShader(const std::string& path);

    Shader* getShader(int id);

private:
    std::unordered_map<int, Model> loadedModels;
    std::unordered_map<int, Shader> loadedShaders;
    int nextModelId;
    int nextShaderId;
//    Shader mainShader;
};


