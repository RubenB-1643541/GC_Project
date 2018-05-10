#ifndef MODELGROUP_H
#define MODELGROUP_H

#include "Point3D.h"

namespace __3DWorld__ {

class ModelGroup {
public:
    ModelGroup();

    void translate(Point3D offset);
    void rotate(float angle, Point3D vector);
    void scale(float size);

    Point3D getTranslation() { return _position; }
    Point3D getRotation() {return Point3D(_angle_x, _angle_y, _angle_z);}
    float getSize() {return _size;}

private:
    Point3D _position;
    float _angle_x;
    float _angle_y;
    float _angle_z;
    float _size;
};

}

#endif // MODELGROUP_H
