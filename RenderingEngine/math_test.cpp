#include "math_test.h"
#include "vector3f.h"
#include "matrix3f.h"
#include "matrix4f.h"
#include <iostream>
namespace test {
	namespace math {
		bool runTests(int* numFailed) {
			bool ret = true;
			if (!vector3Test()) {
				ret = false;
				(*numFailed)++;
			}
			if (!matrix3Test()) {
				ret = false;
				(*numFailed)++;
			}
			if (!matrix4Test()) {
				ret = false;
				(*numFailed)++;
			}
			return ret;
		}

		bool matrix4Test() {
			using namespace engine::math;
			Matrix4f mat;
			Matrix4f mat2;
			if (mat != mat2) {
				std::cout << "mat4 inequality problems!" << std::endl;
				return false;
			}
			mat2.setValue(2, 0, 10.0f);
			if (mat == mat2) {
				std::cout << "mat4 equality problems!" << std::endl;
				return false;
			}
			Matrix4f invMat;
			mat.inverse(&invMat);
			if (mat != invMat) {
				std::cout << "mat4 inverse problems" << std::endl;
				return false;
			}
			mat2.inverse(&invMat);
			if (invMat == mat2) {
				std::cout << "mat4 inverse dif problems" << std::endl;
				return false;
			}
			mat.setIdentity();
			Matrix4f mat3;
			if (mat2 * mat != mat2) {
				std::cout << "mat4 mul problems!" << std::endl;
				return false;
			}
			Vector4f a(1.1f, 6.8f, 2.3f, -9.0f);
			if (mat * a != a) {
				std::cout << "mat4 vec4 mul failed" << std::endl;
				return false;
			}

			return true;
		}

		bool matrix3Test() {
			using namespace engine::math;
			Matrix3f mat;
			Matrix3f mat2;
			mat2.setToIdentity();
			Matrix3f mat3;
			mat3.setValue(0, 0, 10);
			if (mat3 == mat2) {
				std::cout << "equality problems!" << std::endl;
				return false;
			}
			if (mat != mat2) {
				std::cout << "identity matricies not equal!" << std::endl;
				return false;
			}
			Matrix3f inv;
			mat.inverse(&inv);
			if (inv != mat2) {
				std::cout << "inverse failure!" << std::endl;
				return false;
			}
			return true;
		}

		bool vector3Test() {
			using namespace engine::math;
			Vector3f ivec = Vector3f(1, 0, 0);
			Vector3f jvec = Vector3f(0, 1, 0);
			Vector3f kvec = Vector3f(0, 0, 1);
			if (cross(ivec, jvec) != kvec) {
				std::cout << "i X j != k" << std::endl;
				return false;
			} 
			if (cross(ivec, kvec) != -jvec) {
				std::cout << "i x k != -j" << std::endl;
				return false;
			}
			return true;
		}
	}
}