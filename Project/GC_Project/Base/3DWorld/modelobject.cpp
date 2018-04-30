#include "modelobject.h"

namespace __3DWorld__ {

ModelObject::ModelObject() {
    _position = new Point3D();
    _rotation = new Point3D();
    _size = 1;
}

ModelObject::ModelObject(Point3D * position) : _position(position) {
    _rotation = new Point3D();
    _size = 1;
}

ModelObject::ModelObject(Point3D * position, Point3D * rotation) :
    _position(position), _rotation(rotation) {
    _size = 1;

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


