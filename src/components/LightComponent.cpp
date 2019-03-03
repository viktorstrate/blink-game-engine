//
// Created by Viktor Hundahl Strate on 2019-03-03.
//

#include "LightComponent.h"

LightComponent::LightComponent() : type(DIRECTIONAL)
{}

LightComponent::LightComponent(LightComponent::Type type) : type(type)
{}

LightComponent::Type LightComponent::getType() const
{
    return type;
}

const glm::vec3& LightComponent::getPosition() const
{
    return position;
}

const glm::vec3& LightComponent::getDirection() const
{
    return position;
}

const glm::vec3& LightComponent::getAmbient() const
{
    return ambient;
}

const glm::vec3& LightComponent::getDiffuse() const
{
    return diffuse;
}

const glm::vec3& LightComponent::getSpecular() const
{
    return specular;
}

void LightComponent::setDirectional(const glm::vec3& direction, const glm::vec3& ambient, const glm::vec3& diffuse,
                                    const glm::vec3& specular)
{
    this->type = DIRECTIONAL;
    this->position = direction;
    this->ambient = ambient;
    this->diffuse = diffuse;
    this->specular = specular;
}
