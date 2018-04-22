#ifndef FROST_CAMERA_CAMERA_KEY_HANDLER
#define FROST_CAMERA_CAMERA_KEY_HANDLER

#include "Camera.h"

namespace __3DWorld__ {

/**
 * @author Wald Habets
 * @brief
 */
class CameraKeyHandler {
public:
	CameraKeyHandler(Camera* cam);
	
	////////////////////////////////////////////////////////
	/// Key Handling
	////////////////////////////////////////////////////////
    enum Key {
		Strafe_Forward,
		Strafe_Back,
		Strafe_Left,
		Strafe_Right,
		Strafe_Up,
		Strafe_Down,
		Move_Forward,
		Move_Back,
		Rotate_Up,
		Rotate_Down,
		Rotate_Left,
		Rotate_Right
    };
	void keyDown(Key key);
	void keyUp(Key key);
	
	////////////////////////////////////////////////////////
	/// Query
	////////////////////////////////////////////////////////
	void setRotationAmount(const double radians);
	void setMovementAmount(const double amount);
	
	double getRotationAmount() const;
	double getMovementAmount() const;

    ////////////////////////////////////////////////////////
    /// Camera
    ////////////////////////////////////////////////////////
    void updateCamera();
private:
    ////////////////////////////////////////////////////////
	/// Variables
	////////////////////////////////////////////////////////
	const static int NUMBER_OF_KEYS = 12;

	double _rotation_amount;
	double _movement_amount;
	
	Camera* _cam;
	bool _key_is_pressed[NUMBER_OF_KEYS];
};
	
}


#endif FROST_CAMERA_CAMERA_KEY_HANDLER
