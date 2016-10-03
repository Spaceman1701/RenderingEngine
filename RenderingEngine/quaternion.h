#pragma once
#include "vector3f.h"
#include "matrix3f.h"
namespace engine {
	namespace math {
		class Quaternion {
		private:
			float x;
			float y;
			float z;
			float w;
		public:
			Quaternion();
			Quaternion(Quaternion* q);
			Quaternion(float x, float y, float z, float w);
			Quaternion(const Vector3f& eulerAngles);
			Quaternion(float x, float y, float z);
			Quaternion(const Vector3f& axis, float rads);
			Quaternion(float x, float y, float z, float rads);

			void fromEulerAngles(const Vector3f& eulerAngles);
			void fromEulerAngles(float x, float y, float z);

			void fromAxisAngle(const Vector3f& axis, float rads);
			void fromAxisAngle(float x, float y, float z, float rads);

			void setToIdentity();

			void invertSelf();
			void conjugateSelf();
			void normalizeSelf();

			Quaternion invert();
			Quaternion conjugate();
			Quaternion normalize();

			Quaternion rotate(const Vector3f& eulerAngles);
			Quaternion rotate(float x, float y, float z);

			Quaternion rotate(const Vector3f& axis, float rads);
			Quaternion rotate(float x, float y, float z, float rads);

			void rotateSelf(const Vector3f& eulerAngles);
			void rotateSelf(float x, float y, float z);
			
			void rotateSelf(const Vector3f& axis, float rads);
			void rotateSelf(float x, float y, float z, float rads);

			float length2();
			float length();

			Matrix3f toMatrix();

			Quaternion operator*(const Quaternion& right);
		};
	}
}