#include "matrix4f.h"
#include "matrix_math.h"
#include <math.h>

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
			mat[15] = 1.0f;
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

		void Matrix4f::transposeSelf() {
			for (int x = 0; x < 4; x++) {
				for (int y = 0; y < 4; y++) {
					setValue(x, y, getValue(y, x));
				}
			}
		}

		bool Matrix4f::inverse(Matrix4f* inverse) {
			inverse->setToMatrix(mat);
			return inverse->invertSelf();
		}
		bool Matrix4f::invertSelf() {
			float inv[16];
			float cofactor[9];
			float detTotals[4];
			float detSacaler;
			for (int c = 0; c < 4; c++) {
				detSacaler = getValue(0, c);
				for (int r = 0; r < 4; r++) {
					cofactorMatrix(mat, cofactor, r, c, 4);
					float cofactorDet = determinant3(cofactor);
					inv[c * 4 + r] = cofactorDet;
					if (r == 0) {
						detTotals[c] = detSacaler * cofactorDet;
					}
				}
			}
			float det = detTotals[0] - detTotals[1] + detTotals[2] - detTotals[3];
			if (det == 0) {
				return false;
			}
			float invdet = 1.0f / det;
			for (int i = 0; i < 16; i++) {
				inv[i] *= invdet;
			}
			setToMatrix(inv);
			return true;
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
		void Matrix4f::rawMatrix(float matrix[16]) {
			memcpy(matrix, mat, sizeof(mat));
		}
		void Matrix4f::setToMatrix(float matrix[16]) {
			memcpy(mat, matrix, sizeof(mat));
		}

		Matrix4f Matrix4f::operator*(Matrix4f& right) {
			float output[16];
			for (int row = 0; row < 4; row++) {
				for (int col = 0; col < 4; col++) {
					output[row + col * 4] = mulRowCol(mat, right.mat, row, col, 4);
				}
			}
			return Matrix4f(output);
		}

		Vector4f Matrix4f::operator*(Vector4f& right) {
			Vector4f output;
			output.x = mulRowVec(right, 0);
			output.y = mulRowVec(right, 1);
			output.z = mulRowVec(right, 2);
			output.w = mulRowVec(right, 3);
			return output;
		}

		float Matrix4f::mulRowVec(const Vector4f& vec, int row) {
			return getValue(row, 0)*vec.x + getValue(row, 1)*vec.y + getValue(row, 2)*vec.z + getValue(row, 3)*vec.w;
		}

		Matrix3f Matrix4f::getMatrix3() {
			return Matrix3f(mat[0], mat[1], mat[2],
				mat[4], mat[5], mat[6],
				mat[8], mat[9], mat[10]);
		}

		void Matrix4f::setMatrix3(const Matrix3f& m) {
			mat[0] = m.getValue(0);
			mat[1] = m.getValue(1);
			mat[2] = m.getValue(2);

			mat[4] = m.getValue(3);
			mat[5] = m.getValue(4);
			mat[6] = m.getValue(5);

			mat[8] = m.getValue(6);
			mat[9] = m.getValue(7);
			mat[10] = m.getValue(8);
		}
		void Matrix4f::setToTranslation(float x, float y, float z) {
			setIdentity();
			mat[12] = x;
			mat[13] = y;
			mat[14] = z;
		}
		void Matrix4f::setToTranslation(const Vector3f& trans) {
			setToTranslation(trans.x, trans.y, trans.z);
		}
		void Matrix4f::setToTranslation(const Vector4f& trans) {
			setToTranslation(trans.x, trans.y, trans.z);
		}

		void Matrix4f::setToRotation(float x, float y, float z, float rads) {
			setToRotation(Vector3f(x, y, z), rads);

		}
		void Matrix4f::setToRotation(Vector3f axis, float rads) {
			setIdentity();
			Vector3f norm_axis = axis.norm();
			float c = cosf(rads);
			float s = sinf(rads);
			float t = 1.0f - c;
			float x = norm_axis.x;
			float y = norm_axis.y;
			float z = norm_axis.z;
			float x2 = x * x;
			float y2 = y * y;
			float z2 = z * z;
			mat[0] = c * x2 * t;
			mat[1] = (y * z * t) + (y * s);
			mat[2] = (z * x * t) - (y * s);

			mat[4] = (x * y * t) - (z * s);
			mat[5] = c + (y2 * t);
			mat[6] = (z * y * t) + (x * c);

			mat[8] = (x * z * t) + (y * s);
			mat[9] = (y * z * t) - (x * s);
			mat[10] = c * (z2 * t);
		}

		void Matrix4f::translate(const Vector3f& trans) {
			translate(trans.x, trans.y, trans.z);
		}

		void  Matrix4f::translate(const Vector4f& trans) {
			translate(trans.x, trans.y, trans.z);
		}

		void Matrix4f::translate(float x, float y, float z) {
			Matrix4f temp;
			temp.setToTranslation(x, y, z);
			multiplySelf(temp);
		}

		void Matrix4f::rotate(float x, float y, float z, float rads) {
			rotate(Vector3f(x, y, z), rads);
		}

		void Matrix4f::rotate(const Vector3f& axis, float rads) {
			Matrix4f temp;
			temp.setToRotation(axis, rads);
			multiplySelf(temp);
		}

		void Matrix4f::setToScale(const Vector3f& scale) {
			setToScale(scale.x, scale.y, scale.z);
		}

		void Matrix4f::setToScale(float x, float y, float z) {
			setIdentity();
			mat[0] = x;
			mat[5] = y;
			mat[10] = z;
		}

		void Matrix4f::setToScale(float s) {
			setToScale(s, s, s);
		}

		void Matrix4f::scale(const Vector3f& s) {
			scale(s.x, s.y, s.z);
		}

		void Matrix4f::scale(float x, float y, float z) {
			Matrix4f temp;
			temp.setToScale(x, y, z);
			multiplySelf(temp);
		}

		void Matrix4f::scale(float s) {
			scale(s, s, s);
		}

		void Matrix4f::multiplySelf(const Matrix4f& right) {
			float output[16];
			for (int row = 0; row < 4; row++) {
				for (int col = 0; col < 4; col++) {
					output[row + col * 4] = mulRowCol(mat, right.mat, row, col, 4);
				}
			}
			setToMatrix(output);
		}

		float Matrix4f::operator[](int i) const{
			return mat[i];
		}
		float& Matrix4f::operator[](int i) {
			return mat[i];
		}
	}
}