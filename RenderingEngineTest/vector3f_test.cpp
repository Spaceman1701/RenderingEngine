#include "stdafx.h"
#include "vector3f.h"
#include "math_util.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RenderingEngineTest
{
	TEST_CLASS(vector3f_test)
	{
	public:
		TEST_METHOD(vector3EqualityTest) {
			using namespace engine::math;
			Vector3f vec(0.0, 0.0f, 0.0f);
			Vector3f vec2(0.0f, 0.0f, 0.0f);
			bool equal = vec == vec2;
			bool unequal = vec != vec2;
			Assert::AreEqual(true, equal, L"false negative", LINE_INFO());
			Assert::AreEqual(false, unequal, L"false positive", LINE_INFO());
		}

		TEST_METHOD(vector3AddSubTest) {
			using namespace engine::math;
			Vector3f vec(1.0f, -0.7f, 16.3f);
			Vector3f vec2(2.0f, 1.0f, 3.7f);
			Vector3f add = vec + vec2;
			Vector3f addExpected(1.0f + 2.0f, -0.7f + 1.0f, 16.3f + 3.7f); //to avoid floating point errors... 
			Vector3f sub = vec - vec2;
			Vector3f subExpected(1.0f - 2.0f, -0.7f - 1.0f, 16.3f - 3.7f);
			Assert::AreEqual(addExpected, add, L"add failed", LINE_INFO());
			Assert::AreEqual(subExpected, sub, L"sub failed", LINE_INFO());
		}

		TEST_METHOD(vector3DotTest) {
			using namespace engine::math;
			Vector3f x(1.0f, 0.0f, 0.0f);
			Vector3f y(0.0f, 1.0f, 0.0f);
			bool result = isZero(x * y, 0.00001f);
			Assert::AreEqual(true, result, L"axis dot not zero", LINE_INFO());
		}

		TEST_METHOD(vector3CrossTest) {
			using namespace engine::math;
			Vector3f x(1.0f, 0.0f, 0.0f);
			Vector3f y(0.0f, 1.0f, 0.0f);
			Vector3f result = cross(x, y);
			Vector3f expected = Vector3f(0.0f, 0.0f, 1.0f);
			Assert::AreEqual(expected, result, L"cross product", LINE_INFO());
		}
	};
}