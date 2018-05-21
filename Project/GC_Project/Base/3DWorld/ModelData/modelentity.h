#ifndef MODELENTITY_H
#define MODELENTITY_H

#include "Point3D.h"

namespace __3DWorld__ {
class Model;
class ModelEntity {
public:
    ModelEntity(Model * model);
    virtual void update() = 0;
    virtual void pick() = 0;
    void moveTo(Point3D position);
    void move(Point3D(direction), int distance);
    void rotateTo(float angle, Point3D rotation);
    void rotate(Point3D rotation, float angle);
    void rotateX(float angle);
    void rotateY(float angle);
    void rotateZ(float angle);
    void sizeTo(float size);
    void scale(float size);
    bool selected();

private:
    Model * _model;
};


}



#endif // MODELENTITY_H
