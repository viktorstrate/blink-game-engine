//
// Created by Viktor Hundahl Strate on 2019-02-19.
//

#include "components/ModelComponent.h"
#include "World.h"
#include "ModelSystem.h"

ModelSystem::ModelSystem()
    : nextId(1), mainShader("assets/shaders/color-light.glsl")
{}

void ModelSystem::drawModels(World* world)
{
    for (auto &item : world->entities) {
        auto* component = item.get<ModelComponent>();
        if (component != nullptr) {

            mainShader.setMat4("model", component->modelMatrix);
            int id = component->getModelId();
            loadedModels[id].Draw(mainShader);
        }
    }
}

int ModelSystem::loadModel(const std::string &path)
{
    int id = ++nextId;

    Model model(path);

    loadedModels[id] = model;

    return id;
}
