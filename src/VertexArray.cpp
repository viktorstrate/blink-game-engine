//
// Created by Viktor Hundahl Strate on 12/02/2019.
//

#include "VertexArray.h"

#include "Rendering.h"

VertexArray::VertexArray(): ID(0) {
    glCall(glGenVertexArrays(1, &ID));
}

VertexArray::~VertexArray() {
    glCall(glDeleteVertexArrays(1, &ID));
}

void VertexArray::addBuffer(VertexBuffer &buffer, const VertexAttribute* attributes, unsigned int attributeCount) {
    this->use();
    buffer.use();

    for(int i = 0; i < attributeCount; i++) {
        VertexAttribute attrib = attributes[i];
        glCall(glVertexAttribPointer(i, attrib.count, attrib.type, attrib.normalized, buffer.stride, (const void*)(attrib.offset)));
        glCall(glEnableVertexAttribArray(i));
    }
}

void VertexArray::use() {
    glCall(glBindVertexArray(ID));
}

// Vertex attribute

VertexAttribute::VertexAttribute(unsigned int count, unsigned int type, unsigned int offset, bool normalized) : count(
        count), type(type), offset(offset), normalized(normalized) {}

unsigned int VertexAttribute::sizeofType() const  {
    switch (type) {
        case GL_FLOAT:
            return sizeof(float);
        default:
            assert(false);
            return 0;
    }
}
