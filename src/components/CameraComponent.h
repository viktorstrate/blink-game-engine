//
// Created by Viktor Hundahl Strate on 09/02/2019.
//


#pragma once


#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <vector>

#include "Component.h"
#include "TransformComponent.h"

enum Camera_Movement
{
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
};

const float CAMERA_DEFAULT_YAW = -90.0f;
const float CAMERA_DEFAULT_PITCH = 0.0f;
const float CAMERA_DEFAULT_SPEED = 3.5f;
const float CAMERA_DEFAULT_SENSITIVITY = 0.001f;
const float CAMERA_DEFAULT_FOV = 45.0f;

class CameraComponent : public Component
{
public:

//    glm::vec3 Front;
//    glm::vec3 Up;
//    glm::vec3 Right;

//    float Yaw;
//    float Pitch;

    float MovementSpeed;
    float MouseSensitivity;
    float FOV;

    explicit CameraComponent(TransformComponent* transformCmp);

    glm::mat4 GetViewMatrix();

    glm::mat4 getProjectionMatrix(float aspect);

    glm::vec3 front();
    glm::vec3 up();
    glm::vec3 right();

    void ProcessKeyboard(float forwards, float sideways, float up, float deltaTime);

    void ProcessMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch = true);

    void ProcessMouseScroll(float yoffset);

private:
//    void updateCameraVectors();
    TransformComponent* transformComponent;
};

