#include "modelobject.h"

namespace __3DWorld__ {

ModelObject::ModelObject() {

}

void ModelObject::SetData(QVector<float> *vertices, QVector<float> *normals, QVector<unsigned int> *indices) {
    _vertices = vertices;
    _normals = normals;
    _indices = indices;
}

void ModelObject::SetNode(QSharedPointer<Node> node) {
    _head_node = node;
}

}


