//
// Created by Viktor Hundahl Strate on 09/02/2019.
//


#pragma once

#include <vector>
#include <string>

#include "Shader.h"
#include "Texture.h"

struct Vertex
{
    glm::vec3 Position;
    glm::vec3 Normal;
    glm::vec2 TexCoords;
};

struct MeshTexture
{
    Texture* texture;
    std::string type;
    std::string path;
};

class Mesh
{
public:
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;
    std::vector<MeshTexture> textures;

    Mesh(const std::vector<Vertex> &vertices, const std::vector<unsigned int> &indices,
         const std::vector<MeshTexture> &textures);

    void Draw(Shader shader);

private:
    unsigned int VAO, VBO, EBO;

    void setupMesh();
};

