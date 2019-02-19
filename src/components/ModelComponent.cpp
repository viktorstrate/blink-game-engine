//
// Created by Viktor Hundahl Strate on 2019-02-19.
//

#include "ModelComponent.h"

ModelComponent::ModelComponent(int modelId) : Component(), modelId(modelId), modelMatrix(1.f)
{}

ModelComponent::ModelComponent() : Component()
{}

int ModelComponent::getModelId() const
{
    return modelId;
}

void ModelComponent::setModelId(int modelId)
{
    ModelComponent::modelId = modelId;
}

int ModelComponent::getShaderId() const
{
    return shaderId;
}

void ModelComponent::setShader(int shaderId)
{
    ModelComponent::shaderId = shaderId;
}
