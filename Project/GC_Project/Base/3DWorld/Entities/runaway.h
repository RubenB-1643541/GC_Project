#ifndef RUNAWAY_H
#define RUNAWAY_H

#include "ModelData/groupentity.h"

namespace __3DWorld__ {

class RunAway : public GroupEntity
{
public:
    RunAway(ModelGroup * group);
    void update();

private:
    void cirkel();
    int _timer;
    int _timer2;
    int _timer_rotate;
};

}

#endif // RUNAWAY_H
