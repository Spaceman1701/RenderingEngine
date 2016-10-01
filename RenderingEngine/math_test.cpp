#include "math_test.h"
#include "vector3f.h"
#include <iostream>;
namespace test {
	namespace math {
		bool runTests(int* numFailed) {
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
			*numFailed = 0;
			return true;
		}
	}
}