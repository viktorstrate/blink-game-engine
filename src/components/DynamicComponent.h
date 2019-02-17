//
// Created by Viktor Hundahl Strate on 2019-02-17.
//

#pragma once

#include "Component.h"

class GLFWwindow;

class DynamicComponent : public Component
{
public:
    explicit DynamicComponent() : Component() {}

    virtual void update(float dt) {}
    virtual void fixedUpdate() {}

    virtual void onInput(GLFWwindow* window, double dt) {}
    virtual void onMouseMove(double xpos, double ypos) {}
    virtual void onMouseScroll(double horizontal, double vertical) {}
};
