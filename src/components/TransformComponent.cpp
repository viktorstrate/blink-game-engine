//
// Created by Viktor Hundahl Strate on 15/02/2019.
//

#include "TransformComponent.h"

TransformComponent::TransformComponent(World* world, glm::vec3 pos, glm::vec3 scale, glm::quat rotation)
    : Component(world), position(pos), scale(scale), rotation(rotation)
{}