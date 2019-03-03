//
// Created by Viktor Hundahl Strate on 2019-03-03.
//


#pragma once

#include "Component.h"

class LightComponent : public Component
{
public:
    enum Type {
        DIRECTIONAL, POINT, SPOT
    };

    LightComponent();

    LightComponent(Type type);

private:
    Type type;
};


