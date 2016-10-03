#include "quaternion.h"
#include <math.h>
namespace engine {
	namespace math {
		Quaternion::Quaternion() {
			this->x = 0;
			this->y = 0;
			this->z = 0;
			this->w = 0;
		}

		Quaternion::Quaternion(Quaternion* q) {
			x = q->x;
			y = q->y;
			z = q->z;
			w = q->w;
		}

		Quaternion::Quaternion(float x, float y, float z, float w) {
			this->x = x;
			this->y = y;
			this->z = z;
			this->w = w;
		}

		Quaternion::Quaternion(const Vector3f& eulerAngles) {
			fromEulerAngles(eulerAngles);
		}

		Quaternion::Quaternion(float x, float y, float z) {
			fromEulerAngles(x, y, z);
		}

		Quaternion::Quaternion(const Vector3f& axis, float rads) {
			fromAxisAngle(axis, rads);
		}

		Quaternion::Quaternion(float x, float y, float z, float rads) {
			fromAxisAngle(x, y, z, rads);
		}

		void Quaternion::fromEulerAngles(const Vector3f& eulerAngles) {
			float rads = eulerAngles.mag();
			fromAxisAngle(eulerAngles, rads);
		}

		void Quaternion::fromEulerAngles(float x, float y, float z) {
			fromEulerAngles(x, y, z);
		}

		void Quaternion::fromAxisAngle(const Vector3f& axis, float rads) {
			Vector3f norm_axis = axis.norm();
			w = cos(rads / 2);
			x = sin(rads / 2) * cos(axis.x);
			y = sin(rads / 2) * cos(axis.y);
			z = sin(rads / 2) * cos(axis.z);
		}

		void Quaternion::fromAxisAngle(float x, float y, float z, float rads) {
			fromAxisAngle(Vector3f(x, y, z), rads);
		}

		void Quaternion::setToIdentity() {
			w = 1.0f;
			x = 0.0f;
			y = 0.0f;
			z = 0.0f;
		}

		void Quaternion::invertSelf() {
			float x1 = x;
			float y1 = y;
			float z1 = z;
			float w1 = w1;
			conjugateSelf();
			x /= x1;
			y /= y1;
			z /= z1;
			w /= w1;
		}

		void Quaternion::conjugateSelf() {
			x *= -1;
			y *= -1;
			z *= -1;
		}

		void Quaternion::normalizeSelf() {
			float lgh = length();
			w /= lgh;
			x /= lgh;
			y /= lgh;
			z /= lgh;
		}

		Quaternion Quaternion::invert() {
			Quaternion temp(this);
			temp.invertSelf();
			return temp;
		}

		Quaternion Quaternion::conjugate() {
			Quaternion temp(this);
			temp.conjugateSelf();
			return temp;
		}

		Quaternion Quaternion::normalize() {
			Quaternion temp(this);
			temp.normalizeSelf();
			return temp;
		}

		Quaternion Quaternion::rotate(const Vector3f& eulerAngles) {
			return rotate(eulerAngles, eulerAngles.mag());
		}

		Quaternion Quaternion::rotate(float x, float y, float z) {
			return rotate(Vector3f(x, y, z));
		}

		Quaternion Quaternion::rotate(const Vector3f& axis, float rads) {
			Quaternion temp(axis, rads);
			temp = (*this) * temp;
			return temp;
		}

		Quaternion Quaternion::rotate(float x, float y, float z, float rads) {
			return rotate(Vector3f(x, y, z), rads);
		}

		void Quaternion::rotateSelf(const Vector3f& eulerAngles) {
			rotateSelf(eulerAngles, eulerAngles.mag);
		}

		void Quaternion::rotateSelf(float x, float y, float z) {
			rotateSelf(Vector3f(x, y, z));
		}

		void Quaternion::rotateSelf(const Vector3f& axis, float rads) {
			Quaternion temp(axis, rads);
			temp = (*this) * temp;
			x = temp.x;
			y = temp.y;
			z = temp.z;
			w = temp.w;
		}

		void Quaternion::rotateSelf(float x, float y, float z, float rads) {
			rotateSelf(Vector3f(x, y, z), rads);
		}

		float Quaternion::length2() {
			return (w * w) + (x * x) + (y * y) + (z * z);
		}

		float Quaternion::length() {
			return sqrt(length2());
		}

		Matrix3f Quaternion::toMatrix() {

		}

		Quaternion Quaternion::operator*(const Quaternion& right) {
			Vector3f vec(x, y, z);
			Vector3f rvec(right.x, right.y, right.z);

			float scaler = (w * right.w) - (vec * rvec);
			Vector3f out = cross(vec, rvec) + (w * rvec) + (right.w * vec);
			
			return Quaternion(out.x, out.y, out.z, scaler);
		}
	}
}
