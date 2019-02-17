//
// Created by Viktor Hundahl Strate on 09/02/2019.
//

#include "CameraComponent.h"

#include <iostream>

#define WORLD_UP glm::vec3(0.0f, 1.0f, 0.0f)

CameraComponent::CameraComponent(World* world, TransformComponent* transformCmp)
        : transform(transformCmp),
          FOV(CAMERA_DEFAULT_FOV),
          Component(world)
{

}

glm::mat4 CameraComponent::GetViewMatrix()
{
    glm::mat4 mat = glm::lookAt(transform->position,
                                transform->position+front(), WORLD_UP);

    return mat;
}

glm::mat4 CameraComponent::getProjectionMatrix(float aspect)
{
    glm::mat4 projection = glm::perspective(glm::radians(FOV), aspect,
                     0.1f, 100.0f);

    return projection;
}

glm::vec3 CameraComponent::front()
{
    glm::vec3 front = transform->rotation * glm::vec3(1.0f, 0.0f, 0.0f);
    front = glm::normalize(front);
    return front;
}
