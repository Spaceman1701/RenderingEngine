#include "matrix3f.h"

namespace engine {
	namespace math {
		float Matrix3f::determinant() {
			float v1 = mat[0] * (mat[4] * mat[8] - mat[5] * mat[7]);
			float v2 = mat[3] * (mat[1] * mat[8] - mat[2] * mat[7]);
			float v3 = mat[6] * (mat[1] * mat[5] - mat[2] * mat[4]);
			return v1 - v2 + v3;
		}
	}
}