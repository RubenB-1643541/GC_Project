#include "Camera.h"

namespace __3DWorld__ {

Camera::Camera() :
	_p_position(Point3D(0.0, 0.0, 0.0)), 
    _p_looks_at(Point3D(0.0, 0.0, 1.0)),
    _max_up_down_at_90(true),
    _r_current_up_down_radians(0) {
	_v_looks_at = Vector3D(_p_position, _p_looks_at);
	
    Point3D up(
        _p_position.x(),
		_p_position.y()+1,
		_p_position.z()
	);
    _v_up = Vector3D(_p_position, up);
	
    Point3D forward(
        _p_position.x(),
		_p_position.y(),
		_p_position.z()+1
	);
	_v_forward = Vector3D(_p_position, forward);
	
	
    Point3D right(
		_p_position.x()+1,
		_p_position.y(),
		_p_position.z()
	);
	_v_right = Vector3D(_p_position, right);
}

void Camera::moveTowardLooksAT(const double amount) {
    return;
} // Todo

void Camera::strafeForwardBack(const double amount) {
	if (amount == 0.0) {
		return;
	}
	double s = amount / _v_forward.length();
	
    double dx = s*(_v_forward.to().x() - _v_forward.from().x());
    double dz = s*(_v_forward.to().z() - _v_forward.from().z());
	
	_p_position.translate(dx, 0.0, dz);
	_p_looks_at.translate(dx, 0.0, dz);
	
	_v_looks_at.translate(dx, 0.0, dz);
	_v_up.translate(dx, 0.0, dz);
	_v_forward.translate(dx, 0.0, dz);
	_v_right.translate(dx, 0.0, dz);
	return;
}
void Camera::strafeLeftRight(const double amount) {
	if (amount == 0.0) {
		return;
	}
	double s = amount / _v_right.length();
	
    double dx = s*(_v_right.to().x() - _v_right.from().x());
    double dz = s*(_v_right.to().z() - _v_right.from().z());
	
	_p_position.translate(dx, 0.0, dz);
	_p_looks_at.translate(dx, 0.0, dz);
	
	_v_looks_at.translate(dx, 0.0, dz);
	_v_up.translate(dx, 0.0, dz);
	_v_forward.translate(dx, 0.0, dz);
	_v_right.translate(dx, 0.0, dz);
	return;
}
void Camera::strafeUpDown(const double amount) {
	if (amount == 0.0) {
		return;
	}
	_p_position.translate(0.0, amount, 0.0);
	_p_looks_at.translate(0.0, amount, 0.0);
	
	_v_looks_at.translate(0.0, amount, 0.0);
	_v_up.translate(0.0, amount, 0.0);
	_v_forward.translate(0.0, amount, 0.0);
	_v_right.translate(0.0, amount, 0.0);
	return;
}

void Camera::rotateUpDown(const double radians) {
    if (_max_up_down_at_90 && // Max Up-Down rotation is enabled
            (_r_current_up_down_radians + radians) > DEG_90_IN_RAD || // Up rotation < 90 deg
            (_r_current_up_down_radians + radians) < -DEG_90_IN_RAD) {// Down rotation > 90 deg
        return;
    }
    _v_looks_at.rotate(-radians, _v_right);
	_p_looks_at = _v_looks_at.to();

    _r_current_up_down_radians += radians;
	return;
}
void Camera::rotateLeftRight(const double radians) {
    _v_looks_at.rotate(radians, _v_up);
	_p_looks_at = _v_looks_at.to();
	
    _v_forward.rotate(radians, _v_up);
    _v_right.rotate(radians, _v_up);
	return;
}

Point3D Camera::getPosition() const { return _p_position; }
Point3D Camera::getLooksAt() const { return _p_looks_at; }

void Camera::setPosition(const Point3D& point) { _p_looks_at = point; return; }
void Camera::setLooksAt(const Point3D& point) { _p_looks_at = point; return; }

void Camera::setMaxUpDownRotationAt90(bool is_set) { _max_up_down_at_90 = is_set; return; }
}

