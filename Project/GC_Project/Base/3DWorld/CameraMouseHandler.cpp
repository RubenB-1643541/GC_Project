#include "CameraMouseHandler.h"
#include <cmath>

namespace __3DWorld__ {

CameraMouseHandler::CameraMouseHandler(Camera* cam) :
    _rotation_amount(0.01745329), // ~1deg
    _acceleration(Acceleration::FAST){
    _cam = cam;

    _rotation_for_direction[Direction::Rotate_Up_Down] = 0.0;
    _rotation_for_direction[Direction::Rotate_Left_Right] = 0.0;
}

void CameraMouseHandler::registerMouseMovement(QPoint start, QPoint end) {
    double dx = start.x() - end.x();
    double dy = start.y() - end.y();

    double x_accel = (std::abs(dx) < _acceleration) ? 1 : _acceleration;
    double y_accel = (std::abs(dy) < _acceleration) ? 1 : _acceleration;

    _rotation_for_direction[Direction::Rotate_Left_Right] += _rotation_amount * (dx / x_accel);
    _rotation_for_direction[Direction::Rotate_Up_Down] += _rotation_amount * (dy / y_accel);
}

////////////////////////////////////////////////////////
/// Query
////////////////////////////////////////////////////////
void CameraMouseHandler::setRotationAmount(const double radians) { _rotation_amount = radians; return; }
void CameraMouseHandler::setAcceleration(const Acceleration acceleration) { _acceleration = acceleration; return; }

double CameraMouseHandler::getRotationAmount() const { return _rotation_amount; }
CameraMouseHandler::Acceleration CameraMouseHandler::getAcceleration() const { return _acceleration; }

////////////////////////////////////////////////////////
/// Camera
////////////////////////////////////////////////////////
void CameraMouseHandler::updateCamera() {
    _cam->rotateUpDown(_rotation_for_direction[Direction::Rotate_Up_Down]);
    _cam->rotateLeftRight(_rotation_for_direction[Direction::Rotate_Left_Right]);

    _rotation_for_direction[Direction::Rotate_Up_Down] = 0.0;
    _rotation_for_direction[Direction::Rotate_Left_Right] = 0.0;
}

}
