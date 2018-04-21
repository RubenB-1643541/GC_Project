#ifndef VECTOR_3D
#define VECTOR_3D

#include "Point3D.h"

namespace __3DWorld__ {

/**
 * @author Wald Habets
 * @brief This class represents a vector in a 3d space.
 */
class Vector3D {
public:
	////////////////////////////////////////////////////////
	/// Construction
	////////////////////////////////////////////////////////
    Vector3D();
	Vector3D(Point3D to);
	Vector3D(Point3D from, Point3D to);
    Vector3D(const Vector3D& vector);
	
	/**
	 * @brief returns a copy of the object
	 * @return Vector3D
	 */
	Vector3D copy() const;
	
	////////////////////////////////////////////////////////
	/// Query
	////////////////////////////////////////////////////////
	Point3D from() const;
	Point3D to() const;
	double length() const;
	
	////////////////////////////////////////////////////////
	/// Compare
	////////////////////////////////////////////////////////
	/**
	 * @brief checks if two vectors are equal
	 * - Two vectors are equal if they match in size and direction
	 * @param vector
	 * @return bool
	 * - true if equal
	 * - false if not equal
	 */
	bool equal(const Vector3D& vector) const;
	bool operator==(const Vector3D& vector) const;
	bool operator!=(const Vector3D& vector) const;
	/**
	 * @brief calculates and returns the angle between two vectors
	 * @param vector
	 * @return double
	 * - The angle between the vectors in radians
	 */
	double angle(const Vector3D& vector) const;
	
	////////////////////////////////////////////////////////
	/// Modify
	////////////////////////////////////////////////////////
	void setFrom(const Point3D from);
	void setTo(const Point3D to);
	/**
	 * @brief Translates the vector following the translation values
	 * @param dx
	 * - The translation value for the x coordinates
	 * @param dy
	 * - The translation value for the y coordinates
	 * @param dz
	 * - The translation value for the z coordinates
	 */
	void translate(const double dx, const double dy, const double dz);
	void rotate(const double radians, const Vector3D vector);
	/**
	 * @brief scales the vector with factor s
	 * - this is equal to the scalar product
	 * @param s
	 */
	void scale(const double s);
	/**
	 * @brief normalizes the vector
	 * - this usually results in a translation followed by a scaling
	 */
	void normalize();
	
	////////////////////////////////////////////////////////
	/// Operation
	////////////////////////////////////////////////////////
	/**
	 * @brief calculates and returns the sum of two vectors
	 * @param vector
	 * @return Vector3D
	 * - the resulting vector sum
	 */
	Vector3D add(const Vector3D& vector) const;
	Vector3D operator+(const Vector3D& vector) const;
	/**
	 * @brief calculates and returns the cross product of two vectors
	 * @param vector
	 * @return Vector3D
	 * - the resulting cross product
	 */
	Vector3D crossProduct(const Vector3D& vector) const;
	/**
	 * @brief calculates and returns the dot product of two vectors
	 * @param vector
	 * @return Vector3D
	 * - the resulting dot product
	 */
	double dotProduct(const Vector3D& vector) const;
private:
	Point3D _from;
	Point3D _to;
};
	
}

#endif VECTOR_3D
