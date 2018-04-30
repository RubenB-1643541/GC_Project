#ifndef MODELOBJECT_H
#define MODELOBJECT_H

#include <QVector3D>
#include "Model/modeldata.h"
#include "Point3D.h"

namespace __3DWorld__ {

class ModelObject {
public:
    ModelObject();
    ModelObject(Point3D * position);
    ModelObject(Point3D * position, Point3D * rotation);
    ModelObject(QVector<float> *vertices, QVector<float> * normals, QVector<unsigned int> *indices);
    void SetData(QVector<float> *vertices, QVector<float> * normals, QVector<unsigned int> *indices);
    void SetNode(QSharedPointer<Node> node);
    QSharedPointer<Node> GetNode() {return _head_node;}
    QVector<float> * GetVertices() {return _vertices;}
    QVector<float> * GetNormals() {return _normals;}
    QVector<unsigned int> * GetIndices() {return _indices;}
    void SetPosition(Point3D * position) { _position = position;}
    Point3D * GetPosition() {return _position;}
    void SetRotation(Point3D * rotation) {_rotation = rotation;}
    Point3D * GetRotation() {return _rotation;}
    void SetSize(float size) {_size = size;}
    float GetSize() {return _size;}
private:
    QVector<float> * _vertices;
    QVector<float> * _normals;
    QVector<unsigned int> * _indices;
    QSharedPointer<Node> _head_node;
    Point3D * _position;
    Point3D * _rotation;
    float _size;
};

}


#endif // MODELOBJECT_H
