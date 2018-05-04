#ifndef CAMERAMOUSEHANDLER_H
#define CAMERAMOUSEHANDLER_H

#include "Camera.h"
#include <QPoint>

namespace __3DWorld__ {

/**
 * @author Wald Habets
 * @brief The CameraMouseHandler class
 */
class CameraMouseHandler
{
public:
    CameraMouseHandler(Camera* cam);

    ////////////////////////////////////////////////////////
    /// Mouse Handling
    ////////////////////////////////////////////////////////
    enum Direction {
        Rotate_Up_Down,
        Rotate_Left_Right
    };
    enum Acceleration {
        FASTEST = 1,
        FAST = 3,
        MEDIUM = 5,
        SLOW = 7,
        SLOWEST = 9
    };

    void registerMouseMovement(QPoint start, QPoint end);

    ////////////////////////////////////////////////////////
    /// Query
    ////////////////////////////////////////////////////////
    void setRotationAmount(const double radians);
    void setAcceleration(const Acceleration acceleration);

    double getRotationAmount() const;
    Acceleration getAcceleration() const;

    ////////////////////////////////////////////////////////
    /// Camera
    ////////////////////////////////////////////////////////
    void updateCamera();
private:
    ////////////////////////////////////////////////////////
    /// Variables
    ////////////////////////////////////////////////////////
    const static int NUMBER_OF_DIRECTIONS = 2;

    double _rotation_amount;
    Acceleration _acceleration;

    Camera* _cam;
    double _rotation_for_direction[NUMBER_OF_DIRECTIONS];
};

}

#endif // CAMERAMOUSEHANDLER_H
