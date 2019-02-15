//
// Created by Viktor Hundahl Strate on 14/02/2019.
//

#pragma once

#include "Rendering.h"

class Texture
{
public:
    unsigned int ID;

    Texture(unsigned int width, unsigned int height, GLenum format = GL_RGB, void* data = nullptr);

    explicit Texture(const char* path);

    ~Texture();

    void use(unsigned int activeTex = 0);

    void setWrap(int sWrap, int tWrap);

    void setFilter(int min, int max);
};

