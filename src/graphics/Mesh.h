//
// Created by Viktor Hundahl Strate on 09/02/2019.
//


#pragma once

#include <vector>
#include <string>

#include "graphics/Shader.h"
#include "graphics/Texture.h"

struct MeshVertex
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
    std::vector<MeshVertex> vertices;
    std::vector<unsigned int> indices;
    std::vector<MeshTexture> textures;

    Mesh(const std::vector<MeshVertex> &vertices, const std::vector<unsigned int> &indices,
         const std::vector<MeshTexture> &textures);

    void Draw(Shader shader);

private:
    unsigned int VAO, VBO, EBO;

    void setupMesh();
};

