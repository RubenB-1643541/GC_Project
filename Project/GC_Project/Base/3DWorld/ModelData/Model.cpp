#include "ModelData/Model.h"

namespace __3DWorld__ {

Model::Model() {

}

void Model::setModelObj(ModelObject *obj) {
    _object = obj;
}

void Model::draw(ShadingMode s_mode, FrameMode f_mode) {
    _object->draw(s_mode, f_mode);
}

}
