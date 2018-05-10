#include "ModelGroup.h"

namespace __3DWorld__ {

ModelGroup::ModelGroup() {
    _position = Point3D(0, 0, 0);
    _angle_x = 0;
    _angle_y = 0;
    _angle_z = 0;
    _size = 1;
}

void ModelGroup::translate(Point3D offset) {
    _position = offset;
}

void ModelGroup::rotate(float angle, Point3D vector) {
    _angle_x += vector.x() * angle;
    _angle_y += vector.y() * angle;
    _angle_z += vector.z() * angle;
}

void ModelGroup::scale(float size) {
    _size = size;
}

}


