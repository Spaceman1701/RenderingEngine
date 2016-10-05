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

		void Quaternion::fromEulerAngles(const Vector3f& eulerAngles) {
			float rads = eulerAngles.mag();
			fromAxisAngle(eulerAngles, rads);
		}

		void Quaternion::fromEulerAngles(float x, float y, float z) {
			fromEulerAngles(Vector3f(x, y, z));
		}

		void Quaternion::fromAxisAngle(const Vector3f& axis, float rads) {
			Vector3f norm_axis = axis.norm();
			w = cosf(rads / 2);
			x = sinf(rads / 2) * axis.x;
			y = sinf(rads / 2) * axis.y;
			z = sinf(rads / 2) * axis.z;
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
			float mag2 = length2();
			conjugateSelf();
			x /= mag2;
			y /= mag2;
			z /= mag2;
			w /= mag2;
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
			temp = temp * (*this);
			return temp;
		}

		Quaternion Quaternion::rotate(float x, float y, float z, float rads) {
			return rotate(Vector3f(x, y, z), rads);
		}

		void Quaternion::rotateSelf(const Vector3f& eulerAngles) {
			rotateSelf(eulerAngles, eulerAngles.mag());
		}

		void Quaternion::rotateSelf(float x, float y, float z) {
			rotateSelf(Vector3f(x, y, z));
		}

		void Quaternion::rotateSelf(const Vector3f& axis, float rads) {
			Quaternion temp(axis, rads);
			temp = temp * (*this);
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
			float l2 = length2();
			if (l2 == 1.0f) { //Should use epsilon value
				return 1;
			}
			return sqrtf(l2);
		}

		Matrix3f Quaternion::toMatrix() {
			normalizeSelf();
			float mat[9];
			float x2 = x * x;
			float y2 = y * y;
			float z2 = z * z;

			mat[0] = 1 - (2 * y2) - (2 * z2);
			mat[1] = (2 * x * y) + (2 * w * y);
			mat[2] = (2 * x * z) - (2 * w * y);

			mat[3] = (2 * x * y) - (2 * w * z);
			mat[4] = 1 - (2 * x2) - (2 * z2);
			mat[5] = (2 * y * z) - (2 * w * x);

			mat[6] = (2 * x * z) + (2 * w * y);
			mat[7] = (2 * y * z) + (2 * w * x);
			mat[8] = 1 - (2 * x2) - (2 * y2);

			return Matrix3f(mat);
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
