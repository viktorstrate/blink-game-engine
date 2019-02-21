//
// Created by Viktor Hundahl Strate on 2019-02-19.
//

#include "components/CameraComponent.h"
#include "components/ModelComponent.h"
#include "World.h"
#include "ModelSystem.h"

ModelSystem::ModelSystem()
    : nextId(1), mainShader("assets/shaders/lamp.glsl")
{}

void ModelSystem::drawModels(World* world)
{
    for (auto &item : world->entities) {
        if (!item.contains<ModelComponent, TransformComponent>()) continue;

        auto* modelComp = item.get<ModelComponent>();

        glm::mat4 model = modelComp->getModelMatrix();

        mainShader.use();

        mainShader.setMat4("model", model);
        world->activeCamera->configureShader(mainShader);

        int id = modelComp->getModelId();
        loadedModels[id].Draw(mainShader);
    }
}

int ModelSystem::loadModel(const std::string &path)
{
    int id = ++nextId;

    Model model(path);

    loadedModels[id] = model;

    return id;
}
