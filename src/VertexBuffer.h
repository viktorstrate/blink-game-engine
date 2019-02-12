//
// Created by Viktor Hundahl Strate on 12/02/2019.
//


#pragma once


class VertexBuffer {
public:
    unsigned int ID;
    unsigned int stride;

    VertexBuffer(void* data, unsigned int size, unsigned int stride);

    void use();

    virtual ~VertexBuffer();
};

