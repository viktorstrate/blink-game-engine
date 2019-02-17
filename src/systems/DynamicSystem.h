//
// Created by Viktor Hundahl Strate on 2019-02-17.
//

#pragma once


#include <GameObject.h>

class DynamicSystem
{
public:
    void update(std::vector<GameObject> &gameObjects, double dt);
    void fixedUpdate(std::vector<GameObject> &gameObjects);
};