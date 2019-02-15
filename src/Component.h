//
// Created by Viktor Hundahl Strate on 15/02/2019.
//


#pragma once

//#define MAX_COMPONENTS 3
//
//#define COMPONENT_TRANSFORM 0
//#define COMPONENT_MODEL 1
//#define COMPONENT_CAMERA 1

typedef unsigned long ComponentMask;

class Component
{
public:
    virtual ~Component() = default;
};