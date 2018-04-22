#include "Vector3D.h"
#include <cmath>

namespace __3DWorld__ {

////////////////////////////////////////////////////////
/// Construction
////////////////////////////////////////////////////////

Vector3D::Vector3D() :
    _from(Point3D(0.0, 0.0, 0.0)),
    _to(Point3D(0.0, 0.0, 0.0)) {
    return;
}
Vector3D::Vector3D(Point3D to): 
    _from(Point3D(0.0, 0.0, 0.0)),
	_to(to) {
	return;
}
Vector3D::Vector3D(Point3D from, Point3D to) :
	_from(from),
	_to(to) {
	return;
}
Vector3D::Vector3D(const Vector3D& vector) {
	_from = vector.from();
	_to = vector.to();
	return;
}

Vector3D Vector3D::copy() const {
	return Vector3D(_from, _to);
}

////////////////////////////////////////////////////////
/// Query
////////////////////////////////////////////////////////
Point3D Vector3D::from() const { return _from; }
Point3D Vector3D::to() const { return _to; }
double Vector3D::length() const {
	return _from.distanceTo(_to);
}

////////////////////////////////////////////////////////
/// Compare
////////////////////////////////////////////////////////
bool Vector3D::equal(const Vector3D& vector) const {
	double dx = vector.from().x() - _from.x();
	double dy = vector.from().y() - _from.y();
	double dz = vector.from().z() - _from.z();
    Vector3D translated = vector.copy();
    translated.translate(-dx, -dy, -dz);
	
	return (_to == translated.to());
}
bool Vector3D::operator==(const Vector3D& vector) const {
	double dx = vector.from().x() - _from.x();
	double dy = vector.from().y() - _from.y();
	double dz = vector.from().z() - _from.z();
    Vector3D translated = vector.copy();
    translated.translate(-dx, -dy, -dz);
	
	return (_to == translated.to());
}
bool Vector3D::operator!=(const Vector3D& vector) const {
	return !equal(vector);
}
double Vector3D::angle(const Vector3D& vector) const {
    Vector3D c_this = this->copy();
    c_this.normalize();
    Vector3D c_vect = vector.copy();
    c_vect.normalize();
	
	double x = c_this.to().x() * c_vect.to().x();
	double y = c_this.to().y() * c_vect.to().y();
	double z = c_this.to().z() * c_vect.to().z();
	double n = x + y + z;

    return std::acos(n);
}

////////////////////////////////////////////////////////
/// Modify
////////////////////////////////////////////////////////
void Vector3D::setFrom(const Point3D from) { _from = from; return; }
void Vector3D::setTo(const Point3D to) { _to = to; return; }
void Vector3D::translate(const double dx, const double dy, const double dz) {
	_from.translate(dx, dy, dz);
	_to.translate(dx, dy, dz);
	return;
}
void Vector3D::rotate(const double radians, const Vector3D vector) { // Todo
	double dx = _from.x();
	double dy = _from.y();
	double dz = _from.z();
	
	translate(-dx, -dy, -dz);	// Translate to origin
	
    Vector3D normalized = vector.copy();
    normalized.normalize();
    _to.rotate(radians, normalized.to());
	
	translate(dx, dy, dz);		// Translate back to original position
	return;
}
void Vector3D::scale(const double s) {
    double dx = _from.x();
    double dy = _from.y();
    double dz = _from.z();

    translate(-dx, -dy, -dz);	// Translate to origin

    double new_x = s * _to.x();
    double new_y = s * _to.y();
    double new_z = s * _to.z();

    _to.setX(new_x);
    _to.setY(new_y);
    _to.setZ(new_z);

    translate(dx, dy, dz);		// Translate back to original position

    return;
}

void Vector3D::normalize() {
    double length = this->length();

    double dx = _from.x();
    double dy = _from.y();
    double dz = _from.z();

    translate(-dx, -dy, -dz);

    double new_x = _to.x() / length;
    double new_y = _to.y() / length;
    double new_z = _to.z() / length;

    _to.setX(new_x);
    _to.setY(new_y);
    _to.setZ(new_z);

    return;
}

////////////////////////////////////////////////////////
/// Operation
////////////////////////////////////////////////////////
Vector3D Vector3D::add(const Vector3D& vector) const {
    return vector;
}
Vector3D Vector3D::operator+(const Vector3D& vector) const {
    return vector;
}
Vector3D Vector3D::crossProduct(const Vector3D& vector) const {
    return vector;
}
double Vector3D::dotProduct(const Vector3D& vector) const {
    return 0.0;
}

}
