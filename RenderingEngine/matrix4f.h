#pragma once
#include "vector4f.h"
#include "matrix3f.h"
namespace engine {
	namespace math {
		class Matrix4f {
		private:
			float mat[16];
			float mulRowVec(const Vector4f& vec, int row);
		public:
			Matrix4f();
			Matrix4f(Matrix4f* m);
			Matrix4f(const Vector4f& c1, const Vector4f& c2, Vector4f& c3, Vector4f& c4);
			Matrix4f(const Matrix3f& rot, const Vector3f& trans);
			Matrix4f(float m00, float m01, float m02, float m03, float m10, float m11, float m12, float m13, float m20, float m21,
				float m22, float m23, float m30, float m31, float m32, float m33);
			Matrix4f(float m[16]);

			Matrix4f transpose();
			void transposeSelf();

			bool inverse(Matrix4f* inverse);
			bool invertSelf();

			void setIdentity();

			float getValue(const int row, const int col);
			float getValue(int i);
			void setValue(const int row, const int col, const float value);
			void rawMatrix(float matrix[16]);
			void setToMatrix(float matrix[16]);
			
			bool inline operator==(Matrix4f& right) {
				return (memcmp(mat, right.mat, sizeof(mat)) == 0); //memcmp returns 0 if two blocks are equal
			}

			bool inline operator!=(Matrix4f& right) {
				return (memcmp(mat, right.mat, sizeof(mat)) != 0);
			}

			Matrix4f operator*(Matrix4f& right);
			Vector4f operator*(Vector4f& right);
		};
	}
}