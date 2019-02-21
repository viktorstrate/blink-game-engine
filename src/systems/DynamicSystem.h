//
// Created by Viktor Hundahl Strate on 2019-02-17.
//

#pragma once


#include "Entity.h"

class GLFWwindow;

class DynamicSystem
{
public:
    void update(std::vector<Entity> &gameObjects, double dt);
    void fixedUpdate(std::vector<Entity> &entity);

    void processInput(std::vector<Entity> &entity, GLFWwindow* window, double dt);
    void processMouseMove(std::vector<Entity> &entity, double xpos, double ypos);
    void processMouseScroll(std::vector<Entity> &entity, double horizontal, double vertical);
};