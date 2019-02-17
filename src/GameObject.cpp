//
// Created by Viktor Hundahl Strate on 15/02/2019.
//

#include "GameObject.h"
#include "World.h"

GameObject::GameObject() {}

GameObject::~GameObject()
{
    for(auto& comp : components) {
        delete comp.second;
    }
}