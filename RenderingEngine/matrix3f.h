#pragma once
#include "vector3f.h"
namespace engine {
	namespace math {
		class Matrix3f { //Column major... feelsuhgman
		private:
			float mat[9];
		public:
			Matrix3f();
			Matrix3f(Matrix3f* mat);
			Matrix3f(Vector3f c1, Vector3f c2, Vector3f c3);
			//m21 = column 2 row 1 [0,3)
			Matrix3f(float m00, float m01, float m02, float m10, float m11, float m12, float m20, float m21, float m22);
			Matrix3f(float mat[]);

			Matrix3f transpose();
			Matrix3f inverse();

			float getValue(const int row, const int col);
			float getValue(int i);
			float determinant();

			void setToMatrix(float matrix[9]);

			void rawMatrix(float matrix[9]);
		};
	}
}