//
// Created by Viktor Hundahl Strate on 16/02/2019.
//

#include "World.h"

World::World(Game* game) : game(game),
    dynamicSystem(), modelSystem()
{}

Entity* World::makeEntity()
{
    Entity entity;
    entity.id = nextId++;
    entity.world = this;
    entities.push_back(entity);
    return getEntity(nextId-1);
}

Entity* World::getEntity(int id)
{
    for (auto& entity : entities) {
        if (entity.id == id) return &entity;
    }
    return nullptr;
}

void World::update(double dt)
{
    dynamicSystem.update(entities, dt);
}

void World::fixedUpdate()
{
    dynamicSystem.fixedUpdate(entities);
}

void World::render()
{

}

void World::onInput(GLFWwindow* window, double dt)
{
    dynamicSystem.processInput(entities, window, dt);
}

void World::onMouseMove(double xpos, double ypos)
{
    dynamicSystem.processMouseMove(entities, xpos, ypos);
}

void World::onMouseScroll(double horizontal, double vertical)
{
    dynamicSystem.processMouseScroll(entities, horizontal, vertical);
}

DynamicSystem& World::getDynamicSystem()
{
    return dynamicSystem;
}

ModelSystem& World::getModelSystem()
{
    return modelSystem;
}
