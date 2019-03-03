//
// Created by Viktor Hundahl Strate on 2019-03-03.
//

#include "ShaderSystem.h"

#include "Entity.h"
#include "components/CameraComponent.h"

ShaderSystem::ShaderSystem() : loadedShaders(), nextShaderId(1)
{}

void ShaderSystem::updateShaders(std::vector<Entity>* entities, CameraComponent* activeCamera)
{
    glm::mat4 view = activeCamera->GetViewMatrix();
    glm::mat4 projection = activeCamera->getProjectionMatrix();

    auto* cameraTransform = activeCamera->getEntity()->get<TransformComponent>();

    for (auto& elm : loadedShaders){
        Shader& shader = elm.second;

        shader.use();

        shader.setMat4("view", view);
        shader.setMat4("projection", projection);
        shader.setVec3("viewPos", cameraTransform->position);
    }
}

int ShaderSystem::loadShader(const std::string& path)
{
    int id = nextShaderId++;

    Shader shader(path);

    loadedShaders[id] = shader;

    return id;
}

Shader* ShaderSystem::getShader(int id)
{
    return &loadedShaders[id];
}

std::unordered_map<int, Shader>* ShaderSystem::getShaders()
{
    return &loadedShaders;
}