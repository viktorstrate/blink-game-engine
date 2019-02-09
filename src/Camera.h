//
// Created by Viktor Hundahl Strate on 09/02/2019.
//


#pragma once


#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <vector>

enum Camera_Movement {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
};

const float CAMERA_DEFAULT_YAW = -90.0f;
const float CAMERA_DEFAULT_PITCH = 0.0f;
const float CAMERA_DEFAULT_SPEED = 2.5f;
const float CAMERA_DEFAULT_SENSITIVITY = 0.1f;
const float CAMERA_DEFAULT_FOV = 45.0f;

class Camera {
public:
    glm::vec3 Position;
    glm::vec3 Front;
    glm::vec3 WorldUp;
    glm::vec3 Up;
    glm::vec3 Right;

    float Yaw;
    float Pitch;

    float MovementSpeed;
    float MouseSensitivity;
    float FOV;

    explicit Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f),
           float yaw = CAMERA_DEFAULT_YAW, float pitch = CAMERA_DEFAULT_PITCH);

    glm::mat4 GetViewMatrix();

    void ProcessKeyboard(float forwards, float sideways, float deltaTime);
    void ProcessMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch = true);
    void ProcessMouseScroll(float yoffset);

private:
    void updateCameraVectors();
};

