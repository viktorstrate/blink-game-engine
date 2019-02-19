//
// Created by Viktor Hundahl Strate on 2019-02-19.
//


#pragma once

#include <glm/matrix.hpp>
#include "Component.h"

class ModelComponent : public Component
{
public:
    ModelComponent(int modelId);

    ModelComponent();

    int getModelId() const;

    void setModelId(int modelId);

    int getShaderId() const;

    void setShader(int shaderId);

    glm::mat4 modelMatrix;

private:
    int modelId;
    int shaderId;
};


