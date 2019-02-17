//
// Created by Viktor Hundahl Strate on 16/02/2019.
//

#include "World.h"

World::World(Game* game) : game(game),
    dynamicSystem()
{}

void World::addGameObject(const GameObject &gameObject)
{
    gameObjects.push_back(gameObject);
}

void World::update(double dt)
{
    dynamicSystem.update(gameObjects, dt);
}

void World::fixedUpdate()
{
    dynamicSystem.fixedUpdate(gameObjects);
}

void World::render()
{

}
