//
// Created by Viktor Hundahl Strate on 15/02/2019.
//


#pragma once

#include "Component.h"
#include <glm/glm.hpp>

class TransformComponent : public Component
{
public:
    TransformComponent();

    glm::vec3 position;
    glm::vec3 scale;
};

