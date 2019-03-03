//
// Created by Viktor Hundahl Strate on 2019-02-19.
//

#include "components/CameraComponent.h"
#include "components/ModelComponent.h"
#include "graphics/Shader.h"
#include "World.h"
#include "ModelSystem.h"

ModelSystem::ModelSystem()
    : nextModelId(1), loadedModels()
{}

void ModelSystem::drawModels(World* world, ShaderSystem* shaderSystem)
{
    for (auto &item : world->entities) {
        if (!item.contains<ModelComponent, TransformComponent>()) continue;

        auto* modelComp = item.get<ModelComponent>();

        glm::mat4 model = modelComp->getModelMatrix();

        auto* shader = shaderSystem->getShader(modelComp->getShaderId());

        shader->use();
        shader->setMat4("model", model);

        int id = modelComp->getModelId();
        loadedModels[id].Draw(*shader);
    }
}

int ModelSystem::loadModel(const std::string &path)
{
    int id = nextModelId++;

    Model model(path);

    loadedModels[id] = model;

    return id;
}
