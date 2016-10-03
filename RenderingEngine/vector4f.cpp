#include "vector4f.h"
#include <math.h>
namespace engine {
	namespace math {
		Vector4f::Vector4f(float x, float y, float z, float w) {
			this->x = x;
			this->y = y;
			this->z = z;
			this->w = w;
		}
		Vector4f::Vector4f() : Vector4f(0.0f, 0.0f, 0.0f, 0.0f) {}
		Vector4f::Vector4f(float x, float y, float z) : Vector4f(x, y, z, 0.0f) {}
		Vector4f::Vector4f(Vector4f* vec) : Vector4f(vec->x, vec->y, vec->z, vec->w) {}
		Vector4f::Vector4f(const Vector3f& vec) : Vector4f(vec.x, vec.y, vec.z, 0.0f) {}

		float Vector4f::mag2() {
			return x*x + y*y + z*z + w*w;
		}
		float Vector4f::mag() {
			return sqrt(mag2());
		}
		Vector4f Vector4f::norm() {
			float m = mag();
			return Vector4f(x / m, y / m, z / m, w / m);
		}

		float Vector4f::spaceMag2() {
			return x*x + y*y + z*z;
		}

		float Vector4f::spaceMag() {
			return sqrt(spaceMag2());
		}

		Vector3f Vector4f::asVector3() {
			return Vector3f(x, y, z);
		}

		void Vector4f::fromVector3(const Vector3f& vec) {
			x = vec.x;
			y = vec.y;
			z = vec.z;
			w = 1.0f;
		}
	}
}
