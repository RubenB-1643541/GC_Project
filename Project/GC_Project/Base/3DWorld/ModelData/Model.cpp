#include "ModelData/Model.h"

namespace __3DWorld__ {

Model::Model() {
    _position = Point3D(0, 0, 0);
    _angle = 0;
    _rotation = Point3D(0, 0, 0);
    _size = 1;
    _type = STATIC;
}

Model::Model(TYPE type) {
    _type = type;
}

Model::Model(ModelObject *obj, TYPE type) {
    setModelObj(obj);
    _type = type;
}

void Model::setModelObj(ModelObject *obj) {
    _object = obj;

}

void Model::draw(GLenum s_mode, GLenum f_mode) {

    glPushMatrix();
    setPosition();
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

void Model::move(Point3D position) {
    _position = position;


}

void Model::rotate(float angle, Point3D vertex) {
    _angle = angle;
    _rotation = vertex;
}

void Model::scale(float size) {
    _size = size;
}

void Model::setPosition() {
    glTranslatef(_position.x(), _position.y(), _position.z());
    glRotatef(_angle, _rotation.x(), _rotation.y(), _rotation.z());
    glScalef(_size, _size, _size);
}

}
