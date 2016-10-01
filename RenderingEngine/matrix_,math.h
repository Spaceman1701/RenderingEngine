#pragma once

namespace engine {
	namespace math {
		float inline determinant2(float m00, float m01, float m10, float m11) {
			return (m00 * m11) - (m01 * m10);
		}

		float inline determinant3(const float m[9]) {
			float v1 = m[0] * (m[4] * m[8] - m[5] * m[7]);
			float v2 = m[3] * (m[1] * m[8] - m[2] * m[7]);
			float v3 = m[6] * (m[1] * m[5] - m[2] * m[4]);
			return v1 - v2 + v3;
		}

		void minorMatrix(const float mat[], float minor[], int size);
	}
}