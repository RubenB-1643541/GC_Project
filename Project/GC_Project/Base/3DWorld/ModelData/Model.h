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
    void move(Point3D);


private:
    ModelObject * _object;
    GLuint _display_list;


};
}

#endif MODEL
