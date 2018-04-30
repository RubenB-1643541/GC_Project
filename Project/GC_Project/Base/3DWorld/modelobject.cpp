#include "modelobject.h"

namespace __3DWorld__ {

ModelObject::ModelObject() {
    _position = new Point3D();
}

ModelObject::ModelObject(Point3D * position) : _position(position) {

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


