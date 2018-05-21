#include "ModelData/Model.h"

namespace __3DWorld__ {

Model::Model(GLuint list_index) {
    index = list_index;
    _texture_id = -1;
    _position = Point3D(0, 0, 0);
    _angle_x = 0;
    _angle_y = 0;
    _angle_z = 0;
    _size = 1;
    _picked = false;
}
Model::Model(GLuint list_index, GLuint texture_id) {
    index = list_index;
    _texture_id = texture_id;
    _position = Point3D(0, 0, 0);
    _angle_x = 0;
    _angle_y = 0;
    _angle_z = 0;
    _size = 1;
    _picked = false;
}

std::vector<MLMesh> Model::getMeshes() const {
    return _meshes;
}

void Model::translate(Point3D offset) {
    _position = offset;
}

void Model::rotate(float angle, Point3D vector) {
    _angle_x += vector.x() * angle;
    _angle_y += vector.y() * angle;
    _angle_z += vector.z() * angle;
}

void Model::scale(float size) {
    _size = size;
}

void Model::togglePick() {
    _picked = !_picked;
}

}
