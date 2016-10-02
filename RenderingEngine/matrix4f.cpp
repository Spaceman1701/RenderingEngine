#include "matrix4f.h"

namespace engine {
	namespace math {
		Matrix4f::Matrix4f() {
			setIdentity();
		}
		Matrix4f::Matrix4f(Matrix4f* m) {
			memcpy(mat, m->mat, sizeof(mat));
		}
		Matrix4f::Matrix4f(const Vector4f& c1, const Vector4f& c2, Vector4f& c3, Vector4f& c4) {
			mat[0] = c1.x;
			mat[1] = c1.y;
			mat[2] = c1.z;
			mat[3] = c1.w;

			mat[4] = c2.x;
			mat[5] = c2.y;
			mat[6] = c2.z;
			mat[7] = c2.w;

			mat[8] = c3.x;
			mat[9] = c3.y;
			mat[10] = c3.z;
			mat[11] = c3.w;

			mat[12] = c4.x;
			mat[13] = c4.y;
			mat[14] = c4.z;
			mat[15] = c4.w;
		}
		Matrix4f::Matrix4f(const Matrix3f& rot, const Vector3f& trans) {
			mat[0] = rot.getValue(0);
			mat[1] = rot.getValue(1);
			mat[2] = rot.getValue(2);
			mat[3] = 0.0f;

			mat[4] = rot.getValue(3);
			mat[5] = rot.getValue(4);
			mat[6] = rot.getValue(5);
			mat[7] = 0.0f;

			mat[8] = rot.getValue(6);
			mat[9] = rot.getValue(7);
			mat[10] = rot.getValue(8);
			mat[11] = 0.0f;

			mat[12] = trans.x;
			mat[13] = trans.y;
			mat[14] = trans.z;
			mat[15] = 0.0f;
		}
		Matrix4f::Matrix4f(float m00, float m01, float m02, float m03, float m10, float m11, float m12, float m13, float m20, float m21,
			float m22, float m23, float m30, float m31, float m32, float m33) {
			mat[0] = m00;
			mat[1] = m01;
			mat[2] = m02;
			mat[3] = m03;

			mat[4] = m10;
			mat[5] = m11;
			mat[6] = m12;
			mat[7] = m13;

			mat[8] = m20;
			mat[9] = m21;
			mat[10] = m22;
			mat[11] = m23;

			mat[12] = m30;
			mat[13] = m31;
			mat[14] = m32;
			mat[15] = m33;
		}

		void Matrix4f::setIdentity() {
			mat[0] = 1;
			mat[1] = 0;
			mat[2] = 0;
			mat[3] = 0;

			mat[4] = 0;
			mat[5] = 1;
			mat[6] = 0;
			mat[7] = 0;

			mat[8] = 0;
			mat[9] = 0;
			mat[10] = 1;
			mat[11] = 0;

			mat[12] = 0;
			mat[13] = 0;
			mat[14] = 0;
			mat[15] = 1;
		}

		Matrix4f::Matrix4f(float m[16]) {
			memcpy(mat, m, sizeof(mat));
		}

		Matrix4f Matrix4f::transpose() {
			Matrix4f transpose;
			for (int x = 0; x < 4; x++) {
				for (int y = 0; y < 4; y++) {
					transpose.setValue(x, y, getValue(y, x));
				}
			}
			return transpose;
		}
		Matrix4f Matrix4f::inverse() {

		}

		void Matrix4f::transposeSelf() {
			for (int x = 0; x < 4; x++) {
				for (int y = 0; y < 4; y++) {
					setValue(x, y, getValue(y, x));
				}
			}
		}

		bool Matrix4f::inverse(Matrix4f* inverse) {

		}
		bool Matrix4f::invertSelf() {
			float inv[16];

		}

		float Matrix4f::getValue(const int row, const int col) {
			return mat[col * 4 + row];
		}
		float Matrix4f::getValue(int i) {
			return mat[i];
		}
		void Matrix4f::setValue(const int row, const int col, const float value) {
			mat[col * 4 + row] = value;
		}
		void Matrix4f::rawMatrix(float matrix[9]) {
			memcpy(matrix, mat, sizeof(mat));
		}
	}
}