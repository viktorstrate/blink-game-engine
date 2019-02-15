//
// Created by Viktor Hundahl Strate on 15/02/2019.
//

#include "Rendering.h"
#include "Game.h"

#include <iostream>

Game::Game(std::string windowTitle, int windowWidth, int windowHeight)
        : screenWidth(windowWidth), screenHeight(windowHeight)
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // uncomment this statement to fix compilation on OS X
#endif
    glfwWindowHint(GLFW_SAMPLES, 4); // Anti aliasing

    window = glfwCreateWindow(screenWidth, screenHeight, windowTitle.c_str(), NULL, NULL);
    if (window == NULL) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        exit(-1);
    }
    glfwSetWindowUserPointer(window, this);
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        exit(-1);
    }

    glfwSetFramebufferSizeCallback(window, Game::window_resize_callback);
}

Game::~Game()
{
    glfwDestroyWindow(window);
}

void Game::window_resize_callback(GLFWwindow* window, int width, int height)
{
    Game* game = (Game*)glfwGetWindowUserPointer(window);

    glViewport(0, 0, width, height);

    game->screenHeight = width;
    game->screenHeight = height;
}

bool Game::update()
{

    glfwSwapBuffers(window);
    glfwPollEvents();

    return !glfwWindowShouldClose(window);
}