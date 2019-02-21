//
// Created by Viktor Hundahl Strate on 15/02/2019.
//

#include "TransformComponent.h"

TransformComponent::TransformComponent(glm::vec3 pos, glm::vec3 scale, glm::quat rotation)
    : Component(), position(pos), scale(scale), rotation(rotation)
{}

glm::mat4 TransformComponent::applyTransform(glm::mat4 matrix)
{
    matrix = glm::scale(matrix, scale);
//    matrix = glm::mat4_cast(rotation) * matrix;
    matrix = glm::translate(matrix, position);

    return matrix;
}
