#ifndef MODELOBJECT_H
#define MODELOBJECT_H

#include <QVector3D>
#include "Model/modeldata.h"

namespace __3DWorld__ {

class ModelObject {
public:
    ModelObject();
    ModelObject(QVector<float> *vertices, QVector<float> * normals, QVector<unsigned int> *indices);
    void SetData(QVector<float> *vertices, QVector<float> * normals, QVector<unsigned int> *indices);
    void SetNode(QSharedPointer<Node> node);
    QSharedPointer<Node> GetNode() {return _head_node;}
    QVector<float> * GetVertices() {return _vertices;}
    QVector<float> * GetNormals() {return _normals;}
    QVector<unsigned int> * GetIndices() {return _indices;}
private:
    QVector<float> * _vertices;
    QVector<float> * _normals;
    QVector<unsigned int> * _indices;
    QSharedPointer<Node> _head_node;
};

}


#endif // MODELOBJECT_H
