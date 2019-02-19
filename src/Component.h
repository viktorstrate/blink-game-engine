//
// Created by Viktor Hundahl Strate on 15/02/2019.
//


#pragma once

class Entity;

class Component
{
public:
    explicit Component() : entity(nullptr)
    {}

    virtual ~Component() = default;

    virtual void destroy()
    {};

    virtual void configure(Entity* entity)
    {
        this->entity = entity;
    }

protected:
    Entity* entity;
};