#include "thwomp.h"

namespace __3DWorld__ {

Thwomp::Thwomp(Model * model) : ModelEntity(model) {
    _timer = 0;
    _high = 15;
    _low = 0;
    _current = 0;
    _up = true;
}

void Thwomp::update() {

    if(_timer > 5) {

        if(_up) {
            up();
        }
        else {
            down();
        }
        if(_current == _high) {
            _up = false;
        }
        if(_current == _low) {
            _up = true;
        }
        _timer = 0;
    }
    else {
        ++_timer;
    }
}

void Thwomp::down() {
    move(Point3D(0,-1,0), 3);
    _current -= 3;
}

void Thwomp::up() {
    move(Point3D(0,1,0), 1);
    ++_current;
}

void Thwomp::pick() {

}

}
