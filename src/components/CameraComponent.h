//
// Created by Viktor Hundahl Strate on 09/02/2019.
//


#pragma once


#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Component.h"
#include "TransformComponent.h"

class Shader;

const float CAMERA_DEFAULT_FOV = 45.0f;

class CameraComponent : public Component
{
public:
    float FOV;

    explicit CameraComponent();

    glm::mat4 GetViewMatrix() const;

    glm::mat4 getProjectionMatrix() const;

    glm::vec3 front(const TransformComponent* transform) const;

};

