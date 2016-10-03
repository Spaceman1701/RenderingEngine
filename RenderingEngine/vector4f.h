#pragma once
#include "vector3f.h"
namespace engine {
	namespace math {
		class Vector4f {
		public:
			float x;
			float y;
			float z;
			float w;

			Vector4f();
			Vector4f(float x, float y, float z, float w);
			Vector4f(float x, float y, float z);
			Vector4f(Vector4f* vec);
			Vector4f(const Vector3f& vec);

			float spaceMag2(); //magnitude of x y z... so mag if Vec4 was Vec3
			float spaceMag();

			float mag2();
			float mag();
			Vector4f norm();

			Vector3f asVector3();
			void fromVector3(const Vector3f& vec);
		};

		bool inline operator==(const Vector4f& left, const Vector4f& right) {
			return left.x == right.x && left.y == right.y && left.z == right.z
				&& left.w == right.w;
		}

		bool inline operator!=(const Vector4f& left, const Vector4f& right) {
			return !(left == right);
		}

		Vector4f inline operator+(const Vector4f& l, const Vector4f& r) {
			return Vector4f(l.x + r.x, l.y + r.y, l.z + r.z, l.w + r.w);
		}

		Vector4f inline operator-(const Vector4f& vec) {
			return Vector4f(-vec.x, -vec.y, -vec.z, -vec.w);
		}

		Vector4f inline operator-(const Vector4f& l, const Vector4f& r) {
			return l + (-r);
		}

		float inline operator*(const Vector4f& l, const Vector4f& r) {
			return l.x*r.x + l.y*r.y + l.z*r.z + l.w*r.w;
		}
	
		Vector4f inline operator*(const float f, const Vector4f& r) {
			return Vector4f(r.x * f, r.y * f, r.z * f, r.w * f);
		}
	}
}