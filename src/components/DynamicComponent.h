//
// Created by Viktor Hundahl Strate on 2019-02-17.
//

#pragma once

#include "Component.h"

class DynamicComponent : public Component
{
public:
    explicit DynamicComponent(World* world) : Component(world) {}

    virtual void update(float dt) {};
    virtual void fixedUpdate() {};
};
