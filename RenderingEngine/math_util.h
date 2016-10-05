#pragma once
#include "vector3f.h"
#include "vector4f.h"
#include "matrix4f.h"
#include "quaternion.h"

namespace engine {
	namespace math {
		Matrix4f createProjectionMatrix(float near, float far, float fov, float aspect);
		Matrix4f createOrthographicMatrix(float near, float far, float left, float right, float top, float bottom);
		Matrix4f createFrustrumMatrix(float near, float far, float left, float right, float top, float bottom);

		float lerp(float a, float b, float t);
		Vector3f lerp(const Vector3f& a, const Vector3f& b, float t);
		Vector4f lerp(const Vector4f& a, const Vector4f& b, float y);
		Quaternion lerp(const Quaternion& a, const Quaternion& b, float t);
		bool isZero(float value, float epsilon);
	}
}