#pragma once
namespace engine {
	namespace math {
		class Vector3f {
		public:
			float x;
			float y;
			float z;

			Vector3f();
			Vector3f(Vector3f* v);
			Vector3f(float x, float y, float z);

			Vector3f norm(); //should copy vector
			float mag2();
			float mag();
			
		};
		bool inline operator==(const Vector3f& left, const Vector3f& right) {
			return (left.x == right.x) && (left.y == right.y) && (left.z == right.z);
		}

		bool inline operator!=(const Vector3f& left, const Vector3f& right) {
			return !(left == right);
		}

		Vector3f inline operator+(const Vector3f& left, const Vector3f& right) {
			return Vector3f(left.x + right.x, left.y + right.y, left.z + right.z);
		}

		Vector3f inline operator-(const Vector3f& left, const Vector3f& right) {
			return Vector3f(left.x - right.x, left.y - right.y, left.z - right.z);
		}

		float inline operator*(const Vector3f& left, const Vector3f& right) {
			return left.x * right.x + left.y * right.y + left.z * right.z;
		}

		Vector3f inline operator-(const Vector3f& v) {
			return Vector3f(-v.x, -v.y, -v.z);
		}

		Vector3f cross(const Vector3f left, const Vector3f right);
	}

}


