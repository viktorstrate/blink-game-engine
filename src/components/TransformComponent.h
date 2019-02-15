//
// Created by Viktor Hundahl Strate on 15/02/2019.
//


#pragma once

#include "Component.h"
#include <glm/glm.hpp>
#include<glm/gtc/quaternion.hpp>

class TransformComponent : public Component
{
public:
    explicit TransformComponent(glm::vec3 pos = glm::vec3(0.0f), glm::vec3 scale = glm::vec3(1.0f), glm::quat rotation = glm::qua<float>(glm::vec3(glm::radians(180.0f), 0.0f, 0.0f)));

    glm::vec3 position;
    glm::vec3 scale;
    glm::quat rotation;
};

