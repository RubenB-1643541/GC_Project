#include "HeadLamp.h"
#include <QDebug>

namespace __3DWorld__ {

HeadLamp::HeadLamp() : 
	_position(0.0, 0.0, 0.0),
    _cone_angle(10.0),
    _is_enabled(true) {
	setRgba(1.0, 1.0, 1.0, 0.0);
	return;
}

void HeadLamp::openGlRender(GLenum light) {
    float gl_position[] = {
        _position.x(),
        _position.y(),
        _position.z(),
        1.0
    };
    float gl_spot_cutoff[] = {
        _cone_angle
    };
    float gl_diffuse[] = {
        _rgba[RGBA::R],
        _rgba[RGBA::G],
        _rgba[RGBA::B],
        _rgba[RGBA::A]
    };
    if(_is_enabled) {
        glEnable(GL_LIGHTING);
        glEnable(light);
        glLightfv (light, GL_POSITION, gl_position);
        glLightfv (light, GL_SPOT_CUTOFF, gl_spot_cutoff);
        glLightfv (light, GL_DIFFUSE, gl_diffuse);
    } else {
        glDisable(GL_LIGHTING);
        glDisable(light);
    }
}

////////////////////////////////////////////////////////
/// Modify
////////////////////////////////////////////////////////
void HeadLamp::setPosition(const Point3D position) {
	_position = position;
	return;
}
void HeadLamp::setConeAngle(const float degrees) {
	if (degrees < 0 || degrees > 90) { return; }
    _cone_angle = degrees;
	return;
}
void HeadLamp::setRgba(const float r, const float g, const float b, const float a) {
	_rgba[RGBA::R] = r;
	_rgba[RGBA::G] = g;
	_rgba[RGBA::B] = b;
	_rgba[RGBA::A] = a;
	return;
}

////////////////////////////////////////////////////////
/// Enabling and Disabling
////////////////////////////////////////////////////////
bool HeadLamp::isEnabled() const { return _is_enabled; }
void HeadLamp::isEnabled(const bool is_enabled) {
	_is_enabled = is_enabled;
	return;
}
void HeadLamp::toggle() {
    qDebug() << "toggle";
	_is_enabled = (_is_enabled) ? false : true;
	return;
}

}
