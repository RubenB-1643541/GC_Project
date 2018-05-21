#ifndef THWOP_H
#define THWOP_H

#include "ModelData/modelentity.h"
#include "Point3D.h"

namespace __3DWorld__ {

class Thwomp : public ModelEntity
{
public:
    Thwomp(Model * model);
    void update();
    void pick();
private:
    void up();
    void down();
    int _timer;
    int _high, _low, _current;
    bool _up;
    bool _disappear;
};

}

#endif // THWOP_H
