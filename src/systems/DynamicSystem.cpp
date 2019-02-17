//
// Created by Viktor Hundahl Strate on 2019-02-17.
//

#include "components/DynamicComponent.h"
#include "DynamicSystem.h"

void DynamicSystem::update(std::vector<GameObject> &gameObjects, double dt)
{
    for (auto &item : gameObjects) {
        auto* component = item.getComponent<DynamicComponent>();
        if (component != nullptr) {
            component->update(dt);
        }
    }
}

void DynamicSystem::fixedUpdate(std::vector<GameObject> &gameObjects)
{
    for (auto &item : gameObjects) {
        auto* component = item.getComponent<DynamicComponent>();
        if (component != nullptr) {
            component->fixedUpdate();
        }
    }
}
