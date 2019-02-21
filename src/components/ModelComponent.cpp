//
// Created by Viktor Hundahl Strate on 2019-02-19.
//

#include "ModelComponent.h"

#include "Entity.h"
#include "components/TransformComponent.h"

ModelComponent::ModelComponent(int modelId) : Component(), modelId(modelId), shaderId(0)
{}

ModelComponent::ModelComponent() : Component(), modelId(0), shaderId(0)
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

glm::mat4 ModelComponent::getModelMatrix()
{
    auto* transform = entity->get<TransformComponent>();

    glm::mat4 model = transform->applyTransform(glm::mat4(1.f));

    return model;
}
