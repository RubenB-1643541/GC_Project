#ifndef STAR_H
#define STAR_H

#include "ModelData/modelentity.h"
#include "ModelData/Model.h"

namespace __3DWorld__ {



class Star : public ModelEntity
{
public:
    Star(Model * model);
    void update();
    void pick();

private:
    bool _activated;
};

}

#endif // STAR_H
