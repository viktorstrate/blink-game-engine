//
// Created by Viktor Hundahl Strate on 2019-02-17.
//

#pragma once


#include "Entity.h"

class DynamicSystem
{
public:
    void update(std::vector<Entity> &gameObjects, double dt);
    void fixedUpdate(std::vector<Entity> &gameObjects);

    void processInput(std::vector<Entity> &gameObjects, GLFWwindow* window, double dt);
    void processMouseMove(std::vector<Entity> &gameObjects, double xpos, double ypos);
    void processMouseScroll(std::vector<Entity> &gameObjects, double horizontal, double vertical);
};