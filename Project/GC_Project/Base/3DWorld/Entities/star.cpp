#include "star.h"

namespace __3DWorld__ {



Star::Star(Model * model) : ModelEntity(model)
{
    _activated = false;
}

void Star::update() {
    if(selected()) {
        pick();
    }
    if(_activated) {
        move(Point3D(0,1,0), 1);
        move(Point3D(1,0,0),1);
    }
}

void Star::pick() {
    _activated = true;
}

}