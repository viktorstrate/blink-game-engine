//
// Created by Viktor Hundahl Strate on 2019-03-03.
//


#pragma once

#include "graphics/Rendering.h"

class UniformBlock
{
public:
    UniformBlock(size_t size, unsigned int blockIndex, GLenum usage = GL_STATIC_DRAW);

    void updateData(size_t offset, size_t dataSize, void* data);

    void use();

    unsigned int getBlockIndex() const;
    unsigned int getBufferIndex() const;
    size_t getSize() const;

private:
    size_t size;
    unsigned int blockIndex;
    unsigned int bufferIndex;
};


