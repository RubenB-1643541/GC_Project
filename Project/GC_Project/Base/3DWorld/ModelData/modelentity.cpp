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

void ModelEntity::rotateTo(float angle, Point3D rotation) {
    _model->rotate(angle, rotation);
}

void ModelEntity::sizeTo(float size) {
    _model->scale(size);
}


}
