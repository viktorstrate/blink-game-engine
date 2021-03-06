//
// Created by Viktor Hundahl Strate on 16/02/2019.
//


#pragma once

#include <vector>
#include "Entity.h"
#include "Game.h"

#include "systems/DynamicSystem.h"
#include "systems/ModelSystem.h"
#include "systems/ShaderSystem.h"

class CameraComponent;

class World
{
public:
    World(Game* game);

    void update(double dt);
    void fixedUpdate();
    void render();

    void onInput(GLFWwindow* window, double dt);
    void onMouseMove(double xpos, double ypos);
    void onMouseScroll(double horizontal, double vertical);

    Entity* makeEntity();
    Entity* getEntity(int id);

    DynamicSystem& getDynamicSystem();
    ModelSystem& getModelSystem();
    ShaderSystem& getShaderSystem();

    CameraComponent* activeCamera;
    std::vector<Entity> entities;
    std::vector<Shader> shaders;
    Game* game;

protected:

    int nextId = 1;

    DynamicSystem dynamicSystem;
    ModelSystem modelSystem;
    ShaderSystem shaderSystem;

};

