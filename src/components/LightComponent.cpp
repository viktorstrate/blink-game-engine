//
// Created by Viktor Hundahl Strate on 2019-03-03.
//

#include "Entity.h"
#include "LightComponent.h"
#include "TransformComponent.h"

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
    auto* transform = entity->get<TransformComponent>();
    return transform->position;
}

const glm::vec3& LightComponent::getDirection() const
{
    return getPosition();
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

float LightComponent::getRange() const
{
    return range;
}

void LightComponent::setDirectional(const glm::vec3& direction, const glm::vec3& ambient, const glm::vec3& diffuse,
                                    const glm::vec3& specular)
{
    this->type = DIRECTIONAL;
    auto* transform = entity->get<TransformComponent>();
    transform->position = direction;
    this->ambient = ambient;
    this->diffuse = diffuse;
    this->specular = specular;
}

void LightComponent::setPoint(const glm::vec3& position, float range,
                              const glm::vec3& ambient, const glm::vec3& diffuse, const glm::vec3& specular)
{
    this->type = POINT;
    auto* transform = entity->get<TransformComponent>();
    transform->position = position;
    this->range = range;
    this->ambient = ambient;
    this->diffuse = diffuse;
    this->specular = specular;
}

void LightComponent::setType(LightComponent::Type type)
{
    LightComponent::type = type;
}

void LightComponent::setAmbient(const glm::vec3& ambient)
{
    LightComponent::ambient = ambient;
}

void LightComponent::setDiffuse(const glm::vec3& diffuse)
{
    LightComponent::diffuse = diffuse;
}

void LightComponent::setSpecular(const glm::vec3& specular)
{
    LightComponent::specular = specular;
}

void LightComponent::setRange(float range)
{
    LightComponent::range = range;
}
