#include <iostream>

#include "math_test.h"

//1 = run folder specific test file, 0 = don't
#define MATH 1

namespace test {
	void runAllTests() {
		if (MATH) {
			int numFailed = 0;
			if (math::runTests(&numFailed)) {
				std::cout << "MATH: success - all tests passed" << std::endl;
			} else {
				std::cout << "MATH: failure - " << numFailed << " tests failed" << std::endl;
			}
		}
	}
}