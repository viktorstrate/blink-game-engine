//
// Created by Viktor Hundahl Strate on 2019-03-03.
//


#pragma once

#include <glm/glm.hpp>
#include "Component.h"

class LightComponent : public Component
{
public:
    enum Type {
        DIRECTIONAL, POINT, SPOT
    };

    LightComponent();

    LightComponent(Type type);

    void setDirectional(const glm::vec3& direction, const glm::vec3& ambient = glm::vec3(0.f), const glm::vec3& diffuse = glm::vec3(1.f), const glm::vec3& specular = glm::vec3(0.f));

    Type getType() const;

    const glm::vec3& getPosition() const;
    const glm::vec3& getDirection() const;

    const glm::vec3& getAmbient() const;

    const glm::vec3& getDiffuse() const;

    const glm::vec3& getSpecular() const;

private:
    Type type;
    glm::vec3 position;
    glm::vec3 ambient;
    glm::vec3 diffuse;
    glm::vec3 specular;
};


