//
// Created by Viktor Hundahl Strate on 15/02/2019.
//


#pragma once

#include <typeindex>
#include <unordered_map>
#include <vector>
#include "Component.h"

class World;

class GameObject
{

public:
    explicit GameObject();

    virtual ~GameObject();

    template <class T>
    void addComponent(T* component) {
        static_assert(std::is_base_of<Component, T>::value);
        components[typeid(T)] = component;
    }

    template <class T>
    T* getComponent()
    {
        static_assert(std::is_base_of<Component, T>::value);
        return dynamic_cast<T*>(components[typeid(T)]);
    }

    GameObject* parent;
    World* world;

private:
    std::unordered_map<std::type_index, Component*> components;

};

