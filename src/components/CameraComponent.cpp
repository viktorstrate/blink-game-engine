//
// Created by Viktor Hundahl Strate on 09/02/2019.
//

#include "CameraComponent.h"

CameraComponent::CameraComponent(TransformComponent* transformCmp, glm::vec3 up, float yaw, float pitch)
        : transformComponent(transformCmp),
          Front(glm::vec3(0.0f, 0.0f, -1.0f)),
          MovementSpeed(CAMERA_DEFAULT_SPEED),
          MouseSensitivity(CAMERA_DEFAULT_SENSITIVITY),
          FOV(CAMERA_DEFAULT_FOV)
{

    WorldUp = up;
    Yaw = yaw;
    Pitch = pitch;
    updateCameraVectors();

}

// Calculates the front vector from the Camera's (updated) Euler Angles
void CameraComponent::updateCameraVectors()
{
    // Calculate the new Front vector
    glm::vec3 front;
    front.x = cos(glm::radians(Yaw))*cos(glm::radians(Pitch));
    front.y = sin(glm::radians(Pitch));
    front.z = sin(glm::radians(Yaw))*cos(glm::radians(Pitch));
    Front = glm::normalize(front);
    // Also re-calculate the Right and Up vector
    Right = glm::normalize(glm::cross(Front,
                                      WorldUp));  // Normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
    Up = glm::normalize(glm::cross(Right, Front));
}

glm::mat4 CameraComponent::GetViewMatrix()
{
    return glm::lookAt(transformComponent->position, transformComponent->position + Front, Up);
}

void CameraComponent::ProcessKeyboard(float forwards, float sideways, float up, float deltaTime)
{

    glm::vec3 direction = glm::vec3(forwards, sideways, up);

    if (direction.x == 0 && direction.y == 0 && direction.z == 0)
        return;

    float velocity = MovementSpeed*deltaTime;

    direction = glm::normalize(direction)*velocity;

    transformComponent->position += -direction.x*Front + direction.y*Right + direction.z*WorldUp;
}

void CameraComponent::ProcessMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch)
{
    xoffset *= MouseSensitivity;
    yoffset *= MouseSensitivity;

    Yaw += xoffset;
    Pitch += yoffset;

    // Make sure that when pitch is out of bounds, screen doesn't get flipped
    if (constrainPitch) {
        if (Pitch > 89.0f)
            Pitch = 89.0f;
        if (Pitch < -89.0f)
            Pitch = -89.0f;
    }

    // Update Front, Right and Up Vectors using the updated Euler angles
    updateCameraVectors();
}

void CameraComponent::ProcessMouseScroll(float yoffset)
{
    float min = 1.0f;
    float max = 45.0f;

    if (FOV <= max && FOV >= min)
        FOV -= yoffset;

    if (FOV <= min)
        FOV = min;

    if (FOV >= max)
        FOV = max;
}
