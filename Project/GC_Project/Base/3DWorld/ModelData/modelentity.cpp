#include "ModelData/modelentity.h"
#include "Model.h"
//Yhae include in de cpp ModelEntity en Model hebben elkaar nodig


namespace __3DWorld__ {

ModelEntity::ModelEntity(Model *model) {
    _model = model;
}

void ModelEntity::moveTo(Point3D position) {
    _model->move(position);
}

void ModelEntity::move(Point3D direction, int distance) {
    Point3D current = _model->getPosition();
    float x = current.x() + direction.x() * distance;
    float y = current.y() + direction.y() * distance;
    float z = current.z() + direction.z() * distance;
    _model->move(Point3D(x, y, z));
}

void ModelEntity::rotateTo(float angle, Point3D rotation) {
    _model->rotate(angle, rotation);
}

void ModelEntity::sizeTo(float size) {
    _model->scale(size);
}


}
