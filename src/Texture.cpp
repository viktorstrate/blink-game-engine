//
// Created by Viktor Hundahl Strate on 14/02/2019.
//

#include "Texture.h"

#include <stb_image.h>
#include <iostream>

Texture::Texture(unsigned int width, unsigned int height, GLenum format, void* data)
{
    glCall(glGenTextures(1, &ID));
    glCall(glBindTexture(GL_TEXTURE_2D, ID));
    glCall(glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data));
    glCall(glGenerateMipmap(GL_TEXTURE_2D));
}

Texture::Texture(const char* path)
{
    glCall(glGenTextures(1, &ID));

    int width, height, nrComponents;
    unsigned char* data = stbi_load(path, &width, &height, &nrComponents, 0);
    if (data) {
        GLenum format = GL_RGB;
        if (nrComponents == 1)
            format = GL_RED;
        else if (nrComponents == 3)
            format = GL_RGB;
        else if (nrComponents == 4)
            format = GL_RGBA;

        glCall(glBindTexture(GL_TEXTURE_2D, ID));
        glCall(glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data));
        glCall(glGenerateMipmap(GL_TEXTURE_2D));

        this->setWrap(GL_REPEAT, GL_REPEAT);
        this->setFilter(GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);

        stbi_image_free(data);
    } else {
        std::cout << "Texture failed to load at path: " << path << std::endl;
        stbi_image_free(data);
    }
}

Texture::~Texture()
{
    glCall(glDeleteTextures(1, &ID));
}

void Texture::use(unsigned int activeTex)
{
    glCall(glActiveTexture(GL_TEXTURE0 + activeTex));
    glCall(glBindTexture(GL_TEXTURE_2D, ID));
}

void Texture::setWrap(int sWrap, int tWrap)
{
    glCall(glBindTexture(GL_TEXTURE_2D, ID));
    glCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, sWrap));
    glCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, tWrap));
}

void Texture::setFilter(int min, int max)
{
    glCall(glBindTexture(GL_TEXTURE_2D, ID));
    glCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, min));
    glCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, max));
}
