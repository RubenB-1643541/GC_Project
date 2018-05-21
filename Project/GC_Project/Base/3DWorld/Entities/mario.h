#ifndef MARIO_H
#define MARIO_H

#include "ModelData/modelentity.h"

namespace __3DWorld__ {

class Mario : public ModelEntity
{
public:
    Mario(Model * model);
    void update();
    void pick();
private:
    void up();
    void down();
    bool pause();
    int _timer2;
    int _timer;
    int _high, _low, _current;
    bool _up;
    bool _pause;
};

}

#endif // MARIO_H
