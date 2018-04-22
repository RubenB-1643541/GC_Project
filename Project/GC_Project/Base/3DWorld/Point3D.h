#ifndef FROST_GEOMETRY_POINT_3D
#define FROST_GEOMETRY_POINT_3D

namespace __3DWorld__ {

/**
 * @author Wald Habets
 * @brief This class represents a point in a 3d space.
 */
class Point3D {
public:
	////////////////////////////////////////////////////////
	/// Construction
	////////////////////////////////////////////////////////
    Point3D();
	Point3D(const double x, const double y, const double z);
	Point3D(const Point3D& point);
	
	/**
	 * @brief returns a copy of the object
	 * @return Point3D
	 */
	Point3D copy() const;
	
	////////////////////////////////////////////////////////
	/// Query
	////////////////////////////////////////////////////////
	double x() const;
	double y() const;
	double z() const;
	
	////////////////////////////////////////////////////////
	/// Compare
	////////////////////////////////////////////////////////
	/**
	 * @brief returns the distance to a specific point
	 * @param point
	 * @return double
	 * - The distance
	 */
	double distanceTo(const Point3D& point) const;
	/**
	 * @brief checks if this objects coordinates match with those of a specific point
	 * @param point
	 * @return bool
	 * - true if the coordinates match
	 * - false if the coordinates don't match
	 */
	bool equals(const Point3D& point) const;
	bool operator==(const Point3D& point) const;
	bool operator!=(const Point3D& point) const;
	
	////////////////////////////////////////////////////////
	/// Modify
	////////////////////////////////////////////////////////
	void setX(const double x);
	void setY(const double y);
	void setZ(const double z);
	/**
	 * @brief Translates the object following the translation values
	 * @param dx
	 * - The translation value for the x coordinate
	 * @param dy
	 * - The translation value for the y coordinate
	 * @param dz
	 * - The translation value for the z coordinate
	 */
	void translate(const double dx, const double dy, const double dz);
	/**
	 * @brief rotates the point around a rotation vector
	 * @param radians
	 * - The angle of the rotation, a positive angle is a counterclockwise rotation
	 * @param vector
	 * - The vector around which the point should be rotated
	 * - Rotation happens around the normalized vector
	 */
    void rotate(const double radians, const Point3D vector);
private:
	double _x;
	double _y;
	double _z;
};


}
#endif FROST_GEOMETRY_POINT_3D
