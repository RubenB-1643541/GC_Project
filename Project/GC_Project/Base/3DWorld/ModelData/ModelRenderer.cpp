#include "ModelRenderer.h"

namespace __3DWorld__ {

ModelRenderer::ModelRenderer(Model* model) {
    _model = model;
    _is_active = false;
}
void ModelRenderer::draw(GLenum s_mode, GLenum f_mode) {
    glPushMatrix();

    GLfloat diffuse_color[] = { 1.0f, 1.0f, 1.0f, 1.0f }; // Green
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_color);
    glMateriali(GL_FRONT, GL_SHININESS, 0);


    glShadeModel(s_mode);                       // Type of shader (flat, smooth)
    glPolygonMode(GL_FRONT_AND_BACK, f_mode);   // Type of frame (wirefram, filled)

    Point3D t = _model->getTranslation();
    glTranslatef(t.x(), t.y(), t.z());
    Point3D r = _model->getRotation();
    glRotatef(r.x(), 1, 0, 0); // rotate around x with angle x()
    glRotatef(r.y(), 0, 1, 0); // rotate around y with angle y()
    glRotatef(r.z(), 0, 0, 1); // rotate around z with angel z()
    float s = _model->getSize();
    glScalef(s, s, s);

    if (_model->_texture_id > 0) {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, _model->_texture_id);
    }

    glCallList(_model->index);

    glPopMatrix();
}
void ModelRenderer::onPick() {
    _model->setPicked(true);
}

}

