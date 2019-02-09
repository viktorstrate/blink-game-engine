//
// Created by Viktor Hundahl Strate on 09/02/2019.
//


#pragma once

#include <vector>
#include <string>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "Shader.h"
#include "Mesh.h"

class Model {
public:
    Model(char* path) {
        loadModel(path);
    }

    void Draw(Shader shader);

private:
    /*  Model Data  */
    std::vector<Mesh> meshes;
    std::string directory;
    std::vector<Texture> textures_loaded;

    /*  Functions   */
    void loadModel(std::string path);

    void processNode(aiNode* node, const aiScene* scene);

    Mesh processMesh(aiMesh* mesh, const aiScene* scene);

    std::vector <Texture> loadMaterialTextures(aiMaterial* mat, aiTextureType type,
                                               std::string typeName);
};

