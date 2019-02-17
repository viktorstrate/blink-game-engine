//
// Created by Viktor Hundahl Strate on 15/02/2019.
//


#pragma once

#include <GLFW/glfw3.h>
#include <string>
#include "systems/DynamicSystem.h"

class Game
{
public:

    Game(std::string windowTitle, unsigned int windowWidth, unsigned int windowHeight);

    virtual ~Game();

    bool update();

    GLFWwindow* window;
    unsigned int screenWidth, screenHeight;

    double deltaTime() const;

    World* getActiveWorld() const;

    void setActiveWorld(World* activeWorld);

private:
    double dt;
    double lastFrame;
    double fixedUpdateTime;

    World* activeWorld;

    static void window_resize_callback(GLFWwindow* window, int width, int height);

    static void mouseMoveCallback(GLFWwindow* window, double xpos, double ypos);
    static void mouseScrollCallback(GLFWwindow* window, double xoffset, double yoffset);
};

