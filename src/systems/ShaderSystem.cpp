//
// Created by Viktor Hundahl Strate on 2019-03-03.
//

#include <glm/gtc/type_ptr.hpp>
#include "ShaderSystem.h"

#include "Entity.h"
#include "components/CameraComponent.h"
#include "components/LightComponent.h"

ShaderSystem::ShaderSystem() : loadedShaders(), nextShaderId(1)
{
}

#define MAX_DIRECTIONAL_LIGHTS 50
#define DIRECTIONAL_LIGHT_SIZE (sizeof(glm::vec4)*4)

ShaderSystem::ShaderBlocks::ShaderBlocks() :
    // view + projection + position
    cameraBlock(sizeof(glm::mat4)*2 + sizeof(glm::vec4), 0),
    directionalLightsBlock(sizeof(int)+DIRECTIONAL_LIGHT_SIZE*MAX_DIRECTIONAL_LIGHTS, 1)
{
}

void ShaderSystem::updateShaders(std::vector<Entity>* entities, CameraComponent* activeCamera)
{
    glm::mat4 view = activeCamera->GetViewMatrix();
    glm::mat4 projection = activeCamera->getProjectionMatrix();

    auto* cameraTransform = activeCamera->getEntity()->get<TransformComponent>();

    // Update shared uniform buffers
    shaderBlocks.cameraBlock.updateData(0, sizeof(glm::mat4), glm::value_ptr(view));
    shaderBlocks.cameraBlock.updateData(sizeof(glm::mat4), sizeof(glm::mat4), glm::value_ptr(projection));
    shaderBlocks.cameraBlock.updateData(sizeof(glm::mat4)*2, sizeof(glm::vec4), glm::value_ptr(cameraTransform->position));

    int directionalLightsIndex = 0;

    // Update lights uniform buffers
    for(auto& entity : *entities) {
        if (entity.contains<LightComponent>()) {

            auto* lightComponent = entity.get<LightComponent>();

            switch(lightComponent->getType()) {
                case LightComponent::DIRECTIONAL:
                {
                    size_t baseOffset = DIRECTIONAL_LIGHT_SIZE*directionalLightsIndex;
                    // Direction
                    glm::vec3 direction = lightComponent->getDirection();
                    shaderBlocks.directionalLightsBlock.updateData(baseOffset,
                                                                   sizeof(glm::vec4),
                                                                   glm::value_ptr(direction));

                    // Ambient
                    glm::vec3 ambient = lightComponent->getAmbient();
                    shaderBlocks.directionalLightsBlock.updateData(baseOffset + sizeof(glm::vec4),
                                                                   sizeof(glm::vec4),
                                                                   (void*) glm::value_ptr(ambient));

                    // Diffuse
                    glm::vec3 diffuse = lightComponent->getDiffuse();
                    shaderBlocks.directionalLightsBlock.updateData(baseOffset + sizeof(glm::vec4)*2,
                                                                   sizeof(glm::vec4),
                                                                   (void*) glm::value_ptr(diffuse));

                    // Specular
                    glm::vec3 specular = lightComponent->getSpecular();
                    shaderBlocks.directionalLightsBlock.updateData(sizeof(int)+DIRECTIONAL_LIGHT_SIZE*directionalLightsIndex + sizeof(glm::vec4)*3,
                                                                   sizeof(glm::vec4),
                                                                   (void*) glm::value_ptr(specular));

                    directionalLightsIndex++;
                    break;
                }
                default: break;
            }
        }
    }

    // Directional lights Amount
    shaderBlocks.directionalLightsBlock.updateData(DIRECTIONAL_LIGHT_SIZE*MAX_DIRECTIONAL_LIGHTS,
                                                   sizeof(int),
                                                   &directionalLightsIndex);

//    for (auto& elm : loadedShaders){
//        Shader& shader = elm.second;
//
//        shader.use();
//
//    }
}

int ShaderSystem::loadShader(const std::string& path)
{
    int id = nextShaderId++;

    Shader shader(path);

    shader.use();
    shader.setUniformBlock("Camera", shaderBlocks.cameraBlock);
    shader.setUniformBlock("DirectionalLights", shaderBlocks.directionalLightsBlock);

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
