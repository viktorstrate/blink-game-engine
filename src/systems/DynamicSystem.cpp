//
// Created by Viktor Hundahl Strate on 2019-02-17.
//

#include <GLFW/glfw3.h>
#include "components/DynamicComponent.h"
#include "DynamicSystem.h"

void DynamicSystem::update(std::vector<Entity> &gameObjects, double dt)
{
    for (auto &item : gameObjects) {
        auto* component = item.get<DynamicComponent>();
        if (component != nullptr) {
            component->update(dt);
        }
    }
}

void DynamicSystem::fixedUpdate(std::vector<Entity> &gameObjects)
{
    for (auto &item : gameObjects) {
        auto* component = item.get<DynamicComponent>();
        if (component != nullptr) {
            component->fixedUpdate();
        }
    }
}

void DynamicSystem::processInput(std::vector<Entity> &gameObjects, GLFWwindow* window, double dt)
{
    for (auto &item : gameObjects) {
        item.each<DynamicComponent>([window, dt](DynamicComponent* component) {
            component->onInput(window, dt);
        });
    }
}

void DynamicSystem::processMouseMove(std::vector<Entity> &gameObjects, double xpos, double ypos)
{
    for (auto &item : gameObjects) {
        item.each<DynamicComponent>([xpos, ypos](DynamicComponent* component) {
            component->onMouseMove(xpos, ypos);
        });
    }
}

void DynamicSystem::processMouseScroll(std::vector<Entity> &gameObjects, double horizontal, double vertical)
{
    for (auto &item : gameObjects) {
        item.each<DynamicComponent>([horizontal, vertical](DynamicComponent* component) {
            component->onMouseScroll(horizontal, vertical);
        });
    }
}
