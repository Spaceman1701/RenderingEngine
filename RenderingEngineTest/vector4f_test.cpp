#include "stdafx.h"
#include "vector4f.h"
#include "math_util.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RenderingEngineTest
{
	TEST_CLASS(Vector4f_Test)
	{
	public:
		TEST_METHOD(vector4EqualityTest) {
			using namespace engine::math;
			Vector4f vec(0.0, 0.0f, 0.0f, 0.0f);
			Vector4f vec2(0.0f, 0.0f, 0.0f, 0.0f);
			bool equal = vec == vec2;
			bool unequal = vec != vec2;
			Assert::AreEqual(true, equal, L"false negative", LINE_INFO());
			Assert::AreEqual(false, unequal, L"false positive", LINE_INFO());
		}

		TEST_METHOD(vector4AddSubTest) {
			using namespace engine::math;
			Vector4f vec(1.0f, -0.7f, 16.3f, -6.3f);
			Vector4f vec2(2.0f, 1.0f, 3.7f, 5.4f);
			Vector4f add = vec + vec2;
			Vector4f addExpected(1.0f + 2.0f, -0.7f + 1.0f, 16.3f + 3.7f, -6.3f + 5.4f); 

			Vector4f sub = vec - vec2;
			Vector4f subExpected(1.0f - 2.0f, -0.7f - 1.0f, 16.3f - 3.7f, -6.3f - 5.4f);
			Assert::AreEqual(addExpected, add, L"add failed", LINE_INFO());
			Assert::AreEqual(subExpected, sub, L"sub failed", LINE_INFO());
		}

		TEST_METHOD(vector4DotTest) {
			using namespace engine::math;
			Vector4f x(1.0f, 2.0f, 3.0f, 4.0f);
			Vector4f y(5.0f, 6.0f, 7.0f, 8.0f);
			bool result = isZero((70 - (x * y)), 0.00001f);
			Assert::AreEqual(true, result, L"axis dot not zero", LINE_INFO());
		}
	};
}