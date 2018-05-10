#ifndef MODEL
#define MODEL

#include "modelloader.h"

#include <windows.h>
#include <gl/GL.h>

namespace __3DWorld__ {

/**
 * @author Ruben Ballet
 * @brief
 */
class Model {
public:
    Model(GLuint list_index);
    Model(GLuint list_index, GLuint texture_id);

    std::vector<MLMesh> getMeshes() const;

    void translate(Point3D offset);
    void rotate(float angle, Point3D vector);
    void scale(float size);

    Point3D getTranslation() { return _position; }
    Point3D getRotation() {return Point3D(_angle_x, _angle_y, _angle_z);}
    float getSize() {return _size;}

    GLuint index;
    GLuint _texture_id;
    GLuint _picking_id;
private:
    GLuint _display_list;
    Point3D _position;
    float _angle_x;
    float _angle_y;
    float _angle_z;
    float _size;

    std::vector<MLMesh> _meshes;
};
}

#endif MODEL
