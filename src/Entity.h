//
// Created by Viktor Hundahl Strate on 15/02/2019.
//


#pragma once

#include <typeindex>
#include <unordered_map>
#include <functional>
#include <vector>
#include "Component.h"

class World;

class Entity
{

public:
    explicit Entity();

    virtual ~Entity();

    template <class T = Component, typename... Args>
    void assign(Args&&... args) {
        static_assert(std::is_base_of<Component, T>::value);

        T* component = new T( args...);

        static_cast<Component*>(component)->configure(this);

        components[typeid(T)] = component;
    }

    template <class T = Component>
    T* get()
    {
        for(auto& comp : components)
        {
//            if (comp.first != typeid(T)) continue;

            if (T* casted = dynamic_cast<T*>(comp.second))
            {
                return casted;
            }
        }
        return nullptr;
    }

    template <class T = Component>
    void each(std::function<void (T*)> callback)
    {
        if (!this->contains<T>()) return;

        for (auto& c : components)
        {
            Component* comp = c.second;

            if (T* casted = dynamic_cast<T*>(comp)) {
                callback(casted);
            }
        }
    }

    template <class T>
    bool contains()
    {
        return get<T>() != nullptr;
    }

    template <class T, class U, class... Types>
    bool contains()
    {
        return contains<T>() && contains<U, Types...>();
    }

    World* world;
    int id;

private:
    std::unordered_map<std::type_index, Component*> components;

};

