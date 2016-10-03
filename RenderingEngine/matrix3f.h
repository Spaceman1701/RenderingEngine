#pragma once
#include "vector3f.h"
#include <string.h>
namespace engine {
	namespace math {
		class Matrix3f { //Column major... feelsuhgman
		private:
			float mat[9];
			float mulRowVec(const Vector3f& vec, int row);
		public:
			Matrix3f();
			Matrix3f(Matrix3f* mat);
			Matrix3f(Vector3f c1, Vector3f c2, Vector3f c3);
			//m21 = column 2 row 1 [0,3)
			Matrix3f(float m00, float m01, float m02, float m10, float m11, float m12, float m20, float m21, float m22);
			Matrix3f(float mat[9]);

			Matrix3f transpose();
			void transposeSelf();

			bool inverse(Matrix3f* inverse);
			bool invertSelf();


			float inline getValue(const int row, const int col) const {
				return mat[3 * col + row];
			}

			void inline setValue(const int row, const int col, const float val) {
				mat[3 * col + row] = val;
			}

			void setToIdentity();

			float inline getValue(int i) const{
				return mat[i];
			}
			float determinant();

			void setToMatrix(float matrix[9]);

			void rawMatrix(float raw[9]);

			bool inline operator==(Matrix3f& right) {
				return (memcmp(mat, right.mat, sizeof(mat)) == 0); //memcmp returns 0 if two blocks are equal
			}

			bool inline operator!=(Matrix3f& right) {
				return (memcmp(mat, right.mat, sizeof(mat)) != 0);
			}

			Matrix3f operator*(Matrix3f& right);
			Vector3f operator*(Vector3f& right);

		};

		
	}
}