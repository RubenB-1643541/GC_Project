#include "groupentity.h"

namespace __3DWorld__ {


GroupEntity::GroupEntity(ModelGroup * group) {
    _model = group;
}

void GroupEntity::moveTo(Point3D position) {

    _model->translate(position);

}

void GroupEntity::move(Point3D direction, int distance) {

    Point3D current = _model->getTranslation();
    float x = current.x() + direction.x() * distance;
    float y = current.y() + direction.y() * distance;
    float z = current.z() + direction.z() * distance;
    _model->translate(Point3D(x, y, z));
}

void GroupEntity::rotateTo(float angle, Point3D rotation) {

    _model->rotate(angle, rotation);

}

void GroupEntity::rotate(Point3D rotation, float angle) {

    Point3D current = _model->getRotation();
    //X
    _model->rotate(angle + current.x(), rotation);

}

void GroupEntity::rotateX(float angle) {

    Point3D current = _model->getRotation();
    _model->rotate(angle + current.x(), Point3D(1,0,0));

}

void GroupEntity::rotateY(float angle) {

    Point3D current = _model->getRotation();
    _model->rotate(angle + current.y(), Point3D(0,1,0));

}

void GroupEntity::rotateZ(float angle) {

    Point3D current = _model->getRotation();
    _model->rotate(angle + current.z(), Point3D(0,0,1));

}

void GroupEntity::sizeTo(float size) {

    _model->scale(size);

}

void GroupEntity::scale(float size) {

    float current = _model->getSize();
    sizeTo(current * size);

}


}
