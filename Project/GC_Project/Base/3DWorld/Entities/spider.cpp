#include "spider.h"

namespace __3DWorld__ {

Spider::Spider(Model *model) :ModelEntity(model) {
    _timer = 0;
    _timer2 = 0;
    _timer_rotate = 0;
}

void Spider::update() {
    ++_timer;
    ++_timer2;
    ++_timer_rotate;
    if(_timer > 5) {
        _timer = 0;
        move(Point3D(1,0,0), 1);
    }
    if(_timer2 > 100) {
        _timer2 = 0;
        scale(1.1);
    }
    if(_timer_rotate > 10) {
        _timer_rotate = 0;
        rotateY(10);
    }

}

}
