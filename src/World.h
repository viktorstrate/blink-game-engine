//
// Created by Viktor Hundahl Strate on 16/02/2019.
//


#pragma once

#include <vector>
#include "GameObject.h"
#include "Game.h"

class CameraComponent;

class World
{
public:
    World(Game* game);

    void addGameObject(const GameObject& gameObject);

    CameraComponent* activeCamera;
    std::vector<GameObject> gameObjects;
    Game* game;
};

