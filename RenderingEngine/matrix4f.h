#pragma once

namespace engine {
	namespace math {
		class Matrix4f {
		private:
			float mat[16];
		public:
			Matrix4f();
			Matrix4f(Matrix4f* m);
			Matrix4f(float m00, float m01, float m02, float m03, float m10, float m11, float m12, float m13, float m20, float m21,
				float m22, float m23, float m30, float m31, float m32, float m33);

			Matrix4f transpose();
			Matrix4f inverse();

			float getValue(const int row, const int col);
			float getValue(int i);
			void setValue(const int row, const int col, const float value);
			void rawMatrix(float matrix[9]);
		};
	}
}