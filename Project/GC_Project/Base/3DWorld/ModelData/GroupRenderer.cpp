#include "GroupRenderer.h"

namespace __3DWorld__ {

GroupRenderer::GroupRenderer(ModelGroup* group) {
    _group = group;
    _is_active = false;
}

void GroupRenderer::draw(GLenum s_mode, GLenum f_mode) {
    if (_model_renderers.empty()) {
        return;
    }
    glPushMatrix();

    // Group Transformations
    // Group Transformation need to happen after individual tranformations
    Point3D t = _group->getTranslation();
    glTranslatef(t.x(), t.y(), t.z());
    Point3D r = _group->getRotation();
    glRotatef(r.x(), 1, 0, 0); // rotate around x with angle x()
    glRotatef(r.y(), 0, 1, 0); // rotate around y with angle y()
    glRotatef(r.z(), 0, 0, 1); // rotate around z with angel z()
    float s = _group->getSize();
    glScalef(s, s, s);

    // Draw Models
    for (ModelRenderer* renderer : _model_renderers) {
        renderer->draw(s_mode, f_mode);
    }



    glPopMatrix();
}

void GroupRenderer::onPick() {
    _is_active = !_is_active;
}

void GroupRenderer::addModelRenderer(ModelRenderer *model_renderer) {
    _model_renderers.push_back(model_renderer);
}

}
