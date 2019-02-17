//
// Created by Viktor Hundahl Strate on 16/02/2019.
//


#pragma once

#include <vector>
#include "Entity.h"
#include "Game.h"

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

    void addEntity(Entity &entity);

    CameraComponent* activeCamera;
    std::vector<Entity> entities;
    Game* game;

protected:

    DynamicSystem dynamicSystem;
};

