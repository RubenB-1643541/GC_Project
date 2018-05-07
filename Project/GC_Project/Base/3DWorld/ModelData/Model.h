#ifndef MODEL
#define MODEL

#include "ModelData/ModelObject.h"
#include "modelentity.h"
#include "ModelData/texture.h"

namespace __3DWorld__ {

/**
 * @author Ruben Ballet
 * @brief
 */

enum TYPE {STATIC, DYNAMIC};

class Model {
public:
    Model();
    Model(TYPE type);
    Model(ModelObject * obj, TYPE type);
    void setModelObj(ModelObject * obj);
    void draw(GLenum s_mode, GLenum f_mode);
    void move(Point3D position);
    void rotate(float angle, Point3D vertex);
    void scale(float size);
    Point3D getPosition() {return _position;}
    Point3D getRotation() {return Point3D(_angle_x, _angle_y, _angle_z);}
    float getSize() {return _size;}
private:

    void setPosition();
    ModelObject * _object;
    GLuint _display_list;
    Point3D _position;
    float _angle_x;
    float _angle_y;
    float _angle_z;
    float _size;
    TYPE _type;
    Texture * _texture;


};
}

#endif MODEL
