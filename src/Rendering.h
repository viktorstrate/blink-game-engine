//
// Created by Viktor Hundahl Strate on 12/02/2019.
//

#pragma once

#include <glad/glad.h>

#include <assert.h>
#define glCall(x) GLClearError(); \
    x; assert(GLLogCall(#x, __FILE__, __LINE__))

void GLClearError();

bool GLLogCall(const char* function, const char* file, int line);
