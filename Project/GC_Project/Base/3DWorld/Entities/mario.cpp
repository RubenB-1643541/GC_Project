#include "mario.h"

namespace __3DWorld__ {

Mario::Mario(Model * model) : ModelEntity(model)
{
    _timer = 0;
    _timer2 = 0;
    _high = 6;
    _low = 0;
    _current = 0;
    _up = true;
    _pause = false;
}

void Mario::update() {
    if(pause()) {

    }
    else if(_timer == 5) {

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
            _pause = true;
        }
        _timer = 0;

    }
    else {
        ++_timer;
    }

}

void Mario::down() {
    move(Point3D(0,-1,0),1);
    _current -= 1;
}

void Mario::up() {
    move(Point3D(0,1,0), 3);
    _current += 3;
}

bool Mario::pause() {
    if(_pause) {
        ++_timer2;
    }
    if(_timer2 == 30) {
        _pause = false;
        _timer2 = 0;
    }
    return _pause;
}

void Mario::pick() {

}

}
