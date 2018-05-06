#ifndef MODELENTITY_H
#define MODELENTITY_H

#include "Point3D.h"

namespace __3DWorld__ {
class Model;
class ModelEntity {
public:
    ModelEntity(Model * model);
    virtual void update() = 0;
    void moveTo(Point3D position);
    void move(Point3D(direction), int distance);
    void rotateTo(float angle, Point3D rotation);
    void sizeTo(float size);

private:
    Model * _model;
};


}



#endif // MODELENTITY_H
