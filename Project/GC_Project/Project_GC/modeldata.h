#ifndef MODELDATA_H
#define MODELDATA_H

#include <QString>
#include <QVector3D>
#include <QVector4D>
#include <QSharedPointer>
#include <QMatrix4x4>

struct MaterialInfo {
    QString name;
    QVector3D ambient;
    QVector3D diffuse;
    QVector3D specular;
    float shininess;
};

struct LightInfo {
    QVector4D position;
    QVector3D intensity;
};

struct Mesh {
    QString name;
    unsigned int indexCount;
    unsigned int indexOffset;
    QSharedPointer<MaterialInfo> material;
};

struct Node
{
    QString name;
    QMatrix4x4 transformation;
    QVector<QSharedPointer<Mesh> > meshes;
    QVector<Node> nodes;
};



#endif // MODELDATA_H
