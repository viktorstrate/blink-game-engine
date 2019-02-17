//
// Created by Viktor Hundahl Strate on 15/02/2019.
//

#include "Entity.h"
#include "World.h"

Entity::Entity() {}

Entity::~Entity()
{
    for(auto& comp : components) {
        delete comp.second;
    }
}