//
// Created by Viktor Hundahl Strate on 2019-03-03.
//

#include "UniformBlock.h"

unsigned int UniformBlock::getBlockIndex() const
{
    return blockIndex;
}

size_t UniformBlock::getSize() const
{
    return size;
}

UniformBlock::UniformBlock(size_t size, unsigned int blockIndex, GLenum usage) : blockIndex(blockIndex)
{
    glCall(glGenBuffers(1, &bufferIndex));
    this->use();
    glCall(glBufferData(GL_UNIFORM_BUFFER, size, nullptr, usage));
    glCall(glBindBuffer(GL_UNIFORM_BUFFER, 0));

    glCall(glBindBufferRange(GL_UNIFORM_BUFFER, blockIndex, bufferIndex, 0, size));
}

void UniformBlock::use()
{
    glCall(glBindBuffer(GL_UNIFORM_BUFFER, bufferIndex));
}

void UniformBlock::updateData(size_t offset, size_t dataSize, void* data)
{
    this->use();
    glCall(glBufferSubData(GL_UNIFORM_BUFFER, offset, dataSize, data));
    glCall(glBindBuffer(GL_UNIFORM_BUFFER, 0));
}

unsigned int UniformBlock::getBufferIndex() const
{
    return bufferIndex;
}
