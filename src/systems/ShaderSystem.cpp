//
// Created by Viktor Hundahl Strate on 2019-03-03.
//

#include <glm/gtc/type_ptr.hpp>
#include "ShaderSystem.h"

#include "Entity.h"
#include "components/CameraComponent.h"

ShaderSystem::ShaderSystem() : loadedShaders(), nextShaderId(1)
{
}

ShaderSystem::ShaderBlocks::ShaderBlocks() :
    // view + projection + position
    cameraBlock(sizeof(glm::mat4)*2 + sizeof(glm::vec4), 0)
{
}

void ShaderSystem::updateShaders(std::vector<Entity>* entities, CameraComponent* activeCamera)
{
    glm::mat4 view = activeCamera->GetViewMatrix();
    glm::mat4 projection = activeCamera->getProjectionMatrix();

    auto* cameraTransform = activeCamera->getEntity()->get<TransformComponent>();

    // Set shared uniform buffers
    shaderBlocks.cameraBlock.updateData(0, sizeof(glm::mat4), glm::value_ptr(view));
    shaderBlocks.cameraBlock.updateData(sizeof(glm::mat4), sizeof(glm::mat4), glm::value_ptr(projection));
    shaderBlocks.cameraBlock.updateData(sizeof(glm::mat4)*2, sizeof(glm::vec4), glm::value_ptr(cameraTransform->position));

    for (auto& elm : loadedShaders){
        Shader& shader = elm.second;

        shader.use();

    }
}

int ShaderSystem::loadShader(const std::string& path)
{
    int id = nextShaderId++;

    Shader shader(path);

    shader.use();
    shader.setUniformBlock("Camera", shaderBlocks.cameraBlock);

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
