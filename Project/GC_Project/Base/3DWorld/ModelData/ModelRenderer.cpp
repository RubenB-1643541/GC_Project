#include "ModelData/ModelRenderer.h"

namespace __3DWorld__ {

ModelRenderer::ModelRenderer() {

}

ModelRenderer::ModelRenderer(ModelObject *model) {
    setModelObj(model);
}

void ModelRenderer::setModelObj(ModelObject *model) {
    if(_model == NULL) {
        _model = new Model();
    }
    _model->setModelObj(model);
}

void ModelRenderer::draw(GLenum s_mode, GLenum f_mode) {
    _model->draw(s_mode, f_mode);
}

}
