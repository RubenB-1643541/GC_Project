#include "spider.h"

namespace __3DWorld__ {

Spider::Spider(Model *model) :ModelEntity(model) {
    _timer = 0;
    _timer2 = 0;
    _timer_rotate = 0;
}

void Spider::update() {
    cirkel();



}

void Spider::cirkel() {
    ++_timer2;
    if(_timer2 > 10) {
        _timer2 = 0;
        ++_timer;
        if(_timer <= 4) {
            move(Point3D(1,0,0), 2);
        }

        if(_timer >= 4 && _timer <= 8) {
            move(Point3D(0,0,1), 2);
        }

        if(_timer >= 8 && _timer <= 12) {
            move(Point3D(-1,0,0), 2);
        }

        if(_timer >= 12 && _timer <= 16) {
            move(Point3D(0,0,-1), 2);
        }

        if(_timer % 4 == _timer / 4) {
            rotateY(-90);
        }
        if(_timer >= 16) {
            _timer = 0;
            rotateX(80);
        }
    }
}

void Spider::test() {
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
