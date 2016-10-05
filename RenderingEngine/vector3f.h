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

			Vector3f norm() const; //should copy vector
			float mag2() const;
			float mag() const;
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

		Vector3f inline operator*(const float f, const Vector3f r) {
			return Vector3f(r.x * f, r.y * f, r.z * f);
		}

		Vector3f cross(const Vector3f left, const Vector3f right);
	}

}


