#ifndef RENDERERENTITY_H
#define RENDERERENTITY_H

#include "entity.h"
#include "ModelGroup.h"

namespace __3DWorld__ {

class GroupEntity : public Entity
{
public:
    GroupEntity(ModelGroup * group);
    void update() = 0;

    void moveTo(Point3D position);
    void move(Point3D(direction), int distance);
    void rotateTo(float angle, Point3D rotation);
    void rotate(Point3D rotation, float angle);
    void rotateX(float angle);
    void rotateY(float angle);
    void rotateZ(float angle);
    void sizeTo(float size);
    void scale(float size);
private:
    ModelGroup * _model;
};

}

#endif // RENDERERENTITY_H
