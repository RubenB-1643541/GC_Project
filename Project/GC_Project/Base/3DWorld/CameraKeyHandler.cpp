#include "CameraKeyHandler.h"

namespace __3DWorld__ {

CameraKeyHandler::CameraKeyHandler(Camera* cam) :
	_rotation_amount(0.01745329),	// ~1deg
	_movement_amount(0.3),
	_cam(cam) {
	for (int i = 0; i < NUMBER_OF_KEYS; i++) {
		_key_is_pressed[i] = false;
	}
	return;
}
	
////////////////////////////////////////////////////////
/// Key Handling
////////////////////////////////////////////////////////
void CameraKeyHandler::keyDown(Key key) {
    _key_is_pressed[key] = true;
    updateCamera();
}
void CameraKeyHandler::keyUp(Key key) {
    _key_is_pressed[key] = false;
    updateCamera();
}

////////////////////////////////////////////////////////
/// Query
////////////////////////////////////////////////////////
void CameraKeyHandler::setRotationAmount(const double radians) { _rotation_amount = radians; return; }
void CameraKeyHandler::setMovementAmount(const double amount) { _movement_amount = amount; return; }

double CameraKeyHandler::getRotationAmount() const { return _rotation_amount; }
double CameraKeyHandler::getMovementAmount() const { return _movement_amount; }

////////////////////////////////////////////////////////
/// Camera
////////////////////////////////////////////////////////
void CameraKeyHandler::updateCamera() {
    if (_key_is_pressed[Strafe_Forward])    { _cam->strafeForwardBack(_movement_amount); }
    if (_key_is_pressed[Strafe_Back])       { _cam->strafeForwardBack(-_movement_amount); }
    if (_key_is_pressed[Strafe_Left]) 		{ _cam->strafeLeftRight(_movement_amount); }
    if (_key_is_pressed[Strafe_Right]) 		{ _cam->strafeLeftRight(-_movement_amount); }
    if (_key_is_pressed[Strafe_Up]) 		{ _cam->strafeUpDown(_movement_amount); }
    if (_key_is_pressed[Strafe_Down]) 		{ _cam->strafeUpDown(-_movement_amount); }
    if (_key_is_pressed[Move_Forward])	{ _cam->moveTowardLooksAT(_movement_amount); }
    if (_key_is_pressed[Move_Back])		{ _cam->moveTowardLooksAT(_movement_amount); }
    if (_key_is_pressed[Rotate_Up]) 	{ _cam->rotateUpDown(_rotation_amount); }
    if (_key_is_pressed[Rotate_Down]) 	{ _cam->rotateUpDown(-_rotation_amount); }
    if (_key_is_pressed[Rotate_Left]) 	{ _cam->rotateLeftRight(_rotation_amount); }
    if (_key_is_pressed[Rotate_Right]) 	{ _cam->rotateLeftRight(-_rotation_amount); }
    return;
}

}
