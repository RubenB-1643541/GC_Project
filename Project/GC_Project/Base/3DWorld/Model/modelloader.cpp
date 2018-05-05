#include "modelloader.h"
#include <QDebug>

namespace __3DWorld__ {

ModelLoader::ModelLoader()
{

}

void ModelLoader::load(std::string path) {
    Assimp::Importer import;
        const aiScene *scene = import.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs);

        if(!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
        {
            qDebug() << "ERROR::ASSIMP::" << import.GetErrorString();
            return;
        }

        processNode(scene->mRootNode, scene);
}
void ModelLoader::processNode(aiNode *node, const aiScene *scene)
{
    // process all the node's meshes (if any)
    for(unsigned int i = 0; i < node->mNumMeshes; i++) {
        aiMesh *mesh = scene->mMeshes[node->mMeshes[i]];
        _meshes.push_back(processMesh(mesh, scene));
    }
    // then do the same for each of its children
    for(unsigned int i = 0; i < node->mNumChildren; i++) {
        processNode(node->mChildren[i], scene);
    }
}
MLMesh ModelLoader::processMesh(aiMesh *mesh, const aiScene *scene)
{
    MLMesh new_mesh;
    new_mesh.num_vertices = mesh->mNumVertices;

    std::vector<MLVertex> vertices;

    for(unsigned int i = 0; i < mesh->mNumVertices; i++)
    {
        MLVertex vertex;
        vertex.position.setX(mesh->mVertices[i].x);
        vertex.position.setY(mesh->mVertices[i].y);
        vertex.position.setZ(mesh->mVertices[i].z);

        vertices.push_back(vertex);
    }
    new_mesh.vertices = vertices;


    return new_mesh;
}

}
