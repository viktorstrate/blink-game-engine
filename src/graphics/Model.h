//
// Created by Viktor Hundahl Strate on 09/02/2019.
//


#pragma once

#include <vector>
#include <string>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "graphics/Shader.h"
#include "Mesh.h"

class Model
{
public:
    Model();

    Model(const std::string &path);

    void Draw(Shader shader);

    virtual ~Model();

    void loadModel(std::string path);


private:
    std::vector<Mesh> meshes;
    std::string directory;
    std::vector<MeshTexture> textures_loaded;
    bool modelLoaded;

    void processNode(aiNode* node, const aiScene* scene);

    Mesh processMesh(aiMesh* mesh, const aiScene* scene);

    std::vector<MeshTexture> loadMaterialTextures(aiMaterial* mat, aiTextureType type,
                                                  std::string typeName);
};

