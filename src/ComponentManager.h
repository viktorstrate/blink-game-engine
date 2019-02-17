//
// Created by Viktor Hundahl Strate on 16/02/2019.
//


#pragma once

#include <unordered_map>
#include <typeindex>

#include "Component.h"

class ComponentManager
{
    struct ComponentData {
        size_t size;
        void* stride;
    };

    template<class T>
    void registerComponent()
    {
        ComponentData data{};

        data.size = sizeof(T);
        data.stride = (void*) totalComponentSize;

        totalComponentSize += sizeof(T);
        components[typeid(T)] = data;
    }

    unsigned int totalComponentSize;
    std::unordered_map<std::type_index, ComponentData> components;
};

