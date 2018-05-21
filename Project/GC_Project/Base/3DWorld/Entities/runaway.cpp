#include "runaway.h"

namespace __3DWorld__ {

RunAway::RunAway(ModelGroup * group) : GroupEntity(group)
{
    _timer = 0;
    _timer2 = 0;
    _timer_rotate = 0;
}

void RunAway::update() {
    cirkel();
}

void RunAway::cirkel() {
    ++_timer2;
    if(_timer2 > 20) {
        _timer2 = 0;
        ++_timer;
        if(_timer <= 4 || _timer == 16) {
            move(Point3D(-1,0,0), 2);
        }

        if(_timer >= 4 && _timer <= 8) {
            move(Point3D(0,0,-1), 2);
        }

        if(_timer >= 8 && _timer <= 12) {
            move(Point3D(1,0,0), 2);
        }

        if(_timer >= 12 && _timer <= 16) {
            move(Point3D(0,0,1), 2);
        }
        if(_timer % 4 == 0) {
            rotateY(-89);
        }

        if(_timer >= 16) {
            _timer = 0;
        }
    }
}


}
