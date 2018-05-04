#ifndef CAMERA
#define CAMERA

#include "Vector3D.h"
#include "Point3D.h"

namespace __3DWorld__ {

const double DEG_90_IN_RAD = 1.570796;

/**
 * @author Wald Habets
 * @brief
 */
class Camera {
public:
    Camera();

    /**
     * @brief Move the camera towards the point it is looking at
     * @param amount
     * - The amount the camera has to move
     * - A positive value moves the camera forward
     * - A negative value moves the camera backwards
     */
    void moveTowardLooksAT(const double amount);

    /**
     * @brief Move the camera forward or backwards parallel to the xz-plane
     * @param amount
     * - The amount the camera has to move
     * - A positive value moves the camera forward
     * - A negative value moves the camera backwards
     */
    void strafeForwardBack(const double amount);
    /**
     * @brief Move the camera left or right parallel to the xz-plane
     * @param amount
     * - The amount the camera has to move
     * - A positive value moves the camera left
     * - A negative value moves the camera right
     */
    void strafeLeftRight(const double amount);
    /**
     * @brief Move the camera forward or backwards parallel to the y-axis of the space
     * @param amount
     * - The amount the camera has to move
     * - A positive value moves the camera up
     * - A negative value moves the camera down
     */
    void strafeUpDown(const double amount);

    /**
     * @brief Rotate the camera up or down around its x-axis
     * @param radians
     * - The angle the camera has to rotate in radians
     * - A positive value rotates the camera upwards
     * - A negative value rotates the camera downwards
     */
    void rotateUpDown(const double radians);
    /**
     * @brief Rotate the camera up or down around its y-axis
     * @param radians
     * - The angle the camera has to rotate in radians
     * - A positive value rotates the camera left
     * - A negative value rotates the camera right
     */
    void rotateLeftRight(const double radians);

    Point3D getPosition() const;
    Point3D getLooksAt() const;

    void setPosition(const Point3D& point);
    void setLooksAt(const Point3D& point);

    void setMaxUpDownRotationAt90(bool is_set);
private:
    Point3D _p_position;
    Point3D _p_looks_at;

    bool _max_up_down_at_90;
    double _r_current_up_down_radians;

    Vector3D _v_looks_at;
    Vector3D _v_up;
    Vector3D _v_forward;
    Vector3D _v_right;
};
}

#endif CAMERA
