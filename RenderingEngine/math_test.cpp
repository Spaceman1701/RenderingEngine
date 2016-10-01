#include "math_test.h"
#include "vector3f.h"
#include "matrix3f.h"
#include <iostream>;
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
			return ret;
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