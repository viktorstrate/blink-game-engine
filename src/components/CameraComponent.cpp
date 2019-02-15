//
// Created by Viktor Hundahl Strate on 09/02/2019.
//

#include "CameraComponent.h"

CameraComponent::CameraComponent(TransformComponent* transformCmp)
        : transformComponent(transformCmp),
          MovementSpeed(CAMERA_DEFAULT_SPEED),
          MouseSensitivity(CAMERA_DEFAULT_SENSITIVITY),
          FOV(CAMERA_DEFAULT_FOV)
{

//    Yaw = yaw;
//    Pitch = pitch;
//    updateCameraVectors();

}

// Calculates the front vector from the Camera's (updated) Euler Angles
/*void CameraComponent::updateCameraVectors()
{
    // Calculate the new Front vector
    glm::vec3 front;
//    front.x = cos(glm::radians(Yaw))*cos(glm::radians(Pitch));
//    front.y = sin(glm::radians(Pitch));
//    front.z = sin(glm::radians(Yaw))*cos(glm::radians(Pitch));
    Front = glm::normalize(front);
    // Also re-calculate the Right and Up vector
    Right = glm::normalize(glm::cross(Front,
                                      glm::vec3(0.0f, 1.0f, 0.0f)));  // Normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
    Up = glm::normalize(glm::cross(Right, Front));
}*/

glm::mat4 CameraComponent::GetViewMatrix()
{
    return glm::lookAt(transformComponent->position,
            transformComponent->position + front(), glm::vec3(0.0f, 1.0f, 0.0f));
}

void CameraComponent::ProcessKeyboard(float forwards, float sideways, float up, float deltaTime)
{

    glm::vec3 direction = glm::vec3(forwards, sideways, up);

    if (direction.x == 0 && direction.y == 0 && direction.z == 0)
        return;

    float velocity = MovementSpeed*deltaTime;

    direction = glm::normalize(direction)*velocity;



    transformComponent->position += -direction.x * front() + direction.y * right() + direction.z*glm::vec3(0.0f, 1.0f, 0.0f);
}

void CameraComponent::ProcessMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch)
{
    xoffset *= MouseSensitivity;
    yoffset *= MouseSensitivity;

    transformComponent->rotation = glm::normalize(glm::quat(1.0f, 0.0f, -xoffset, 0.0f)) * transformComponent->rotation;
    transformComponent->rotation = transformComponent->rotation * glm::normalize(glm::quat(1.0f, 0.0f, 0.0f, yoffset));

//    if (constrainPitch) {
//        auto eulerRot = glm::eulerAngles(transformComponent->rotation);
//
//        if (eulerRot.z > glm::radians(45.0f))
//            eulerRot.z = glm::radians(45.0f);
//        if (eulerRot.z < -glm::radians(45.0f))
//            eulerRot.z = -glm::radians(45.0f);
//
//        transformComponent->rotation = glm::quat(eulerRot);
//    }
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

glm::mat4 CameraComponent::getProjectionMatrix(float aspect)
{
    glm::mat4 projection = glm::perspective(glm::radians(FOV), aspect,
                     0.1f, 100.0f);

    return projection;
}

glm::vec3 CameraComponent::front()
{

    glm::vec3 front(1.0f, 0.0f, 0.0f);

    front = transformComponent->rotation * front;

    return front;
}

glm::vec3 CameraComponent::up()
{
    return glm::vec3(0.0f, 1.0f, 0.0f);
}

glm::vec3 CameraComponent::right()
{
    return glm::cross(front(), up());
}
