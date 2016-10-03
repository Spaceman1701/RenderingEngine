#include "vector3f.h"
#include <math.h>
using namespace engine::math;

Vector3f::Vector3f() : Vector3f(0.0f, 0.0f, 0.0f) {}

Vector3f::Vector3f(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3f::Vector3f(Vector3f* v) {
	this->x = v->x;
	this->y = v->y;
	this->z = v->z;
}

Vector3f Vector3f::norm() const{
	float mag = this->mag();
	return Vector3f(x / mag, y / mag, z / mag);
}
float Vector3f::mag2() const{
	return x*x + y*y + z*z;
}
float Vector3f::mag() const{
	return sqrt(mag2());
}
namespace engine {
	namespace math {
		Vector3f cross(Vector3f left, Vector3f right) {
			float x = left.y * right.z - left.z * right.y;
			float y = left.z * right.x - left.x * right.z;
			float z = left.x * right.y - left.y * right.x;
			return Vector3f(x, y, z);
		}
	}
}

