#include "ModelData/ModelRenderer.h"

namespace __3DWorld__ {

ModelRenderer::ModelRenderer() {

}

ModelRenderer::ModelRenderer(ModelObject *model) {
    setModelObj(model);
}

ModelRenderer::ModelRenderer(Model *model) {
    _model = model;
}

void ModelRenderer::setModelObj(ModelObject *model) {
    if(_model == NULL) {
        _model = new Model();
    }
    _model->setModelObj(model);
}

void ModelRenderer::draw(GLenum s_mode, GLenum f_mode) {
    glPushMatrix();

    glMateriali(GL_FRONT, GL_SHININESS, 20);

    glShadeModel(s_mode);                       // Type of shader (flat, smooth)
    glPolygonMode(GL_FRONT_AND_BACK, f_mode);   // Type of frame (wirefram, filled)

    _model->draw();

    glPopMatrix();
}

}
