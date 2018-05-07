#include "ModelData/Model.h"

namespace __3DWorld__ {

Model::Model() {
    _position = Point3D(0, 0, 0);
    _angle_x = 0;
    _angle_y = 0;
    _angle_z = 0;
    _size = 1;
    _type = STATIC;
    _texture = new Texture();
    _texture->addTexture("Images/basic_orange.png");
    _texture->initialize();
}

Model::Model(TYPE type) {
    Model::Model();
    _type = type;
}

Model::Model(ModelObject *obj, TYPE type) {
    Model::Model();
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
    _texture->use();
    _object->draw(s_mode, f_mode);

    glPopMatrix();
}

void Model::move(Point3D position) {
    _position = position;
}

void Model::rotate(float angle, Point3D vertex) {
    _angle_x = vertex.x() * angle;
    _angle_y = vertex.y() * angle;
    _angle_z = vertex.z() * angle;
}

void Model::scale(float size) {
    _size = size;
}

void Model::setPosition() {
    glTranslatef(_position.x(), _position.y(), _position.z());
    //rotate x
    glRotatef(_angle_x, 1, 0, 0);
    //rotate y
    glRotatef(_angle_y, 0, 1, 0);
    //rotate z
    glRotatef(_angle_z, 0, 0, 1);
    glScalef(_size, _size, _size);
}

}
