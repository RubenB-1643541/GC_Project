#include "modelloader.h"
#include <QDebug>

namespace __3DWorld__ {

ModelLoader::ModelLoader()
{

}

void ModelLoader::load(std::string path) {
    Assimp::Importer import;
        const aiScene *scene = import.ReadFile(
            path,
            aiProcess_Triangulate | // Build object from triangles
            aiProcess_FlipUVs |
            aiProcess_GenNormals    // Generate vertex normals
        );

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
    // process child nodes
    for(unsigned int i = 0; i < node->mNumChildren; i++) {
        processNode(node->mChildren[i], scene);
    }
}
MLMesh ModelLoader::processMesh(aiMesh *mesh, const aiScene *scene)
{
    MLMesh new_mesh;

    new_mesh.num_vertices = mesh->mNumVertices;
    std::vector<MLVertex> vertices;
    std::vector<MLVertex> normals;

    for (unsigned int i = 0; i < mesh->mNumVertices; i++) {
        MLVertex vertex;

        // Get Vertex
        vertex.position.setX(mesh->mVertices[i].x);
        vertex.position.setY(mesh->mVertices[i].y);
        vertex.position.setZ(mesh->mVertices[i].z);  

        // Get normal for vertex
        if (mesh->HasNormals()) {
            vertex.normal.setX(mesh->mNormals[i].x);
            vertex.normal.setY(mesh->mNormals[i].y);
            vertex.normal.setZ(mesh->mNormals[i].z);
        }
        vertices.push_back(vertex);
    }
    new_mesh.vertices = vertices;

    new_mesh.num_faces = mesh->mNumFaces;
    std::vector<unsigned int> indices;

    // Get vertex draw order
    for (unsigned int i = 0; i < mesh->mNumFaces; i++) {
        aiFace face = mesh->mFaces[i];
        for (unsigned int j = 0; j < face.mNumIndices; j++) {
            indices.push_back(face.mIndices[j]);
        }
    }

    new_mesh.indices = indices;

    return new_mesh;
}

}
