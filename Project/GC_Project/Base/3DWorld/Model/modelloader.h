#ifndef MODELLOADER_H
#define MODELLOADER_H

#include "modeldata.h"
#include "modelobject.h"
#include <QString>
#include <QVector>
#include <QMatrix4x4>
#include <assimp/material.h>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <assimp/Importer.hpp>

using namespace __3DWorld__;

class ModelLoader
{
public:
    ModelLoader();
    bool Load(QString pathToFile);
    void GetBufferData(QVector<float> **vertices, QVector<float> ** normals, QVector<unsigned int> **indices);
    ModelObject * GetBufferData(ModelObject * obj);
    ModelObject * GetNodeData(ModelObject * obj);
    QSharedPointer<Node> GetNodeData() {return m_rootNode;}

private:
    QSharedPointer<MaterialInfo> ProcessMaterial(aiMaterial *mater);
    QSharedPointer<Mesh> ProcessMesh(aiMesh *mesh);
    void ProcessNode(const aiScene *scene, aiNode *node, Node *parentNode, Node &newNode);

    void TransformToUnitCoordinates();
    void FindObjectDimensions(Node *node, QMatrix4x4 transformation, QVector3D &minDimension, QVector3D &maxDimension);

    QVector<float> m_vertices;
    QVector<float> m_normals;
    QVector<unsigned int> m_indices;

    QVector<QSharedPointer<MaterialInfo> > m_materials;
    QVector<QSharedPointer<Mesh> > m_meshes;
    QSharedPointer<Node> m_rootNode;

};

#endif // MODELLOADER_H
