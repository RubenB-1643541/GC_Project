#ifndef MODEL
#define MODEL

#include "ModelData/ModelObject.h"

namespace __3DWorld__ {

/**
 * @author Ruben Ballet
 * @brief
 */
class Model {
public:
    Model();
    Model(ModelObject * obj);
    void setModelObj(ModelObject * obj);
    void draw(GLenum s_mode, GLenum f_mode);
    void move(Point3D position);
    void rotate(float angle, Point3D vertex);
    void scale(float size);


private:
    void setPosition();
    ModelObject * _object;
    GLuint _display_list;
    Point3D _position;
    float _angle;
    Point3D _rotation;
    float _size;


};
}

#endif MODEL
