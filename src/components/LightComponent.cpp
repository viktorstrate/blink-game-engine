//
// Created by Viktor Hundahl Strate on 2019-03-03.
//

#include "LightComponent.h"

LightComponent::LightComponent() : type(DIRECTIONAL)
{}

LightComponent::LightComponent(LightComponent::Type type) : type(type)
{}
