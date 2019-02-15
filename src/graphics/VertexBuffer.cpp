//
// Created by Viktor Hundahl Strate on 12/02/2019.
//

#include "Rendering.h"
#include "VertexBuffer.h"

VertexBuffer::VertexBuffer(void* data, unsigned int size, unsigned int stride) : ID(0), stride(stride)
{
    glCall(glGenBuffers(1, &ID));
    glCall(glBindBuffer(GL_ARRAY_BUFFER, ID));
    glCall(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));

    glCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
}

VertexBuffer::~VertexBuffer()
{
    glCall(glDeleteBuffers(1, &ID));
}

void VertexBuffer::use()
{
    glCall(glBindBuffer(GL_ARRAY_BUFFER, ID));
}
