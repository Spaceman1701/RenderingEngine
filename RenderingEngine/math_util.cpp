#include "unit_test.h"
#include "math_util.h"
#define _USE_MATH_DEFINES
#include <math.h>
namespace engine {
	namespace math {
		Matrix4f createProjectionMatrix(float near, float far, float fov, float aspect) {
			float top = near * tanf((M_PI / 180.0f) * (fov / 2));
			float bottom = -top;
			float right = top * aspect;
			float left = -right;
			return createFrustrumMatrix(near, far, left, right, top, bottom);
		}

		Matrix4f createOrthographicMatrix(float near, float far, float left, float right, float top, float bottom) {
			Matrix4f mat;
			float width = right - left;
			float height = top - bottom;
			float dist = far - near;

			mat[0] = 2 / width;
			mat[5] = 2 / height;
			mat[10] = (-2) / dist;
			mat[12] = -(right + left) / width;
			mat[13] = -(top + bottom) / (top - bottom);
			mat[14] = -(far + near) / dist;
			mat[15] = 1;
			return mat;
		}

		Matrix4f createFrustrumMatrix(float near, float far, float left, float right, float top, float bottom) {
			Matrix4f mat;
			float width = right - left;
			float height = top - bottom;
			float dist = far - near;
			mat[0] = (2 * near) / width;

			mat[5] = (2 * near) / height;

			mat[8] = (right + left) / width;
			mat[9] = (top + bottom) / height;
			mat[10] = (-(far + near)) / dist;
			mat[11] = -1;

			mat[14] = (-2 * far * near) / dist;
			return mat;
		}

		TESTABLE float lerp(float a, float b, float t) {
			return (1 - t) * a + t * b;
		}

		Vector3f lerp(const Vector3f& a, const Vector3f& b, float t) {
			return ((1 - t) * a) + (t * b);
		}

		Vector4f lerp(const Vector4f& a, const Vector4f& b, float t) {
			return ((1 - t) * a) + (t * b);

		}

		bool isZero(float value, float epsilon) {
			return fabsf(value) < epsilon;
		}
	}
}