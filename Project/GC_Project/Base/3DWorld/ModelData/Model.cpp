#include "ModelData/Model.h"

namespace __3DWorld__ {

Model::Model() {

}

void Model::setModelObj(ModelObject *obj) {
    _object = obj;

}

void Model::draw(GLenum s_mode, GLenum f_mode) {

    glPushMatrix();
    glMateriali(GL_FRONT, GL_SHININESS, 20);

    glShadeModel(s_mode);                       // Type of shader (flat, smooth)
    glPolygonMode(GL_FRONT_AND_BACK, f_mode);   // Type of frame (wirefram, filled)

    //if(_display_list == NULL) {
    //    _display_list = _object->initialize();
    //}
    //glCallList(_display_list);

    _object->draw(s_mode, f_mode);

    glPopMatrix();
}

void Model::move(Point3D point) {
    glMatrixMode(GL_PROJECTION);
    glTranslatef(point.x(), point.y(), point.z());

}

}
