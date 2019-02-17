//
// Created by Viktor Hundahl Strate on 16/02/2019.
//

#include "World.h"

World::World(Game* game) : game(game),
    dynamicSystem()
{}

void World::addEntity(Entity &entity)
{
    entity.world = this;
    entities.push_back(entity);
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
