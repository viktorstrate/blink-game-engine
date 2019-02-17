//
// Created by Viktor Hundahl Strate on 09/02/2019.
//


#pragma once


#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Component.h"
#include "TransformComponent.h"

const float CAMERA_DEFAULT_FOV = 45.0f;

class CameraComponent : public Component
{
public:
    float FOV;

    explicit CameraComponent(World* world, TransformComponent* transformCmp);

    glm::mat4 GetViewMatrix();

    glm::mat4 getProjectionMatrix(float aspect);

    glm::vec3 front();

private:
    TransformComponent* transform;
};

