//
// Created by Viktor Hundahl Strate on 09/02/2019.
//

#include "CameraComponent.h"

#include "Entity.h"
#include "TransformComponent.h"
#include "graphics/Shader.h"

#include <iostream>
#include <World.h>

#define WORLD_UP glm::vec3(0.0f, 1.0f, 0.0f)

CameraComponent::CameraComponent()
        : FOV(CAMERA_DEFAULT_FOV),
          Component()
{

}

glm::mat4 CameraComponent::GetViewMatrix() const
{
    auto* transform = entity->get<TransformComponent>();

    glm::mat4 mat = glm::lookAt(transform->position,
                                transform->position+front(transform), WORLD_UP);

    return mat;
}

glm::mat4 CameraComponent::getProjectionMatrix() const
{
    Game* game = entity->world->game;

    glm::mat4 projection = glm::perspective(glm::radians(FOV), (float)game->screenWidth / (float)game->screenHeight,
                                            0.1f, 100.0f);

    return projection;
}

glm::vec3 CameraComponent::front(const TransformComponent* transform) const
{
    glm::vec3 front = transform->rotation * glm::vec3(1.0f, 0.0f, 0.0f);
    front = glm::normalize(front);
    return front;
}

