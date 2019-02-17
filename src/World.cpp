//
// Created by Viktor Hundahl Strate on 16/02/2019.
//

#include "World.h"

World::World(Game* game) : game(game) {}

void World::addGameObject(const GameObject &gameObject)
{
    gameObjects.push_back(gameObject);
}
