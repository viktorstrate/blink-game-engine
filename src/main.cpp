//
// Created by Viktor Hundahl Strate on 2019-02-03.
//

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>
#include <vector>
#include <math.h>
#include <stb_image.h>

#include "Shader.h"
#include "Camera.h"

int screenWidth, screenHeight;

Camera camera = Camera(glm::vec3(0, 0, 5));

bool firstMouse = true;
float lastMouseX = 0, lastMouseY = 0;

float deltaTime = 0.0f;    // Time between current frame and last frame
float lastFrame = 0.0f; // Time of last frame

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);

    screenWidth = width;
    screenHeight = height;
}

void processInput(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    float forwards = 0, sideways = 0, up = 0;

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        forwards += -1;
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        forwards += 1;

    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        sideways += -1;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        sideways += 1;

    if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
        up += -1;
    if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
        up += 1;

    camera.ProcessKeyboard(forwards, sideways, up, deltaTime);
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos) {

    if (firstMouse) {
        firstMouse = false;
        lastMouseX = xpos;
        lastMouseY = ypos;
    }

    float xoffset = (float) (xpos - lastMouseX);
    float yoffset = (float) (lastMouseY - ypos); // reversed since y-coordinates range from bottom to top
    lastMouseX = (float) xpos;
    lastMouseY = (float) ypos;

    camera.ProcessMouseMovement(xoffset, yoffset);
}


void scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
    camera.ProcessMouseScroll(yoffset);
}


int main(int argc, char** argv) {

    screenWidth = 800;
    screenHeight = 600;

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // uncomment this statement to fix compilation on OS X
#endif

    GLFWwindow* window = glfwCreateWindow(screenWidth, screenHeight, "LearnOpenGL", NULL, NULL);
    if (window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);

    // Window resize callback
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    Shader program = Shader("assets/shaders/textured-flat.glsl");
    program.use();

    program.setInt("texture1", 0);
    program.setInt("texture2", 1);

    // Verticies that make up a cube + normals
    float vertices[] = {
            -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
            0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
            0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
            0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
            -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
            -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,

            -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
            0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
            0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
            0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
            -0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
            -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,

            -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
            -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
            -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
            -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
            -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
            -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,

            0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
            0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
            0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
            0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
            0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
            0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,

            -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
            0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
            0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
            0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
            -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
            -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,

            -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
            0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
            0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
            0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
            -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
            -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f
    };


    Shader lampShader("assets/shaders/lamp.glsl");

    Shader lightingShader("assets/shaders/color-light.glsl");

    lightingShader.use();
    lightingShader.setVec3("objectColor", 1.0f, 0.5f, 0.31f);
    lightingShader.setVec3("lightColor",  1.0f, 1.0f, 1.0f);

    unsigned int VBO;

    // Setup the vertex buffer
    glGenBuffers(1, &VBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    unsigned int lampVAO, cubeVAO;

    // Setup lamp vertex array
    glGenVertexArrays(1, &lampVAO);
    glBindVertexArray(lampVAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6*sizeof(float), (void*) 0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6*sizeof(float), (void*) (3*sizeof(float)));
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    // Setup cube vertex array
    glGenVertexArrays(1, &cubeVAO);
    glBindVertexArray(cubeVAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6*sizeof(float), (void*) 0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6*sizeof(float), (void*) (3*sizeof(float)));
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    // Unbind vertex buffer and vertex array
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    // Wireframe mode
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    glEnable(GL_DEPTH_TEST);

    while (!glfwWindowShouldClose(window)) {

        float currentFrame = (float) glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        processInput(window);

        glm::mat4 view = camera.GetViewMatrix();

        glm::mat4 projection;
        projection = glm::perspective(glm::radians(camera.FOV), (float) screenWidth/(float) screenHeight, 0.1f, 100.0f);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Draw lamp
        lampShader.use();

        lampShader.setMat4("view", view);
        lampShader.setMat4("projection", projection);

        float lampX = cosf(glfwGetTime()) * 3.0f;
        float lampZ = sinf(glfwGetTime()) * 3.0f;
        glm::vec3 lightPos = glm::vec3(lampX, 2.0f, lampZ);

        {
            glm::mat4 model = glm::mat4(1.0f);

            model = glm::translate(model, lightPos);
            model = glm::scale(model, glm::vec3(0.2f));

            lampShader.setMat4("model", model);

            glBindVertexArray(lampVAO);
            glDrawArrays(GL_TRIANGLES, 0, 36);
        }

        // Draw cube
        lightingShader.use();

        lightingShader.setMat4("view", view);
        lightingShader.setMat4("projection", projection);
        lightingShader.setVec3("lightPos", lightPos);
        lightingShader.setVec3("viewPos", camera.Position);

        lightingShader.setVec3("material.ambient",  1.0f, 0.5f, 0.31f);
        lightingShader.setVec3("material.diffuse",  1.0f, 0.5f, 0.31f);
        lightingShader.setVec3("material.specular", 0.5f, 0.5f, 0.5f);
        lightingShader.setFloat("material.shininess", 32.0f);

        lightingShader.setVec3("light.ambient",  0.2f, 0.2f, 0.2f);
        lightingShader.setVec3("light.diffuse",  0.5f, 0.5f, 0.5f); // darken the light a bit to fit the scene
        lightingShader.setVec3("light.specular", 1.0f, 1.0f, 1.0f);
        lightingShader.setVec3("light.position", lightPos);

        {
            glm::mat4 model = glm::mat4(1.0f);
//            model = glm::rotate(model, glm::radians(33.0f), glm::vec3(0.8f, 0.2f, 0.0f));

            lightingShader.setMat4("model", model);

            glBindVertexArray(lampVAO);
            glDrawArrays(GL_TRIANGLES, 0, 36);
        }

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &lampVAO);
    glDeleteVertexArrays(1, &cubeVAO);
    glDeleteBuffers(1, &VBO);

    glfwTerminate();
    return 0;
}
