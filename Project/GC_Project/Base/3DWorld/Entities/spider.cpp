#include "spider.h"

namespace __3DWorld__ {

Spider::Spider(Model *model) :ModelEntity(model) {
    _timer = 0;
}

void Spider::update() {
    _timer++;
    if(_timer > 5) {
        _timer = 0;
        move(Point3D(1,0,0), 1);
    }
}

}
