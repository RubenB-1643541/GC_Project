#include "Point3D.h"
#include <cmath>

namespace __3DWorld__ {

////////////////////////////////////////////////////////
/// Construction
////////////////////////////////////////////////////////
Point3D::Point3D() :
    _x(0.0),
    _y(0.0),
    _z(0.0) {
    return;
}

Point3D::Point3D(const double x, const double y, const double z) : 
	_x(x),
	_y(y),
	_z(z) {
	return;
}
Point3D::Point3D(const Point3D& point) {
	_x = point.x();
	_y = point.y();
	_z = point.z();
	return;
}

Point3D Point3D::copy() const {
	return Point3D(_x, _y, _z);
}

////////////////////////////////////////////////////////
/// Query
////////////////////////////////////////////////////////
double Point3D::x() const { return _x; }
double Point3D::y() const { return _y; }
double Point3D::z() const { return _z; }

////////////////////////////////////////////////////////
/// Compare
////////////////////////////////////////////////////////
double Point3D::distanceTo(const Point3D& point) const {
	// Euclidean distance formula
	double dx = point.x() - _x;
	double dy = point.y() - _y;
	double dz = point.z() - _z;
	return sqrt(dx*dx + dy*dy + dz*dz);
}
bool Point3D::equals(const Point3D& point) const {
	return (_x == point.x() && _y == point.y() && _z == point.z());
}
bool Point3D::operator==(const Point3D& point) const {
	return (_x == point.x() && _y == point.y() && _z == point.z());
}
bool Point3D::operator!=(const Point3D& point) const {
    return !equals(point);
}

////////////////////////////////////////////////////////
/// Modify
////////////////////////////////////////////////////////
void Point3D::setX(const double x) { _x = x; return; }
void Point3D::setY(const double y) { _y = y; return; }
void Point3D::setZ(const double z) { _z = z; return; }
void Point3D::translate(const double dx, const double dy, const double dz) {
    _x += dx;
    _y += dy;
    _z += dz;
	return;
}
void Point3D::rotate(const double radians, const Point3D vector) {
    double nx = vector.x();
    double ny = vector.y();
    double nz = vector.z();
	
	double cos = std::cos(radians);
	double sin = std::sin(radians);
	
	// Matrix rotation
	double new_x = (
        (_x * ( cos + ((nx*nx)*(1-cos)) ))
		+ 
        (_y * ( ((nx*ny)*(1-cos)) - (nz*sin) ))
		+
        (_z * ( ((nx*nz)*(1-cos)) + (ny*sin) ))
	);
	double new_y = (
        (_x * ( ((ny*nx)*(1-cos)) + (nz*sin) ))
		+
        (_y* ( cos + ((ny*ny)*(1-cos)) ))
		+
        (_z * ( ((ny*nz)*(1-cos)) - (nx*sin) ))
    );
    double new_z = (
        (_x * ( ((nz*nx)*(1-cos)) - (ny*sin) ))
		+
        (_y * ( ((nz*ny)*(1-cos)) + (nx*sin) ))
		+
        (_z * ( cos + ((nz*nz)*(1-cos)) ))
	);
	
	_x = new_x;
	_y = new_y;
	_z = new_z;
	return;
}

}
