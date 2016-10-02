#include "matrix3f.h"
#include "matrix_,math.h"
#include <string.h>

namespace engine {
	namespace math {

		Matrix3f::Matrix3f() {
			setToIdentity();
		}
		Matrix3f::Matrix3f(Matrix3f* m) {
			memcpy(this->mat, m->mat, sizeof(m->mat));
		}
		Matrix3f::Matrix3f(Vector3f c1, Vector3f c2, Vector3f c3) {
			mat[0] = c1.x;
			mat[1] = c1.y;
			mat[2] = c1.z;
			mat[3] = c2.x;
			mat[4] = c2.y;
			mat[5] = c2.z;
			mat[6] = c3.x;
			mat[7] = c3.y;
			mat[8] = c3.z;
		}
		//m21 = column 2 row 1 [0,3)
		Matrix3f::Matrix3f(float m00, float m01, float m02, float m10, float m11, float m12, float m20, float m21, float m22) {
			mat[0] = m00;
			mat[1] = m01;
			mat[2] = m02;
			mat[3] = m10;
			mat[4] = m11;
			mat[5] = m12;
			mat[6] = m20;
			mat[7] = m21;
			mat[8] = m22;
		}

		Matrix3f::Matrix3f(float mat[9]) {
			memcpy(this->mat, mat, sizeof(mat));
		}

		void Matrix3f::setToMatrix(float matrix[9]) {
			memcpy(this->mat, matrix, sizeof(matrix));
		}


		float Matrix3f::determinant() {
			return determinant3(mat);
		}

		void Matrix3f::setToIdentity() {
			mat[0] = 1;
			mat[1] = 0;
			mat[2] = 0;
			mat[3] = 0;
			mat[4] = 1;
			mat[5] = 0;
			mat[6] = 0;
			mat[7] = 0;
			mat[8] = 1;
		}

		void Matrix3f::transposeSelf() {
			for (int x = 0; x < 3; x++) {
				for (int y = 0; y < 3; y++) {
					setValue(x, y, getValue(y, x));
				}
			}
		}

		bool Matrix3f::invertSelf() {
			float det = determinant3(mat);
			if (det == 0) {
				return false;
			}
			float invdet = 1.0f / det;

			float inv[9];
			inv[0] = determinant2(getValue(1, 1), getValue(2, 1), getValue(1, 2), getValue(2, 2)) * invdet;
			inv[1] = determinant2(getValue(1, 2), getValue(2, 2), getValue(1, 0), getValue(2, 0)) * invdet;
			inv[2] = determinant2(getValue(1, 0), getValue(2, 0), getValue(1, 1), getValue(2, 1)) * invdet;

			inv[3] = determinant2(getValue(0, 2), getValue(2, 2), getValue(0, 1), getValue(2, 1)) * invdet;
			inv[4] = determinant2(getValue(0, 0), getValue(2, 0), getValue(0, 2), getValue(2, 2)) * invdet;
			inv[5] = determinant2(getValue(0, 1), getValue(2, 1), getValue(0, 0), getValue(2, 0)) * invdet;

			inv[6] = determinant2(getValue(0, 1), getValue(1, 1), getValue(0, 2), getValue(1, 2)) * invdet;
			inv[7] = determinant2(getValue(0, 2), getValue(1, 2), getValue(0, 0), getValue(1, 0)) * invdet;
			inv[8] = determinant2(getValue(0, 0), getValue(1, 0), getValue(0, 1), getValue(1, 1)) * invdet;
			memcpy(mat, inv, sizeof(mat));
			return true;
		}

		bool Matrix3f::inverse(Matrix3f* inverse) {
			//compute the minors
			float det = determinant3(mat);
			if (det == 0) {
				return false;
			}
			float invdet = 1.0f / det;

			float inv[9];
			inv[0] = determinant2(getValue(1, 1), getValue(2, 1), getValue(1, 2), getValue(2, 2)) * invdet;
			inv[1] = determinant2(getValue(1, 2), getValue(2, 2), getValue(1, 0), getValue(2, 0)) * invdet;
			inv[2] = determinant2(getValue(1, 0), getValue(2, 0), getValue(1, 1), getValue(2, 1)) * invdet;

			inv[3] = determinant2(getValue(0, 2), getValue(2, 2), getValue(0, 1), getValue(2, 1)) * invdet;
			inv[4] = determinant2(getValue(0, 0), getValue(2, 0), getValue(0, 2), getValue(2, 2)) * invdet;
			inv[5] = determinant2(getValue(0, 1), getValue(2, 1), getValue(0, 0), getValue(2, 0)) * invdet;

			inv[6] = determinant2(getValue(0, 1), getValue(1, 1), getValue(0, 2), getValue(1, 2)) * invdet;
			inv[7] = determinant2(getValue(0, 2), getValue(1, 2), getValue(0, 0), getValue(1, 0)) * invdet;
			inv[8] = determinant2(getValue(0, 0), getValue(1, 0), getValue(0, 1), getValue(1, 1)) * invdet;
		}

		Matrix3f Matrix3f::transpose() {
			Matrix3f trans;
			for (int x = 0; x < 3; x++) {
				for (int y = 0; y < 3; y++) {
					trans.setValue(x, y, getValue(y, x));
				}
			}
			return trans;
		}

		void Matrix3f::rawMatrix(float raw[9]) {
			memcpy(raw, mat, sizeof(mat));
		}
		
	}
}